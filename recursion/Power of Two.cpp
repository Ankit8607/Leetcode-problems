// https://leetcode.com/problems/power-of-two/

/*

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 

Example 1:

Input: n = 1
Output: true
Explanation: 20 = 1
Example 2:

Input: n = 16
Output: true
Explanation: 24 = 16
Example 3:

Input: n = 3
Output: false
 

Constraints:

-231 <= n <= 231 - 1

*/

// O(logn)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        if(n==1) return 1;
        return (n%2==0 and isPowerOfTwo(n/2));
    }
};

//O(1)

// class Solution {
// public:
//     bool isPowerOfTwo(int n) {
//         if(n<=0) return 0; 
//         return (n&(n-1))==0;
//     }
// };