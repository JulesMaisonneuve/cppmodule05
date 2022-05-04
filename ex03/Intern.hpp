#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
    private:
    public:
        Intern(void);
        Intern(const Intern &s);
        Intern& operator=(const Intern &other);
        Form *makeForm(const std::string name, const std::string target);
        Form *createPresidentialForm(const std::string target);
        Form *createShrubberyForm(const std::string target);
        Form *createRobotomyForm(const std::string target);
        ~Intern(void);
};

#endif 