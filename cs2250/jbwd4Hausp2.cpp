/*
Joshua Bearden
7/6/15
A program to translate english to pig latin
*/

#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

//The word struct, contains strings in english and pig latin
struct Word {
	string english;
	string piglatin;
};

//initializes the array of words
Word * init_array (string sentence, int &numWords)
{
	numWords = 1;
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
		else if (sentence[i] <= 'Z' && sentence[i] >= 'A')
		{
			itr->english += tolower(sentence[i]);
		}
		else if(sentence[i] <= 'z' && sentence[i] >= 'a')
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

//translates the words from english to pig latin
void translate(Word * wordArr, int size)
{
	string appendCon = "ay";
	string appendVow = "way";
	bool lastWord = false;
	char lastChar;

	for(int i = 0; i < size; i++)
	{
		char firstLetter = wordArr[i].english[0];
		if(i == size-1)
		{
			lastWord = true;
		}
		//determines if the first letter is a vowel for the vowel translation
		if((firstLetter == 'a' || firstLetter == 'e') || (firstLetter == 'i' || firstLetter == 'o') || (firstLetter == 'u'))
		{
			wordArr[i].piglatin = wordArr[i].english;
			if(lastWord)
			{
				lastChar = wordArr[i].piglatin.at(wordArr[i].piglatin.size()-1);
				if(!(lastChar < 'z' && lastChar > 'a'))
				{
					wordArr[i].piglatin.erase(wordArr[i].piglatin.size()-1, 1);
					wordArr[i].piglatin += appendVow;
					wordArr[i].piglatin += lastChar;
				}
				else
				{
					wordArr[i].piglatin += appendVow;
				}

			}
			else
			{
				wordArr[i].piglatin += appendVow;
			}
		}
		//if the first letter is a consonant
		else
		{
			wordArr[i].piglatin = wordArr[i].english;
			wordArr[i].piglatin.erase(0,1);
			if(lastWord)
			{
				lastChar = wordArr[i].piglatin.at(wordArr[i].piglatin.size()-1);
				if(!(lastChar < 'z' && lastChar > 'a'))
				{
					wordArr[i].piglatin.erase(wordArr[i].piglatin.size()-1, 1);
					wordArr[i].piglatin += firstLetter;
					wordArr[i].piglatin += appendCon;
					wordArr[i].piglatin += lastChar;
				}
				else
				{
					wordArr[i].piglatin += firstLetter;
					wordArr[i].piglatin += appendCon;
				}
			}
			else
			{
				wordArr[i].piglatin += firstLetter;
				wordArr[i].piglatin += appendCon;
			}
		}
	}
}
//displays the translated sentence
void showTranslation(Word * wordArr, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << wordArr[i].piglatin << ' ';
	}
	cout << endl;
}

int main()
{
	cout << "Please enter a string to convert to PigLatin:" << endl;
	string sentence;
	getline(cin, sentence);
	int size = 0;
	Word * wordArr = 0;
	wordArr = init_array(sentence, size);
	translate(wordArr, size);
	cout << "Output:" << endl;
	showTranslation(wordArr, size);
	return 0;
}