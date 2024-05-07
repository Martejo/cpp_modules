#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		m_ideas[i] = "Brain Idea.";
	std::cout << "Default Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	*this = copy;
	std::cout << "Copy Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Destructor Brain called" << std::endl;
}

Brain &Brain::operator=(const Brain &a)
{
	for (int i = 0; i < 100; i++)
		m_ideas[i] = a.m_ideas[i];
	return (*this);
}

void Brain::setBrainIdeas( std::string idea)
{
	for (int i = 0; i < 100; i++)
		m_ideas[i] = idea;
}

void	Brain::printBrainIdeas() const
{
	for (int i = 0; i < 3; i++)
		std::cout << this->m_ideas[i] << std::endl;
}