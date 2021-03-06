// ChairSavior.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include<windows.h>
#include <chrono>
#include <iostream>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
int minutes = 0;
int seconds = 0;
string name;
vector<string>character;
void implement(vector<string> *a);
int main() {
	//Stores users name
	user("Please input your name. It shall be used to refer to you when neccessary", name);
	cout << "Hello, " << name << ". This program will help you become active throughout the day.\n For every 15 minutes, you should do some physical activity to help you stay healthy. This timer will count up to 15, and then will warn you that you are sitting down for too long. \n Give it a go!" << endl;
	system("pause");
	//WIll allow program to run forever, or at least until the user clicks the X button
	while (true) {
		do {
			//Prevents the program from making walls of texts, places new letters on the same line
			system("cls");
			//Will add 1 to seconds for every loop
			++seconds;
			//Will generate a new tip when seconds is at 1
			if (seconds == 1) {
				implement(&character);
			}
			cout << name << ", you have spent..." << endl;
			// The clock. Will display the amount of time the user has spent sitting
			cout << minutes << " Minutes and " << seconds << " seconds sitting!" << endl;
			cout << character[0] << endl;
			// Will take 1 second for the program to loop again
			Sleep(1000);
		} while (seconds != 60);
		if (seconds == 60) {
			//Resets seconds
			seconds = 0;
			//Adds 1 to minutes for every 60 seconds 
			++minutes;
		}
		//Stops the program when X amount of minutes has passed
		if (minutes == 15) {
			cout << "Hey, you should start walking around to fit in your daily excercise. Once you are done, press the Enter key" << endl;
			cin.get();
			//Resets time
			seconds = 0;
			minutes = 0;
			system("pause");
			//Restarts clock
			continue;
		}

	}
	return 0;
}
//Implements tips into vector character, and scrammbles them. What is within the 0 part of the vector will get written
void implement(vector<string> *a) {
	a->clear();
	a->push_back("Tip: Just working out after your work day isn't enough. Try to do some physical activity repeatedly throughout the day");
	a->push_back("Tip: The fat, lazy programmer is just a stereotype! You can be active while also dishing out good code");
	a->push_back("Tip: Sitting down for too long can actually slow your metabolism, which will cause you to gain weight more easily. Move around more to prevent this!");
		auto rng = std::default_random_engine{};
		std::random_shuffle(a->begin(), a->end());
}



