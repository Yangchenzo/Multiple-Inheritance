#include"inverter.h"

inverter::inverter() {}

inverter::inverter(int num, string word) {
	pos = num;
	key = word;
	state = true;
}

string inverter::swapIt() {
	string outStr = "";
	if (state) {
		int size = key.size();
		char strChar[MAX_SIZE];
		for (int i = 0; i <= size; i++)
			strChar[i] = key[i];

		if (pos > size) {
			pos = pos % size;
		}
		int sub = pos + 1;
		char temp;
		temp = strChar[sub];
		strChar[sub] = strChar[pos];
		strChar[pos] = temp;

		outStr = strChar;
	}
	return outStr;
}

bool inverter::checkState() {
	return state;
}

void inverter::stateSwitch(bool lever) {
	state = lever;
}
