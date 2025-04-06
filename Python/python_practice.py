print("Hello")

hello = 'Hey'
world = 'world'

print(hello, world)

# Input type is by default - STRING
# num  = input("Give a number : ")
# print(int(num) - 5)
# print(type(num))

# % gives remainder
# / gives dividend

# String operation
hey = "hey"
print(hey, hey.upper())
print(hey.count(''))
print(hey.count("e"))

# String can be printed multiple times by multiplication
print(hey*3)
print(hey + hey)

# Conditional Operators
x = "Hey"
y = "World"
print(x == y)

# Prints the ascii value
print(ord("a"))     

# If condition
if x == 'Hey':
    print("Hey", x)
elif x == 'World':
    print("Hey", y)
else:
    print("nope")
    
# List, can be changed
x = [1, True, 'hi']
print(x)
x.append(6)
print(x)
print(x[0])

# Tupple , can not be changed
x = (0, 1, 2)
print(x)
#  cant use append or pop operation

#  For loops
for i in range(5):
    print(i, end=" ")
# range can have (start, stop, step)

print()
# While loop
i = 0;
while i < 5:
    i = i + 1
    print(i, end=" ")
print()

# Sets
s = { 3, 1, 1, 3, 4, 5}
print(s)
# it also have some classes like append and pop like string

# Dictionary
x = {'key' : 4}
print(x['key'])
print('key' in x)
print(list(x.values()))

# Comprehentions
x = [i for i in range(5)]
print(x)

# Functions
def my_func(x, y):
    print("my_func")
    print(x, y)
    print(y*x)
    
my_func(5, "Hey")

# Calling the function inside function
def func(x):
    def func2():
        print(x)
    return func2
# Calling the func which returns func2 and then calling func2 by using extra () in print
print(func(2)())

# args and kwargs, unpack operator
# Passes the elements as an individual argument
x = [1, 2, 3]
print(*x)

def func(x, y):
    print(x, y)
    
pairs = [(1, 2), (3, 4)]

for i in pairs:
    func(*i)    #unpacks the pair as an individual argument
# kwargs can let us pass whatever number of elements we want to pass

def func(*args, **kwargs):
    print(args, kwargs)
    
print(func(1, 2, 3, 4))

# Try and except
try:
    x = 7/0
except:
    print("oops, exception")
    
# Lamda function, basically one line function
# lamda parameters : operation
x = lambda x,y:x+y
print(x(1, 2))

# map(lamda func, parameter for lamda)
x = [1, 2, 3, 4, 5]
mp = map(lambda i : i + 2, x)
print(list(mp))

# Filter


# F strings
hey = "hey"
x = f"hello {5 + 4} {hey}"
print(x)