#include "spasEnum.h"
spasEnum::spasEnum() :sequenceEnum() {}
spasEnum::spasEnum(string word) : sequenceEnum(word) {
  key = word;
  state = true;
}

string spasEnum::showVariant() {
	string outStr = "";
	if (key.size() >= LIMIT)
	{
		if (state)
		{
			if (pattern)
			{
				outStr = patternHelper(SECRET2, SECRET3);
				pattern = false;
			}
			else
			{
				outStr = patternHelper(SECRET, SECRET4);
				pattern = true;
			}
		}
		else
		{
			if (pattern)
			{
				outStr = truncateHelper(SECRET);
				pattern = false;
			}
			else
			{
				outStr = truncateHelper(SECRET2);
				pattern = true;
			}
		}
	}
	return outStr;
}

string spasEnum::truncateHelper(int num) {
	string outStr = key;
	int trunkIndex = num % key.size();

	outStr = outStr.erase(trunkIndex);

	return outStr;
}
