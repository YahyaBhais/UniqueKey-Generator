// UniqueKey-Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;

enum encharType{
	CapitalLatter=1
	,SmallLatter=2
	,Digits=3
	,SpeacialCharacter=4};

int RandNumber(int From,int To) {

	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
int ReadPositiveNumber(string Message) {
	int Number = 0;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number<=0);
	return Number;
}

char GetRandomCharacter(encharType CharType) {

	switch (CharType) {

	case encharType::CapitalLatter:
		return char(RandNumber(65, 90));
		break;
	case encharType::SmallLatter:
		return char(RandNumber(97, 122));
		break;
	case encharType::SpeacialCharacter:
		return char(RandNumber(33, 47));
		break;
	case encharType::Digits:
		return char(RandNumber(48, 57));
		break;
	default:
		return char(RandNumber(65, 90));


	}
}

string GenerateWord(encharType CharType,short Length) {

	string Word;
	for (int i = 0; i < Length; i++) {
		Word += GetRandomCharacter(CharType);

	}
	return Word;
}

string GenerateKey() {

	string Key = GenerateWord(encharType::CapitalLatter, 4) + "-";
	Key += GenerateWord(encharType::CapitalLatter, 4) + "-";
	Key += GenerateWord(encharType::CapitalLatter, 4) + "-";
	Key += GenerateWord(encharType::CapitalLatter, 4);

	return Key;
}

void SaveKeysToFile(string arr[100], short Length) {
	ofstream MyFile;
	MyFile.open("MyGeneratedKeys.txt", ios::out);

	if (MyFile.is_open()) {
		for (int i = 0; i < Length; i++) {
			MyFile << "Key [" << i + 1 << "]" << arr[i] << endl;

		}

		MyFile.close();
		cout << "\n[Success] All keys have been saved to 'MyGeneratedKeys.txt'!" << endl;
	}
	else {
		cout << "\nInvalid choice! Please select 1, 2, or 3." << endl;
	}
}
void ShowMainMenu() {
	cout << "\n========================================" << endl;
	cout << "   KEY GENERATOR SYSTEM - VERSION 1.0" << endl;
	cout << "========================================" << endl;
	cout << "[1] Generate Keys & Save to File" << endl;
	cout << "[2] About Project" << endl;
	cout << "[3] Exit" << endl;
	cout << "========================================" << endl;
	cout << "Select an option [1-3]: ";
}
void StartApp() {
	string arr[100];
	int Choice=0;
	
	do
	{
		ShowMainMenu();
        cin >> Choice;
		
		switch (Choice) {
		case 1: {

			short NumberOfKeys = ReadPositiveNumber("Please Enter Number Of Keys You Want To Generate (1-100)");
			if (NumberOfKeys > 100)
				NumberOfKeys = 100;
			if (NumberOfKeys <= 0)
				cout << "Invalid Number.Please Try Again !\n";
			
			cout << "\n--- Generating Keys ---" << endl;
			for (int i = 0; i < NumberOfKeys; i++) {
				arr[i] = GenerateKey();
				cout << "Key [" << i + 1 << "] = " << arr[i] << endl;
				
			}
			SaveKeysToFile(arr, NumberOfKeys);
			break;
		}

		case 2:
			cout << "\n--- ABOUT THIS PROJECT ---" << endl;
			cout << "Inspired by the legacy of telecom scratch cards." << endl;
			cout << "A educational project for learning C++ Logic & File I/O." << endl;
			cout << "Proudly Developed in Yatta, Palestine." << endl;
			break;

		case 3:
			cout << "\nThank you for using the System. Goodbye!" << endl;
			break;
		default:
			cout << "\nInvalid choice! Please select 1, 2, or 3." << endl;

		}
	} while (Choice!=3);



}

int main() {

	srand((unsigned)time(NULL));
	
	StartApp();

}