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
		if (sentence[i] == " ")
		{
			numWords++;
		}
	}

	Word * wordArr = new Word[numWords];
	//TODO - copy the words from sentence into the struct array while ignoring punctuation

	return init_array;
}

void translate(Word * wordArr, int size)
{
	string appendCon = "ay";
	string appendVow = "way";

	for(int i = 0; i < size; i++)
	{
		char firstLetter = wordArr[i]->english[0];
		if(isVowel(firstLetter))
		{
			wordArr[i]->english.copy(wordArr[i]->piglatin, wordArr[i]->english.size(), 0);
			wordArr[i]->piglatin += appendVow;
		}
		else
		{
			wordArr[i]->english.copy(wordArr[i]->piglatin, wordArr[i]->english.size(), 1);
			wordArr[i]->piglatin += firstLetter;
			wordArr[i]->piglatin += appendCon;
		}
	}
}

void showTranslation(Word * wordArr)
{
	for(int i = 0; i < size; i++)
	{
		cout << wordArr[i]->piglatin << " ";
	}
}

int main()
{
	cout << "Please enter a string to convert to PigLatin:" << endl;
	string sentence;
	cin >> sentence;
	int size = 0;
	Word * wordArr = 0;
	wordArr = init_array(sentence, size);
	translate(wordArr, size);
	cout << "Output:" << endl;
	showTranslation(wordArr);
	return 0;
}