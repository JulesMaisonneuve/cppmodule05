#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Subject Test*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	Intern someRandomIntern;
	Form* rrf;

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*More Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		rrf = someRandomIntern.makeForm("formulaire", "Target");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	rrf = someRandomIntern.makeForm("shrubbery creation", "Target");
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "Target");
	delete rrf;
	return (0);
}
