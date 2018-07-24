
#ifndef __VETERINARIAN_H
#define __VETERINARIAN_H

#include "Worker.h"

class Veterinarian : public Worker
{
private:
	int licenseNumber;

	void setLicenseNumber(int licenseNumber) throw (const char*);

public:
	Veterinarian(const string& name, long idNumber, int salary, int licenseNumber);
	
	Veterinarian(const Veterinarian& veterinarian) = delete;
	const Veterinarian& operator=(const Veterinarian& veterinarian) = delete;
	
	inline int getLicenseNumber() const;
	
	virtual void toOs(ostream& os) const override;
	
};

#endif /* __VETERINARIAN_H */
