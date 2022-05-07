#include "Intern.hpp"

Intern::Intern(void)
{
    return ;
}

Intern::Intern(const Intern &s)
{
	(void)s;
}

Form *Intern::makeForm(const std::string &formName, const std::string &target)
{
    Form* form = NULL;
	int index;
	std::string names[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};

	index = -1;
	for (int i = 0; i < 3; i++)
	{
		if (formName == names[i])
		{
			index = i;
			break;
		}
	}
	switch (index)
	{
	case 0:
		std::cout << "Intern creates " << formName << std::endl;
		form = new RobotomyRequestForm(target);
		break;
	case 1:
		std::cout << "Intern creates " << formName << std::endl;
		form = new PresidentialPardonForm(target);
		break;
	case 2:
		std::cout << "Intern creates " << formName << std::endl;
		form = new ShrubberyCreationForm(target);
		break;
	default:
		throw UnknownForm();
		break;
	}
	return (form);
}

Intern& Intern::operator=(const Intern &other)
{
    (void)other;   
    return (*this);
}

const char* Intern::UnknownForm::what() const throw()
{
	return ("Unknown form");
}

Intern::~Intern(void)
{
    return ;
}
