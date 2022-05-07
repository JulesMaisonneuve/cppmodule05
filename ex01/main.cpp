#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Bad instanciation Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Form form("Form 01", 151, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Form form("Form 01", 150, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Sign Form Test*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Johnny("Johnny", 30);
		std::cout << Johnny << std::endl;
		Form form("Form", 29, 31);
		std::cout << form << std::endl;
		Johnny.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------" << std::endl;
	try
	{
		Bureaucrat Johnny("Johnny", 29);
		std::cout << Johnny << std::endl;
		Form form("Form", 29, 31);
		std::cout << form << std::endl;
		Johnny.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "------" << std::endl;
	try
	{
		Bureaucrat Johnny("Johnny", 29);
		Form form("Form", 29, 31);
		Johnny.signForm(form);
		std::cout << form << std::endl;
		Johnny.signForm(form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "------" << std::endl;
	try
	{
		Form *form = new Form();
		Bureaucrat Jimmy("Jimmy", 150);
		Jimmy.signForm(*form);
		std::cout << *form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
