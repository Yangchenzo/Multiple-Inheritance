#include<iostream>
#include"sequenceEnum.h"
/* Name: Vincent Yang
* Date: 02/09/2017
* File: seqExtract.cs
* Purpose: This class is a child class of sequenceEnum that uses the function
*          that was implemented as NoP. It changes the functionality of
*          the showVariant function, that supports truncates the part of the key
*          that is passed in and returns the rest of the key back to AP.
* version 1.1
* CLASS INVARIANT:
*          - Relationship:
*              Association: This class is a child class from the sequenceEnum class,
*                           and has access to all the public and preotected data
*                           from its parent class
*              Cardinality: Can only take in one key at a time
*          - The object requres a string to be passed in as 'key' upon construction
*            or it will be "" as default
*/
#ifndef SEQEXTRACT_H
#define SEQEXTRACT_H
using namespace std;

class seqExtract: public virtual sequenceEnum {
private:
	// Copy Constructor and Overloaded Assignment Operator suppressed.
	seqExtract(const seqExtract& obj) : sequenceEnum("") {}
    seqExtract operator=(const seqExtract& obj) {return *this;}
protected:
	// Supressed default1 constructor
	seqExtract();
	/* Default showVariant
	* Description: override the default showVariant to NoP so the other
	*              showVariant method can be implemented without risk
	*/
	string showVariant();
public:
	/* Overload Constructor
	* Description: Carries over the constructor from the parent
	*/
	seqExtract(string word);
	/* showVariant (pass in string)
	* Description: THe function takes in a string that will be an excerpt
	*              of the key, and the function will truncates the excerpt
	*              part and return the rest to the AP
	* Assumption: sub is a consecutive part of the key
	*
	* PRE: sub is part of the key
	* POST: the part of ther than sub is returned
	*/
	string showVariant(string sub);
	virtual ~seqExtract() {}
};

#endif
