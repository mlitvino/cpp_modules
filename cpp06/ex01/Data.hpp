#ifndef DATA_HPP
#define DATA_HPP

class Data
{
	private:
		int x;
		int y;

	public:
		Data();
		Data(const Data& other);
		Data& operator= (const Data& other);
		~Data();
};

#endif
