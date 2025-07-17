#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
	int x;
	int y;

	Data();
	Data(const Data& other);
	Data& operator= (const Data& other);
	~Data();
};

#endif
