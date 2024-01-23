// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).
Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed).
For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].
Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.
You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

Follow up: This problem is similar to Search in Rotated Sorted Array, but nums may contain duplicates. Would this affect the runtime complexity? How and why?
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <assert.h>
using namespace std;

class Solution {
public:
    static bool search( vector<int>& nums, int target )
	{
        int pivot, size, requiredIndex;
		size = nums.size();
		pivot = searchPivot( nums );
		if( pivot == -1 ) 
		{
			requiredIndex = search( nums, 0, size - 1, target);
			if( requiredIndex != -1 ) return true;
		}
		else
		{
			requiredIndex = search( nums, 0, pivot, target );
			if( requiredIndex != -1 ) return true;
			requiredIndex = search( nums, pivot + 1, size - 1, target );
			if( requiredIndex != -1 ) return true;
			return false;
		}
    }

	// Вектор nums в диапазоне индексов от start до end должен быть отсортирован по возрастанию.
	static int search( vector<int>& nums, int start, int end, int target )
	{
		int size, index;
		size = nums.size();
		assert( end < size );
		assert( start >= 0 );
		while( start <= end )
		{
			index = start + ( end - start ) / 2;
			if( nums[index] == target ) return index;
			if( nums[index] < target ) start = index + 1;
			else end = index - 1;
		}
		return -1;
    }
	
	// An iterative algorithm:
	static int searchPivot( vector<int>& nums )
	{
        int size, index, start, end;
		size = nums.size();
		start = 0;
		end = size - 1;
		while( start <= end && start < size - 1 )
		{
			index = start + ( end - start ) / 2;
			if( nums[index] > nums[index + 1] ) return index;
			if( nums[start] > nums[index] ) end = index - 1;
			else start = index + 1;
//			if( nums[start] < nums[index] ) start = index + 1;
//			else end = index - 1;
		}
		return -1; // Это значит, что отсортированный массив в возрастающем порядке не подвергался вращениям.
    }

	// A recursive algorithm:
	static int searchPivot( vector<int>& nums, int start, int end )
	{
        int size, index;
		size = nums.size();
		while( start <= end && start < size - 1 )
		{
			index = start + ( end - start ) / 2;
			if( nums[index] > nums[index + 1] ) return index;
			if( nums[start] > nums[index] ) return searchPivot( nums, start, index - 1 );
			else return searchPivot( nums, index + 1, end );
		}
		return -1; // Это значит, что отсортированный массив в возрастающем порядке не подвергался вращениям.
    }
};

void RotateVectorLeft( vector<int>& v, int k )
{
	if( k == 0 ) return;
	int size = v.size();
	assert( 0 <= k && k < size );
	vector<int>::iterator it_start;

	it_start = v.begin();
	for( int i = k; i < size; i++ )
	{
		v.insert( it_start, v[size - 1] );
		v.pop_back();
	}
}

int main( void )
{
	setlocale( LC_ALL, "Russian" ); // В консоль можно выводить русские буквы.

	vector<int> arr;
	arr.push_back( 0 );
	arr.push_back( 1 );
	arr.push_back( 2 );
	arr.push_back( 4 );
	arr.push_back( 4 );
	arr.push_back( 4 );
	arr.push_back( 5 );
	arr.push_back( 6 );
	arr.push_back( 6 );
	arr.push_back( 7 );
	int size, k, pivot, target;
	bool targetIsExists;
	size = arr.size();
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << "}" << endl;

//	k = 1;
//	k = 3;
//	k = 4;
	k = size - 1;
	RotateVectorLeft( arr, k );

	cout << "Массив arr после его вращения влево для k = " << k << endl;
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << "}";
	pivot = Solution::searchPivot( arr );
	cout << "  pivot = " << pivot << endl << endl;

	for( target = -1; target <= 8; target++ )
		cout << "target = " << target << ",\ttargetIsExists = " << Solution::search( arr, target ) << endl;

	cout << endl;
	return 0;
}