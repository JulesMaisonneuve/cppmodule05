#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : Form("PresidentialPardonForm", 25, 5), target(target)
{
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &p) : Form("PresidentialPardonForm", 25, 5), target(target)
{
	*this = p;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	Form::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return ;
}

