#include "Zebra.h"

void Zebra::setNumOfStrips(int numOfStrips) throw(const char *)
{
	if (numOfStrips <= 0)
		throw("num of strips must be positive");
	else
		this->numOfStrips = numOfStrips;
}

Zebra::Zebra(const string& name, float weight, int birthYear, int numOfStrips)
	: Animal(name, weight, birthYear)
{
	setNumOfStrips(numOfStrips);
}

inline int Zebra::getNumOfStrips() const
{
	return numOfStrips;
}

void Zebra::toOs(ostream & os) const
{
	os << "num of strips:" << getNumOfStrips() << endl;
}
