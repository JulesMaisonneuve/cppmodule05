#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*PresidentialPardonForm Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Jimmy("Jimmy", 5);
		PresidentialPardonForm Form("target");
		std::cout << Form << std::endl;
		Jimmy.signForm(Form);
		Jimmy.executeForm(Form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*RobotomyRequestForm Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Jimmy("Jimmy", 5);
		RobotomyRequestForm Form("target");
		std::cout << Form << std::endl;
		Jimmy.signForm(Form);
		Jimmy.executeForm(Form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*ShrubberyCreationForm Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Jimmy("Jimmy", 5);
		ShrubberyCreationForm Form("target");
		std::cout << Form << std::endl;
		Jimmy.signForm(Form);
		Jimmy.executeForm(Form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Executing not signed Form*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Jimmy("Jimmy", 5);
		ShrubberyCreationForm Form("target");
		std::cout << Form << std::endl;
		Jimmy.executeForm(Form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
