#include "BSTreeInt.h"

bool BSTreeInt::insert(int k)
{
	#ifdef AUCA_DEBUG
	path.clear();
	#endif
	
	if (root == nullptr)
	{
		root = new Node(k, nullptr, nullptr);
		++counter;
		return true;
	}

	bool isLeft = false;
	Node* prev = nullptr;
	Node* curr = root;
	
	while (curr)
	{
		if (curr->data < k)
		{
			#ifdef AUCA_DEBUG
			path += "R";
			#endif
			
			isLeft = false;
			prev = curr;
			curr = curr->right;
		}
		else if (curr->data > k)
		{
			#ifdef AUCA_DEBUG
			path += "L";
			#endif
			
			isLeft = true;
			prev = curr;
			curr = curr->left;
		} 
		else {
			return false;
		}
	}
		
	Node* t = new Node(k, nullptr, nullptr);

	if (isLeft)
	{
		prev->left = t;
	} 
	else {
		prev->right = t;
	}
		
	++counter;
		
	return true;
}