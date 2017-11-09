#include "seqExtract.h"

seqExtract::seqExtract(string word) : sequenceEnum(word) { key = word; }
seqExtract::seqExtract() : sequenceEnum() {}
string seqExtract::showVariant() {
	return "";
}

string seqExtract::showVariant(string sub) {
	string outStr = "";
	int index = 0;

	if (key.size() < LIMIT)
		outStr = "";
	else
	{
		if (state)
		{
			outStr = key;
			index = outStr.find(sub);
			outStr = outStr.erase(index, sub.size());
		}
	}

	return outStr;
}