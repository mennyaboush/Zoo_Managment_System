
#ifndef __ZOO_H
#define __ZOO_H

#include "Area.h"
#include "Worker.h"
#include "Animal.h"
#include"AreaManager.h"
#include<vector>


using namespace std;
class AreaManager;
class ManagerSuspended;
class Zoo
{
public:
	static Zoo* getInstence();

	const string& getName() const;
	
	const int getMaxNumOfAreas() const;

	const int getNumOfAreas() const;
	
	int Zoo::getIndexOfAreaByName(const string& name) throw(const char *);

	const Area& getQuarentineArea() const;

	template<class T, class Function>
	void add(T& object, const string& areaName, Function& addition) throw(char*);

	void addArea(Area& area)  throw (const char *);
	
	void addAnimal(Animal& animal, const string& areaName)  throw (const char*);
	
	void addWorker(Worker& worker, const string& areaName)  throw (const char*);
	
	const vector<Area*>& Zoo::getAllAreas() const;
	
	const Zoo& operator+(Area& area);
	
	const Area& operator[](int index) const;
	
	friend ostream& operator<<(ostream& os, const Zoo& zoo);

	operator const char*() { return name.c_str(); }


private:
	static Zoo zooInstance;

	string name;
	int maxNumOfAreas;
	int numOfAreas;
	vector<Area*> areas;
	Area quarentineArea;

	Zoo();
	Zoo(const Zoo& other) = delete;
	const Zoo& operator=(const Zoo& zoo) = delete;
	void setMaxNumOfAreas(int maxNumOfAreas) throw (const char*);
};


#endif /* __ZOO_H */

template<class T, class Function>
inline void Zoo::add(T & object, const string & areaName, Function & addition) throw(char *)
{
}
