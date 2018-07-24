#include "Lion.h"

Lion::Lion(const string& name, float weight, int birthYear, eManeColor maneColor)
	:Animal(name, weight, birthYear), maneColor(maneColor)
{
}

inline Lion::eManeColor Lion::getManeColor() const
{
	return maneColor;
}

void Lion::toOs(ostream & os) const
{
	os << "mane color: " << getManeColor() << endl;
}
