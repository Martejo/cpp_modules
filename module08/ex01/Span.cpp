#include "Span.hpp"


Span::Span( unsigned int maxSize ) : _maxSize(maxSize) {}

Span::Span( const Span &copy ) : _maxSize(copy._maxSize), _iVector(copy._iVector)
{

}

Span::~Span(){}

Span	&Span::operator=( const Span& other )
{
	if(this == &other)
		return (*this);
	_maxSize = other._maxSize;
	_iVector = other._iVector;
    return (*this);
}

void	Span::addNumber(int nb)
{
	if(_iVector.size() >= _maxSize)
		throw(Span::MaxSizeException());
	_iVector.push_back(nb);
}

std::vector<int>	Span::getIntVector( void ) const
{
	return (_iVector);
}


unsigned int Span::shortestSpan() const{
    if (_iVector.size() < 2)
        throw (Span::SpanException());

    // Créer une copie du vecteur et la trier
    std::vector<int> iVecCopy = _iVector;
    std::sort(iVecCopy.begin(), iVecCopy.end());

    // Trouver la différence minimale entre les éléments adjacents
    unsigned int minRange = std::numeric_limits<unsigned int>::max();//static_cast<unsigned int>(-1); // Utiliser la plus grande valeur possible pour unsigned int
    for (size_t i = 1; i < iVecCopy.size(); ++i) {
        unsigned int range = static_cast<unsigned int>(iVecCopy[i] - iVecCopy[i - 1]);
        if (range < minRange)
            minRange = range;
    }

    // Retourner la valeur minimale
    return (minRange);
}

unsigned int Span::longestSpan() const
{
	//trouver le plus grand ecart (max - min)
	if(_iVector.size() < 2)
		throw(SpanException());
	
	//retourne un iterateur(std::vector<int>::const_iterator), que l' on doit dereferencer pour obtenir la valeur int
	int max = *std::max_element(_iVector.begin(), _iVector.end()); 
	int min = *std::min_element(_iVector.begin(), _iVector.end());

	return (max - min);
}

std::ostream &operator<<( std::ostream &flux, const Span &span )
{
    const std::vector<int>& vec = span.getIntVector();
    for (size_t i = 0; i < vec.size(); ++i)
        flux << vec[i] << (i != vec.size() - 1 ? ", " : "");
    return (flux);
}


const char *Span::MaxSizeException::what() const throw()
{
	return ("Error: Max size of the span has been reached, you can't add more integers.\n");
}

const char *Span::SpanException::what() const throw()
{
	return ("Error: Not enough elements to calculate a span.\n");
}