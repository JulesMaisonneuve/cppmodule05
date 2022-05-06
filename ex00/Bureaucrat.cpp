#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.name), grade(b.grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade = grade;
	return ;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade += 1;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("The grade is too high (Max 1)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("The grade is too low (Min 150)");
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b)
{
	output << b.getName() << ", bureaucrat grade " << b.getGrade();
	return output;
}
