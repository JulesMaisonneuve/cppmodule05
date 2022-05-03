#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	try
	{
		const Bureaucrat Jimmy("Jimmy", 41);
		RobotomyRequestForm Form("target");
		PresidentialPardonForm ppf("target2", 50, 60);
		Form.execute(Jimmy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
