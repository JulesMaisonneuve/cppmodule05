#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : Form("ShrubberyCreationForm", 145, 137), target(target)
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &s) : Form("ShrubberyCreationForm", 145, 137), target(s.target)
{
	*this = s;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	Form::operator=(other);
    return *this;
}

// void ShrubberyCreationForm::executeSpecial() const
// {
// 	std::ofstream ofs(this->getTarget() + "_shrubbery");
// 	ofs << "	      /\\n" 
    	// << "	 	 /\*\\n"
// 		<< "		/\O\*\\n"  
// 		<< "	   /*/\/\/\\n"  
// 		<< "	  /\O\/\*\/\\n"
// 		<< "	 /\*\/\*\/\/\\n"
// 		<< "	/\O\/\/*/\/O/\\n"
// 		<< "		  ||\n"     
// 		<< "		  ||\n"      
// 		<< "		  ||\n";   
// }

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return ;
}
