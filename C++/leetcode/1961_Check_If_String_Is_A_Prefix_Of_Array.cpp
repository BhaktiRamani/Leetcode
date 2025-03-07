// 1961. Check If String Is a Prefix of Array
// Easy
// Topics
// Companies
// Hint
// Given a string s and an array of strings words, determine whether s is a prefix string of words.

// A string s is a prefix string of words if s can be made by concatenating the first k strings in words for some positive k no larger than words.length.

// Return true if s is a prefix string of words, or false otherwise.

 

// Example 1:

// Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
// Output: true
// Explanation:
// s can be made by concatenating "i", "love", and "leetcode" together.
// Example 2:

// Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
// Output: false
// Explanation:
// It is impossible to make s using a prefix of arr.


#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
        bool isPrefixString(string s, vector<string>& words) {
            int index = 0;
            
            for(int i = 0; i < words.size(); i++)
            {
                if(s[0] != words[0][0])
                {
                    return false;
                }
                
                int j = 0;
                while(s[index] == words[i][j] && j < words[i].size())  {
                    cout << s[index] << "  " << words[i][j] << endl;
                    index++;j++;
                }
                cout << "Next : " << "s[index] : " << s[index] << " words[i][j] : " << words[i][j] << endl;
               
            }
            if(index == s.size())
            {
                return true;
            }
            else{
                return false;
            }
            return false;
        }
};

int main()
{
    vector<string> vect = { "apples", "i", "love", "leetcode"};
    cout << vect[1][1] << endl;

    Solution s;
    bool result = s.isPrefixString("iloveleetcode", vect);
    cout << "Result : " << result << endl;
}