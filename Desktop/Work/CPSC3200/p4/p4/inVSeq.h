/*
* Vincent Yang
* inVSeq.h
* version 1.0
*
* Purpose:
* This class inherits from the inverter class and the sequenceEnum class
* hierarchy (including seqExtract and spasEnum). It provides the combined
* functionality of all of them. A inVSeq object can showVariant(), swapIt(),
* invertSQ(), invertSE(),or invertSP(). Also the guessing function from
* sequenceEnum.
*
* Class Invariants:
* - Numbers being encapsulated must be positive integers. 0 counts as
*	improperly constructed too.
* - The max number of inversion will be forced back below the size of the
* 	word
* - ShowVariant() uses sequenceEnum's version of feedback
* - If no otherwise specified in the file, invariants from parent classes
*	hold.
*
* States:
* active = allows all function operation
* inactive = only allow the alternative spasEnum operation
*/
#include<iostream>
#include"inverter.h"
#include"sequenceEnum.h"
#include"seqExtract.h"
#include"spasEnum.h"

#ifndef INVSEQ_H
#define INVSEQ_H

class inVSeq : public inverter, public spasEnum, public seqExtract
{
	// Default Constructor, copy constructor, overloaded assignment operator
	// suppressed.
private:
	inVSeq();
	inVSeq(const inVSeq& obj) {}
	inVSeq& operator=(const inVSeq& obj) { return *this; }
public:
	/*Constructor
	* Description: takes an int and a string to encapsulate,
	*	default constructor does not exist. Improper Construction is not allowed.
	* 
	* Interface Invariant: The no-parameter call of the constructer is 
	*	eligible to be called.
	*/
	inVSeq(int pos, string key);
	string showVariant() { return sequenceEnum::showVariant(); }
	string showVariant(string sub) { return seqExtract::showVariant(sub); }
	/*CheckState() Method
	* Description: Accessor that checks the state and returns it.
	* Interface Invariant: inVSeq is always active for inverters 
	* PRE: N/A
	* POST: N/A
	* FUNCTIONS: N/A
	* IN: N/A
	* OUT: sequenceEunum::state
	* MOD: N/A
	*/
	bool checkState();
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
	string invertSQ();
	string invertSE(string sub);
	string invertSP();
	virtual ~inVSeq() {}
	
};

#endif
