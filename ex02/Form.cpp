#include "Form.hpp"

Form::Form(const std::string name, const int gS, const int gE) : name(name), gradeToSign(gS), gradeToExec(gE)
{
	if (this->gradeToSign < 1 || this->gradeToExec < 1)
		throw GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExec > 150)
		throw GradeTooLowException();
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

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() <= this->getGradeSign())
	{
		this->Signed = true;
	}
	else
	{
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because grade is too low" << std::endl;
		throw GradeTooLowException();
	}
}

Form::GradeTooHighException::GradeTooHighException()
{
	std::cout << "The grade is too high" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException()
{
	std::cout << "The grade is too low" << std::endl;
}

void Form::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
	{
		std::cout << this->getName() << " is not signed therefore the bureaucrat " << executor.getName() << " cannot sign it" << std::endl;
	}
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else
	{
		std::cout << executor.getName() << " executed " << this->getName() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &output, const Form &f)
{
	output << f.getName() << " is " << (f.getSigned() ? "signed, " : "not signed, ") << "grade required to sign: " << f.getGradeSign() << ", grade required to execute: " << f.getGradeExec();
	return output;
}

Form::~Form(void)
{
	return ;
}
