#include "ShrubberyCreationForm.hpp"

void	ShrubberyCreationForm::executeForm() const
{
	std::ofstream	outfile(getTarget() + "_shrubbery");

	if (!outfile.good())
		throw FailedToOpenException();
	outfile << "       _-_" << std::endl;
	outfile << "    /~~   ~~\\" << std::endl;
	outfile << " /~~         ~~\\" << std::endl;
	outfile << "{               }" << std::endl;
	outfile << " \\  _-     -_  /" << std::endl;
	outfile << "   ~  \\ //  ~" << std::endl;
	outfile << "      // \\" << std::endl;
	outfile << "-----------------" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(SHRUB_FORM_NAME, target, SHRUB_FORM_SIGN, SHRUB_FORM_EXEC)
{}

// Orthodox Canonical

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("nameless", "nameless", SHRUB_FORM_SIGN, SHRUB_FORM_EXEC)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
	: ShrubberyCreationForm()
{
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator= (const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	return *this;
}
