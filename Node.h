// Node.h

// tom bailey   0755  05 oct 2010
// Declare the Node class.

// Node uses public access to simplify code in the
// container classes that use Nodes.  Client access is
// controlled by the container classes.

// The constructors and destructor are verbose to facilitate
// tracking of memory leaks.

// The default constructor and assignment operator are
// declared private so they cannot be called.

// MODIFIED: by rafe cooley 11/13/2017
// change entry type to string for hashing lab

#ifndef _NODE_H_
#define _NODE_H_

#include <iostream>
using std::cout;
using std::endl;


class Node
{
public:
	string entry_;
	Node * next_;

public:
	// Constructors

	// post: this Node contains entry and a NULL pointer
	explicit Node(string entry);

	// post: this Node contains entry and next
	Node(string entry, Node * next);

	// Destructor

	~Node();

private:
	// Inaccessible standard functions
	Node();
	Node(const Node &);
	const Node & operator=(const Node &);
};

#endif
