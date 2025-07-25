#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* Base::generate()
{
	std::default_random_engine	generator{std::random_device{}()};
	std::uniform_int_distribution<int> range(0, 2);

	switch (range(generator))
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
		default:
			return nullptr;
	}
}

void Base::identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "type of p ptr: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "type of p ptr: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "type of p ptr: C" << std::endl;
}

void Base::identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "type of p ref: A" << std::endl;
	}
	catch (std::bad_cast &e)
	{ }
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "type of p ref: B" << std::endl;
	}
	catch (std::bad_cast &e)
	{ }
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "type of p ref: C" << std::endl;
	}
	catch (std::bad_cast &e)
	{ }
}

