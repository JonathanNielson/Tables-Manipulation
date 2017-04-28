#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "alphabetize.h"
using namespace std;

void print(ifstream &in);
void alphabetize(ifstream &in);

int main()
{
	string file = "river.txt";

	ifstream in(file);

	if (!in.good())
	{
		cout << "Unable to open " << file << " Exiting Program." << endl;
		exit(1);
	}

	print(in);

	int menuSelect = 10;

	while (menuSelect != 0)
	{
		cout << "Menu:" << endl;
		cout << "1) Add Game" << endl;
		cout << "2) Sort by Title" << endl;
		cout << "3) Sort by Developer" << endl;
		cout << "4) Sort by Release Date" << endl;
		cout << "5) Sort by How Long to Beat" << endl;
		cout << "6) Display Current Table" << endl;
		cout << endl << "0) Exit Program" << endl;

		cin >> menuSelect;

		switch (menuSelect)
		{
			case (1):
			{
				ofstream file;
				file.open("river.txt", ios::out | ios::app);

				string data;
				cout << endl << "Please enter the game's title:" << endl;
				cin.ignore();		//Still not sure why this works, other than that it is clearing(?) any leftover presses of the enter key from earlier
				std::getline(std::cin, data);
				file << endl << data << ":";

				cout << "Please enter the developer's name:" << endl;
				std::getline(std::cin, data);
				file << data << ":";

				cout << "Please enter the game's release date:" << endl;
				std::getline(std::cin, data);
				file << data << ":";

				cout << "Please enter the approximate length of the game:" << endl;
				std::getline(std::cin, data);
				file << data;

				file.close();

				break;
			}
			case 2:
			{
				ifstream editIn("river.txt");

				alphabetize(editIn);


				ifstream rDisplayFile("displayFile.txt");

				if (!rDisplayFile.good())
				{
					cout << "Unable to open displayfile.txt" << endl;
				}

				print(rDisplayFile);

				break;
			}
			case 3:
			{

				break;
			}
			case 4:
			{

				break;
			}
			case 5:
			{

				break;
			}
			case (6):
			{
				ifstream editIn("river.txt");
				print(editIn);
				break;
			}
			case (0):
			{
				cout << "Exiting Program." << endl;
				break;
			}
			default:
			{
				cout << "Error. Try Again." << endl;
				break;
			}
		}

	}

	return 0;
}


void print(ifstream &in)
{
	cout << endl << "|             Title             |      Developer      |  Release Date  | HLTB |" << endl;

	for (int i = 0; i < 79; i++)
	{
		cout << "-";
	}

	cout << endl;

	while (!in.eof())
	{
		string title;
		getline(in, title, ':');
		cout << left << setw(32) << title;

		string developer;
		getline(in, developer, ':');
		cout << left << setw(25) << developer;

		string release;
		getline(in, release, ':');
		cout << right << setw(15) << release;

		string hltb;
		getline(in, hltb);
		cout << right << setw(7) << hltb << endl;
	}

	for (int i = 0; i < 79; i++)
	{
		cout << "-";
	}

	cout << endl << endl;
}
