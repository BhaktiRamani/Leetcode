class MyContextManager:
    def __enter__(self):
        print("Entering the context.")
        return self  # Optional: return any object that you want to use inside the context

    def __exit__(self, exc_type, exc_value, traceback):
        print("Exiting the context.")
        if exc_type:
            print(f"An error occurred: {exc_value}")
        return True  # Suppress the exception (if you want to handle it)

# Using the custom context manager
with MyContextManager() as manager:
    print("Inside the context.")
    # Uncomment to raise an exception and see how it's handled
    raise ValueError("Something went wrong!")

