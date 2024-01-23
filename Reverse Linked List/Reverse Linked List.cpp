// https://leetcode.com/problems/reverse-linked-list/

#include <iostream>
#include <assert.h>
using namespace std;


// Definition for singly-linked list.
struct ListNode 
{
     int val;
     ListNode *next;
     ListNode() : val( 0 ), next( nullptr ) {}
     ListNode( int x ) : val(x), next( nullptr ) {}
     ListNode( int x, ListNode *next ) : val( x ), next( next ) {}
};

void CopyNode( ListNode *srcNode, ListNode *copiedNode )
{
	assert( srcNode );
	assert( copiedNode );
	copiedNode->val = srcNode->val;
	copiedNode->next = srcNode->next;
}

class Solution 
{
public:
	// recursively without generation new list
	static ListNode* reverse( ListNode* current, ListNode* next )
	{
		ListNode temp;
		CopyNode( next, &temp );
		next->next = current;
		current = next;
		next = temp.next;
		if( next )
			return reverse( current, next );
		else
			return current;
	}
	/*
	// recursively with generation new list
	static ListNode* reverse( ListNode* current, ListNode* next )
	{
		ListNode *temp;
		temp = new ListNode( next->val, current );
		current = temp;
		next = next->next;
		if( next )
			return reverse( current, next );
		else
			return current;
	}
	*/

	// recursively
    static ListNode* reverseList( ListNode* head )
	{
        ListNode *current, *next;
		current = head;
		next = head->next;
		head->next = nullptr;
		if( next )
			return reverse( current, next );
		else
			return current;
    }

	// iteratively without generation new list
	static ListNode* reverseList_2( ListNode* head )
	{
        ListNode *prev, *next, temp;
		next = head->next;
		head->next = nullptr;
		prev = head;
		while( next )
		{
			CopyNode( next, &temp );
			next->next = prev;
			prev = next;
			next = temp.next;
		}
		return prev;
    }
	/*
	// iteratively with generation new list
	static ListNode* reverseList_2( ListNode* head )
	{
        ListNode *current, *next, *temp;
		current = head;
		next = head->next;
		head->next = nullptr;
		while( next )
		{
			temp = new ListNode( next->val, current );
			current = temp;
			next = next->next;
		}
		return current;
    }
	*/
};

int main( void )
{
	ListNode *l, *current, *prev;
	int numOfNodes;

	// —формируем односв€зный список:
	current = new ListNode;
	prev = current;
	numOfNodes = 100;
	for( int i = 0; i < numOfNodes; i++ )
	{
		current = new ListNode( i + 1, prev );
		prev = current;
	}
	l = current;
	cout << "Output singly linked list 'l' on the console:" << endl;
	for( ; current; current = current->next )
		cout << current->val << ", ";
	cout << endl << endl;

	l = Solution::reverseList( l );
	cout << "Output singly linked list 'l' on the console after reverse:" << endl;
	for( current = l; current; current = current->next )
		cout << current->val << ", ";
	cout << endl << endl;

	l = Solution::reverseList_2( l );
	cout << "Output singly linked list 'l' on the console after reverse:" << endl;
	for( current = l; current; current = current->next )
		cout << current->val << ", ";
	cout << endl << endl;
	
	return 0;
}