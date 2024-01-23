// https://leetcode.com/problems/add-two-numbers/

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode() : val( 0 ), next( nullptr ) {}
	ListNode( int x ) : val(x), next( nullptr )
	{
		val %= 10;
		x /= 10;
		if( x > 0 ) 
			next = new ListNode( x );
	}
	ListNode( int x, ListNode *next ) : val( x ), next( next ) {}
	int Val()
	{
		ListNode *current;
		int res, factor;
		res = 0;
		factor = 1;
		current = this;
		while( current )
		{
			res += current->val * factor;
			current = current->next;
			factor *= 10;
		}
		return res;
	}
};

class Solution 
{
public:
	static ListNode* addTwoNumbers( ListNode* l1, ListNode* l2 )
	{
		ListNode *res, *current, *c1, *c2;
		int digitTransfer, digitsSum;
		res = new ListNode;
		current = res;
		c1 = l1;
		c2 = l2;
		digitTransfer = 0;
		digitsSum = 0;
		while( c1 || c2 )
		{
			if( c1 ) digitsSum += c1->val;
			if( c2 ) digitsSum += c2->val;
			if( digitsSum > 9 )
			{
				digitsSum %= 10;
				digitTransfer = 1;
			}
			current->val = digitsSum;
			if( c1 ) c1 = c1->next;
			if( c2 ) c2 = c2->next;
			if( c1 || c2 || digitTransfer ) current->next = new ListNode( digitTransfer );
			digitsSum = digitTransfer;
			digitTransfer = 0;
			current = current->next;
		}
		return res;
    }
};

int main( void )
{
	ListNode num_1( 105 ), num_2( 7 ), num_3( 0 ), num_4( 10240 ), *res;

	cout << num_1.Val() << ": ";
	for( ListNode* current = &num_1; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;

	cout << num_2.Val() << ": ";
	for( ListNode* current = &num_2; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;

	cout << num_3.Val() << ": ";
	for( ListNode* current = &num_3; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;
	
	cout << num_4.Val() << ": ";
	for( ListNode* current = &num_4; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;

	res = Solution::addTwoNumbers( &num_1, &num_2 );
	cout << res->Val() << ": ";
	for( ListNode* current = res; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;

	res = Solution::addTwoNumbers( &num_1, &num_4 );
	cout << res->Val() << ": ";
	for( ListNode* current = res; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;

	res = Solution::addTwoNumbers( &num_1, &num_3 );
	cout << res->Val() << ": ";
	for( ListNode* current = res; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;

	res = Solution::addTwoNumbers( new ListNode( 9999 ), new ListNode( 1 ) );
	cout << res->Val() << ": ";
	for( ListNode* current = res; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;

	res = Solution::addTwoNumbers( new ListNode( 9999 ), new ListNode( 111 ) );
	cout << res->Val() << ": ";
	for( ListNode* current = res; current != nullptr; current = current->next )
		cout << current->val << "->";
	cout << endl;

	return 0;
}