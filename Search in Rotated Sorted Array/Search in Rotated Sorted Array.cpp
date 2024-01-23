// https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <assert.h>
using namespace std;

class Solution {
public:
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

    static int search( vector<int>& nums, int target )
	{
        int pivot, size;
		size = nums.size();
		pivot = searchPivot( nums );
		if( pivot == -1 ) return search( nums, 0, size - 1, target);
		else
		{
			int requiredIndex;
			requiredIndex = search( nums, 0, pivot, target );
			if( requiredIndex != -1 ) return requiredIndex;
			return search( nums, pivot + 1, size - 1, target );
		}
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

void RotateVectorRight( vector<int>& v, int k )
{
	int size = v.size();
	if( k == size - 1 ) return;
	assert( 0 <= k && k < size );
	vector<int>::iterator it_start;

	for( int i = 0; i <= k; i++ )
	{
		v.push_back( v[0] );
		it_start = v.begin();
		v.erase( it_start );
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
	int size, k, pivot, requiredIndex, target;
	size = arr.size();
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << "}" << endl;

//	k = 1;
	k = 3;
//	k = 4;
//	k = size - 1;
	RotateVectorLeft( arr, k );

	cout << "Массив arr после его вращения влево для k = " << k << endl;
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << "}";
	pivot = Solution::searchPivot( arr );
	cout << "  pivot = " << pivot << endl;
	target = 5;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;

	RotateVectorRight( arr, pivot );

	cout << "Массив arr после его вращения вправо для k = " << pivot << endl;
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << "}";
	pivot = Solution::searchPivot( arr );
	cout << "  pivot = " << pivot << endl;
	target = 5;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = 0;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = 7;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = 3;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = -1;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = 10;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;

	k = 0;
	RotateVectorRight( arr, k );

	cout << "Массив arr после его вращения вправо для k = " << k << endl;
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << "}";
	pivot = Solution::searchPivot( arr );
	cout << "  pivot = " << pivot << endl;
	target = 5;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = 0;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = 1;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = 3;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = -1;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;
	target = 10;
	requiredIndex = Solution::search( arr, target );
	cout << "target = " << target << ",  requiredIndex = " << requiredIndex << endl;

	cout << endl << endl;
	return 0;
}