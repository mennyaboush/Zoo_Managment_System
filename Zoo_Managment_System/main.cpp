#pragma warning( disable : 4290 )

#include <iostream>
using namespace std;
#include "Zoo.h"
#include "Area.h"
#include "Animal.h"
#include "Worker.h"
#include "AreaManager.h"
#include "Veterinarian.h"
#include "Keeper.h"
#include "MaintenanceWorker.h"
#include "Elephant.h"
#include "Giraffe.h"
#include "Horse.h"
#include "Lion.h"
#include "AdapterLion.h"
#include "Penguin.h"
#include "Zebra.h"
#include "Zebroid.h"


void createAreaManagers(vector<AreaManager*>& managers, int& numOfManagers, int& numOfAreas);

void createAllAreas(int& numOfAreas, vector<AreaManager*>& managers, vector<Area*> &areas);
void addAreasToZoo(Zoo& zoo, vector<Area*>& areas, int& numOfAreas);
void createAnimals(int& numOfAnimals, vector<Animal*>& animals);
void addAllAnimalsToZoo(Zoo& myZoo, vector<Animal*>& animals, int& numOfAnimals);
void createAllKeepers(int& numOfKeepers, vector<Keeper*>& keepers);
void addKeepersToZoo(Zoo& myZoo, vector<Keeper*>& keepers, int& numOfKeepers);
void  createAllVeterinarian(int& numOfVeterinarian, vector<Veterinarian*>& vets);
void addAllVeterinarianToZoo(Zoo& myZoo, vector<Veterinarian*>& vets, int& numOfVeterinarian);
void freeAllAreaManagers(vector<AreaManager*>& areaManagers);
void freeAllAreas(vector<Area*>& areas );
void freeAllAnimals(vector<Animal*>& animals );
void freeAllVeterinarian(vector<Veterinarian*>& vets );
void freeAllKeepers(vector<Keeper*>& keepers);

int main()
{
	try
	{
		AreaManager quarantineManager("Menny", 5468, 50000, 20);
		Area quarentineArea("quarentineArea", 4, 4, &quarantineManager);

		Zoo* myZoo = Zoo::getInstence();

		int numOfManagers = 3;
		int numOfAreas = 3;

		vector<AreaManager*> managers;
		createAreaManagers(managers, numOfManagers, numOfAreas);
		vector<Area*> areas;
		createAllAreas(numOfAreas, managers, areas);
		// add all areas
		addAreasToZoo(*myZoo, areas, numOfAreas);

		int numOfAnimals;
		vector<Animal*> animals;
		createAnimals(numOfAnimals, animals);

		// add animals
		addAllAnimalsToZoo(*myZoo, animals, numOfAnimals);

		int numOfKeepers;
		vector<Keeper*> keepers;
		createAllKeepers(numOfKeepers,keepers);

		// add all the keepers
		addKeepersToZoo(*myZoo, keepers, numOfKeepers);

		int numOfVeterinarian;
		vector<Veterinarian*> vets;
		createAllVeterinarian(numOfVeterinarian, vets);

		// add all vets
		addAllVeterinarianToZoo(*myZoo, vets, numOfVeterinarian);

		// print the whole zoo
		cout << "My Zoo: \n" << *myZoo << endl << endl;

		// free all memory 
		freeAllAreaManagers(managers);
		freeAllAreas(areas);
		freeAllKeepers(keepers );
		freeAllVeterinarian(vets );
		freeAllAnimals(animals );
		
	}
	catch (const char* message)
	{
		cout << message;
	}
	catch (...)
	{
		cout << "Something went wrong" << endl;
	}

	system("pause");
	return 0;
}

void createAreaManagers(vector<AreaManager*> &managers, int& numOfManagers, int& numOfAreas)
{
	numOfAreas = 3;
	numOfManagers = 3;
	const vector<string> managersNames = { "Yogev", "Moshe", "Roie" };
	vector<int> managersId = { 31235, 51455, 84578 };
	vector<int> managersSalary = { 5000, 4500, 4800 };
	vector<int> managersYearsOfExperience = { 2, /*-*/3, 4 };


	vector<string>::const_iterator nameItr = managersNames.begin();
	vector<int>::iterator idItr = managersId.begin();
	vector<int>::iterator salaryItr = managersSalary.begin();
	vector<int>::iterator yearsItr = managersYearsOfExperience.begin();
	for (int i = 0; i < numOfManagers && i < numOfAreas; i++)
	{
		try
		{
			managers.push_back(new AreaManager(*nameItr, *idItr, *salaryItr, *yearsItr));
			++nameItr; ++idItr; ++salaryItr; ++yearsItr;
		}
		catch (const char* errMessage)
		{
			cout << "Could not create manager " << (*nameItr).c_str() << ":" << endl << errMessage << endl << endl;
			//managers.insert(managerItr , nullptr );
			numOfManagers = managers.size();
			break;
		}
	}
}

void createAllAreas(int& numOfAreas, vector<AreaManager*>& managers, vector<Area*> &areas)
{

	int maxNumberOfAnimals = 4, maxNumberOfWorkers = 4, wrongMaxNumberOfAnimals = -5;
	const vector<string> areasNames = { "A1", "A2", "A3" };
	vector<string>::const_iterator itrBegin = areasNames.begin();
	vector<string>::const_iterator itrEnd = areasNames.end();
	vector<Area*>::iterator areaItr = areas.begin();
	vector<AreaManager*>::iterator manegerItr = managers.begin();

	for (; itrBegin < itrEnd; ++itrBegin)
	{
		try
		{
			areas.push_back(new Area(*itrBegin, maxNumberOfAnimals, maxNumberOfWorkers, *manegerItr));
			++manegerItr;
		}
		catch (const char* errMessage)
		{
			cout << "Could not create area " << (*itrBegin).c_str() << ":" << endl << errMessage << endl << endl;
			areas.insert(areaItr, nullptr);
			numOfAreas = areas.size();
			break;
		}
	}
}

void addAreasToZoo(Zoo& zoo, vector<Area*>& areas, int& numOfAreas)
{
	vector<Area*>::iterator itr = areas.begin();
	for (int i = 0; i < numOfAreas; i++)
	{
		try
		{
			zoo.addArea(**itr);
			++itr;
		}
		catch (const char* errMessage)
		{
			cout << "Area " << (*itr)->getName().c_str() << " was not added to the zoo:" << endl << errMessage << endl << endl;
		}
	}
}

void createAnimals(int& numOfAnimals, vector<Animal*>& animals)
{
	numOfAnimals = 4;
	const vector<string> names = { "Horsy", "Pini", "Eli", "Zeze" };

	vector<string>::const_iterator nameItr = names.begin();
	vector <Animal*>::iterator animelsItr = animals.begin();

	for (int i = 0; i < numOfAnimals; i++)
	{
		try
		{
			switch (i%numOfAnimals)
			{
			case 0:
			{
				animals.push_back(new Horse(*nameItr, 208.5f, 1998, 40.2f));
				++nameItr;
				break;
			}
			case 1:
			{
				animals.push_back(new Penguin(*nameItr, 1.2f, 2005, Penguin::CRAB));
				++nameItr;
				break;
			}
			case 2:
			{
				animals.push_back(new Elephant(*nameItr, 2.5f, 1752, 1.35f, 2.75f));
				++nameItr;
				break;
			}
			case 3:
			{
				animals.push_back(new Zebroid(*nameItr, 1.45f, 2010, 128, 38.6f));
				++nameItr;
				break;
			}
			}
		}
		catch (const char *errMessage)
		{
			cout << "Could not create animal " << (*nameItr).c_str() << ":" << endl << errMessage << endl << endl;
			animals.insert(animelsItr, nullptr);
			numOfAnimals = animals.size();
			break;
		}
	}
}

void addAllAnimalsToZoo(Zoo& myZoo, vector<Animal*>& animals, int& numOfAnimals)
{
	int numOfAreas = myZoo.getNumOfAreas();

	vector<Area*>::const_iterator areasItr = myZoo.getAllAreas().begin();
	vector<Area*>::const_iterator endItr = myZoo.getAllAreas().end();

	vector<Animal*>::iterator animelsItr = animals.begin();

	for (int i = 0; i < numOfAnimals, areasItr<endItr; i++, ++areasItr, ++animelsItr)
	{
		try
		{
			myZoo.addAnimal(**animelsItr, (*areasItr)->getName());
		}
		catch (const char* errMessage)
		{
			cout << "Could not add " << (*areasItr)->getName().c_str() << ":" << endl << errMessage << endl << endl;
		}
	}

	// another animal to the last area
	myZoo.addAnimal(*new AdapterLion("lio",250,2004,Lion::BROWN), (*--areasItr)->getName());
}

void createAllKeepers(int& numOfKeepers, vector<Keeper*>& keepers)
{
	numOfKeepers = 3;
	int keeperSalary = 7500;

	const vector<string> keepersNames = { "Kipi", "Keepi", "Keepee" };
	vector<int> keepersId = { 312542, 387542, 955642 };
	Keeper::eAnimal animals[] = { Keeper::PENGUIN, Keeper::ELEPHANT, Keeper::HORSE };

	vector<string>::const_iterator nameItr = keepersNames.begin();
	vector<int>::iterator idItr = keepersId.begin();
	vector<Keeper*>::iterator keeperItr = keepers.begin();

	for (int i = 0; i < numOfKeepers; i++)
	{
		try
		{
			keepers.push_back(new Keeper(*nameItr, *idItr, keeperSalary, animals[i]));
		}
		catch (const char* errMessage)
		{
			cout << "Could not create keeper " << (*keeperItr)->getName().c_str() << endl << ":" << errMessage << endl << endl;
			keepers.insert(keeperItr, nullptr);
			numOfKeepers = i;
			break;
		}
	}


}

void addKeepersToZoo(Zoo& myZoo, vector<Keeper*>& keepers, int& numOfKeepers)
{
	int numOfAreas = myZoo.getNumOfAreas();

	vector<Area*>::const_iterator areasItr = myZoo.getAllAreas().begin();
	vector<Keeper*>::iterator keeperItr = keepers.begin();

	for (int i = 0; i < numOfKeepers && i < numOfAreas; i++, ++keeperItr, ++areasItr)
	{
		try
		{
			myZoo.addWorker(**keeperItr, (*areasItr)->getName().c_str());
		}
		catch (const char* errMessage)
		{
			cout << "Could not add keeper " << (*keeperItr)->getName().c_str() << " to the zoo:" << endl << errMessage << endl << endl;
		}
	}
}

void  createAllVeterinarian(int& numOfVeterinarian, vector<Veterinarian*>& vets)
{
	numOfVeterinarian = 3;
	int vetsSalary = 10000;

	const vector<string> vetsNames = { "Dr. Vivi", "Dr. Vuvu", "Dr. Kobi" };
	vector<int> vetsId = { 45875, 87457, 26584 };
	vector<int> vetsLicenseNumbers = { 5, 8, 10 };

	vector<string>::const_iterator namesItr = vetsNames.begin();
	vector<int>::iterator idItr = vetsId.begin();
	vector<int>::iterator licenseItr = vetsLicenseNumbers.begin();
	vector<Veterinarian*>::iterator vetItr = vets.begin();

	for (int i = 0; i < numOfVeterinarian; i++)
	{
		try
		{
			vets.push_back(new  Veterinarian(vetsNames[i], vetsId[i], vetsSalary, vetsLicenseNumbers[i]));
		}
		catch (const char* errMessage)
		{
			cout << "Could not create Veterinarian " << (*vetItr)->getName().c_str() << ":" << endl << errMessage << endl << endl;
			*vetItr = nullptr;
			numOfVeterinarian = vets.size();
			break;
		}
	}
}

void addAllVeterinarianToZoo(Zoo& myZoo, vector<Veterinarian*>&vets, int& numOfVeterinarian)
{
	int numOfAreas = myZoo.getNumOfAreas();

	vector<Area*>::const_iterator areasItr = myZoo.getAllAreas().begin();
	vector<Veterinarian*>::iterator vetsItr = vets.begin();

	for (int i = 0; i < numOfVeterinarian && i < numOfAreas; i++, ++vetsItr, ++areasItr)
	{
		try
		{
			myZoo.addWorker(**vetsItr, (*areasItr)->getName().c_str());
		}
		catch (const char* errMessage)
		{
			cout << "Could not add Veterinarian " << (*vetsItr)->getName().c_str() << " to the zoo:" << endl << errMessage << endl << endl;
		}
	}
}


void freeAllAreaManagers(vector<AreaManager*>& areaManagers)
{
	vector<AreaManager*>::iterator itBegin = areaManagers.begin();
	vector<AreaManager*>::iterator itEnd = areaManagers.end();

	for (; itBegin != itEnd; ++itBegin)
		delete *itBegin;


}

void freeAllAreas(vector<Area*>& areas)
{
	vector<Area*>::iterator itrBegin = areas.begin();
	vector<Area*>::iterator itrEnd = areas.end();

	for (; itrBegin != itrEnd; ++itrBegin)
		//delete *itrBegin;
		;
}


void freeAllAnimals(vector<Animal*>& animals)
{
	vector<Animal*>::iterator itBegin = animals.begin();
	vector<Animal*>::iterator itEnd = animals.end();

	for (; itBegin != itEnd; ++itBegin)
		delete *itBegin;

}

void freeAllVeterinarian(vector<Veterinarian*>& vets)
{
	vector<Veterinarian*>::iterator itBegin = vets.begin();
	vector<Veterinarian*>::iterator itEnd = vets.end();

	for (; itBegin != itEnd; ++itBegin)
		delete *itBegin;

}

void freeAllKeepers(vector<Keeper*>& keepers)
{
	vector<Keeper*>::iterator itBegin = keepers.begin();
	vector<Keeper*>::iterator itEnd = keepers.end();

	for (; itBegin != itEnd; ++itBegin)
		delete *itBegin;
}
