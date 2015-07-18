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
	setMaxRunningDistPerSecond(rand() % 100+1);
}

void Horse::runASecond()
{
	distanceTraveled += (rand() % getMaxRunningDistPerSecond());
}

void toString(int distance)
{
	factor = distance / 50;
	position = factor / getDistanceTraveled();
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
	cout << getName() << ", ridden by " << getRider() << endl;
}