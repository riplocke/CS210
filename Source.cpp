//River Williams
//CS 210 Project 3: Corner Grocer
//8-13/25

#include <iostream>
#include <map>
#include <fstream>
#include <string>

using namespace std;

class GroceryFrequency {
public: //Reading the input file and generating the frequency data
	void processInputFile(string filename) {
		ifstream input(filename);
		if (input.fail()) {
			cout << "Error: unable to open file " << filename << endl;
			return;
		}
		string item;
		while (input >> item) {
			freqData[item]++;
		}
		input.close(); //closes file
	}
	int getItemFrequency(string item) {
		return freqData[item];
	}
	void printFrequencyList() { //printing a list of items and frequencies
		for (auto it = freqData.begin(); it != freqData.end(); ++it) {
			cout << it->first << ": " << it->second << endl;
			}
		}
		//Pringting a histogram of item frequency data
		void printFrequencyHistogram(){
			for (auto it = freqData.begin(); it != freqData.end(); ++it) {
				cout << it->first << " ";
				for (int i = 0; i < it->second; i++) {
					cout << "*";
				}
				cout << endl;
			}
	}
	//Writing the data to a backup file (frequency.dat)
	void backupFrequencyData(string filename) {
		ofstream output(filename);
		if (output.fail()) {
			cout << "Error: Unable to open file " << filename << endl;
			return;
		}
		for (auto it = freqData.begin(); it != freqData.end(); ++it) {
			output << it->first << ": " << it->second << endl;
		}
		output.close(); //closing file
	}
private:
	map<string, int>freqData;
};

int main() {
	GroceryFrequency grocery;
	//processing the input file
	grocery.processInputFile("CS210_Project_Three_Input_File.txt");

	//Main Menu
	bool running = true;
	while (running) {
		//Menu options
		cout << endl;
		cout << "Please select an option from the menu:" << endl;
		cout << "1.) Look up an item's frequency" << endl;
		cout << "2.) Print list of all items and their frequencies" << endl;
		cout << "3.) Print a histogram of item frequencies" << endl;
		cout << "4.) Exit" << endl;

		//retrieving and executing user input
		int choice;
		cout << "Enter your selection (1-4): ";
		cin >> choice;

		switch (choice) {
		case 1: {
			string item;
			cout << "Enter the item to look up: ";
			cin >> item;
			int freq = grocery.getItemFrequency(item);
			cout << "Frequency of " << item << ": " << freq << endl;
			break;
		}
		case 2: {
			grocery.printFrequencyList();
			break;
		}
		case 3: {
			grocery.printFrequencyHistogram();
			break;
		}
		case 4:
			grocery.backupFrequencyData("frequency.dat");
			running = false;
			break;
		}
	}
	return 0;
}