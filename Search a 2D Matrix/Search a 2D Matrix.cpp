// https://leetcode.com/problems/search-a-2d-matrix/

/*
You are given an m x n integer matrix matrix with the following two properties:

    Each row is sorted in non-decreasing order.
    The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m * n)) time complexity.
*/

#include <iostream>
#include <vector>
//#include <assert.h>
using namespace std;

class Solution {
public:
    static bool searchMatrix( vector<vector<int>>& matrix, int target )
	{
        int size, start, end, index, row, col, numOfRows, numOfCols;
		numOfRows = matrix.size();
		numOfCols = matrix[0].size();
		size = numOfRows * numOfCols;
		start = 0;
		end = size - 1;
		while( start <= end )
		{
			index = start + ( end - start ) / 2;
			row = index / numOfCols;
			col = index % numOfCols;
			if( matrix[row][col] == target ) return true;
			if( matrix[row][col] < target ) start = index + 1;
			else end = index - 1;
		}
		return false;
		
		/*
		int len = size / 2;
		index = len;
		row = index / numOfCols;
		col = index % numOfCols;
		while( matrix[row][col] != target && len != 0 )
		{
			if( matrix[row][col] < target )
			{
				start = index;
				len = ( end - start ) / 2;
				index += len;
			}
			else
			{
				end = index;
				len = ( end - start ) / 2;
				index -= len;
			}
			row = index / numOfCols;
			col = index % numOfCols;
		}
		if( matrix[row][col] == target ) return true;
		if( matrix[0][0] == target ) return true;
		if( matrix[numOfRows - 1][numOfCols - 1] == target ) return true;
		return false;
		*/
    }
};

int main( void )
{
	vector<vector<int>> matrix;
    int numOfRows = 3;
    int numOfCols = 4;

	///---------------------------------|
    /// Инициализация числом следования.|
    ///---------------------------------:
    int val = 0;
    for( int i = 0; i < numOfRows; i++ )
    {   
		matrix.push_back( vector<int>() );
        for( int j = 0; j < numOfCols; j++ )
			matrix.back().push_back( val++ );	// Вначале значение из переменной val добавляется в матрицу, и только после этого переменная val инкрементируется.
//			matrix.back().push_back( ++val );	// Вначале переменная val инкрементируется, и только после этого значение из переменной val добавляется в матрицу.
    }
    
    ///---------------------------------|
    /// Вывод матрицы на экран.         |
    ///---------------------------------:
    for( int i = 0; i < numOfRows; i++ )
    {   
		for ( int j = 0; j < numOfCols; j++ )
			cout << matrix[i][j] << "\t";
		cout << "\n";
    }
	cout << endl;

	cout << "matrix.size() = " << matrix.size() << endl
		<< "matrix[0].size() = " << matrix[0].size() << endl;

	cout << endl;
	int target, size = numOfRows * numOfCols;
	for( int i = 0; i < size; i++ )
	{
		target = i;
		cout << "target = " << target << ",  " << Solution::searchMatrix( matrix, target ) << endl;
	}
	target = -1;
	cout << "target = " << target << ",  " << Solution::searchMatrix( matrix, target ) << endl;
	target = 150;
	cout << "target = " << target << ",  " << Solution::searchMatrix( matrix, target ) << endl;
	cout << endl;

	return 0;
}