#pragma once
#include <stdint.h>
#include "Data.hpp" 


class Serialization
{
	public : 
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t ptr);
	
	private :
	Serialization();
	~Serialization();
};