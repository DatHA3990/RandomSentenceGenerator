#include "stdafx.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

const string LOCATION = "C:\\Personnal\\programming\\c++\\RandomSentenceGenerator\\Words\\";

string randomWordFromTextFile(string location) {
	ifstream file;
	vector<string> vec;

	file.open(location);

	while (!file.eof()) {
		string text;
		getline(file, text);
		vec.push_back(text);
	}

	srand((unsigned)time(NULL));
	return vec[rand() % vec.size()];
}

int main()
{
	while (true) {
		string subject = randomWordFromTextFile(LOCATION + "subject.txt");
		string verb = randomWordFromTextFile(LOCATION + "verb.txt");
		string location = randomWordFromTextFile(LOCATION + "location.txt");

		string sentence = "A " + subject + " " + verb + " in " + location + ".";
		cout << sentence << endl;

		cin.get();
	}

	return 0;
}