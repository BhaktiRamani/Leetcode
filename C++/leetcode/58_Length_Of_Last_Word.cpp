// 58. Length of Last Word
// Easy
// Topics
// Companies
// Given a string s consisting of words and spaces, return the length of the last word in the string.

// A word is a maximal substring consisting of non-space characters only.

 

// Example 1:

// Input: s = "Hello World"
// Output: 5
// Explanation: The last word is "World" with length 5.
// Example 2:

// Input: s = "   fly me   to   the moon  "
// Output: 4
// Explanation: The last word is "moon" with length 4.
// Example 3:

// Input: s = "luffy is still joyboy"
// Output: 6
// Explanation: The last word is "joyboy" with length 6.

#include<iostream>
#include<string.h>

using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {

            int i = s.length() - 1;
            int len = 0;
            
             // check if last characters are spaces
             while(i >= 0 && s[i] == ' ')
             {
                i--;
             }
    
             //count the last word length
             while(i >= 0 && s[i] != ' ')
             {
                i--;
                len++;
             }

             cout << "Length of the last word is : " << len << endl;
             return len;
           
        }
};

int main()
{
    Solution s;
    s.lengthOfLastWord("fly     me to the           moon        ");
}
