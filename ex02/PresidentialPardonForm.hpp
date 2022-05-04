#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
	private:
		const std::string target;
	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &s);
		PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
		void executeSpecial() const;
		~PresidentialPardonForm(void);
};

#endif
