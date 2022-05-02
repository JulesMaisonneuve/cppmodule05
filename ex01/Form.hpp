#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool Signed;
		const int gradeSign;
		const int gradeExec;
	public:
		Form(void);
		~Form(void);
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getName() const;
		bool getSigned();
	class GradeTooHighException : public std::exception
	{
		private:
		public:
			GradeTooHighException();
	};

	class GradeTooLowException : public std::exception
	{
		private:
		public:
			GradeTooLowException();
	};
};

std::ostream &operator<<(std::ostream &output, const Form &f);

#endif
