# 125. Valid Palindrome
# Easy
# Topics
# Companies
# A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

# Given a string s, return true if it is a palindrome, or false otherwise.

 

# Example 1:

# Input: s = "A man, a plan, a canal: Panama"
# Output: true
# Explanation: "amanaplanacanalpanama" is a palindrome.
# Example 2:

# Input: s = "race a car"
# Output: false
# Explanation: "raceacar" is not a palindrome.
# Example 3:

# Input: s = " "
# Output: true
# Explanation: s is an empty string "" after removing non-alphanumeric characters.
# Since an empty string reads the same forward and backward, it is a palindrome.

str_p = "radar"

def is_palindrome(s):
    # Compare characters from beginning and end
    s = s.replace(" ", "")
    s = s.replace(",", "")
    s = s.replace(":", "")
    s = s.lower();
    print(s);
    left = 0
    right = len(s) - 1
    
    while left < right:
        if s[left] != s[right]:
            return False
        left += 1
        right -= 1
    
    return True

# Test it
str_p = "radar"
print(is_palindrome("A man, a plan, a canal: Panama"))  # True

def reverse_str(s):
    s = s.replace(" ", "")
    s = s.replace(",", "")
    s = s.replace(":", "")
    s = s.lower();
    return s == s[::-1];

print(reverse_str("civic"));