
#ifndef __PENGUIN_H
#define __PENGUIN_H

#include "Animal.h"

class Penguin : public Animal
{

public:
	enum eSeaFood { SHRIMP, CRAB, FISH, CALAMARI };
    
	Penguin(const string& name, float weight, int birthYear, eSeaFood favoriteFood);
    
    Penguin(const Penguin& penguin) = delete;
    const Penguin& operator=(const Penguin& penguin) = delete;
    
    inline eSeaFood getFavoriteFood() const;
    void setFavoriteFood(eSeaFood favoriteFood);
    
	virtual void toOs(ostream& os) const override;
  
private:
	eSeaFood favoriteFood;

};


#endif /* __PENGUIN_H */
