#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : Form(s), target(s.target)
{
	return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return *this;
	Form::operator=(other);
	this->target = other.target;
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
	{
		throw Form::FormNotSignedException();
	}
	else if (executor.getGrade() > this->getGradeExec())
	{
		throw Form::GradeTooLowException();
	}
	std::string tf = target;
	tf.append("_shrubbery");
	std::ofstream ofs(tf.c_str());
	ofs

		<< "   0\n"
		<< "  000\n"
		<< " 00000\n"
		<< "0000000\n"
		<< "   8 \n"
		<< "   8 \n"
		<< "   8 \n"
		<< "       0\n"
		<< "      000\n"
		<< "     00000\n"
		<< "    0000000\n"
		<< "   000000000\n"
		<< "       8 \n"
		<< "       8 \n"
		<< "       8 \n";
	ofs.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}
