#include "MaintenanceWorker.h"

MaintenanceWorker::MaintenanceWorker(const string& name, long idNumber, int salary, float shoeSize)
	:Worker(name, idNumber, salary)
{
	setShoeSize(shoeSize);
}

void MaintenanceWorker::setShoeSize(float shoeSize) throw(const char *)
{
	if (shoeSize <= 0)
		throw "Eror.shoe size most be positive.";
	if (shoeSize < 26 || shoeSize > 52)
		throw "Sorry we didn't have shoes for you.";
	this->shoeSize = shoeSize;
}

void MaintenanceWorker::toOs(ostream & os) const
{
	os << "Shoe size:" << getShoeSize() << endl;
}
