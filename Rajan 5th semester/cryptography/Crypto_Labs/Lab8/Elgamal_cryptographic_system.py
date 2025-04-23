from random import randint

def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True

def gen_keys(p, g):
    if not is_prime(p) or g < 1 or g >= p:
        raise ValueError("Invalid p or g.")
    x = randint(2, p-2)  # Random private key
    h = pow(g, x, p)     # Public key: h = g^x mod p
    return x, h

def encrypt(h, p, g, msg):
    c = []
    for m in msg:
        m = ord(m)  # Convert char to ASCII
        if m >= p:
            raise ValueError(f"Char value too large for p={p}.")
        k = randint(2, p-2)  # Random k per character
        c.append((pow(g, k, p), (pow(h, k, p) * m) % p))  # (c1, c2) = (g^k, h^k * m) mod p
    return c

def decrypt(x, p, c):
    # Decrypt: m = c2 * (c1^x)^(-1) mod p, convert to char
    return ''.join(chr((c2 * pow(pow(c1, x, p), -1, p)) % p) for c1, c2 in c)

def main():
    try:
        p = int(input("Prime p: "))
        if p <= 1:
            raise ValueError("p must be > 1.")  # Validate prime
        g = int(input(f"Generator g (1 to {p-1}): "))
        x, h = gen_keys(p, g)  # Generate keys
        print(f"Private: {x}, Public: {h}")
        msg = input("Message: ")
        if not msg:
            raise ValueError("Empty message.")  # Check non-empty message
        enc = encrypt(h, p, g, msg)  # Encrypt message
        print(f"Encrypted: {enc}")
        dec = decrypt(x, p, enc)  # Decrypt message
        print(f"Decrypted: {dec}")
    except ValueError as e:
        print(f"Error: {e}")
    except:
        print("Error: Invalid input.")

if __name__ == "__main__":
    main()