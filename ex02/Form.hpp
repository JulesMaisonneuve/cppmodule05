#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include <cstdlib>

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool Signed;
		const int gradeToSign;
		const int gradeToExec;
		const std::string target;
	public:
		Form(const std::string name, const int gS, const int gE);
		Form(const Form &f);
		Form& operator=(const Form &other);
		virtual ~Form(void);
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getName() const;
		bool getSigned() const;
		std::string getTarget() const;
		void beSigned(const Bureaucrat &b);
		void execute(Bureaucrat const & executor) const;
		virtual void executeSpecial() const = 0;
	class GradeTooHighException : public std::exception
	{
		private:
			const char *msg;
		public:
			GradeTooHighException(const char *msg);
			virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		private:
			const char *msg;
		public:
			GradeTooLowException(const char *msg);
			virtual const char *what(void) const throw();
	};
};

std::ostream &operator<<(std::ostream &output, const Form &f);

#endif
