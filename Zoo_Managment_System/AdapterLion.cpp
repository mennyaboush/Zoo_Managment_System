#include "AdapterLion.h"

AdapterLion::AdapterLion(const string& name, float weight, int birthYear, eManeColor maneColor)
	:Lion(name,weight,birthYear,Lion::YELLOW) 
{
}

void AdapterLion::speak()
{
	cout << "whaaa!!! \n";
}
