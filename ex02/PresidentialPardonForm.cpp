#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5), target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form("PresidentialPardonForm", 25, 5), target(p.target)
{
	*this = p;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	Form::operator=(other);
    return *this;
}

void PresidentialPardonForm::executeSpecial() const
{
	std::cout << this->target << " has been forgiven by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

