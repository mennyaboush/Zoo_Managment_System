

#ifndef __WORKER_H
#define __WORKER_H

#include <iostream>

using namespace std;

class Area;

class Worker
{
	
private:
	string name;
	long idNumber;
	int salary;
	Area* area; // maximum 1 area

	void setIdNumber(long idNumber) throw (const char*);
	
public:
	Worker(const string& name, long idNumber, int salary, const Area* area = nullptr);
	//~Worker();
	Worker(const Worker& worker) = delete;
	const Worker& operator=(const Worker& worker) = delete;
	
	inline const string& getName() const;
	
	inline long getIdNumber() const;
	
	inline int getSalary() const;
	void setSalary(int salary) throw (const char*);
	
	Area& getArea() ;
	void setArea(const Area& area);
	
	virtual void toOs(ostream& os) const =0;
	friend ostream& operator<<(ostream& os, const Worker& worker);

	operator const char*() { return name.c_str(); }
};

#endif /* __WORKER_H */
