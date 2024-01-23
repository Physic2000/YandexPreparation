// https://leetcode.com/problems/two-sum/description/

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.


Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]


Constraints:

    2 <= nums.length <= 104
    -109 <= nums[i] <= 109
    -109 <= target <= 109
    Only one valid answer exists.

 
Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
*/

#include <iostream>
//#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    static vector<int> twoSum( vector<int>& nums, int target )
	{
		// создание unordered_map для хранения чисел и их индексов
		unordered_map<int, int> mp;
		for( int i = 0; i < nums.size(); i++ )
		{
			// находим число-дополнение
			int complement = target - nums[i];
			// если находим дополнение в unordered_map
			if( mp.find( complement ) != mp.end() )
			{
				vector<int> res;
				res.push_back( mp[complement] );
				res.push_back( i );
				// возвращаем его индекс и текущий индекс
				return res;
			}
			// добавляем текущее число и его индекс в unordered_map
			mp[nums[i]] = i;   
		}
		// если нет решения, выбрасываем исключение
		throw invalid_argument( "No two sum solution" );
	}
};

int main( void )
{
	vector<int> arr, v;
	int size, target;
	arr.push_back( 2 );
	arr.push_back( 7 );
	arr.push_back( 11 );
	arr.push_back( 15 );
	size = arr.size();
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
	{
		if( 0 < i && i < size )
			cout << ", ";
		cout << arr[i];
	}
	cout << "};  ";
	target = 17;
	target = 13;
//	target = 100;
	v = Solution::twoSum( arr, target );
	cout << "target = " << target << ";  v = {";
	for( int i = 0; i < v.size(); i++ )
	{
		if( 0 < i && i < size )
			cout << ", ";
		cout << v[i];
	}
	cout << "},  " << "v.size() = " << v.size();
	cout << endl;
	
	arr.clear();
	size = 10;
	cout << "arr = {";
	for( int i = 0; i < size; i++ )
	{
		arr.push_back( i );
		if( 0 < i && i < size )
			cout << ", ";
		cout << arr[i];
	}
	cout << "};  ";

	v = Solution::twoSum( arr, target );
	cout << "target = " << target << ";  v = {";
	for( int i = 0; i < v.size(); i++ )
	{
		if( 0 < i && i < size )
			cout << ", ";
		cout << v[i];
	}
	cout << "},  " << "v.size() = " << v.size();
	cout << endl << endl;

	/*
	vector<int>::iterator it;
	//arr.erase( arr.begin(), arr.end() );
	//for( auto it = arr.begin(); it != arr.end(); it++ )
	for( it = arr.begin(); it != arr.end(); it++ )
	{
		if( *it == arr[v[0]] )
			arr.erase( it );
	}
	cout << "arr = {";
	for( int i = 0; i < arr.size(); i++ )
	{
		if( 0 < i && i < size )
			cout << ", ";
		cout << arr[i];
	}
	cout << "};  ";
	*/
	
	return 0;
}