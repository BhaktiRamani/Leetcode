# 1. Two Sum
# Easy
# Topics
# Companies
# Hint
# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# You can return the answer in any order.


nums = [5, 15, 2, 7]
target = 9

for i in range(len(nums) - 1):
    if nums[i] + nums[i+1] == target:
        print(f" i : {i}, i+1 : {i+1}")
        break