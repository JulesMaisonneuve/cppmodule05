#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
	private:
		const std::string target;
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &s);
		RobotomyRequestForm& operator=(const RobotomyRequestForm &other);
		void execute(Bureaucrat const & executor) const;
		std::string getTarget() const;
		~RobotomyRequestForm(void);
};

#endif
