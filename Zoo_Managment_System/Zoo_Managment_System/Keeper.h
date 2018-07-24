
#ifndef __KEEPER_H
#define __KEEPER_H

#include "Worker.h"



class Keeper : public Worker
{
    
public:
	enum eAnimal { LION, PENGUIN, ELEPHANT, GIRAFFE, ZEBRA, HORSE, ZEBROID };

	Keeper(const string& name, long idNumber, int salary, eAnimal keeperSpecialty);

    Keeper(const Keeper& keeper) = delete;
    const Keeper& operator=(const Keeper& keeper) = delete;
    
    inline eAnimal getKeeperSpecialty() const;
    
	virtual void toOs(ostream& os) const override;

private:
	eAnimal keeperSpecialty;

};


#endif /* __KEEPER_H */
