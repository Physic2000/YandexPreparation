// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

/*
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

    [4,5,6,7,0,1,2] if it was rotated 4 times.
    [0,1,2,4,5,6,7] if it was rotated 7 times.

Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
Given the sorted rotated array nums of unique elements, return the minimum element of this array.
You must write an algorithm that runs in O(log n) time.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <assert.h>
using namespace std;

class Solution {
public:
	static int findMin( vector<int>& nums )
	{
		int min, size, pivot;
		size = nums.size();
		pivot = searchPivot( nums, 0, size - 1 );
		if( pivot != -1 ) return nums[pivot + 1];
		return nums[0];
    }

	static int findMax( vector<int>& nums )
	{
		int min, size, pivot;
		size = nums.size();
		pivot = searchPivot( nums, 0, size - 1 );
		if( pivot != -1 ) return nums[pivot];
		return nums[size - 1];
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
//			if( nums[start] > nums[index] ) end = index - 1;
//			else start = index + 1;
			if( nums[start] < nums[index] ) start = index + 1;
			else end = index - 1;
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
	arr.push_back( 5 );
	arr.push_back( 6 );
	arr.push_back( 7 );
	int size, k, pivot, min, max;
	size = arr.size();
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << "}";
	pivot = Solution::searchPivot( arr, 0, size - 1 );
	min = Solution::findMin( arr );
	max = Solution::findMax( arr );
	cout << "  pivot = " << pivot << endl
		<< "min = " << min << endl
		<< "max = " << max << endl;

//	k = 1;
	k = 3;
//	k = 4;
	k = size - 1;
	RotateVectorLeft( arr, k );

	cout << "Массив arr после его вращения влево для k = " << k << endl;
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << "}";
	pivot = Solution::searchPivot( arr, 0, size - 1 );
	min = Solution::findMin( arr );
	max = Solution::findMax( arr );
	cout << "  pivot = " << pivot << endl
		<< "min = " << min << endl
		<< "max = " << max << endl;

	cout << endl;
	return 0;
}