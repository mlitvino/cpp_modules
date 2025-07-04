#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	std::string	str;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < argc; i++)
	{
		str = argv[i];
		for (char& c : str)
			c = std::toupper(c);
		std::cout << str << " ";
	}
	std::cout << std::endl;
	return 0;
}
