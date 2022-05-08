#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name(""), grade(150)
{
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &b) : name(b.getName()), grade(b.getGrade())
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return *this;
	this->grade = other.grade;
    return *this;
}

void Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because: " << e.what() << std::endl;
	}
	catch (Form::FormAlreadySignedException &e)
	{
		std::cout << this->getName() << " couldn't sign " << f.getName() << " because: " << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
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
		throw GradeTooHighException();
	else
		this->grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw GradeTooLowException();
	else
		this->grade += 1;
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because: " << e.what() << std::endl;
	}
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
	return ;
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b)
{
	output << b.getName() << ", bureaucrat grade " << b.getGrade();
	return output;
}
