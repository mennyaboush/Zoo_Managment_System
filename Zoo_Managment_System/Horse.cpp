#include "Horse.h"

void Horse::setSizeOfHorseShoe(float sizeOfHorseShoe) throw(const char *)
{
	if (sizeOfHorseShoe <= 0)
		throw("shoe must be over 0");
	else
		this->sizeOfHorseShoe = sizeOfHorseShoe;

}

Horse::Horse(const string& name, float weight, int birthYear, float sizeOfHorseShoe)
	:Animal(name, weight, birthYear)
{
	this->setSizeOfHorseShoe(sizeOfHorseShoe);
}

inline float Horse::getSizeOfHorseShoe() const
{
	return sizeOfHorseShoe;
}

void Horse::toOs(ostream & os) const
{
	os << "size of horse shoe: " << getSizeOfHorseShoe() << endl;
}
