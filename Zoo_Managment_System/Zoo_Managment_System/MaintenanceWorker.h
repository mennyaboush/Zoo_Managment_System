
#ifndef __MAINTENANCE_WORKER_H
#define __MAINTENANCE_WORKER_H

#include "Worker.h"

class MaintenanceWorker : public Worker
{
private:
	float shoeSize;

public:
	MaintenanceWorker(const string& name, long idNumber, int salary, float shoeSize);
	
	MaintenanceWorker(const MaintenanceWorker& maintenanceWorker) = delete;
	const MaintenanceWorker& operator=(const MaintenanceWorker& maintenanceWorker) = delete;

	float getShoeSize() const { return shoeSize; }
	void setShoeSize(float shoeSize) throw (const char*);

	virtual void toOs(ostream& os) const override;
	
};


#endif /* __MAINTENANCE_WORKER_H */
