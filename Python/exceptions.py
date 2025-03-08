try:
    result = 1/0
except ZeroDivisionError as e:
    print(f"OOPS, error occured : {e}")
else:
    print("Everything successfull")
finally:
    print("This will always get print")
