#include "Form.hpp"

Form::Form(const std::string name, const int gS, const int gE) : name(name), gradeToSign(gS), gradeToExec(gE)
{
	if (this->gradeToSign < 1 || this->gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExec > 150)
		throw Form::GradeTooLowException();
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
		std::cout << b.getName() << " couldn't sign " << this->getName() << " because: ";
		throw Form::GradeTooLowException();
	}
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return ("The form was already signed");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("The grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("The grade is too low");
}

const char* Form::FormNotSignedException::what() const throw()
{
	return ("The form is not signed");
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
