#ifndef BSTREEINT_H
#define BSTREEINT_H

#include <string>

class BSTreeInt
{
	private:
	
		struct Node 
		{
			int data;
			Node* left;
			Node* right;
		
			Node(int aData, Node* aLeft, Node* aRight)
			: data(aData), left(aLeft), right(aRight)
			{
			}
		};
	
		Node* root;
		int counter;
		
	public:
	
		BSTreeInt()
		: root(nullptr), counter(0)
		{
		}
		
		int size() const
		{
			return counter;
		}
		
		std::string path;
		
		bool insert(int k);
};

#endif