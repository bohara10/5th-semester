import math

def is_prime(n):
    """Check if a number is prime."""
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def generate_keys(p, q):
    """Generate RSA public and private keys."""
    if not (is_prime(p) and is_prime(q)):
        raise ValueError("Both p and q must be prime numbers.")
    if p == q:
        raise ValueError("p and q must be distinct prime numbers.")
    
    n = p * q
    phi = (p - 1) * (q - 1)
    
    # Choose e: coprime to phi and 1 < e < phi
    e = 3
    while math.gcd(e, phi) != 1:
        e += 2
        if e >= phi:
            raise ValueError("No suitable e found.")
    
    # Choose d: modular inverse of e mod phi
    d = pow(e, -1, phi)
    
    return (e, n), (d, n)

def encrypt(public_key, message):
    """Encrypt the message using the public key."""
    e, n = public_key
    # Convert each character to a number and encrypt
    encrypted = [pow(ord(char), e, n) for char in message]
    return encrypted

def decrypt(private_key, encrypted):
    """Decrypt the message using the private key."""
    d, n = private_key
    # Decrypt each number and convert back to character
    decrypted = [chr(pow(num, d, n)) for num in encrypted]
    return ''.join(decrypted)

def main():
    try:
        # Get prime numbers from user
        p = int(input("Enter first prime number (p): "))
        q = int(input("Enter second prime number (q): "))
        
        # Generate keys
        public_key, private_key = generate_keys(p, q)
        print(f"Public key: {public_key}")
        print(f"Private key: {private_key}")
        
        # Get message
        message = input("Enter a message to encrypt: ")
        if not message:
            print("Error: Message cannot be empty.")
            return
        
        # Encrypt
        encrypted_msg = encrypt(public_key, message)
        print(f"Encrypted message (numerical): {encrypted_msg}")
        
        # Decrypt
        decrypted_msg = decrypt(private_key, encrypted_msg)
        print(f"Decrypted message: {decrypted_msg}")
        
    except ValueError as e:
        if str(e) in ["Both p and q must be prime numbers.", "p and q must be distinct prime numbers.", "No suitable e found."]:
            print(f"Error: {e}")
        else:
            print("Error: Please enter valid integers for p and q.")
    except Exception as e:
        print(f"Error: An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()