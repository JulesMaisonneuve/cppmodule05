#include "Form.hpp"



Form::GradeTooHighException::GradeTooHighException()
{
	std::cout << "The grade is too high (Max 150)" << std::endl;
}

Form::GradeTooLowException::GradeTooLowException()
{
	std::cout << "The grade is too low (Min 1)" << std::endl;
}

std::ostream &operator<<(std::ostream &output, const Form &f)
{
	// output << b.getName() << ", bureaucrat grade " << b.getGrade();
	return output;
}
