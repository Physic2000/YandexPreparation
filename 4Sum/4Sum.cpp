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
using namespace std;

 
// The function finds four
// elements with given sum target
vector<vector<int>> fourSum( vector<int>& nums, int target )
{
    // Store sums of all pairs
    // in a hash table
	int n = nums.size();
    unordered_map<int, pair<int, int> > mp;
	vector<vector<int>> res;
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
					vector<int> q;
					q.push_back( nums[i] ),
					q.push_back( nums[j] ),
					q.push_back( nums[p.first] ),
					q.push_back( nums[p.second] ),
					res.push_back( q );
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
	target = 91;
	target = 1;
    
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
    return 0;
}