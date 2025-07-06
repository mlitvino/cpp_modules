#include <string>
#include <iostream>
#include <fstream>

# define BUFFER_SIZE 1024

int	open_file(std::string& filename, std::string& text)
{
	std::ifstream	infile(filename);
	static char		buf[BUFFER_SIZE];

	if (!infile.good())
	{
		std::cout << "Error: failed to open: " << filename << "\n";
		return 1;
	}
	text.clear();
	while (infile.read(buf, BUFFER_SIZE) || infile.gcount() > 0)
		text += buf;
	infile.close();
	if (infile.bad())
	{
		std::cout << "Error: failed to read: " << filename << "\n";
		return 1;
	}
	return 0;
}

void	format_text(std::string& text, std::string& s1, std::string& s2)
{
	std::size_t found;;

	if (s1.empty())
		return ;
	while (1)
	{
		found = text.find(s1);
		if (found == std::string::npos)
			break ;
		text.erase(found, s1.length());
		text.insert(found, s2);
	}
}

int	open_newfile(std::string& filename, std::string& text)
{
	std::string		new_filename = filename + ".replace";
	std::ofstream	outfile(new_filename);

	if (!outfile.good())
	{
		std::cout << "Error: failed to open" << new_filename << "\n";
		return (1);
	}
	outfile << text;
	outfile.close();
	return 0;
}

int	main(int argc, char **argv)
{
	std::string	text;
	std::string	filename;
	std::string	s1;
	std::string	s2;

	if (argc != 4)
		std::cout << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
	else
	{
		filename = argv[1];
		s1 = argv[2];
		s2 = argv[3];
		if (open_file(filename, text))
			return 1;
		format_text(text, s1, s2);
		if (open_newfile(filename, text))
			return 1;
	}
	return 0;
}
