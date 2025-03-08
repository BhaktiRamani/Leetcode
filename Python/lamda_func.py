add = lambda x, y : x+y

print(add(2,3))

num = [1, 2 , 3, 4]

squared = list(map(lambda x : x*x, num))
print(num)
print(squared)

print()
# Using lambda with filter to get even numbers from a list
numbers = [1, 2, 3, 4, 5, 6]
even_numbers = list(filter(lambda x: x % 2 == 0, numbers))
print(even_numbers)  # Output: [2, 4, 6]

print()

#NOT SURE
# Sorting a list of tuples based on the second element of each tuple
data = [(1, 'apple'), (2, 'banana'), (3, 'cherry')]

# Sorting by the second element (fruit name)
sorted_data = sorted(data, key=lambda x: x[1])
print(sorted_data)  # Output: [(1, 'apple'), (2, 'banana'), (3, 'cherry')]
