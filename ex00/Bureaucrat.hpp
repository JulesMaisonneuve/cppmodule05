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
		Bureaucrat(const std::string, int grade);
		Bureaucrat(const Bureaucrat &b);
		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat(void);
	class GradeTooHigh : public std::exception
	{
		private:
		public:
			GradeTooHigh();
	};

	class GradeTooLow : public std::exception
	{
		private:
		public:
			GradeTooLow();
	};
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &b);

#endif
