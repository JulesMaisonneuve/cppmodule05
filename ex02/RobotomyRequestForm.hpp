#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		std::string target;
	public:
		RobotomyRequestForm(std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &s);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		void execute(Bureaucrat const & executor) const;
		~RobotomyRequestForm(void);
};

#endif
