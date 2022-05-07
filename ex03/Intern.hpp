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
        Form *makeForm(const std::string& name, const std::string& target);
        ~Intern(void);
    class UnknownForm : public std::exception
    {
        private:
        public:
            virtual const char* what() const throw();
    };
};

#endif 
