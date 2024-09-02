# include "AForm.hpp"

AForm::AForm(const std::string name, const int gradeSign, const int gradeExec)
: _name(name), _isSigned(false), _gradeToSign(gradeSign), _gradeToExec(gradeExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw (GradeTooHighException());
	else if (_gradeToSign > 150 || _gradeToExec > 150)
		throw (GradeTooLowException());
	std::cout << "AForm Default constructor called : " << *this << std::endl;
}

AForm::AForm(const AForm& toCopy)
:_name(toCopy.getName()), _isSigned(toCopy.getSigned()), _gradeToSign(toCopy.getSignGrade()), _gradeToExec(toCopy.getExecGrade())
{
	std::cout << "AForm Copy constructor called : " << *this << std::endl;
}

//Only copy the non-const attributes can be copied after init
AForm& AForm::operator=(AForm& other) 
{
	std::cout << "AForm Assignement operator called" << std::endl;
	if (this != &other)
		_isSigned = other.getSigned();
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm Destructor called : " << *this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& to_display)
{
	os << "AForm name : " << to_display.getName()
	<< ", Grade to sign : " << to_display.getSignGrade()
	<< ", Grade to exec : " << to_display.getExecGrade()
	<< ", Is already signed ? : " << to_display.getSigned();
	return (os);
}

const std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (_isSigned);
}

int AForm::getSignGrade() const
{
	return (_gradeToSign);
}

int AForm::getExecGrade() const
{
	return (_gradeToExec);
}

void AForm::beExecuted(const Bureaucrat& bureaucrat) const
{
	if (bureaucrat.getGrade() > _gradeToExec)
		throw AForm::GradeTooLowException();
	else if (!_isSigned)
		throw AForm::SignatureException();
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm::GradeTooHigh");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm::GradeTooLow");
}


const char * AForm::SignatureException::what() const throw()
{
	return("AForm::SignatureException");
}