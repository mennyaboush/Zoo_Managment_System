#include "AreaManager.h"

void AreaManager::setYearsOfExperience(int yearsOfExperience) throw(const char *)
{
	if (yearsOfExperience < 0)
		throw "Yaers of experience must be positive.";
	this->yearsOfExperience = yearsOfExperience;
}

AreaManager::AreaManager(const string name, long idNumber, int salary, int yearsOfExperience)
	:Worker(name, idNumber, salary)
{
	setYearsOfExperience(yearsOfExperience);
}

AreaManager::AreaManager(const string name, long idNumber, int salary, int yearsOfExperience,Area*  area):AreaManager(name,idNumber,salary,yearsOfExperience)
{
	setArea(*area);
}

inline int AreaManager::getYearsOfExperience() const
{
	return yearsOfExperience;
}

void AreaManager::toOs(ostream & os) const
{
	os << "year of experience:" << getYearsOfExperience() << endl;
	
}
