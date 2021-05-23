#include<iostream>
using namespace std;

class node {
public:
	int key;
	node *left, *right, *parent;
	node(int data = 0)
		:left(NULL), right(NULL), key(data)
	{	}
};
