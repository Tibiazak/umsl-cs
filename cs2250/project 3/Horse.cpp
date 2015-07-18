#include "Horse.h"
#include <string>
#include <cstdlib>

using namespace std;

void Horse::setDistanceTraveled(int n)
{
	distanceTraveled = n;
}

void Horse::setMaxRunningDistPerSecond(int n)
{
	maxRunningDistPerSecond = n;
}

Horse::Horse(string newName, string newRider)
{
	name = newName;
	rider = newRider;
	racesWon = 0;
	distanceTraveled = 0;
	maxRunningDistPerSecond = rand() % 100+1;
}

void Horse::runASecond()
{
	distanceTraveled += (rand() % maxRunningDistPerSecond);
}

void toString(int distance)
{
	int factor = distance / 50;
	int position = factor / this.distanceTraveled;
	cout << '|';
	for(int i = 0; i < 50; i++)
	{
		if(i = position)
		{
			cout << '>';
		}
		else
		{
			cout << ' ';
		}
	}
	cout << '|';
	cout << this.name << ", ridden by " << this.rider << endl;
}