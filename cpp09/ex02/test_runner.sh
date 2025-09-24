#!/usr/bin/env bash
# Test runner for a program that accepts space-separated positive, non-duplicate integers (0..INT_MAX).
# Usage: ./test_runner.sh [program] [num_tests] [nums_per_test] [seed] [outfile] [timeout_sec]
# Defaults:
#   program        -> ./PmergeMe
#   num_tests      -> 100
#   nums_per_test  -> 10
#   seed           -> (random)
#   outfile        -> test_results.txt
#   timeout_sec    -> 5

set -euo pipefail

PROG="${1:-./PmergeMe}"
NUM_TESTS="${2:-100}"
NUMS_PER_TEST="${3:-10}"
SEED="${4:-}"
OUTFILE="${5:-test_results.txt}"
TIMEOUT_SEC="${6:-5}"

# Determine ARG_MAX (fallback)
ARG_MAX="$(getconf ARG_MAX 2>/dev/null || echo 2097152)"

# sanity checks
if [[ ! -x "$PROG" ]]; then
  echo "Error: program '$PROG' not found or not executable." >&2
  exit 2
fi

if ! command -v python3 >/dev/null 2>&1; then
  echo "Error: python3 is required by this script." >&2
  exit 3
fi

# header in output file (use echo to avoid printf portability issues)
{
  echo "Test run: $(date -u +%Y-%m-%dT%H:%M:%SZ)"
  echo "Program: $PROG"
  echo "Tests: $NUM_TESTS, Numbers per test: $NUMS_PER_TEST, Timeout: ${TIMEOUT_SEC}s"
  if [[ -n "$SEED" ]]; then
    echo "Seed: $SEED"
  else
    echo "Seed: (none -> random)"
  fi
  echo "ARG_MAX: $ARG_MAX"
  echo "----"
  echo
} > "$OUTFILE"

# function to produce one test line (space-separated unique integers in [0, INT_MAX])
# Pass arguments to the python here-doc so sys.argv is available
generate_testcase() {
  local k="$1"
  local seed_in="$2"   # may be empty
  python3 - "$k" "$seed_in" <<'PY'
import sys, random
k = int(sys.argv[1])
seed = sys.argv[2] if len(sys.argv) > 2 else ""
MAX = (1 << 31) - 1   # INT_MAX for 32-bit signed
if seed:
    try:
        random.seed(int(seed))
    except Exception:
        random.seed(hash(seed) & 0xffffffff)
else:
    random.seed()
# sample k unique numbers from 0..MAX
res = random.sample(range(0, MAX+1), k)
sys.stdout.write(" ".join(map(str, res)))
PY
}

# main loop
for ((t = 1; t <= NUM_TESTS; ++t)); do
  # reproducible per-test seed if SEED provided
  if [[ -n "$SEED" ]]; then
    TEST_SEED="${SEED}_${t}"
  else
    TEST_SEED=""
  fi

  testcase="$(generate_testcase "$NUMS_PER_TEST" "$TEST_SEED")" || {
    echo "Failed to generate testcase #$t" >> "$OUTFILE"
    continue
  }

  # estimate command length (program + space + testcase)
  cmd_len=$(( ${#PROG} + 1 + ${#testcase} ))
  if (( cmd_len > ARG_MAX )); then
    echo "Error: estimated command length ($cmd_len) exceeds ARG_MAX ($ARG_MAX). Reduce NUMS_PER_TEST." >> "$OUTFILE"
    echo "Aborting tests." >> "$OUTFILE"
    exit 4
  fi

  # convert testcase to an array safely and run program
  IFS=' ' read -r -a args <<< "$testcase"

  {
    printf "TEST %d\n" "$t"
    printf "ARGS: %s\n" "$testcase"
  } >> "$OUTFILE"

  # run with timeout if available, capture stdout+stderr and exit code
  if command -v timeout >/dev/null 2>&1; then
    out="$( timeout "${TIMEOUT_SEC}s" "$PROG" "${args[@]}" 2>&1 )"
    rc=$?
  else
    out="$("$PROG" "${args[@]}" 2>&1)" || rc=$?
    rc=${rc:-0}
  fi

  {
    printf "EXIT_CODE: %d\n" "$rc"
    printf "OUTPUT:\n%s\n" "$out"
  } >> "$OUTFILE"

  # progress
  printf "\rCompleted %d / %d tests" "$t" "$NUM_TESTS"
done

printf "\nAll tests finished. Results saved to %s\n" "$OUTFILE"
