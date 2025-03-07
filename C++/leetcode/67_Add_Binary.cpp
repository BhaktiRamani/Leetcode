// 67. Add Binary
// Easy
// Topics
// Companies
// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"

#include<iostream>
#include<string>

using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {

            int len = a.length();
            string result;
            char carry = '0';
            cout << "Add Bionary" << endl;
            for(int i = len - 1; i >= 0; i--)
            {
                if(a[i] == b[i])
                {
                    result[i] = '0';
                    if(a[i] == 1)
                    {
                        carry = '1';
                    }
                }
                else if(carry != '0')
                {
                    if(a[i] != b[i])
                    {
                        result[i] = '1';
                    }
                    if(result[i] == carry)
                    {
                        result[i] = '0';
                        result[i--] = '1';
                    }
                }
            } 
            
            for(int i = 0; i< result.length(); i++)
            {
                cout << result[i] << " " << endl;
            }
        }
    };

int main()
{
    Solution s;
    s.addBinary("11", "1");
}