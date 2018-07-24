#include "Keeper.h"

Keeper::Keeper(const string& name, long idNumber, int salary, eAnimal keeperSpecialty)
	:Worker(name, idNumber, salary)
{
	this->keeperSpecialty = keeperSpecialty;
}

inline Keeper:: eAnimal Keeper::getKeeperSpecialty() const
{
	return keeperSpecialty;
}

void Keeper::toOs(ostream & os) const
{
	os << "keeper Specialty" << getKeeperSpecialty() << endl;
}
