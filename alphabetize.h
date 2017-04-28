#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

void alphabetize(ifstream &in)
{
	string entries[5];
	string display[5];
	int letPos[5];
	int shift[5] = {0, 0, 0, 0, 0};
	char firstLet;
	int temp = 0;
	string tempEntry;

	for (int i = 0; i < 5; i++)
	{
		getline(in, entries[i]);
	}

	for (int i = 0; i < 5; i++)
	{
		firstLet = entries[i].at(0);


		if (firstLet == '0')
		{
			letPos[i] = 0;
		}
		else if (firstLet == '1')
		{
			letPos[i] = 1;
		}
		else if (firstLet == '2')
		{
			letPos[i] = 2;
		}
		else if (firstLet == '3')
		{
			letPos[i] = 3;
		}
		else if (firstLet == '4')
		{
			letPos[i] = 4;
		}
		else if (firstLet == '5')
		{
			letPos[i] = 5;
		}
		else if (firstLet == '6')
		{
			letPos[i] = 6;
		}
		else if (firstLet == '7')
		{
			letPos[i] = 7;
		}
		else if (firstLet == '8')
		{
			letPos[i] = 8;
		}
		else if (firstLet == '9')
		{
			letPos[i] = 9;
		}
		if (firstLet == 'a' || firstLet == 'A')
		{
			letPos[i] = 10;
		}
		else if (firstLet == 'b' || firstLet == 'B')
		{
			letPos[i] = 11;
		}
		else if (firstLet == 'c' || firstLet == 'C')
		{
			letPos[i] = 12;
		}
		else if (firstLet == 'd' || firstLet == 'D')
		{
			letPos[i] = 13;
		}
		else if (firstLet == 'e' || firstLet == 'E')
		{
			letPos[i] = 14;
		}
		else if (firstLet == 'f' || firstLet == 'F')
		{
			letPos[i] = 15;
		}
		else if (firstLet == 'g' || firstLet == 'G')
		{
			letPos[i] = 16;
		}
		else if (firstLet == 'h' || firstLet == 'H')
		{
			letPos[i] = 17;
		}
		else if (firstLet == 'i' || firstLet == 'I')
		{
			letPos[i] = 18;
		}
		else if (firstLet == 'j' || firstLet == 'J')
		{
			letPos[i] = 19;
		}
		else if (firstLet == 'k' || firstLet == 'K')
		{
			letPos[i] = 20;
		}
		else if (firstLet == 'l' || firstLet == 'L')
		{
			letPos[i] = 21;
		}
		else if (firstLet == 'm' || firstLet == 'M')
		{
			letPos[i] = 22;
		}
		else if (firstLet == 'n' || firstLet == 'N')
		{
			letPos[i] = 23;
		}
		else if (firstLet == 'o' || firstLet == 'O')
		{
			letPos[i] = 24;
		}
		else if (firstLet == 'p' || firstLet == 'P')
		{
			letPos[i] = 25;
		}
		else if (firstLet == 'q' || firstLet == 'Q')
		{
			letPos[i] = 26;
		}
		else if (firstLet == 'r' || firstLet == 'R')
		{
			letPos[i] = 27;
		}
		else if (firstLet == 's' || firstLet == 'S')
		{
			letPos[i] = 28;
		}
		else if (firstLet == 't' || firstLet == 'T')
		{
			letPos[i] = 29;
		}
		else if (firstLet == 'u' || firstLet == 'U')
		{
			letPos[i] = 30;
		}
		else if (firstLet == 'v' || firstLet == 'V')
		{
			letPos[i] = 31;
		}
		else if (firstLet == 'w' || firstLet == 'W')
		{
			letPos[i] = 32;
		}
		else if (firstLet == 'x' || firstLet == 'X')
		{
			letPos[i] = 33;
		}
		else if (firstLet == 'y' || firstLet == 'Y')
		{
			letPos[i] = 34;
		}
		else
		{
			letPos[i] = 35;
		}
	}
		
		//Printing out initial first positions
		for (int j = 0; j < 5; j++)
		{
			cout << letPos[j] << " ";
		}
		//-------

		cout << endl << endl;


		//The actual alphabetizer
		for (int i = 0; i < 5; i++)
		{
			int tempShift = 0;

			for (int j = i; j < 5; j++)
			{
				if (letPos[i] > letPos[j])
				{
					tempShift = (j - i);
				}
			}

			int temp = letPos[i];
			letPos[i] = letPos[(i + tempShift)];
			letPos[(i + tempShift)] = temp;

			if (shift[i] == 0)
			{
				shift[i] = tempShift;
			}
			if (tempShift != 0)
			{
				shift[(i + tempShift)] = -tempShift;
			}
		}

		cout << endl;

		//Printing out final first positions
		for (int j = 0; j < 5; j++)
		{
			cout << letPos[j] << " ";
		}
		cout << endl;
		//-------

		cout << endl;

		//Printing out shift values
		for (int j = 0; j < 5; j++)
		{
			cout << shift[j] << " ";
		}
		
		for (int i = 0; i < 5; i++)
		{
			tempEntry = entries[i];
			if (!(shift[i] <= 0))
			{
				entries[i] = entries[(i + shift[i])];
				entries[(i + shift[i])] = tempEntry;
			}

		}

		ofstream displayFile;
		displayFile.open("displayFile.txt", ios::out);
		for (int i = 0; i < 5; i++)
		{
			if (i < 4)
			{
				displayFile << entries[i] << endl;
			}
			else
			{
				displayFile << entries[i];
			}

		}
}