
#ifndef __AREA_MANAGER_H
#define __AREA_MANAGER_H

#include "Worker.h"
class ManagerSuspended;

class AreaManager : public Worker
{
private:
	int yearsOfExperience;

	void setYearsOfExperience(int yearsOfExperience) throw (const char*);

public:
	AreaManager(const string name, long idNumber, int salary, int yearsOfExperience);
	AreaManager(const string name, long idNumber, int salary, int yearsOfExperience,Area* area);

	AreaManager(const AreaManager& areaManager) = delete;
	const AreaManager& operator=(const AreaManager& areaManager) = delete;

	int getYearsOfExperience() const;

	virtual void toOs(ostream& os) const override;
	
};


#endif /* __AREA_MANAGER_H */
