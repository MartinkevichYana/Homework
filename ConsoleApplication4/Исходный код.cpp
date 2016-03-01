#include <iostream>
#include <string.h>

using namespace std;


void ChangeString(char*, char[]);
int LengthString(char str[]);
bool Compare(char str1[], char str2[]);
void StringCopy(char s1[], char s2[]);


int main()
{
	const int length = 256;
	char string[length];
	cout << "Enter the string: "<<endl;
	cin.getline(string, length, '\n');
	char word[length];
	cout << "Enter the word to delete: " << endl;
	cin.getline(word, length, '\n');
	system("cls");
	cout << "My string is: " << endl;
	cout << string << endl;;
	ChangeString(string, word);
	cout << "My string without my word: " << endl;
	cout << string << endl;
	system("pause");
	return 0;
}

void ChangeString(char* str, char word[])
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* pWord = strpbrk(str, symbols);
	while (pWord)
	{
		int length = strspn(pWord, symbols); 
		if (Compare(pWord, word))
			StringCopy(pWord, pWord + length);
		else
			pWord += length;
		pWord = strpbrk(pWord, symbols);
	}
}

int LengthString(char str[])
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

bool Compare(char str1[], char str2[])
{
	if (LengthString(str1) != LengthString(str2))
	{
		return false;
	}
	int n = LengthString(str1);
	for (int i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
	}
	return true;
}

void StringCopy(char s1[], char s2[])
{
	int i = 0;
	while (s1[i] != LengthString(s2))
	{
		s1[i] = s2[i];
		++i;
	}
}





