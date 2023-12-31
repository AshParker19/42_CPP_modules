#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &newName, int newGrade) : name(newName)
{
    if (newGrade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (newGrade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        grade = newGrade;
}

const std::string &Bureaucrat::getName(void) const
{
    return (name);
}

int Bureaucrat::getGrade(void) const
{
    return (grade);
}

void Bureaucrat::upGrade(void)
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::downGrade(void)
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is to hight");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is to low");
}
