#include "Zoo.h"

void Zoo::setMaxNumOfAreas(int maxNumOfAreas) throw(const char *)
{

	if (maxNumOfAreas < 0)
		throw "num of areas must be positive.";
	this->maxNumOfAreas = maxNumOfAreas;
}
Zoo Zoo::zooInstance;
Zoo::Zoo():quarentineArea("quarentineArea",4,4,nullptr)
{
	name = "Ran&Menny";
	maxNumOfAreas = 10;
	numOfAreas = 0;
}



Zoo * Zoo::getInstence()
{
	return &zooInstance;
}


const string& Zoo::getName() const
{
	return name;
}

const int Zoo::getMaxNumOfAreas() const
{
	return maxNumOfAreas;
}

const int Zoo::getNumOfAreas() const
{
	return numOfAreas;
}

const Area & Zoo::getQuarentineArea() const
{
	return quarentineArea;
}

void Zoo::addArea(Area & area) throw(const char *)
{
	vector<Area*>::iterator areasItr = areas.begin();
	vector<Area*>::iterator endItr = areas.end();

	if (numOfAreas == maxNumOfAreas)
		throw "Error. the zoo have too much areas.";
	for (; areasItr<endItr; ++areasItr)
		if (area == *(*areasItr))
			throw "this area already exists.";
	areas.push_back(&area);
	numOfAreas++;

}

int Zoo::getIndexOfAreaByName(const string& name) throw(const char *)
{
	for (int i = 0; i < numOfAreas; i++)
	{
		if (strcmp(areas[i]->getName().c_str(), name.c_str()) == 0)
			return i;
	}
	throw "Area didn't exists.";
}

void Zoo::addAnimal(Animal & animal, const string& areaName) throw(const char *)
{
	int index = getIndexOfAreaByName(areaName);
	if (areas[index]->getNumOfAnimals() > areas[index]->getMaxNumberOfAnimals())
		throw "The area is full";
	areas[index]->addAnimal(animal);

}

void Zoo::addWorker(Worker & worker, const string& areaName) throw(const char *)
{
	int index = getIndexOfAreaByName(areaName);
	if (areas[index]->getNumOfWorkers() > areas[index]->getMaxNumberOfWorkers())
		throw "The area is full";
	areas[index]->addWorker(worker);
}

template<class T, class Function>
void add(T& object, const string& areaName, Function& addition)
{
	vector<Area*>::iterator itrBegin = areas.begin();
	vector<Area*>::iterator itrEnd = areas.end();

	for (; itr != itrEnd; ++itr)
	{
		if (areaName == (*itr)->getName())
		{
			addition(*itrBegin, object);
			return;
		}
	}
	throw  "Area does not exist.";
}

const vector<Area*>& Zoo::getAllAreas() const
{
	 return areas;
}

const Zoo & Zoo::operator+(Area & area)
{
	addArea(area);
	return *this;
}

const Area & Zoo::operator[](int index) const
{
	if (index < 0)
		throw "Error. negetive index.";
	if (index > numOfAreas)
		throw "nullPointerExeption. the index too large.";
	return *(areas[index]);
}

ostream & operator<<(ostream & os, const Zoo & zoo)
{
	os << "Name:" << zoo.getName().c_str() << " ,areas:"
		<< zoo.getNumOfAreas() << "/" << zoo.getMaxNumOfAreas() << endl;
	os << "Quarentine area:" << zoo.getQuarentineArea() << endl;
	vector<Area*>::const_iterator areasItr = zoo.getAllAreas().begin();
	vector<Area*>::const_iterator areasItrEnd = zoo.getAllAreas().end();
	
	for (; areasItr < areasItrEnd; ++areasItr)
	{
		os << **areasItr <<endl;
	}

	return os;
}
