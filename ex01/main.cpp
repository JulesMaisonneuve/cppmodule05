#include "Bureaucrat.hpp"

int main(void)
{
	// Bureaucrat Jimmy("Jimmy", 102);
	// std::cout << Jimmy << std::endl;
	// Jimmy.incrementGrade();
	// std::cout << Jimmy << std::endl;
	// Jimmy.decrementGrade();
	// std::cout << Jimmy << std::endl;
	// Bureaucrat Johnny("Johnny", 151);
	try
	{
		Bureaucrat Jimmy("Jimmy", 150);
		std::cout << Jimmy << std::endl;
		Jimmy.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}
