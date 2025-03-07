# 171. Excel Sheet Column Number
# Easy
# Topics
# Companies
# Given a string columnTitle that represents the column title as appears in an Excel sheet, return its corresponding column number.

# For example:

# A -> 1
# B -> 2
# C -> 3
# ...
# Z -> 26
# AA -> 27
# AB -> 28 
# ...
 

# Example 1:

# Input: columnTitle = "A"
# Output: 1
# Example 2:

# Input: columnTitle = "AB"
# Output: 28
# Example 3:

# Input: columnTitle = "ZY"
# Output: 701

base_value = 65
str = "ZY"
result = 0
# for i in range(len(str)):
result = result + (ord(str[1]) - base_value + 1)
result = result + 26*(ord(str[0]) - base_value + 1)

print(result)


# from number to letter
str2 = ""
num = 26
result = num%26
result = result*26
str2[0] = chr(result)

print(str2)

