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
	public:
		Form(const std::string name, const int gS, const int gE);
		Form(const Form &f);
		Form& operator=(const Form &other);
		virtual ~Form(void);
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getName() const;
		bool getSigned() const;
		Form& beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const & executor) const = 0;
	class GradeTooHighException : public std::exception
	{
		private:
		public:
			virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		private:
		public:
			virtual const char *what(void) const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
		private:
		public:
			virtual const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		private:
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &output, const Form &f);

#endif
