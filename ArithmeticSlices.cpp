// Source : https://leetcode.com/problems/arithmetic-slices/
// Author : Dylan
// Date   : 2016-11-16

/*************************************************************************************** 
 *
 * A sequence of number is called arithmetic if it consists of at least three elements 
 * and if the difference between any two consecutive elements is the same.
 * 
 * For example, these are arithmetic sequence:
 * 1, 3, 5, 7, 9
 * 7, 7, 7, 7
 * 3, -1, -5, -9
 * 
 * The following sequence is not arithmetic. 1, 1, 2, 5, 7 
 * 
 * A zero-indexed array A consisting of N numbers is given. A slice of that array is 
 * any pair of integers (P, Q) such that 0 
 * 
 * A slice (P, Q) of array A is called arithmetic if the sequence:
 *     A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means 
 * that P + 1 
 * 
 * The function should return the number of arithmetic slices in the array A. 
 * 
 * Example:
 * 
 * A = [1, 2, 3, 4]
 * 
 * return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] 
 * itself.
 ***************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlice(vector<int>& A) {
        int aCNum = 0;

        if (A.size() < 3) {
            cout<<"Array length is shorter than 2.\n";
            return 0;
        }
        
        int diff;
        int eleNum;
        for (int i = 0; i < A.size() - 2; i++) {
            eleNum = 2;
            diff = A[i+1] - A[i];
            for (int j = i + 2; j < A.size() && A[j] - A[j-1] == diff; j++) {
                eleNum++;
                if (eleNum > 2) {
                    aCNum++;
                    for (int q = i; q < i + eleNum; q++) {
                        cout<<A[q]<<' ';
                    }
                    cout<<'\n';
                }
            }
        }
        return aCNum;
    }
};

int main ()
{
    int ia[7] = {1,2,3,4,5,6,7};
    vector<int> A(ia, ia+7);
    Solution test;
    test.numberOfArithmeticSlice(A);

    return 0;
}
