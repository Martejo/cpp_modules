#include "Data.hpp"

Data::Data(const std::string str)
{
	_str = str;
}

Data::Data( const Data &copy )
{
	_str = copy.getStr();
}

Data::~Data(){}

Data &Data::operator=( const Data &a )
{
	if (this == &a)
		return (*this);
	_str = a.getStr();
	return (*this);
}

std::ostream &operator<<( std::ostream &flux, const Data &Data )
{
	flux << Data.getStr();
	return (flux);
}

const std::string	Data::getStr( void ) const {return (_str);}