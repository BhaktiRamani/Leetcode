#encapsulation is hiding the private data from user


class BankAccount:
    def __init__(self, owner, balance=0):   #balance=0 means it is not necessary to pass the balance element
        self.__owner = owner            #private attributes
        self.__balance = balance
        self._public = "Public"         #public attributes
        
    def getOwner(self):
        print("Owner :", self.__owner)
    def getBalance(self):
        print("Balance :", self.__balance)
    def withdraw(self, amount):
        if(self.__balance > amount):
            self.__balance -= amount
            print("Balance after Withdrawal : ", self.__balance)
    
        
        
account = BankAccount("Bhakti", 500);
account.getOwner()
account.getBalance()
account.withdraw(200)

print()
print("Property Decorators : ")
print()
#Property decorators
class Circle:
    def __init__(self, radius):
        self._radius = radius  # public attribute   - can be accessed outside the class

    @property
    def radius(self):
        return self._radius

    @radius.setter
    def radius(self, value):
        if value <= 0:
            raise ValueError("Radius must be positive")
        self._radius = value

    @radius.deleter
    def radius(self):
        print("Deleting radius")
        del self._radius

    @property
    def area(self):
        return 3.14 * self._radius ** 2

# Create an instance
c = Circle(5)

# Access the radius property (getter)
print(c.radius)  # Output: 5

# Set a new value for radius using setter
c.radius = 10
print(c.radius)  # Output: 10

# Access computed area
print(c.area)  # Output: 314.0

# Delete the radius property
del c.radius  # Output: Deleting radius
