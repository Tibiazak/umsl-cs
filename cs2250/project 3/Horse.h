#ifndef HORSE_H
#define HORSE_H
#include <string>

using namespace std;

class Horse
{
	private:
		std::string name;
		std::string rider;
		int maxRunningDistPerSecond;
		int distanceTraveled;
		int racesWon;

		void setDistanceTraveled(int);

		void setMaxRunningDistPerSecond(int);


	public:
		Horse(string, string);

		void incRacesWon()
			{ racesWon++; }

		void sendToGate()
			{ distanceTraveled = 0; }

		void runASecond();

		void toString(int);

		int getMaxRunningDistPerSecond() const
			{return maxRunningDistPerSecond;}

		int getDistanceTraveled() const
			{return distanceTraveled;}

		int getRacesWon() const
			{return racesWon;}

		string getName() const
			{return name; }

		string getRider() const
			{return rider; }
};

#endif