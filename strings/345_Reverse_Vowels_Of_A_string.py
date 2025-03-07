# 345. Reverse Vowels of a String
# Easy
# Topics
# Companies
# Given a string s, reverse only all the vowels in the string and return it.

# The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

# Example 1:

# Input: s = "IceCreAm"

# Output: "AceCreIm"

# Explanation:

# The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

# Example 2:

# Input: s = "leetcode"

# Output: "leotcede"
# NOT WORKINGG
 
s = "leetcode"

# Convert string to list to allow modification
s = list(s.lower())

left = 0
right = len(s) - 1
vowels = {'a', 'e', 'i', 'o', 'u'}

while left < right:
    if s[left] in vowels:
        while right > left and s[right] in vowels:
            right -= 1  # Move right pointer left to find a non-vowel
        
        # Swap vowels
        s[left], s[right] = s[right], s[left]

    left += 1

# Convert list back to string
s = "".join(s)

print(s)
