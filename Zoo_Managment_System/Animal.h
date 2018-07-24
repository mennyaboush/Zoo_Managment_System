
#ifndef __ANIMAL_H
#define __ANIMAL_H

#include <iostream>
#include "Area.h"

using namespace std;

class Animal
{

private:
	string name;
	float weight;
	int birthYear;
	Area* area;

	void setName(const string& name) throw (const char*);
	void setWeight(float weight) throw (const char*);
	void setBirthYear(int birthYear) throw (const char*);

public:
	Animal(const string& name, float weight, int birthYear, const Area* area = nullptr);
	virtual ~Animal();

	Animal(const Animal& animal) = delete;
	const Animal& operator=(const Animal& animal) = delete;

	virtual  const string& getName() const;

	virtual inline float getWeight() const;

	virtual inline int getBirthYear() const;

	friend ostream& operator<<(ostream& os, const Animal& animal);

	virtual void toOs(ostream& os) const = 0;

	operator const char*() { return name.c_str(); }

};

#endif /* __ANIMAL_H */
