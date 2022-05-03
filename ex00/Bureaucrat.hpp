#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <exception>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &b);
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat(void);
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

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b);

#endif
