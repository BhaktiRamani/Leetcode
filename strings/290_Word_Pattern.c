// 290. Word Pattern
// Easy
// Topics
// premium lock icon
// Companies
// Given a pattern and a string s, find if s follows the same pattern.

// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:

// Each letter in pattern maps to exactly one unique word in s.
// Each unique word in s maps to exactly one letter in pattern.
// No two letters map to the same word, and no two words map to the same letter.
 

// Example 1:

// Input: pattern = "abba", s = "dog cat cat dog"

// Output: true

// Explanation:

// The bijection can be established as:

// 'a' maps to "dog".
// 'b' maps to "cat".
// Example 2:

// Input: pattern = "abba", s = "dog cat cat fish"

// Output: false

// Example 3:

// Input: pattern = "aaaa", s = "dog cat cat dog"

// Output: false

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool wordPattern(char* pattern, char* s) {

    char *used_words[10] = {}; 
    char *pattern_arr[10] = {}; 
    char *str = strtok(s, " "); 
    bool flag = false;
    int i_idx = 0;
    while(str != NULL)
    {
        used_words[i_idx] = str; 
        printf("%s\n", used_words[i_idx]);
        i_idx++;
        str = strtok(NULL, " "); 
    }

    for(int i = 0; i<4; i++)
    {
        if(pattern[i] == pattern[i+1])
        {
            if(used_words[i] == used_words[i+1])
            {

            }
            else{return false;}
        }
        else{
            int tmp = 0; 
            while(pattern[i] != pattern_arr[tmp])
            {
                tmp++;
            }
            pattern_arr[]
        }
    }




    
    return false;
    
    
}

int main(){
    char pattern[] = "abba";
    char word[] = "dog cat cat dog";

    bool result = wordPattern(pattern, word );

    printf("Result : %d\n", result);

}