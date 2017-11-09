#include"inVSeq.h"

inVSeq::inVSeq() {}


/* Implementation Invariant: The class's activeness only changes for the
*  sequenceEnum hierarchy. It's always active for inverter hierarchy.
*/

inVSeq::inVSeq(int pos, string key) : inverter(pos, key), spasEnum(key)
									,seqExtract(key){
	pos = pos;
	key = key;
}

bool inVSeq::checkState() {
  return spasEnum::state;
}

string inVSeq::invertSQ() {
	string outStr = "";
	if (checkState()) {
		
		if (inverter::checkState())
			outStr = inverter::swapIt();

		outStr = sequenceEnum::showVariant();
	}
	else
		outStr = "";

	return outStr;
}

string inVSeq::invertSE(string sub) {
	string outStr = "";
	if (checkState()) {
		outStr = seqExtract::showVariant(sub);
		inverter::key = outStr;
		if (inverter::checkState())
			outStr = inverter::swapIt();
	}
	else
		outStr = "";

	return outStr;
}

string inVSeq::invertSP() {
	string outStr = "";
	if (checkState()) {

		if (inverter::checkState())
			outStr = inverter::swapIt();

		outStr = spasEnum::showVariant();
	}
	else
		outStr = "";
	
	return outStr;
}
