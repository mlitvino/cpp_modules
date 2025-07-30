#!/usr/bin/env bash
out=input.txt
{
echo "date | value"
d=2009-01-02
while [[ "$d" < "2023-01-01" ]] || [[ "$d" == "2023-01-01" ]]; do
	# here we just use a dummy value, replace 1.00 with whatever you need
	# generate a random integer from 0 to 1000
	printf "%s | %d\n" "$d" "$(( (RANDOM % 10) - 0 ))"
	d=$(date -I -d "$d + 1 day")
done
} > "$out"
