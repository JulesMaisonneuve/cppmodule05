#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
{
	if (grade > 150)
		throw GradeTooHigh();
	else if (grade < 1)
		throw GradeTooLow();
	else
		this->grade = grade;
	return ;
}

Bureaucrat::GradeTooHigh::GradeTooHigh()
{
	std::cout << "The grade is too high (Max 150)" << std::endl;
}

Bureaucrat::GradeTooLow::GradeTooLow()
{
	std::cout << "The grade is too low (Min 1)" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}


