// https://leetcode.com/problems/linked-list-cycle/

#include <iostream>
#include <assert.h>
using namespace std;

class Solution;

// Definition for singly-linked list.
struct ListNode 
{
private:
	int pos;
public:
	int val;
	ListNode *next;
	ListNode( int x ) : val( x ), next( nullptr ), pos( 0 ) {};
	ListNode* addNext( ListNode &node, int x )
	{  
		ListNode* last = &node;
		while( last->next != nullptr ) last = last->next;
		last->next = new ListNode( x );
		last->next->pos = last->pos + 1;
		return last->next;
	};
	friend Solution; //указываем, что структура ListNode дружественна для класса Solution.
};

class Solution 
{
public:
    static bool hasCycle( ListNode *head ) 
	{
		assert( head->pos == 0 );
		ListNode *current = head;
		while( current->next != nullptr && current->pos < current->next->pos )
			current = current->next;
		if( current->next == nullptr ) return false;
		else return true;
    }
};

int main( void )
{
	Solution solution;
	ListNode example_1( 3 ), *current, *specialNode;
	current = &example_1;
	specialNode = current = example_1.addNext( *current, 2 );
	current = example_1.addNext( *current, 0 );
	current = example_1.addNext( *current, -4 );
	current->next = specialNode;

	ListNode example_2( 1 );
	current = &example_2;
	current = current->addNext( *current, 2 );
	current->next = &example_2;

	ListNode example_3( 1 );

	int numOfNodes = 5000;
	ListNode example_4( 1 );
	current = &example_4;
	for( int i = 0; i < numOfNodes; i++ ) current = current->addNext( *current, i + 1 );

	cout << "Solution::hasCycle( &example_1 )  =  " << Solution::hasCycle( &example_1 ) << endl;
	cout << "Solution::hasCycle( &example_2 )  =  " << Solution::hasCycle( &example_2 ) << endl;
	cout << "Solution::hasCycle( &example_3 )  =  " << Solution::hasCycle( &example_3 ) << endl;
	cout << "Solution::hasCycle( &example_4 )  =  " << Solution::hasCycle( &example_4 ) << endl;

	return 0;
}