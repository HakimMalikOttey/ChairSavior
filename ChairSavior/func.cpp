#include "stdafx.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;
//Will take users input and place whatever they type into string name. Will constantly refer to them as that
void user(string a, string& b) {
	string unam;
	cout << a << endl;
	cin >> unam;
	b = unam;
}

