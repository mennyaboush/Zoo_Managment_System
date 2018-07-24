#include "Area.h"

void Area::setMaxNumberOfAnimals(int maxNumberOfAnimals) throw(const char *)
{
	if (maxNumberOfAnimals < 0)
		throw ("max number of animals can'nt be negative");
	else
		this->maxNumberOfAnimals = maxNumberOfAnimals;
}

void Area::setMaxNumberOfWorkers(int maxNumberOfWorkers) throw(const char *)
{
	if (maxNumberOfWorkers < 0)
		throw ("max number of workers can'nt be negative");
	else
		this->maxNumberOfWorkers = maxNumberOfWorkers;
}

Area::Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, const AreaManager * areaManager)
{
	this->name = name;
	this->setMaxNumberOfAnimals(maxNumberOfAnimals);
	this->setMaxNumberOfWorkers(maxNumberOfWorkers);
	this->setAreaManager(*areaManager);
}

/*Area::~Area()
{
	delete areaManager;
}*/

 const string& Area::getName() const
{
	return name;
}

int Area::getNumOfAnimals() const
{
	return numOfAnimals;
}

int Area::getMaxNumberOfAnimals() const
{
	return maxNumberOfAnimals;
}

int Area::getNumOfWorkers() const
{
	return numOfWorkers;
}

int Area::getMaxNumberOfWorkers() const
{
	return maxNumberOfWorkers;
}

const AreaManager & Area::getAreaManager() const
{
	return *(areaManager);
}

void Area::setAreaManager(const AreaManager&  areaManager)
{
	if (&(this->getAreaManager()) != &areaManager)
		this->areaManager = (AreaManager*)(&areaManager);
}

void Area::addAnimal(const Animal & animal) throw(const char *)
{
	if (numOfAnimals < maxNumberOfAnimals) {
		animals.push_back(&animal);
		numOfAnimals++;
	}
	else
		throw("no place for new animals");
}

void Area::addWorker(const Worker & worker) throw(const char *)
{
	if (numOfWorkers < maxNumberOfWorkers) {
		workers.addToTail((Worker*)&worker);
		numOfWorkers++;
	}
	else
		throw("no place for new workers");
}

const vector<const Animal*> Area::getAllAnimals() const
{
	return  animals;
}


const MyLinkedList<Worker*>& Area::getAllworkers() const
{
	return workers;
}

const Area & Area::operator+=(const Animal & animal)
{
	addAnimal(animal);
	return *this;
}

bool Area::operator<(const Area & area) const
{
	if (this->getNumOfAnimals() < area.getNumOfAnimals())
		return true;
	else
		if (this->getNumOfWorkers() < area.getNumOfWorkers())
			return true;
		else
			return false;
}

bool Area::operator>(const Area & area) const
{
	if (this->getNumOfAnimals() > area.getNumOfAnimals())
		return true;
	else
		if (this->getNumOfWorkers() > area.getNumOfWorkers())
			return true;
		else
			return false;
}

bool Area::operator==(const Area & area) const
{
	return (strcmp(this->getName().c_str(),area.getName().c_str())==0);
}

ostream & operator<<(ostream & os, const Area & area)
{
	
	os << "the area name: " << area.getName().c_str() 
		<< "\nThe number of animals in the area: " << area.getNumOfAnimals()
		<< "\nThe number of workers int the area: " << area.getNumOfWorkers() << endl
		<< "Area manager:" << area.getAreaManager() << endl
		<< "Workers:" << endl
		<< area.getAllworkers() << endl
		<< "Animals:" << endl;
	vector<const Animal*>::const_iterator animalsItr = area.getAllAnimals().begin();
	const vector<const Animal*>::const_iterator animalsItrEnd = area.getAllAnimals().end();
	
	for (; animalsItr != animalsItrEnd; ++animalsItr)
		os << (*(*animalsItr)) << endl  ;
	return os;
}
