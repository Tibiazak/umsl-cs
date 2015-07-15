#ifndef HORSE_H
#define HORSE_H

class Horse
{
	private:
		string name;
		string rider;
		int maxRunningDistPerSecond;
		int distanceTraveled;
		int racesWon;

		void setDistanceTraveled(int);

		void setMaxRunningDistPerSecond(int);


	public:
		Horse(string, string);

		void incRacesWon()
			{ racesWon++; }

		void sendToGate();
			{ distanceTraveled = 0; }

		void runASecond();

		void toString();

		int getMaxRunningDistPerSecond() const
			{return maxRunningDistPerSecond;}

		int getDistanceTraveled() const
			{return distanceTraveled;}

		int getRacesWon() const
			{return racesWon;}
};

#endif