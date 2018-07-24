#include "Animal.h"

bool goodName(const string& name) {
	int i = 0;
	while (name[i] != '\0') {
		if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z')))
			return false;
		i++;
	}
	return true;
}

void Animal::setName(const string& name) throw(const char *)
{
	if (goodName(name))
		this->name = name;
	else
		throw ("name must be letters only");
}

void Animal::setWeight(float weight) throw(const char *)
{
	if (weight <= 0) {
		throw("weight must be positive");
	}
	this->weight = weight;
}

void Animal::setBirthYear(int birthYear) throw(const char *)
{
	this->birthYear = birthYear;
}

Animal::Animal(const string& name, float weight, int birthYear, const Area * area)
{
	this->setName(name);
	this->setWeight(weight);
	this->setBirthYear(birthYear);
	this->area = (Area*)area;
}

Animal::~Animal()
{
	delete[]area;
}

 const  string& Animal::getName() const
{
	return name;
}

inline float Animal::getWeight() const
{
	return this->weight;
}

inline int Animal::getBirthYear() const
{
	return this->birthYear;
}

ostream& operator<<(ostream os, const Animal& animal)
{
	os << "Name: " << animal.getName().c_str() << "weight: " << animal.getWeight()
		<< "birth year" << animal.getBirthYear() << endl;
	animal.toOs(os);
	return os;
}
