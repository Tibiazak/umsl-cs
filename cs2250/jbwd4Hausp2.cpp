#include <iostream>
#include <string>
using namespace std;

struct Word {
	string english;
	string piglatin;
};

Word * init_array (string sentence, int &numWords)
{
	numWords = 0;
	for(int i = 0; i < sentence.size(); i++)
	{
		if (sentence[i] == ' ')
		{
			numWords++;
		}
	}

	Word * wordArr = new Word[numWords];
	Word * itr = wordArr;
	for(int i = 0; i < sentence.size(); i++)
	{
		if(sentence[i] == ' ')
		{
			itr++;
		}
		else if ((sentence[i] < 'Z' && sentence[i] > 'A') || (sentence[i] <'z' && sentence[i] > 'a'))
		{
			itr->english += sentence[i];
		}
		else if (i == sentence.size() -1)
		{
			itr->english += sentence[i];
		}
	}

	return wordArr;
}
/*
void translate(Word * wordArr, int size)
{
	string appendCon = "ay";
	string appendVow = "way";

	for(int i = 0; i < size; i++)
	{
		char firstLetter = wordArr[i].english[0];
		if((firstLetter == 'a' || firstLetter == 'e') || (firstLetter == 'i' || firstLetter == 'o') || (firstLetter == 'u'))
		{
			wordArr[i].piglatin = wordArr[i].english;
			wordArr[i].piglatin += appendVow;

		}
		else
		{
			wordArr[i].piglatin = wordArr[i].english;
			wordArr[i].piglatin.erase(0,0);
			wordArr[i].piglatin += firstLetter;
			wordArr[i].piglatin += appendCon;
		}
	}
}

void showTranslation(Word * wordArr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << wordArr[i].piglatin << ' ';
	}
}
*/
int main()
{
	cout << "Please enter a string to convert to PigLatin:" << endl;
	string sentence;
	cin >> sentence;
	int size = 0;
	Word * wordArr = 0;
	wordArr = init_array(sentence, size);
	cout << returned from wordArr << endl;
	//translate(wordArr, size);
	//cout << "Output:" << endl;
	//showTranslation(wordArr, size);
	return 0;
}