#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include <exception>

class Bureaucrat
{
	private:
		static const std::string name;
		int grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string name, int grade);
		std::string getName();
		int getGrade();
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


#endif
