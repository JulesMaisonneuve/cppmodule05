#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool Signed;
		const int gradeToSign;
		const int gradeToExec;
	public:
		Form(void);
		Form(const std::string name, const int gS, const int gE);
		Form(const Form &f);
		Form& operator=(const Form &other);
		~Form(void);
		int getGradeSign() const;
		int getGradeExec() const;
		std::string getName() const;
		bool getSigned() const;
		void beSigned(const Bureaucrat &b);
	class GradeTooHighException : public std::exception
	{
		private:
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		private:
		public:
			virtual const char* what() const throw();
	};
};

std::ostream &operator<<(std::ostream &output, const Form &f);

#endif
