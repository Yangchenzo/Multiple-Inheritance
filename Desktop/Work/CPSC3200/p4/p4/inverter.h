#include<iostream>
#include<string>
/*
*Purpose: This clss encapsulates a number and a string, and reutnrs
* a "inverted" version of the string encapsulated.
*
*State:
* Active = Object supports all functionality
* Inactive = Object provids NoP and returns ""
*/
#ifndef INVERTER_H
#define INVERTER_H
using namespace std;

const int MAX_SIZE = 100;

class inverter {
private:
	// Copy Constructor and Overloaded Assignment Operator suppressed.
	inverter(const inverter& obj) {}
	inverter& operator=(const inverter& obj) { return *this; }
protected:
	inverter();
	int pos;
	string key;
	bool state;
public:
	/*Constructor
	* Description: takes an int and a string to encapsulate,
	*	default constructor does not exist. Improper Construction is not allowed.
	*
	* Interface Invariant: The no-parameter call of the constructer is
	*	eligible to be called.
	*/
	inverter(int pos, string word);
	/*swapIt() method
	* Description: the method uses pos to locate a location the string "word"
	*	and swaps it with the character located on pos+1
	*
	* Interface Invariant: If inactive, it will be NoP
	*
	* PRE: a key must be encapsulated
	* POST: Key inverted
	*/
	virtual string swapIt();
	/*invertSeq methods
	* Description: These are variations of combined showVariant() operations
	* with the swapIt() operations. Each method returns a inverted version
	* of the respected showVariant() methods.
	*
	* Interface Invariants:
	* - Returns "" if inactive
	* PRE: - Object must be properly constructed
	*
	* FUNCTIONS: inverter::swapIt(), sequenceEnum::showVariant(),
	*	seqExtract::showVariant(sub), and spasEnum::showVariant
	*/
	bool checkState();
	void stateSwitch(bool lever);
	virtual ~inverter() {}
};

#endif
