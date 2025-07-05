#include <string>
#include <iostream>
#include <fstream>

void	open_file(std::string& filename, std::string& text)
{
	std::ifstream	infile(filename);

	if (!infile.is_open())
	{
		std::cout << "Error: failed to open" << filename << "\n";
		exit(1);
	}
	text.clear();

	int count = infile.gcount();
;

	count = infile.gcount();

	std::cout << count << "\n";



	infile.close();
}

void	open_newfile(std::string& filename, std::string& text)
{
	std::string		new_filename = filename + ".replace";
	std::ofstream	outfile(new_filename);

	if (!outfile.is_open())
	{
		std::cout << "Error: failed to open" << new_filename << "\n";
		exit(1);
	}
	outfile.close();
}

void	get_input(char **argv)
{
	std::string	text;
	std::string	filename;
	std::string	s1;
	std::string	s2;

	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	open_file(filename, text);
	//format_text(text, s1, s2);
	//open_newfile(filename, text);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
	}
	else
	{
		get_input(argv);
	}
	return 0;
}
