
// 168. Excel Sheet Column Title
// Easy
// Topics
// Companies
// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:

// Input: columnNumber = 1
// Output: "A"
// Example 2:

// Input: columnNumber = 28
// Output: "AB"
// Example 3:

// Input: columnNumber = 701
// Output: "ZY"

#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
    string convertToTitle(int columnNumber) {
        string result = "";
        char A = 'A';
        int base_value = int(A);
        int str_1 = 0;
        int str_0 = 0;
        int num = columnNumber;

        if(columnNumber > 26)
        {
            
            str_1 = num % 26;       // 2
            cout << str_1 << endl;
            char str1 = ((base_value + str_1) - 1);
            result[1] = str1;
            cout << result[1] << endl;
            str_0 = num - 26*(str_1 + 1);
        }
        
        char str0 = base_value + str_0;
        //cout << str0 << endl;
        result[0] = str0;
        cout << result[0] << endl;
        return result;
    }
};

int main()
{
    char A = 'A';
    int base_value = int(A);
    // char B = 'B';
    // int result = int(B) - base_value;
    // cout << base_value << endl;
    // cout << int(B) << endl;
    // cout << result << endl;

    // cout << endl;
    // string str = "AB";
    // int result_2 = 0;
    // int str_0 = (int(str[0]) - base_value) + 1;
    // int str_1 = (int(str[1]) - base_value) + 1;
    // result_2 = str_0 * 26 + str_1;
    // cout << result_2 << endl;

    // cout << endl;

    // int num = 28;
    // int str_1 = num % 26;       // 2
    // char str1 = ((base_value + str_1) - 1);
    // cout << str1 << endl;

    // int str_0 = num - 26;
    // char str0 = base_value + str_0 - str_1;
    // cout << str0 << endl;


    Solution s;
    string result = s.convertToTitle(28);
    cout << result << endl;



}
