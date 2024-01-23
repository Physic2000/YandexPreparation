// https://leetcode.com/problems/binary-search/

/*
Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index.
Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>
//#include <assert.h>
using namespace std;

template<typename Type>
void Swap( Type &a, Type &b )
{
	Type tmp = a;
	a = b;
	b = tmp;
}

template<typename Type>
void SortVectorAscending( vector<Type> &v )
{
	int numOfSwaps, size;
	size = v.size();
	do{
		numOfSwaps = 0;
		for( int i = 0; i < size - 1; i++ )
			if( v[i] > v[i + 1] )
			{
				//Swap<Type>( v[i], v[i + 1] );
				Swap( v[i], v[i + 1] );				// Вызов шаблонной функции можно сделать и так, в этом случае компилятор сам выведет, т.е. определит тип Type передаваемых аргументов.
				numOfSwaps++;
			}
	}while( numOfSwaps > 0 );
}

class Solution {
public:
	// An iterative binary search function.
	// Вектор nums должен быть отсортирован по возрастанию.
    static int search( vector<int>& nums, int target )
	{
		int size, index, start, end;
		size = nums.size();
		start = 0;
		end = size - 1;
		while( start <= end )
		{
			index = start + ( end - start ) / 2;
			if( nums[index] == target ) return index;
			if( nums[index] < target ) start = index + 1;
			else end = index - 1;
		}
		return -1;
    }

	// A recursive binary search function.
	// Вектор nums должен быть отсортирован по возрастанию.
	static int search( vector<int>& nums, int start, int end, int target )
	{
		int index;
		while( start <= end )
		{
			index = start + ( end - start ) / 2;
			if( nums[index] == target ) return index;
			if( nums[index] < target ) return search( nums, index + 1, end, target );
			else return search( nums, start, index - 1, target );
		}
		return -1;
    }
};

int main( void )
{
	vector<int> arr;
	int size, target;
	size = 11;
	for( int i = 0; i < size; i++ )
		arr.push_back( ( size - 1 - i ) * 100 );
	for( int i = 0; i < size; i++ )
		cout << arr[i] << ", ";
	cout << endl;

	SortVectorAscending( arr );

	for( int i = 0; i < size; i++ )
		cout << arr.at( i ) << ", ";
	cout << endl << endl;

	cout << "An iterative binary search function:" << endl;
	for( int i = 0; i < size; i++ )
	{
		target = arr[i];
		cout << "target = " << target << ",  index = " << Solution::search( arr, target ) << endl;
	}
	target = 1100;
	cout << "target = " << target << ",  index = " << Solution::search( arr, target ) << endl;
	target = -100;
	cout << "target = " << target << ",  index = " << Solution::search( arr, target ) << endl;
	target = 450;
	cout << "target = " << target << ",  index = " << Solution::search( arr, target ) << endl << endl;

	cout << "A recursive binary search function:" << endl;
	for( int i = 0; i < size; i++ )
	{
		target = arr[i];
		cout << "target = " << target << ",  index = " << Solution::search( arr, 0, size - 1, target ) << endl;
	}
	target = 1100;
	cout << "target = " << target << ",  index = " << Solution::search( arr, 0, size - 1, target ) << endl;
	target = -100;
	cout << "target = " << target << ",  index = " << Solution::search( arr, 0, size - 1, target ) << endl;
	target = 450;
	cout << "target = " << target << ",  index = " << Solution::search( arr, 0, size - 1, target ) << endl << endl;
	
	cout << endl << endl;
	return 0;
}