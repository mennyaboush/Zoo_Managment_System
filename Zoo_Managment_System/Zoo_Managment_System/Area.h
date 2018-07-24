

#ifndef __AREA_H
#define __AREA_H

#include <iostream>
#include "AreaManager.h"
#include "Worker.h"
#include "Animal.h"
#include"MyLinkedList.h"
#include<list>
#include<vector>
class Animal; 
using namespace std;

class Area
{

private:
	string name;
	int numOfAnimals;
	int maxNumberOfAnimals;
	int numOfWorkers;
	int maxNumberOfWorkers;
	AreaManager* areaManager;
	vector<const Animal*> animals;
	MyLinkedList<Worker*> workers;

	void setMaxNumberOfAnimals(int maxNumberOfAnimals ) throw (const char*);
	void setMaxNumberOfWorkers(int maxNumberOfWorkers ) throw (const char*);
	
public:
	Area(const string& name, int maxNumberOfAnimals, int maxNumberOfWorkers, const AreaManager* areaManager = nullptr);
	//~Area();
	
	Area(const Area& area) = delete;
	const Area& operator=(const Area& area) = delete;
	
	const string& getName() const;

	int getNumOfAnimals() const;
	int getMaxNumberOfAnimals() const;
 
	int getNumOfWorkers() const;
	int getMaxNumberOfWorkers() const;
	
	const AreaManager& getAreaManager() const;
	void setAreaManager(const AreaManager& areaManager);
	
	void addAnimal(const Animal& animal) throw (const char*);
	
	void addWorker(const Worker& worker) throw (const char*);

	const vector<const Animal*> Area::getAllAnimals() const;

	const MyLinkedList<Worker*>& Area::getAllworkers() const;
	
	const Area& operator+=(const Animal& animal);

	bool operator<(const Area& area) const;
	
	bool operator>(const Area& area) const;
	
	bool operator==(const Area& area) const;
	
	friend ostream& operator<<(ostream& os, const Area& area);
	
	operator const char*() { return name.c_str(); }
};


#endif /* __AREA_H */
