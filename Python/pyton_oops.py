#Object Oriented Programming - Python

class Dog:
    def __init__(self, name, age=None):
        self.age = age
        self.name = name
        self._under1 = 1        #public attribute
        self.__under2 = 2       #private attribute
        print(name)
        
    def __str__(self):    #returns a class name
            return self.__class__.__name__
        
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

print(d._under1)
#print(d.__under2)  #will throw an error
print(d.name)
print(d2.name)
print(d.bark()) 
print(d.add_one(5))   