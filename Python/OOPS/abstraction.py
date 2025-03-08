from abc import ABC, abstractmethod

#we are making sure that our main class or implementation is not visible to user and can be called only from
#child class
#parent class should have all the private implementation and only class(which inherits the parent) can use it

class vehicle(ABC):
    def __init__(self, name):
        self._name = name
        
    @abstractmethod     #decorators
    def start(self):
        pass
    
    @abstractmethod
    def stop(self):
        pass
    
class car(vehicle):
    def start(self):
        print(self._name, "started")
        
        
    def stop(self):
        print("Car stopped")
        
c = car("Swift")
c.start()
c.stop()
