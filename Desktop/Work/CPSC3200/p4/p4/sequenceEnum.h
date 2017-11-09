#include<iostream>
#include<string>
/* Name: Vincent Yang
* Date: 02/09/2017
* File: sequenceEnum.h
* Purpose: The sequenceEnum class is the base class in this hierarchy, it is able to
*          hold a string passed in from the driver as 'key', and return variants from it.
*          The class supports functions including getting the 'key' string from the driver
*          with the constructor, showing the variants of the key with patternHelper function
*          , check the user's guess then return the result, and switching the class' state.
* version 1.1
* CLASS INVARIANTS:
*        - Relationship:
*              - Association: This class is the base/parent class of two children classes
*              - Cardinality: Can only take in one string at a time
*        - The object requires a string to be passed in as 'key' upon construction
*          or it will be "" as default.
*/
#ifndef SEQUENCEENUM_H
#define SEQUENCEENUM_H

using namespace std;

class sequenceEnum {
private:
  // Copy Constructor and Overloaded Assignment Operator suppressed.
  sequenceEnum(const sequenceEnum& obj) {}
  sequenceEnum operator=(const sequenceEnum& obj) {return *this;}
protected:
  // Class Attributes
  static const int SECRET = 42;
  static const int SECRET2 = 29;
  static const int SECRET3 = 32;
  static const int SECRET4 = 66;
  static const int ExtraSize = 2;
  static const int LIMIT = 3;
  bool pattern;
  bool state;
  string key;
  /* patternHelper Method
   * Description: the function takes in two const int from the class and
   *              perform a simple encryption to the key string, then returns
   *              it back out
   * Assumption: A key has been passed in from the AP that is longer than 3 characters
   *
   * POST: a simple encryption of key returned
   */
  string patternHelper(int secret, int num);
  // Suppressed default constructor
  sequenceEnum();
  
 public:
  /* Overload Constructor
   * Parameter: (default) word allows AP to set the key for this class
   *
   * Interface Invariants:
   *      - key will be default as "", or the state will be false if AP doesn't
   *        put a string that's longer than 3
   *
   * POST: key is stored and the state is determined
   * IN: word
   * MOD: key, state, pattern
   */
  sequenceEnum(string word);
  /* showVariant Method (pass in string)
   * Description: A function that takes in a string 'sub', it is prepared
   *              for a children class. The functionality has been set to NoP for
   *              parent to call it
   */
  virtual string showVariant(string sub);
  /* showVariant Method (default)
   * Description: The function returns a variant of the key with the patternHelper
   *              function. It first checks if the state is active, or else it would
   *              return 'N/A' to show it's not active. Then it checks which pattern
   *              is supposed to be returned, and then call the helper function
   *
   * Assumption: A key has been passed in from the AP that is longer than 3 characters
   *
   * PRE: Class must be constructed
   * POST: Key variant returned
   *
   * Functions: patternHelper()
   */
  virtual string showVariant();
  /* checkState Method
   * Description: A simple accessor for the state
   */
  virtual bool checkState();
  /* checkGuess Method
   * Description: The function simply checks if the string that is passed in
   *              matches the key, and returns the result
   * Parameter: guess
   * Assumption: Key has been assigned to a proper value before the call of this
   *             function
   *
   * POST: guess result returned
   */
  virtual bool checkGuess(string guess);
  /* stateChange Method
   * Description: The function takes in an int and then change the state of the class
   *              depending on the int passed in
   * Parameter: lever
   * Assumption: Lever must only be 0 or 1, or else the function returns false
   *             to show the change of state failed
   * PRE: state remains the same
   * POST: state changes according to the int passed in
   */
  virtual bool activeSwitch(int lever);
  virtual ~sequenceEnum(){}
};

#endif
