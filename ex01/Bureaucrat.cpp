#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	// std::cout << "Bureaucrat default constructor called" << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = b;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	this->grade = other.grade;
    return *this;
}

void Bureaucrat::signForm(Form &form)
{
	if (form.getSigned())
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because it was already signed" << std::endl;
	else
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
	// std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooHighException();
	else if (grade < 1)
		throw GradeTooLowException();
	else
	{
		this->grade = grade;
	}
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
		throw GradeTooLowException();
	else
		this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooHighException();
	else
		this->grade += 1;
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
	std::cout << "The grade is too high (Max 150)" << std::endl;
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
	std::cout << "The grade is too low (Min 1)" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	// std::cout << "Bureaucrat destructor called" << std::endl;
	return ;
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b)
{
	output << b.getName() << ", bureaucrat grade " << b.getGrade();
	return output;
}
