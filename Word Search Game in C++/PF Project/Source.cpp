#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
const int ROWS = 15;
const int COLUMNS = 15;
char table[ROWS][COLUMNS];
const int MAX = 5;
int input = 0;
string words[MAX];


void initialize(fstream& inputFile) {

	for (int i = 0; i < ROWS; i++)
	{

		for (int j = 0; j < COLUMNS; j++)
			inputFile >> table[i][j];
	}

}
void displayConfig()
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLUMNS; j++)
		{

			cout << table[i][j];

		}
		cout << endl;
	}

}
int wordcheck(fstream& inputFile) {


	for (int k = 0; k < MAX; k++) 
	{
		inputFile >> table[15][15] >> words[k];
		cout << words[k] << endl;
	}

}


string checkRow(fstream& inputFile, int i)
{

	string temp = "";
	for (int j = 0; j < 15; j++) {
		inputFile >> table[i][j];
		temp += table[i][j];
	}

	int k = 1;

	do {
		if (temp.find(words[k]) != string::npos)
		{
			return words[k];
		}
		else
			k++;
	} while (k <= 5);

}


string checkColumn(fstream& inputFile, int j)

{
	int k = 1;

	string temp = "";
	for (int i = 0; i < 15; i++) {
		inputFile >> table[i][j];
		temp += table[i][j];
	}

	do {

		if (temp.find(words[k]) != string::npos)
		{
			return words[k];
		}
		else
			k++;
	} while (k <= 5);
}

string checkRightDiagonal(fstream& inputFile, int i, int j)
{
	int k = 1;
	string temp = "";

	while (i < 15 && j < 15)
	{
		inputFile >> table[i][j];
		temp += table[i][j];
		i++;
		j++;

	}
	do {

		if (temp.find(words[k]) != string::npos)
		{
			return words[k];
		}
		else
			k++;
	} while (k <= 5);
}

string checkLeftDiagonal(fstream& inputFile, int i, int j)
{

	int k = 1;
	string temp = "";

	while (i < 15 && j >= 0)
	{
		inputFile >> table[i][j];
		temp += table[i][j];
		i++;
		j--;
	}
	do {

		if (temp.find(words[k]) != string::npos)
		{
			return words[k];
		}
		else
			k++;
	} while (k <= 5);
}


int checkConfiguration(fstream& inputFile)
{

	for (int row = 0; row < 15; row++)
	{
		string result = checkRow(inputFile, row);

		{
			cout << result;
		}
	}
	for (int column = 0; column < 15; column++)
	{
		string result = checkColumn(inputFile, column);

		cout << result;
	}
	for (int row = 0; row < 15; row++)
	{
		for (int column = 0; column < 15; column++)
		{
			string result = checkLeftDiagonal(inputFile, row, column);

			cout << result;
		}
	}
	for (int row = 0; row < 15; row++)
	{
		for (int column = 0; column < 15; column++)
		{
			string result = checkRightDiagonal(inputFile, row, column);

			cout << result;
		}
	}
}



int main() {

	fstream inputFile;
	inputFile.open("wordsearch_data.txt");

	initialize(inputFile);
	displayConfig();

	wordcheck(inputFile);

	checkConfiguration(inputFile);
}