#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Bad instanciation Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Jimmy("Jimmy", 41);
		Bureaucrat Billy("Billy", 5);
		RobotomyRequestForm Form("target");
		PresidentialPardonForm ppf("target2");

		Jimmy.signForm(Form);
		Jimmy.executeForm(Form);
		
		Billy.signForm(ppf);
		Billy.executeForm(ppf);

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	try
	{
		Bureaucrat Jimmy("Jimmy", 50);
		RobotomyRequestForm Form("target");
		
		Jimmy.signForm(Form);
		Jimmy.executeForm(Form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

	return (0);
}
