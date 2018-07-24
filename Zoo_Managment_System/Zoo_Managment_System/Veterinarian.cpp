#include "Veterinarian.h"

void Veterinarian::setLicenseNumber(int licenseNumber) throw(const char *)
{
	if (licenseNumber <= 0)
		throw "the license number nust be positive";
	this->licenseNumber = licenseNumber;
}

Veterinarian::Veterinarian(const string& name, long idNumber, int salary, int licenseNumber)
	:Worker(name, idNumber, salary)

{
	setLicenseNumber(licenseNumber);
}

inline int Veterinarian::getLicenseNumber() const
{
	return licenseNumber;
}

void Veterinarian::toOs(ostream & os) const
{
	os << "License number:" << getLicenseNumber() << endl;
}
