
#ifndef __ZEBRA_H
#define __ZEBRA_H

#include "Animal.h"

class Zebra : virtual public Animal
{
private:
	int numOfStrips;

	void setNumOfStrips(int numOfStrips) throw (const char*);
	
public:
	Zebra(const string& name, float weight, int birthYear, int numOfStrips);
	
	Zebra(const Zebra& zebra) = delete;
	const Zebra& operator=(const Zebra& zebra) = delete;
	
	inline int getNumOfStrips() const;
	
	virtual void toOs(ostream& os) const override;
	
};


#endif /* __ZEBRA_H */
