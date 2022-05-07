#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Bureaucrat.hpp"
# include "Form.hpp"
# include <fstream>
# include <string>

class ShrubberyCreationForm : public Form
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &s);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
		void execute(Bureaucrat const & executor) const;
		~ShrubberyCreationForm(void);
};

#endif
