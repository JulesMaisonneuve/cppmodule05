#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : Form(r), target(r.target)
{
	return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return *this;
	Form::operator=(other);
	this->target = other.target;
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand (time(NULL));
	if (this->getSigned() == false)
	{
		throw Form::FormNotSignedException();
	}
	else if (executor.getGrade() > this->getGradeExec())
	{
		throw Form::GradeTooLowException();
	}
	int res = (rand() % 2);
	std::cout << "*LOUD DRILL NOISES*" << std::endl;
	if (res == 1)
		std::cout << this->target << " has been robotomized" << std::endl;
	else if (res == 0)
		std::cout << "The robotomy has failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}
