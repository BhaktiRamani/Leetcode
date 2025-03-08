#encapsulation is hiding the private data from user


class BankAccount:
    def __init__(self, owner, balance=0):   #balance=0 means it is not necessary to pass the balance element
        self.__owner = owner    #private attributes
        self.__balance = balance
        
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