#include "Elephant.h"

void Elephant::setSizeOfEars(float sizeOfEars) throw(const char *)
{
	if (sizeOfEars <= 0)
		throw("size must be positive ");
	else
		this->sizeOfEars = sizeOfEars;
}

void Elephant::setLengthOfTrunk(float lengthOfTrunk) throw(const char *)
{
	if (sizeOfEars <= 0)
		throw("size must be positive ");
	else
		this->lengthOfTrunk = lengthOfTrunk;
}

Elephant::Elephant(const string& name, float weight, int birthYear, float sizeOfEars, float lengthOfTrunk)
	:Animal(name, weight, birthYear)
{
	setSizeOfEars(sizeOfEars);
	setLengthOfTrunk(lengthOfTrunk);
}

inline float Elephant::getSizeOfEars() const
{
	return sizeOfEars;
}

inline float Elephant::getLengthOfTrunk() const
{
	return lengthOfTrunk;;
}

void Elephant::toOs(ostream & os) const
{
	os << "the size of the ears: " << getSizeOfEars() << "the length of the trunk: " << getLengthOfTrunk() << endl;
}
