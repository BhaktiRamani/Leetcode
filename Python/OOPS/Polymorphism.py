

class shape:
    def area(self):
        pass
    
class circle(shape):
    def __init__(self, radius):
        self.__radius = radius
        
    def area(self):
        return (3.14*self.__radius*self.__radius)
    
class rectangle(shape):
    def __init__(self, height, width):
        self.__height = height
        self.__width = width
        
    def area(self):
        return(self.__height*self.__width)
    
rect = rectangle(4, 5)
circ = circle(3)

print("Rect area :", rect.area())
print("Circle area :", circ.area())
