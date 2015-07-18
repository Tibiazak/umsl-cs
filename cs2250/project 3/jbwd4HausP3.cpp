/*
Josh Bearden
7/15/15
A program designed to simulate horse racing
*/

#include "Horse.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int numHorses;
	cout << "How many horses are in the race? ";
	cin >> numHorses;

	Horse *hArr[numHorses];

	for(int i = 0; i < numHorses; i++)
	{
		cout << "Please enter the name of horse " << i <<": ";
		string name;
		cin >> name;

		cout << "Please enter the name of rider " << i <<": ";
		string rider;
		cin >> rider;


		hArr[0] = new Horse(name, rider);
	}
	
	int distance;
	cout << "Please enter the distance of the race: ";
	cin >> distance;

	cout << "The Start!" << endl;
	bool finished = false;
	int totalRaces = 1;
	char flag;
	while(!finished)
	{
		for(int i = 0; i < numHorses; i++)
		{
			hArr[i]->runASecond();
			hArr[i]->toString(distance);
			if(hArr[i]->getDistanceTraveled() >= distance)
			{
				finished = true;
				hArr[i]->incRacesWon();
			}
		}
		if(finished)
		{
			for(int i = 0; i < numHorses; i++)
			{
				cout << hArr[i]->getRider() << " has won " << hArr[i]->getRacesWon() << "/" << totalRaces << " races." << endl;
			}
		
			cout << "Do you wish to continue? (y/n)";
			cin >> flag;
			cout << endl;
			if(flag == 'y')
			{
				totalRaces++;
				for(int i = 0; i < numHorses; i++)
				{
					hArr[i]->sendToGate();
				}
				finished = false;
				cout << "The Start!" << endl;
			}
		}
		else
		{
			cout << "Are you ready for the next second? (y/n)";
			cin >> flag;
			if (flag == 'n')
			{
				finished = true;
			}
			cout << endl;
		}
	}
	for(int i = 0; i < numHorses; i++)
	{
		delete(hArr[i]);
	}
}