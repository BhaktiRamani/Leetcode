#Object Oriented Programming - Python

class Dog:
    def __init__(self, name, age):
        self.age = age
        self.name = name
        print(name)
        
    def add_one(self, x):
        return x+1
    
    def bark(self):
        print("bark")
    
    def get_name(self):
        print (self.name)
        
    def get_age(self):
        print(self.age)
        
d = Dog("Tim")
d2 = Dog("Tom")

print(d.name)
print(d2.name)
print(d.bark()) 
print(d.add_one(5))   