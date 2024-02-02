// https://leetcode.com/problems/4sum/description/

/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

 
Example 1:

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:

Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]


Constraints:

    1 <= nums.length <= 200
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9
*/

// C++ program to find four  
// elements with the given sum 
#include <iostream>
#include <vector>
#include <unordered_map>
#include <assert.h>
using namespace std;

bool ValueDoesNotExistInArray( int *arr, int value );

// Definition for singly-linked list.
class ListNode 
{
public:
	int arr[4];
	ListNode *next;

	ListNode(): next( nullptr ) {};
	ListNode( int i0, int i1, int i2, int i3 ): next( nullptr )
	{  
		arr[0] = i0, arr[1] = i1, arr[2] = i2, arr[3] = i3;
	};
	ListNode* AddNext( ListNode &node, int i0, int i1, int i2, int i3 )
	{  
		ListNode* last = &node;
		assert( last->next == nullptr );
		//while( last->next != nullptr ) last = last->next;
		last->next = new ListNode( i0, i1, i2, i3 );
		return last->next;
	};
	ListNode* AddNext( int i0, int i1, int i2, int i3 )
	{  
		ListNode* last = this;
		while( last->next != nullptr ) last = last->next;
		last->next = new ListNode( i0, i1, i2, i3 );
		return last->next;
	};
//	bool ValueDoesNotExist( int value );
//	bool ValuesDoNotExist( int v0, int v1, int v2, int v3 );
	bool QuadrupletDoesNotExist( int i0, int i1, int i2, int i3 );
};
/*
bool ListNode::ValueDoesNotExist( int value )
{
	bool res = true;
	ListNode *current = this;
	do{
		if( value == current->arr[0] || value == current->arr[1] || value == current->arr[2] || value == current->arr[3] )
			return false;
		current = current->next;
	} while( current != nullptr );
	return res;
}

bool ListNode::ValuesDoNotExist( int v0, int v1, int v2, int v3 )
{
	bool res = true;
	ListNode *current = this;
	do{
		if( v0 == current->arr[0] || v0 == current->arr[1] || v0 == current->arr[2] || v0 == current->arr[3] ||
			v1 == current->arr[0] || v1 == current->arr[1] || v1 == current->arr[2] || v1 == current->arr[3] ||
			v2 == current->arr[0] || v2 == current->arr[1] || v2 == current->arr[2] || v2 == current->arr[3] ||
			v3 == current->arr[0] || v3 == current->arr[1] || v3 == current->arr[2] || v3 == current->arr[3] )
			return false;
		current = current->next;
	} while( current != nullptr );
	return res;
}
*/
bool ListNode::QuadrupletDoesNotExist( int v0, int v1, int v2, int v3 )
{
//	return true; // Если раскомментировать эту строку, то добавленный фильтр окажется отключённым и сгенерированные четвёрки начнут повторяться.
	ListNode *current = this;
	do{
		if( !ValueDoesNotExistInArray( current->arr, v0 ) && !ValueDoesNotExistInArray( current->arr, v1 ) && !ValueDoesNotExistInArray( current->arr, v2 ) && !ValueDoesNotExistInArray( current->arr, v3 ) )
			return false;
		current = current->next;
	} while( current != nullptr );
	return true;
}

bool ValueDoesNotExistInArray( int *arr, int value )
{
	bool res = true;
	if( arr == nullptr )
		return true;
	for( int i = 0; i < 4; i++ )
		if( value == arr[i] )
			return false;
	return res;
}

// The function finds four
// elements with given sum target
vector<vector<int>> fourSum( vector<int>& nums, int target )
{
    // Store sums of all pairs
    // in a hash table
	int n = nums.size();
    unordered_map<int, pair<int, int> > mp;
	vector<vector<int>> res;
	ListNode listOfQuadruplets, *currentQuadruplet = nullptr;

    for ( int i = 0; i < n - 1; i++ )
        for ( int j = i + 1; j < n; j++ )
		{
			pair<int, int> p( i, j );
            //mp[nums[i] + nums[j]] = { i, j };
			mp[nums[i] + nums[j]] = p;
		}
 
    // Traverse through all pairs and search
    // for target - (current pair sum).
    for ( int i = 0; i < n - 1; i++ )
	{
        for ( int j = i + 1; j < n; j++ )
		{
            int sum = nums[i] + nums[j];
 
            // If target - sum is present in hash table,
            if ( mp.find( target - sum ) != mp.end() )
			{
                // Making sure that all elements are
                // distinct array elements and an element
                // is not considered more than once.
                pair<int, int> p = mp[target - sum];
                if ( p.first != i && p.first != j && p.second != i && p.second != j )
				{
					/*
                    cout << nums[i] << ", " << nums[j] << ", "
                         << nums[p.first] << ", "
                         << nums[p.second];
					cout << endl;
                    //return;
					*/
					if( listOfQuadruplets.QuadrupletDoesNotExist( i, j, p.first, p.second ) )
					{
						vector<int> q;
						q.push_back( nums[i] ),
						q.push_back( nums[j] ),
						q.push_back( nums[p.first] ),
						q.push_back( nums[p.second] ),
						res.push_back( q );
						if( currentQuadruplet ) 
							currentQuadruplet = listOfQuadruplets.AddNext( *currentQuadruplet, i, j, p.first, p.second );
						else
							currentQuadruplet = listOfQuadruplets.AddNext( i, j, p.first, p.second );

						//listOfQuadruplets.AddNext( i, j, p.first, p.second );
					}
                }
            }
        }
    }

	return res;
}
 
// Driver code
int main()
{
    //int arr[] = { 10, 20, 30, 40, 1, 2 };
	vector<int> arr;
	vector<vector<int>> v;
    int target;

	arr.push_back( 10 );
	arr.push_back( 20 );
	arr.push_back( 30 );
	arr.push_back( 40 );
	arr.push_back( 1 );
	arr.push_back( 2 );
	//target = 91;
	target = 1;

	cout << "arr = {";
	for( int i = 0; i < arr.size(); i++ )
	{
		if( 0 < i && i < arr.size() )
			cout << ", ";
		cout << arr[i];
	}
	cout << "};  target = " << target << ":" << endl;
    
    // Function call
    v = fourSum( arr, target );

	cout << "v = {";
	for( int i = 0; i < v.size(); i++ )
	{
		cout << "{";
		for( int j = 0; j < v[0].size(); j++ )
		{
			if( 0 < j && j < v[0].size() )
				cout << ", ";
			cout << v[i][j];
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;
	target = 91;
	v = fourSum( arr, target );

	cout << "target = " << target << ":" << endl
		<< "v = {";
	for( int i = 0; i < v.size(); i++ )
	{
		cout << "{";
		for( int j = 0; j < v[0].size(); j++ )
		{
			if( 0 < j && j < v[0].size() )
				cout << ", ";
			cout << v[i][j];
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;

	arr.erase( arr.begin(), arr.end() );
	arr.push_back( 1 );
	arr.push_back( 0 );
	arr.push_back( -1 );
	arr.push_back( 0 );
	arr.push_back( -2 );
	arr.push_back( 2 );
	target = 0;

	cout << endl;
	// Function call
    v = fourSum( arr, target );

	cout << "arr = {";
	for( int i = 0; i < arr.size(); i++ )
	{
		if( 0 < i && i < arr.size() )
			cout << ", ";
		cout << arr[i];
	}
	cout << "};  target = " << target << ":" << endl;
	cout << "v = {";
	for( int i = 0; i < v.size(); i++ )
	{
		cout << "{";
		for( int j = 0; j < v[0].size(); j++ )
		{
			if( 0 < j && j < v[0].size() )
				cout << ", ";
			cout << v[i][j];
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;

	arr.clear();
	arr.push_back( 2 );
	arr.push_back( 2 );
	arr.push_back( 2 );
	arr.push_back( 2 );
	arr.push_back( 2 );
	target = 8;

	cout << endl;
	// Function call
    v = fourSum( arr, target );

	cout << "arr = {";
	for( int i = 0; i < arr.size(); i++ )
	{
		if( 0 < i && i < arr.size() )
			cout << ", ";
		cout << arr[i];
	}
	cout << "};  target = " << target << ":" << endl;
	cout << "v = {";
	for( int i = 0; i < v.size(); i++ )
	{
		cout << "{";
		for( int j = 0; j < v[0].size(); j++ )
		{
			if( 0 < j && j < v[0].size() )
				cout << ", ";
			cout << v[i][j];
		}
		cout << "}" << endl;
	}
	cout << "}" << endl;

	cout << endl;
	char tempStr[2];
	cout << "Press any key and [Enter] ";
	cin >> tempStr;

    return 0;
}