#include "Worker.h"

void Worker::setIdNumber(long idNumber) throw(const char *)
{
	if (getIdNumber() != idNumber)
		this->idNumber = idNumber;
}

Worker::Worker(const string& name, long idNumber, int salary, const Area * area)
{
	this->name = name ;
	setIdNumber(idNumber);
	setSalary(salary);
	setArea(*area);
}

/*Worker::~Worker()
{
	delete area;
}*/

const string& Worker::getName() const
{
	return name;
}

long Worker::getIdNumber() const
{
	return idNumber;
}

int Worker::getSalary() const
{
	return salary;
}

void Worker::setSalary(int salary) throw(const char *)
{
	if (salary < 0)
		throw "Salary must be positive.";
	this->salary = salary;
}

Area & Worker::getArea()
{
	return *area;
}

void Worker::setArea(const Area & area)
{
	//i didnt have a way to compare between the areas//
	if (&area != nullptr)
	{
		this->area = (Area*)(&area);	
	}
}

ostream & operator<<(ostream & os, const Worker & worker)
{
	if (&worker != nullptr) {
	os << "Worker:" << worker.getName().c_str() << " ," << worker.getIdNumber() << " ," << worker.getSalary()
		<< endl; // the area name was deleted
	worker.toOs(os);
}
	return os;
}
