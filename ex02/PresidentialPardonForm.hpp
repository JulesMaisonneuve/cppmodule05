#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		const std::string target;
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &s);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
		~PresidentialPardonForm(void);
};

#endif
