#include "Serialization.hpp"

Serialization::Serialization(){}
Serialization::~Serialization(){}

/*
Reinterpret_cast sert a reinterpr'eter un pointeur attention ce cast ne verifie pas grand chose ce qui a pour consequence 
*/

uintptr_t Serialization::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serialization::deserialize(uintptr_t ptr)
{
	return(reinterpret_cast<Data *>(ptr));
}