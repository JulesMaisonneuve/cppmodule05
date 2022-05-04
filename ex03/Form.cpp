#include "Form.hpp"

Form::Form(const std::string name, const int gS, const int gE) : name(name), gradeToSign(gS), gradeToExec(gE)
{
	if (this->gradeToSign < 1 || this->gradeToExec < 1)
		throw GradeTooHighException("Grade is too high");
	else if (this->gradeToSign > 150 || this->gradeToExec > 150)
		throw GradeTooLowException("Grade is too low");
	this->Signed = false;
	return ;
}

Form::Form(const Form &f) : name(f.name), gradeToSign(f.gradeToSign), gradeToExec(f.gradeToExec)
{
	*this = f;
}

Form& Form::operator=(const Form &other)
{
	if (this == &other)
		return *this;
	this->Signed = other.Signed;
    return *this;
}

int Form::getGradeSign() const
{
	return (this->gradeToSign);
}

int Form::getGradeExec() const
{
	return (this->gradeToExec);
}

std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSigned() const
{
	return (this->Signed);
}

std::string Form::getTarget() const
{
	return (this->target);
}


void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
	{
		this->Signed = true;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because his grade is too low" << std::endl;
		throw GradeTooLowException("Grade is too low");
	}
}

Form::GradeTooHighException::GradeTooHighException(const char *msg) : msg(msg) {}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return this->msg;
}

Form::GradeTooLowException::GradeTooLowException(const char *msg)
	: msg(msg) {}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return this->msg;
}

void Form::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
	{
		std::cout << this->getName() << " is not signed therefore the bureaucrat " << executor.getName() << " cannot execute it" << std::endl;
	}
	else if (executor.getGrade() > this->getGradeExec())
	{
		std::cout << executor.getName() << " couldn't execute" << this->getName() << " because: ";
		throw GradeTooLowException("Grade is too low");
	}
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
		this->executeSpecial();
	}
}

std::ostream &operator<<(std::ostream &output, const Form &f)
{
	output << f.getName() << " is " << (f.getSigned() ? "signed, " : "not signed, ") << "grade required to sign: " << f.getGradeSign() << ", grade required to execute: " << f.getGradeExec() << ", target: " << f.getTarget();
	return output;
}

Form::~Form(void)
{
	return ;
}
