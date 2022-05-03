#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
	private:
		const std::string target;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		std::string getTarget() const;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		// void execute(Bureaucrat const & executor);
		~ShrubberyCreationForm(void);
};

#endif
