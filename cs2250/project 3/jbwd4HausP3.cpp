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
	srand(time(NULL)); //initialize rand
	int numHorses;
	cout << "How many horses are in the race? ";
	cin >> numHorses;
	cin.ignore();

	//make a horse array
	Horse *hArr[numHorses];

	//get the names of the horses and riders
	//and initialize the array elements
	for(int i = 0; i < numHorses; i++)
	{
		cout << "Please enter the name of horse " << i <<": ";
		string name;
		getline(cin, name);
		

		cout << "Please enter the name of rider " << i <<": ";
		string rider;
		getline(cin, rider);


		hArr[i] = new Horse(name, rider);
	}
	
	//get the distance of the race
	int distance;
	cout << "Please enter the distance of the race: ";
	cin >> distance;

	//starts the race
	cout << "The Start!" << endl;
	bool finished = false;
	int totalRaces = 1;
	char flag;
	//the race loop
	while(!finished)
	{
		for(int i = 0; i < numHorses; i++)
		{
			hArr[i]->runASecond(); //has the horse run
			hArr[i]->toString(distance); //outputs the distance it ran
			if(hArr[i]->getDistanceTraveled() >= distance) //check if it finished
			{
				finished = true;
				hArr[i]->incRacesWon();
			}
		}
		if(finished) //if a horse finished, display the winner and stats
		{
			for(int i = 0; i < numHorses; i++)
			{
				cout << hArr[i]->getRider() << " has won " << hArr[i]->getRacesWon() << "/" << totalRaces << " races." << endl;
			}
		
			cout << "Do you wish to continue? (y/n)"; //check if user wants to continue
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
			cout << "Are you ready for the next second? (y/n)"; //if the race isn't over, prompt to continue
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
		delete(hArr[i]); //free the memory
	}
}