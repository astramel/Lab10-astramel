//Created: Rafe Cooley 11/13/2017
// HashTable Class main file
// - this class will keep track of two different hash tables each using a different type of collision avoidance method
// includes Dr. Tom Bailey's LinkedList & Node implementations
// - modified Node for typeof(entry_)==string
//Sasha Stramel
//22 April 2018
//Cosc 2030

#include "stdafx.h"
#include "HashTables.h"

typedef unsigned int unint;

//function to simplify adding to HashTable
// only need to call this from main
// this will forward the input to the different tables
void HashTables::addToTables(unint inputHash, std::string text) {
	addToOpenAddress(inputHash, text);
	addToChaining(inputHash, text);
}

//TODO
// finish this function to add an element to the open addressing table
// this table tries to insert collisions in next position
// remember to count number of collisions
// if a collision occurs,
// - edit collision boolean for current location
// - increment inputHash
// - and recurse to next spot
// else add new openBucket to position
void HashTables::addToOpenAddress(unint inputHash, std::string text)
{
	// Search through the unordered map to look for the inputHash index.
	auto search = openAddressTable.find(inputHash);

	// If the inputHash index is found, edit collision boolean, increment inputHash, and recurse.
	// Otherwise add the new bucket.
	if (search != openAddressTable.end())
	{
		openAddressTable.at(inputHash).collision = true;
		inputHash++;
		addToOpenAddress(inputHash, text);
		openCollisions++;
	}
	else
	{
		openBucket addedBucket = openBucket();
		addedBucket.entry_ = text;
		openAddressTable[inputHash] = addedBucket;
	}
}

//TODO
// finish this function to add an element to the separate chaining table
// this tables tracks collisions with linked lists
// if a collision occurs,
// - edit collision boolean for current location
// - add to linked list
// else add new chainBucket to position
void HashTables::addToChaining(unint inputHash, std::string text)
{
	// Search through the unordered map to look for the inputHash index.
	auto search = chainingTable.find(inputHash);

	// If the inputHash index is found, edit collision boolean and add to linked list.
	// Otherwise add the new bucket.
	if (search != chainingTable.end())
	{
		chainingTable.at(inputHash).collision = true;
		chainingTable.at(inputHash).bucketList->insertAsLast(text);
		chainedCollisions++;
	}
	else
	{
		chainBucket addedBucket = chainBucket();
		addedBucket.bucketList = new List();
		addedBucket.bucketList->insertAsLast(text);
		chainingTable[inputHash] = addedBucket;
	}
}

// prints a collision report
void HashTables::CollisionReport() {
	cout << "--------- Collision Report  ---------" << endl;
	cout << ">Open Addressing Table has   [" << openCollisions << "] collisions" << endl;
	cout << ">Separate Chaining Table has [" << chainedCollisions << "] collisions" << endl;
	cout << "-----------  End Report  ------------" << endl << endl;
}

// print open address table
void HashTables::PrintOpenTable() {
	cout << "--------- Print Open Table  ---------" << endl;
	std::cout << "Key:[**HASHVAL**] Bucket:[<**COLLISION?**> **ENTRY**]\n";
	for (const auto& n : openAddressTable) {
		std::cout << "Key:[" << n.first << "] Bucket:[<" << n.second.collision << "> " << n.second.entry_ << "]\n";
	}
}

// print separate chaining table
void HashTables::PrintChainTable() {
	cout << "--------- Print Chain Table  ---------" << endl;
	std::cout << "Key:[**HASHVAL**] Bucket:[<**COLLISION?**>]\n";
	std::cout << ">>**LinkedList**\n";
	for (const auto& n : chainingTable) {
		std::cout << "Key:[" << n.first << "] Bucket:[<" << n.second.collision << ">]\n";
		std::cout << ">>" << *n.second.bucketList << "\n";
	}
}

// print out tables
void HashTables::PrintTables() {
	PrintOpenTable();
	PrintChainTable();
}

