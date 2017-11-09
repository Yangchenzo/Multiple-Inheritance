/*
* Vincent Yang
* p4.cpp
* 2/23/2017
*                      Contents:
* The structure of this driver will be as follows :
*
*  A. The SequenceEnum Class Hierarchy
*  B. seqExtract Class
*  C. spasEnum Class
*  D. The inverter Class Hierarchy
*  E. inVSeq Class
*
*  The sequenceEnum hierarchy classes' functionality will be tested as follows:
*
*  1. On ACTIVE Objects
*		a. checkState()
*		b. checkGuess()
*       c. showVariant()
*       d. showVariant(string)
*  2. On INACTIVE Objects
*		a. checkState()
*		b. checkGuess()
*       c. showVariant()
*       d. showVariant(string)
*
*  The inverter class functionality will be tested as follows:
*
*  1. On ACTIVE Objects
*		a. checkState()
*		b. swapIt()
*		c. stateSwitch()
*  2. On INACTIVE Objects
*		a. checkState()
*		b. swapIt()
*
*  The inVSeq class has the following functionality. Each method will
* be tested on (a) ACTIVE objects, and (b) INACTIVE objects.
*
*  1. Constructor
*  2. stateCheck()
*  3. checkGuess() wrong & correct
*  4. swapIt()
*  5. showVariant()
*  6. invertSQ() and invertSP()
*  7. invertSE()
*  8. stateSwitch()
*/
#include<iostream>
#include<string>
#include<time.h>
#include<cstdlib>
#include<fstream>
#include"seqExtract.h"
#include"sequenceEnum.h"
#include"spasEnum.h"
#include"inverter.h"
#include"inVSeq.h"
using namespace std;

// Includes base class sequenceEnum and all derived classes
const int NUM_SEQNUM = 4;
// Includes base type inverter and all derived classes
const int NUM_INVERTER = 2;
const int NUM_OBJS_PER_CLASS = 2;
// Refers to the total number of objects in collection. 
const int SIZE_A = NUM_OBJS_PER_CLASS * NUM_SEQNUM;
const int SIZE_B = NUM_OBJS_PER_CLASS;
const int SIZE_C = NUM_OBJS_PER_CLASS;
const int SIZE_D = NUM_OBJS_PER_CLASS * NUM_INVERTER;
const int SIZE_E = NUM_OBJS_PER_CLASS;
// Maximum value to construct the inverter hierarchy with
const int MAX_INVPOS = 100;
const int BANK_SIZE = 20;
const int EXTRACT_START = 4;
const int EXTRACT_STOP = 6;
const int EXTRACT_SIZE = 2;
const int PICKED_NUM = 10;
const int VSEQ_STOP = 1;

const string INPUT_FILE = "input.txt";
const string WRONG_GUESS = "wrongGuess";
const string CLUE_1 = "lo";
const string CLUE_2 = "gan";
const string CLUE_3 = "ment";
const string CLUE_4 = "iu";
const string CLUE_5 = "ca";
const string CLUE[EXTRACT_SIZE] = { CLUE_1, CLUE_2 };
const string CLUE2[EXTRACT_SIZE] = { CLUE_3, CLUE_4 };

int main() {
	cout << "\nWelcome! This is the test driver for the inVSeq class "
		<< "and all of its \nbase classes. Let's begin.\n\n";

	cout << "First generating output file...";

	string bank[BANK_SIZE];
	ifstream file("input.txt");
	if (file.is_open())
	{
		for (int i = 0; i < BANK_SIZE; ++i)
		{
			file >> bank[i];
		}
	}
	srand((unsigned int)time(NULL));

	// A. Testing the sequenceEnum class hierarchy
	cout << "First testing the sequenceEnum class hierarchy." << endl
		<< "Initializing collection A of size " << SIZE_A << endl << endl;
	sequenceEnum* collectionA[SIZE_A];

	// 1. Testing on Active objects
	cout << "Testing Active objects" << endl
		<< "Filling Heterogeneous Collection A with " << endl
		<< "..." << NUM_OBJS_PER_CLASS << " sequenceEnum..." << endl;
	int i = 0;
	int typeNum = 1;
	string temp = "";
	for (; i < (typeNum * NUM_OBJS_PER_CLASS); i++)
	{
	    temp = bank[i];
	    cout << temp << endl;
		collectionA[i] = new sequenceEnum(temp);
	}
	typeNum++;
	cout << "..." << NUM_OBJS_PER_CLASS << " spasEnum...\n";
	for (; i < (typeNum * NUM_OBJS_PER_CLASS); i++)
	{
	    temp = bank[i];
	    cout << temp << endl;
		collectionA[i] = new spasEnum(temp);
	}
	typeNum++;
	cout << "..." << NUM_OBJS_PER_CLASS << " seqExtract...\n";
	for (; i < (typeNum * NUM_OBJS_PER_CLASS); i++)
	{
	    temp = bank[i];
	    cout << temp << endl;
		collectionA[i] = new seqExtract(temp);
	}
	typeNum++;
	cout << "..." << NUM_OBJS_PER_CLASS << " inVSeq...\n";
	for (; i < (typeNum * NUM_OBJS_PER_CLASS); i++)
	{
	    temp = bank[i];
	    cout << temp << endl;
		int pos = rand() % MAX_INVPOS;
		collectionA[i] = new inVSeq(pos, temp);
	}
	typeNum++;
	cout << endl << endl;

	// 1a. checkState()
	cout << "Checking the state for each obj, 1 for active/0 for inactive: " << endl;
	for (int i = 0; i < EXTRACT_STOP; i++)
		cout << collectionA[i]->checkState();
	cout << endl << endl;

	// 1b. checkGuess(wrongGuess)
	cout << "All objects have now encapsulated a certain value" << endl
		<< "Guessing wrong on all. Should show 0's for false: " << endl;
	for (int i = 0; i < SIZE_A; i++)
		cout << collectionA[i]->checkGuess(WRONG_GUESS);
	cout << endl << endl;

	// 1b. checkGuess(correctGuess)
	cout << "Guessing correcttly on all. Should show 1's for true: " << endl;
	for (int i = 0; i < SIZE_A; i++)
		cout << collectionA[i]->checkGuess(bank[i]);
	cout << endl << endl;


	// 1c. showVariant() till seqExtract
	cout << "Calling showVariant() for each object until it requires a parameter"
		<< endl;
	for (int i = 0; i < EXTRACT_START; i++)
		cout << collectionA[i]->showVariant() << endl;
	cout << endl << endl;

	// 1d. showVariant(string) for seqExtract
	cout << "Calling showVariant(string) for the seqExtract objects in the HetCol"
		<< endl;
	int j = 0;
	for (int i = EXTRACT_START; i < EXTRACT_STOP; i++) {
		cout << collectionA[i]->showVariant(CLUE[j]) << endl;
		j++;
	}
	cout << endl << endl;

	// 2. Testing on Inactive Object
	cout << "Now switching all object to inactive" << endl;
	for (int i = 0; i < SIZE_A; i++) {
		collectionA[i]->activeSwitch(false);
	}
	// 2a.
	cout << "Checking the state for each obj, 1 for active/0 for inactive: " << endl;
	for (int i = 0; i < EXTRACT_STOP; i++)
		cout << collectionA[i]->checkState();
	cout << endl << endl;

	// 2b. checkGuess(wrongGuess)
	cout << "Guessing wrong on all on INACTIVE STATE. Should show 0's for false: "
		<< endl;
	for (int i = 0; i < SIZE_A; i++)
		cout << collectionA[i]->checkGuess(WRONG_GUESS);
	cout << endl << endl;

	// 2b. checkGuess(correctGuess)
	cout << "Guessing correcttly on allall on INACTIVE STATE. Should show 1's for true: "
		<< endl;
	for (int i = 0; i < SIZE_A; i++)
		cout << collectionA[i]->checkGuess(bank[i]);
	cout << endl << "the two 0's at the end are the grand children in the " << endl
		<< endl;


	// 2c. showVariant() till seqExtract
	cout << "Calling showVariant() for each object until it requires a parameter"
		<< endl << "on INACTIVE STATE.";
	for (int i = 0; i < EXTRACT_START; i++)
		cout << collectionA[i]->showVariant() << endl;
	cout << endl << endl;

	// 2d. showVariant(string) for seqExtract
	cout << "Calling showVariant(string) for the seqExtract objects in the HetCol"
		<< endl << "on INACTIVE STATE.";
	j = 0;
	for (int i = EXTRACT_START; i < EXTRACT_STOP; i++) {
		cout << collectionA[i]->showVariant(CLUE[j]) << endl;
		j++;
	}
	cout << endl << endl << endl;

	// 2e. deletion
	for(int i = 0; i < SIZE_A; i++)
	  delete collectionA[i];
	
	// B. Collection of seqExtract
	cout << "Initializing Collection B of " << SIZE_B << "seqExtract objects" << endl;
	seqExtract* CollectionB[SIZE_B];

	// Construction
	cout << "encapsulating the first two word in the bank" << endl;
	for (int i = 0; i < SIZE_B; i++) {
	  CollectionB[i] = new seqExtract(bank[i]);
	  cout << bank[i] << endl;
	}
	cout << endl << endl;

	// b1a. checktState()
	cout << "checking the state of objects, 1 for active/0 for inactive:" << endl;
	for (int i = 0; i < SIZE_B; i++)
		cout << CollectionB[i]->checkState();
	cout << endl << endl;

	// b1b. checkGuess(wrongGuess)
	cout << "checking false guess result (1/0)" << endl;
	for (int i = 0; i < SIZE_B; i++)
		cout << CollectionB[i]->checkGuess(WRONG_GUESS);
	cout << endl << endl;

	// b1b. checkGuess(correctGuess)
	cout << "checking correct guess result (1/0)" << endl;
	for (int i = 0; i < SIZE_B; i++)
		cout << CollectionB[i]->checkGuess(bank[i]);
	cout << endl << endl;

	// b1c. showVariant()
	cout << "checking showVariant() with CLUE2" << endl;
	for (int i = 0; i < SIZE_B; i++)
		cout << CollectionB[i]->showVariant(CLUE2[i]) << endl;
	cout << endl << endl;

	// b2a. Test INACTIVE state
	cout << "Now testing the same functionalities in the INACTIVE STATE" << endl;
	cout << "Below are the func test in INACTIVE state for this object." << endl;
	for (int i = 0; i < SIZE_B; i++)
		CollectionB[i]->activeSwitch(false);
	cout << endl << endl;

	// b2a. checktState()
	cout << "checking the state of objects, 1 for active/0 for inactive:" << endl;
	for (int i = 0; i < SIZE_B; i++)
		cout << CollectionB[i]->checkState();
	cout << endl << endl;

	// b2b. checkGuess(correctGuess)
	cout << "checking correct guess result (1/0)" << endl;
	for (int i = 0; i < SIZE_B; i++)
		cout << CollectionB[i]->checkGuess(bank[i]);
	cout << endl << endl;

	// b2c. showVariant()
	cout << "checking showVariant() with CLUE2" << endl;
	for (int i = 0; i < SIZE_B; i++)
		cout << CollectionB[i]->showVariant(CLUE2[i]) << endl;
	cout << endl << endl;

	// b2d. deletion
	for(int i = 0; i < SIZE_B; i++)
	  delete CollectionB[i];

	// C. Collection of spasEnum
	cout << "Initializing Collection C of " << SIZE_C << "spasEnum objects" << endl;
	spasEnum* CollectionC[SIZE_C];

	// Construction
	cout << "encapsulating the first two word in the bank" << endl;
	int w = 0;
	string ansC[SIZE_C];
	for (int i = 0; i < SIZE_C; i++) {
		w = rand() % BANK_SIZE;
		CollectionC[i] = new spasEnum(bank[w]);
		ansC[i] = bank[w];
		cout << bank[w] << endl;
	}
	cout << endl << endl;

	// c1a. checktState()
	cout << "checking the state of objects, 1 for active/0 for inactive:" << endl;
	for (int i = 0; i < SIZE_C; i++)
		cout << CollectionC[i]->checkState();
	cout << endl << endl;

	// c1b. checkGuess(wrongGuess)
	cout << "checking false guess result (1/0)" << endl;
	for (int i = 0; i < SIZE_C; i++)
		cout << CollectionC[i]->checkGuess(WRONG_GUESS);
	cout << endl << endl;

	// c1b. checkGuess(correctGuess)
	cout << "checking correct guess result (1/0)" << endl;
	for (int i = 0; i < SIZE_C; i++)
		cout << CollectionC[i]->checkGuess(ansC[i]);
	cout << endl << endl;

	// c1c. showVariant()
	cout << "checking showVariant()" << endl;
	for (int i = 0; i < SIZE_C; i++)
		cout << CollectionC[i]->showVariant() << endl;
	cout << endl << endl;

	// c2a. Test INACTIVE state
	cout << "Now testing the same functionalities in the INACTIVE STATE" << endl;
	cout << "Below are the func test in INACTIVE state for this object." << endl;
	for (int i = 0; i < SIZE_C; i++)
		CollectionC[i]->activeSwitch(false);
	cout << endl << endl;

	// c2a. checktState()
	cout << "checking the state of objects, 1 for active/0 for inactive:" << endl;
	for (int i = 0; i < SIZE_C; i++)
		cout << CollectionC[i]->checkState();
	cout << endl << endl;

	// c2b. checkGuess(correctGuess)
	cout << "checking correct guess result (1/0)" << endl;
	for (int i = 0; i < SIZE_C; i++)
		cout << CollectionC[i]->checkGuess(bank[i]);
	cout << endl << endl;

	// c2c. showVariant()
	cout << "checking showVariant()" << endl;
	for (int i = 0; i < SIZE_C; i++)
		cout << CollectionC[i]->showVariant() << endl;
	cout << endl;

	cout << "That's it for the the testings for the sequenceEnum hierarchy."
		<< endl;

	// c2d. deletion
	for (int i = 0; i < SIZE_C; i++)
	  delete CollectionC[i];
	
	// D. The inverter hierarchy
	// d1. Construction
	cout << "Now testing the inverter class hierarchy, constructing with " << endl
		<< "random integer input, and four random words from bank" << endl;
	inverter* CollectionD[SIZE_D];
	int invPos = 0,
		k = 0;
	for (int i = 0; i < SIZE_D; i++) {
		invPos = rand() % MAX_INVPOS;
		k = rand() % BANK_SIZE;
		CollectionD[i] = new inverter(invPos, bank[k]);
	}
	cout << endl << endl;

	// d1a. checkState()
	cout << "Now checking all state for CollectionD (1/0)" << endl;
	for (int i = 0; i < SIZE_D; i++) {
		cout << CollectionD[i]->checkState();
	}
	cout << endl << endl;

	// d1b. swapIt()
	cout << "Now testing swapIt() for CollectionD" << endl;
	for (int i = 0; i < SIZE_D; i++) {
		cout << CollectionD[i]->swapIt() << endl;
	}
	cout << endl << endl;

	// d1c. stateSwitch(false)
	cout << "Now changing the state of CollectionD to INACTIVE" << endl;
	for (int i = 0; i < SIZE_D; i++) {
		CollectionD[i]->stateSwitch(false);
	}
	cout << endl << endl;

	// d2a. checkState()
	cout << "Now checking the state of CollectionD again (1/0)" << endl;
	for (int i = 0; i < SIZE_D; i++) {
		cout << CollectionD[i]->checkState();
	}
	cout << endl << endl;

	// d2b. swapIt()
	cout << "Now testing swapIt() in INACTIVE state" << endl;
	for (int i = 0; i < SIZE_D; i++) {
		cout << CollectionD[i]->swapIt() << endl;
	}
	cout << endl << endl;

	// d2c. deletion
	for(int i = 0; i < SIZE_D; i++)
	  delete CollectionD[i];

	// E. inVSeq class
	// eA1. constructor
	cout << "Now testing Collection E for inVSeq" << endl;
	inVSeq* CollectionE[SIZE_E];
	string seqAns[SIZE_E];
	cout << "Constructing with two random number, a random word,"
		 << "and a picked word for "
		 << "invertSE from the bank" << endl;
	k = rand() % BANK_SIZE;
	w = rand() % MAX_INVPOS;
	CollectionE[0] = new inVSeq(w, bank[k]);
	seqAns[0] = bank[k];
	
	k = rand() % MAX_INVPOS;
	CollectionE[VSEQ_STOP] = new inVSeq(k, bank[PICKED_NUM]);
	seqAns[VSEQ_STOP] = bank[PICKED_NUM];
	cout << endl << endl;
		
	// eA2. stateCheck()
	cout << "Testing stateCheck() for CollectionE (1/0)" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->checkState();
	}
	cout << endl << endl;

	// eA3. checkGuess() wrong & correct
	cout << "Testing false guesses for CollectionE (1/0)" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->checkGuess(WRONG_GUESS);
	}
	cout << endl << endl;
	cout << "Testing correct guesses for CollectionE (1/0)" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->checkGuess(seqAns[i]);
	}
	cout << endl << endl;

	// eA4. swapIt()
	cout << "Testing swapIt() for CollectionE" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->swapIt() << endl;
	}
	cout << endl << endl;

	// eA5. showVariant()
	cout << "Testing showVariant() for CollectionE" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->showVariant() << endl;
	}
	cout << endl << endl;

	// eA6. invertSQ() and invertSP() on CollectionE[0]
	cout << "Testing invertSQ() on CollectionE[0]" << endl;
	cout << CollectionE[0]->invertSQ() << endl;
	cout << "Testing invertSP() on CollectionE[0]" << endl;
	cout << CollectionE[0]->invertSP() << endl;

	// eA7. invertSE() on CollectionE[SIZE_E]
	cout << "Testing invertSE() on CollectionE[SIZE_E] with CLUE_5" << endl;
	cout << CollectionE[VSEQ_STOP]->invertSE(CLUE_5) << endl;

	// eA8. stateSwitch() on CollectionE
	cout << "Switching the state to false and test the function again."
		 << endl;
	for (int i = 0; i < SIZE_E; i++)
		CollectionE[i]->stateSwitch(false);
	cout << endl << endl;

	// eB2. stateCheck()
	cout << "Testing stateCheck() for CollectionE (1/0)" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->checkState();
	}
	cout << endl << endl;

	// eB3. checkGuess() wrong & correct
	cout << "Testing false guesses for CollectionE (1/0)" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->checkGuess(WRONG_GUESS);
	}
	cout << endl << endl;
	cout << "Testing correct guesses for CollectionE (1/0)" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->checkGuess(seqAns[i]);
	}
	cout << endl << endl;

	// eB4. swapIt()
	cout << "Testing swapIt() for CollectionE" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->swapIt() << endl;
	}
	cout << endl << endl;

	// eB5. showVariant()
	cout << "Testing showVariant() for CollectionE" << endl;
	for (int i = 0; i < SIZE_E; i++) {
		cout << CollectionE[i]->showVariant() << endl;
	}
	cout << endl << endl;

	// eB6. invertSQ() and invertSP() on CollectionE[0]
	cout << "Testing invertSQ() on CollectionE[0]" << endl;
	cout << CollectionE[0]->invertSQ() << endl;
	cout << "Testing invertSP() on CollectionE[0]" << endl;
	cout << CollectionE[0]->invertSP() << endl;

	// eB7. invertSE() on CollectionE[SIZE_E]
	cout << "Testing invertSE() on CollectionE[SIZE_E] with CLUE_5" << endl;
	cout << CollectionE[VSEQ_STOP]->invertSE(CLUE_5) << endl << endl;

	// eB8. deletion
	for(int i = 0; i < SIZE_E; i++)
	  delete CollectionE[i];
	
	cout << "Thanks for Testing the Program, Have a nice day." << endl;
	cout << "File Made" << endl;
	cin.ignore();
}
