#include "Span.hpp"


Span::Span( unsigned int maxSize ) : _maxSize(maxSize) {}

Span::Span( const Span &copy )
{
	if (this != &copy)
		*this = copy;
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

void	Span::addNumber(const int &nb)
{
	if(_iVector.size() >= _maxSize)
		throw(Span::MaxSizeExeption());
	_iVector.push_back(nb);
}

std::vector<int>	Span::getIntVector( void ) const
{
	return (_iVector);
}


void Span::addItRange(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd, std::vector<int>& container) 
{
    if (!isValidRange(itBegin, itEnd, container)) {
        throw std::invalid_argument("Error: Invalid iterators or iterators do not belong to the same container.");
    }
    for (; itBegin != itEnd; ++itBegin) {
        this->addNumber(*itBegin);
}
}  

bool	Span::isValidRange(std::vector<int>::iterator itBegin, std::vector<int>::iterator itEnd, std::vector<int>& container) 
{
        return itBegin >= container.begin() && itBegin <= container.end() &&
               itEnd >= container.begin() && itEnd <= container.end() &&
               itBegin <= itEnd;
}

unsigned int Span::shortestSpan() const{
    if (_iVector.size() < 2)
        throw (Span::SpanExeption());

    // Créer une copie du vecteur et la trier
    std::vector<int> iVecCopy = _iVector;
    std::sort(iVecCopy.begin(), iVecCopy.end());

    // Trouver la différence minimale entre les éléments adjacents
    unsigned int minRange = static_cast<unsigned int>(-1); // Utiliser la plus grande valeur possible pour unsigned int
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
		throw(SpanExeption());
	
	//retourne un iterateur(std::vector<int>::const_iterator), que l' on doit dereferencer pour obtenir la valeur int
	int max = *std::max_element(_iVector.begin(), _iVector.end()); 
	int min = *std::min_element(_iVector.begin(), _iVector.end());

	return (max - min);
}

std::ostream 	&operator<<( std::ostream &flux, const Span &span )
{
	for (size_t i = 0; i < span.getIntVector().size(); i++)
		flux << span.getIntVector()[i] << (i != span.getIntVector().size() - 1 ? ", " : "");
	return (flux);
}

const char *Span::MaxSizeExeption::what() const throw()
{
	return ("Error: Max size of the span have been reached, you can't add more integers.\n");
}

const char *Span::SpanExeption::what() const throw()
{
	return ("Error: Not enough elements to calculate an interval.\n");
} 