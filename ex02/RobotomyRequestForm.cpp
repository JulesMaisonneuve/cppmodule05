#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form("RobotomyRequestForm", 72, 45), target(target)
{
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &r) : Form("RobotomyRequestForm", 72, 45), target(r.target)
{
	*this = r;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	Form::operator=(other);
    return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	
	srand (time(NULL));
	int res = (rand() % 2);
	std::cout << res << std::endl;
	std::cout << "*LOUD DRILL NOISES*" << std::endl;
	if (res == 1)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else if (res == 0)
		std::cout << "The robotomy has failed" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return ;
}
