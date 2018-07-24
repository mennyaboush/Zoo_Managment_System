#include "Giraffe.h"

void Giraffe::setLengthOfNeck(float lengthOfNeck) throw(const char *)
{
	if (lengthOfNeck <= 0)
		throw ("the length of the neck must be over 0");
	else
		this->lengthOfNeck = lengthOfNeck;
}

Giraffe::Giraffe(const string& name, float weight, int birthYear, float lengthOfNeck)
	:Animal(name, weight, birthYear)
{
	this->setLengthOfNeck(lengthOfNeck);
}

inline float Giraffe::getLengthOfNeck() const
{
	return lengthOfNeck;
}

void Giraffe::toOs(ostream & os) const
{
	os << "length of neck: " << getLengthOfNeck() << endl;
}
