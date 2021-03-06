////
//  main.cpp
//  Hash
//
//  Created by Sasha Stramel on 4/18/18.
//  Copyright Â© 2018 Sasha Stramel. All rights reserved.
//
//Sasha Stramel
//22 April 2018
//Cosc 2030

//#include <stdio.h>
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <functional>
#include "HashTables.h"
#include "GeneralHashFunctions.h"


using namespace std;

//TODO
// read in the two test files (names.txt, randoWords.txt) line by line
// lab1 code comes in handy here

//TODO
//use the STL hash as the hashing function to test your HashTable functionality

//TODO
//use the WeakHash() from GeneralHashFunctions as the hashing function to test your HashTable functionality

//TODO
// now using the same testing methods, pick 2 hashing functions from the included open source library "GeneralHashFunctions"

//TODO
// you will test your HashTable functions using one HashTable per file, per hashing function
// so you should have 2Files*4Hashers = 8 HashTable objects
// each HashTable object contains two different unordered maps for storage using different collision resistance methods
// you will use the addToTables() method once to add one entry into both tables
// you will edit the individual add-to-tables functions to add the appropriate functionality

typedef unsigned int unint;

using namespace std;
int main()
{
	ifstream inputFile;
	string fileName;
	string currentLine;
	HashTables standardTable = HashTables();
	HashTables weakTable = HashTables();
	HashTables BPTable = HashTables();
	HashTables FNVTable = HashTables();

	cout << "Please enter a file name: ";
	getline(cin, fileName);
	inputFile.open(fileName);

	// Continue to ask for a new file name until the file does not fail to open.
	if (inputFile.fail())
	{
		cout << "Error try again \n";
		inputFile.ignore();
		inputFile.clear();
	}
	else
	{
		while (!inputFile.eof() && !inputFile.fail())
		{
			inputFile >> currentLine;
			std::hash<string> standardHash;
			standardTable.addToTables(standardHash(currentLine), currentLine);
			weakTable.addToTables(WeakHash(currentLine), currentLine);
			BPTable.addToTables(BPHash(currentLine), currentLine);
			FNVTable.addToTables(FNVHash(currentLine), currentLine);
		}

		standardTable.PrintTables();
		standardTable.CollisionReport();

	/*	weakTable.PrintTables();
		weakTable.CollisionReport();*/

		/*BPTable.PrintTables();
		BPTable.CollisionReport();*/

		/*FNVTable.PrintTables();
		FNVTable.CollisionReport();*/
	}

	inputFile.close();
	return 0;


//	/*
//	**************************************************************************
//	*                                                                        *
//	*           General Purpose Hash Function Algorithms Test                *
//	*                                                                        *
//	* Author: Arash Partow - 2002                                            *
//	* URL: http://www.partow.net                                             *
//	* URL: http://www.partow.net/programming/hashfunctions/index.html        *
//	*                                                                        *
//	* Copyright notice:                                                      *
//	* Free use of the General Purpose Hash Function Algorithms Library is    *
//	* permitted under the guidelines and in accordance with the MIT License. *
//	* http://www.opensource.org/licenses/MIT                                 *
//	*                                                                        *
//	**************************************************************************
//	*/
//
//
//#include <iostream>
//#include <string>
//
//#include "GeneralHashFunctions.cpp"
//
//	int main(int argc, char* argv[])
//	{
//		const std::string key = "abcdefghijklmnopqrstuvwxyz1234567890";
//
//		std::cout << "General Purpose Hash Function Algorithms Test" << std::endl;
//		std::cout << "By Arash Partow - 2002        " << std::endl;
//		std::cout << "Key: " << key << std::endl;
//		std::cout << " 1. RS-Hash Function Value:   " << RSHash(key) << std::endl;
//		std::cout << " 2. JS-Hash Function Value:   " << JSHash(key) << std::endl;
//		std::cout << " 3. PJW-Hash Function Value:  " << PJWHash(key) << std::endl;
//		std::cout << " 4. ELF-Hash Function Value:  " << ELFHash(key) << std::endl;
//		std::cout << " 5. BKDR-Hash Function Value: " << BKDRHash(key) << std::endl;
//		std::cout << " 6. SDBM-Hash Function Value: " << SDBMHash(key) << std::endl;
//		std::cout << " 7. DJB-Hash Function Value:  " << DJBHash(key) << std::endl;
//		std::cout << " 8. DEK-Hash Function Value:  " << DEKHash(key) << std::endl;
//		std::cout << " 9. FNV-Hash Function Value:  " << FNVHash(key) << std::endl;
//		std::cout << "10. BP-Hash Function Value:   " << BPHash(key) << std::endl;
//		std::cout << "11. AP-Hash Function Value:   " << APHash(key) << std::endl;
//
//		return 1;
//	}

}


