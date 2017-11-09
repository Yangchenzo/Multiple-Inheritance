#include "sequenceEnum.h"

sequenceEnum::sequenceEnum() {}

sequenceEnum::sequenceEnum(string word = "") {
	key = word;
	state = true;
	if (key.size() < LIMIT)
		state = false;
	pattern = true;
}

string sequenceEnum::showVariant(string sub) {
	return "";
}

string sequenceEnum::showVariant() {
	string outStr = "";
	if (state)
	{
		if (pattern)
		{
			outStr = patternHelper(SECRET, SECRET2);
			pattern = false;
		}
		else
		{
			outStr = patternHelper(SECRET3, SECRET4);
			pattern = true;
		}
	}

	return outStr;
}

string sequenceEnum::patternHelper(int secret, int num) {
	string crypted;

	if (state && key.size() > LIMIT) {
		int one = secret % key.size();
		int two = num % key.size();
		string temp = key;

		temp += key[one];
		temp += key[two];

		crypted = temp;
	}
	else
		crypted = "";

	return crypted;
}

bool sequenceEnum::checkGuess(string guess) {
	return guess == key;
}

bool sequenceEnum::checkState() {
	return state;
}

bool sequenceEnum::activeSwitch(int lever) {
	bool status = false;
	if (lever == 0)
	{
		state = false;
		status = true;
	}
	else if (lever == 1)
	{
		state = true;
		status = true;
	}
	else
		status = false;
	return status;
}
