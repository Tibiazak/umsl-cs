#include "Horse.h"
#include <string>
#include <cstdlib>
#include <iostream>

using namespace std;

void Horse::setDistanceTraveled(int n)
{
	distanceTraveled = n;
}

void Horse::setMaxRunningDistPerSecond(int n)
{
	maxRunningDistPerSecond = n;
}

//constructor
Horse::Horse(string newName, string newRider)
{
	name = newName;
	rider = newRider;
	racesWon = 0;
	distanceTraveled = 0;
	maxRunningDistPerSecond = rand() % 100+1;
}

//gets the distance traveled using rand
void Horse::runASecond()
{
	distanceTraveled += (rand() % getMaxRunningDistPerSecond());
}

//graphically displays the position of the horse
void Horse::toString(int distance)
{
	int factor = distance / 50;
	int position = distanceTraveled/factor;
	cout << '|';
	for(int i = 0; i < 50; i++)
	{
		if(i == position)
		{
			cout << '>';
		}
		else
		{
			cout << ' ';
		}
	}
	if(position >= 50)
	{
		cout << "|> ";
	}
	else
	{	
		cout << '|';
	}
	cout << getName() << ", ridden by " << getRider() << endl;
}