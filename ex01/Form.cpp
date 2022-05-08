#include "Form.hpp"

Form::Form(void) : name("Default form name"), Signed(false), gradeToSign(150), gradeToExec(150)
{
	return ;
}

Form::Form(const std::string name, const int gS, const int gE) : name(name), Signed(false), gradeToSign(gS), gradeToExec(gE)
{
	if (this->gradeToSign < 1 || this->gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (this->gradeToSign > 150 || this->gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &f) : name(f.name), Signed(f.Signed), gradeToSign(f.gradeToSign), gradeToExec(f.gradeToExec)
{
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

Form& Form::beSigned(Bureaucrat const & b)
{
	if ( b.getGrade() > this->gradeToSign )
		throw Form::GradeTooLowException();
	else if (this->Signed)
		throw Form::FormAlreadySignedException();
	this->Signed = true;
	return *this;
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


std::ostream &operator<<(std::ostream &output, const Form &f)
{
	output << f.getName() << " is " << (f.getSigned() ? "signed, " : "not signed, ") << "grade required to sign: " << f.getGradeSign() << ", grade required to execute: " << f.getGradeExec();
	return output;
}

Form::~Form(void)
{
	return ;
}
