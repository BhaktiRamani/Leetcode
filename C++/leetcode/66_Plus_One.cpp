// 66. Plus One
// Easy
// Topics
// Companies
// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

// Increment the large integer by one and return the resulting array of digits.

 

// Example 1:

// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
// Incrementing by one gives 123 + 1 = 124.
// Thus, the result should be [1,2,4].
// Example 2:

// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
// Incrementing by one gives 4321 + 1 = 4322.
// Thus, the result should be [4,3,2,2].
// Example 3:

// Input: digits = [9]
// Output: [1,0]
// Explanation: The array represents the integer 9.
// Incrementing by one gives 9 + 1 = 10.
// Thus, the result should be [1,0].

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {

            int vect_len = digits.size();
            cout << vect_len << endl;
            for(int i = (vect_len - 1); i>=0; i--)
            {
                if(digits[i] < 9)
                {
                    digits[i] += 1;
                    cout << digits[i] << endl;
                    return digits;
                }
                digits[i] = 0;
     
            }
            digits.insert(digits.begin(), 1);
            


            // int vec_len = digits.size();
            // int num = 0;
            // int power = vec_len - 1;
            // int temp = 0;
            // int temp2 = 0;
            // for(int i = 0; i < vec_len ; i++)
            // {
            //     temp = pow(10, power);
            //     power -= 1;
            //     temp2 = digits[i] * temp;
            //     num = num + temp2;
            //     cout << "Temp : " << temp << " Num : " << num << endl;
            // }
            // int result = temp2 + 1;
            
            // cout << num << endl;
            return digits;
            
        }
};

int main()
{
    vector<int> vect = {9, 9, 9};
    vector<int> result ;
    Solution s;
    result = s.plusOne(vect);
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
