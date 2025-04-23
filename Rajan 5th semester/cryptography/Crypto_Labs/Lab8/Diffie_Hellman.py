from random import randint

class User:
    def __init__(self, p, g) -> None:
        self.private = randint(1, p)
        self.public = pow(g, self.private, p)
    
    def get_public_key(self):
        return self.public
    
    def get_shared_key(self, public_other, p):
        return pow(public_other, self.private, p)

def main():
    try:
        p = int(input("Enter a prime number (p): "))
        if p <= 1:
            print("Error: Please enter a prime number greater than 1.")
            return
        
        g = int(input(f"Enter a generator (g, between 1 and {p-1}): "))
        if g < 1 or g >= p:
            print(f"Error: Generator must be between 1 and {p-1}.")
            return
        
        user_a = User(p, g)
        user_b = User(p, g)
        
        public_a = user_a.get_public_key()
        public_b = user_b.get_public_key()
        
        shared_a = user_a.get_shared_key(public_b, p)
        shared_b = user_b.get_shared_key(public_a, p)
        
        print(f"User A's public key: {public_a}")
        print(f"User B's public key: {public_b}")
        print(f"Shared secret for User A: {shared_a}")
        print(f"Shared secret for User B: {shared_b}")
    
    except ValueError:
        print("Error: Please enter valid integers for p and g.")

if __name__ == "__main__":
    main()