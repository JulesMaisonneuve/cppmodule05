#include "Intern.hpp"

Intern::Intern(void)
{
    return ;
}

Form *Intern::createPresidentialForm(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

Form *Intern::makeForm(const std::string name, const std::string target)
{
    Form *(Intern::*form_array[4])(const std::string target);
    std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

    form_array[0] = &Intern::createShrubberyForm;
    form_array[1] = &Intern::createRobotomyForm;
    form_array[2] = &Intern::createPresidentialForm;

    for (int i = 0; i < 3; i++)
    {
        if (name == forms[i])
        {

    // std::cout << "Intern creates " << 
            return (this->*form_array[i])(target);
        }
    }
}


Intern& Intern::operator=(const Intern &other)
{
	if (this == &other)
		return *this;
    return *this;
}

Intern::~Intern(void)
{
    return ;
}