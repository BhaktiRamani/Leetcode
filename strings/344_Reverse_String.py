# 344. Reverse String
# Easy
# Topics
# Companies
# Hint
# Write a function that reverses a string. The input string is given as an array of characters s.

# You must do this by modifying the input array in-place with O(1) extra memory.

 

# Example 1:

# Input: s = ["h","e","l","l","o"]
# Output: ["o","l","l","e","h"]
# Example 2:

# Input: s = ["H","a","n","n","a","h"]
# Output: ["h","a","n","n","a","H"]

s = ["h","e","l","l","o"]

left = 0
right = len(s) - 1
print(len(s))
for i in range(int((len(s) - 1)/2)):

    temp = s[left]
    s[left] = s[right]
    s[right] = temp
    # print(temp, s[left], s[right])
    left +=1
    right -= 1
    
    
# print(s[::-1])
print(s)