// Node.cpp
// tom bailey   1050  31 jan 2011
// Definitions of the Node class methods
// MODIFIED: by rafe cooley 11/13/2017
//Sasha Stramel
//22 April 2018
//Cosc 2030

#include "stdafx.h"
#include <string>
#include "Node.h"
using namespace std;
using std::cout;
using std::endl;

Node::Node(string entry)
	: entry_(entry), next_(NULL)
{
	cout << "Node( " << entry_ << ", " << next_ << " ) created at " << this << endl;
}

Node::Node(string entry, Node * next)
	: entry_(entry), next_(next)
{
	cout << "Node( " << entry_ << ", " << next_ << " ) created at " << this << endl;
}

Node::~Node()
{
	cout << "Node( " << entry_ << ", " << next_ << " ) at " << this << " destroyed" << endl;
}
