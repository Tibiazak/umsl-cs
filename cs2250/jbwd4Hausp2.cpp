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
		cout << sentence[i] << endl;
		cout << "for loop number 2, line 26" << endl;
		if(sentence[i] == ' ')
		{
			itr++;
		}
		else if ((sentence[i] < 'Z' && sentence[i] > 'A') || (sentence[i] <'z' && sentence[i] > 'a'))
		{
			cout << "else if 1 before code executed, line 33" << endl;
			itr->english += sentence[i];
			cout << "after else if 1 code executes" << endl;
		}
		else if (i == sentence.size() -1)
		{
			cout << "else if 2 before code executes, line 39" << endl;
			itr->english += sentence[i];
			cout << "else if 2 after code executes" << endl;
		}
		cout << i << endl;
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
	getline(cin, sentence);
	int size = 0;
	Word * wordArr = 0;
	wordArr = init_array(sentence, size);
	cout << "returned from wordArr" << endl;
	//translate(wordArr, size);
	//cout << "Output:" << endl;
	//showTranslation(wordArr, size);
	return 0;
}