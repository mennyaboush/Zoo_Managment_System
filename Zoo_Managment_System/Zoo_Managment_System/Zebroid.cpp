#include "Zebroid.h"

Zebroid::Zebroid(const string& name, float weight, int birthYear, int numOfStrips, float sizeOfHorseShoe)
	:Animal(name, weight, birthYear), Horse(name, weight, birthYear, sizeOfHorseShoe), Zebra(name, weight, birthYear, numOfStrips)
{
}

inline const string& Zebroid::getName() const
{
	return Animal::getName();
}

inline float Zebroid::getWeight() const
{
	return Animal::getWeight();
}

inline int Zebroid::getBirthYear() const
{
	return Animal::getBirthYear();
}

void Zebroid::toOs(ostream & os) const
{
	os << "zebroid, number of stripes: " << getNumOfStrips() << "size of shoe: " << getSizeOfHorseShoe() << endl;
}
