#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Bad instanciation Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Joe("Joe", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat Joe("Joe", -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Decrementation Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Jimmy("Jimmy", 149);
		std::cout << Jimmy << std::endl;
		Jimmy.decrementGrade();
		std::cout << Jimmy << std::endl;
		Jimmy.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Incrementation Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Jimmy("Jimmy", 2);
		std::cout << Jimmy << std::endl;
		Jimmy.incrementGrade();
		std::cout << Jimmy << std::endl;
		Jimmy.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "=====================================================================" << std::endl;
	std::cout << "\e[1m*Copy Constructor Tests*\e[0m" << std::endl;
	std::cout << "=====================================================================" << std::endl;
	try
	{
		Bureaucrat Jimmy("Jimmy", 6);
		std::cout << Jimmy << std::endl;
		Bureaucrat Joe(Jimmy);
		std::cout << Joe << std::endl;
		Jimmy.incrementGrade();
		std::cout << "\e[1mJimmy\e[0m apres incrementation:" << Jimmy << std::endl;
		std::cout << "\e[1mJoe\e[0m apres incrementation: " << Joe << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
