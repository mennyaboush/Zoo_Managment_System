

#ifndef __LION_H
#define __LION_H

#include "Animal.h"


class Lion : public Animal
{
	
public:
	enum eManeColor { WHITE, BROWN, YELLOW, RED, ORANGE };

	Lion(const string& name, float weight, int birthYear, eManeColor maneColor);
	
	Lion(const Lion& lion) = delete;
	const Lion& operator=(const Lion& lion) = delete;
	
	inline eManeColor getManeColor() const;
	
	virtual void toOs(ostream& os) const override;

private:
	eManeColor maneColor;
	
};


#endif /* __LION_H */
