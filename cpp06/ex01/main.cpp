#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data		data;
	Data		*data_ptr;
	uintptr_t	uptr;

	uptr = Serializer::serialize(&data);
	data_ptr = Serializer::deserialize(uptr);

	std::cout << "address of data: " << &data << std::endl;
	std::cout << "value of uptr: " << uptr << std::endl;
	std::cout << "address of data_ptr: " << data_ptr << std::endl;

	return 0;
}
