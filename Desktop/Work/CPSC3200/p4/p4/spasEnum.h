#include<iostream>
#include"sequenceEnum.h"
/* Name: Vincent Yang
* Date: 02/09/2017
* File: spasEnum.cs
* Purpose: This class is a child class of sequenceEnum that tests the
*          manipulation of the state by overriding the showVariant function
*          to show two types of variant depending on the state when the
*          function is called.
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
#ifndef SPASENUM_H
#define SPASENUM_H
using namespace std;

class spasEnum : public virtual sequenceEnum {
private:
	// Copy Constructor and Overloaded Assignment Operator suppressed.
	spasEnum(const spasEnum& obj) : sequenceEnum("") {}
	spasEnum operator=(const spasEnum* obj) { return *this; }
	/* truncateHelper Method
	* Description: The function takes in const int and mods it
	*              by the length of the key, and removes the part of the
	*              key that is after the modded int.
	*
	* Assumption: A proper key value must be assigned before the funcion call
	* PRE: A proper key value has been assigned
	* POST: an variant of the key will be returned
	*/
	string truncateHelper(int num);
protected:
	// Supressed default constructor
	spasEnum();
public:
	/* Overload Constructor
	* Description: Carries over the constructor from the parent
	*/
	spasEnum(string word);
	/* overriden showVariant
	* Description: override the showVariant function
	*              to show two types of variant depending on the state when the
	*              function is called.
	*
	* Assumption: A proper key value must be assigned before the funcion call
	*             , because there are no protection toward that.
	* PRE: A proper key value has been assigned
	* POST: an variant of the key will be returned
	* FUNCTION: truncateHelper()
	*/
	string showVariant();
	virtual ~spasEnum() {}
};

#endif
