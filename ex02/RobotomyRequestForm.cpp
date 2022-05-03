#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : Form("RobotomyRequestForm", 72, 45), target(target)
{
	*this = r;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	Form::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}
