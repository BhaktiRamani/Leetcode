def add_sprinkles(func):
    def wrapper(*args, **kwargs):
        print("You added Sprinkles")
        func(*args, **kwargs)
    return wrapper


@add_sprinkles
def get_ice_cream(flavor):
    print(f"Here is your {flavor} icecream")
    
get_ice_cream("Vannila")

print()
def auth_decorator(func):
    def wrapper(user):
        if user != "admin":
            print("Access Denied!")
            return
        return func(user)
    return wrapper

@auth_decorator
def secret_function(user):
    print(f"Welcome, {user}! You have access.")

secret_function("guest")   # Access Denied!
secret_function("admin")   # Welcome, admin!

print()

#decorator can be used to enforce types
def type_check_decorator(func):
    def wrapper(*args):
        if not all(isinstance(arg, int) for arg in args):
            raise TypeError("All arguments must be integers")
        return func(*args)
    return wrapper

@type_check_decorator
def add(a, b):
    return a + b

print(add(3, 5))    # 8
#print(add("3", 5))  # Raises TypeError

print()
def log_decorator(func):
    def wrapper(*args, **kwargs):
        print(f"Calling function: {func.__name__}")
        return func(*args, **kwargs)
    return wrapper

@log_decorator
def greet(name):
    print(f"Hello, {name}!")

greet("Alice")



        