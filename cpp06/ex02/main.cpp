#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main()
{
	Base exec;
	Base *test;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << "Loop i: " << i << std::endl;
		test = exec.generate();
		exec.identify(test);
		exec.identify(*test);
		delete test;
	}

	return 0;
}
