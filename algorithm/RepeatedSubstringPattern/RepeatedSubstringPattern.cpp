// Source : https://leetcode.com/problems/repeated-substring-pattern/
// Author : Dylan
// Date   : 2016-11-17

/*************************************************************************************** 
 *
 * Given a non-empty string check if it can be constructed by taking a substring of it 
 * and appending multiple copies of the substring together.  You may assume the given 
 * string consists of lowercase English letters only and its length  will not exceed 
 * 10000. 
 * 
 * Example 1:
 * 
 * Input: "abab"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "ab" twice.
 * 
 * Example 2:
 * 
 * Input: "aba"
 * 
 * Output: False
 * 
 * Example 3:
 * 
 * Input: "abcabcabcabc"
 * 
 * Output: True
 * 
 * Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 ***************************************************************************************/
#include<iostream>
#include<stdio.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        bool goToFirst = false;
        bool goToSecond = false;
        for (int i = 1; i <= str.size()/2; i++) {
            if (str.size() % i != 0) {
                continue;
            }
            for (int j = i; j < str.size(); j=j+i) {
                for (int k = 0; k < i; k++) {
                    if (str[j+k] != str[k]) {
                        goToSecond = true;
                        break;
                    }
                }
                if (goToSecond == true) {
                    goToSecond = false;
                    goToFirst = true;
                    break;
                }
            }
            if (goToFirst != true) {
                return true;
            }
            goToFirst = false;
        }
        return false;
    }
};

int main()
{
    Solution test;
    string str;
    cin>>str;
    cout<<'\n';
    if (test.repeatedSubstringPattern(str) == true) {
        printf("true\n");
    } else {
        printf("false\n");
    }
}
