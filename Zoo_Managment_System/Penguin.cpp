#include "Penguin.h"

Penguin::Penguin(const string& name, float weight, int birthYear, eSeaFood favoriteFood)
	:Animal(name, weight, birthYear), favoriteFood(favoriteFood)
{
}

inline Penguin::eSeaFood Penguin::getFavoriteFood() const
{
	return this->favoriteFood;
}

void Penguin::setFavoriteFood(eSeaFood favoriteFood)
{
	this->favoriteFood = favoriteFood;
}

void Penguin::toOs(ostream & os) const
{
	os << "favorite food: " << getFavoriteFood() << endl;
}
