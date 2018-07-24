#pragma once
#ifndef __ADAPTERLION_H
#define __ADAPTERLION_H
#include"Lion.h"
#include"adapterAnimal.h"
class AdapterLion :public Lion, public AdapterAnimal
{
public:
	AdapterLion(const string& name, float weight, int birthYear, eManeColor maneColor);
	void speak();

};
#endif // !__ADAPTERLION_H
