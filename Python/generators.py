#[expression for item in iterable if condition]
#expression = work or operation

square = [x**2 for x in range(6) if x >0]
print(square)

num = [x for x in range(10) if x%2 == 0 and x > 0]
print(num)

chars = ['a', 'b', 'c', 'd']
uppercase_chars = [char.upper() for char in chars]
print(uppercase_chars)

