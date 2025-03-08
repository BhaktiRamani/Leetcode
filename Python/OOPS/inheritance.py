#Inheritance is same as cpp. Parent and Child

class animal:
    def __init__(self, animal_name, type=0):
        self._animal_name = animal_name #single underscore - inherited class can access it
        self.__type = type  #double underscore - inherited class can not access it - need to use gettars for this
        
    def sound(self):    #similar to virtual functions in CPP
        pass
    
    def type(self):
        pass
    
    def getType(self):      #have to use gettars for private elements
        return self.__type
    
#SYNTAX = IMP
class dog(animal):
    def sound(self):
        print(self._animal_name, ": Bark Bark!")
        
    def type(self):
        print("Type :", self.getType())
        
class cat(animal):
    def sound(self):
        print(self._animal_name, ": Meow")
        
        
d = dog("Tuffy", "Dog")
d.sound()
d.type()

c = cat("Mini")
c.sound()