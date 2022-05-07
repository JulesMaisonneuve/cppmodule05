#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string &target) : Form("PresidentialPardonForm", 25, 5), target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form(p), target(p.target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return *this;
	Form::operator=(other);
	this->target = other.target;
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
	{
		std::cout << executor.getName() << " couldn't execute " << this->getName() << " because: ";
		throw Form::FormNotSignedException();
	}
	else if (executor.getGrade() > this->getGradeExec())
	{
		std::cout << executor.getName() << " couldn't execute" << this->getName() << " because: ";
		throw Form::GradeTooLowException();
	}
	std::cout << this->target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

