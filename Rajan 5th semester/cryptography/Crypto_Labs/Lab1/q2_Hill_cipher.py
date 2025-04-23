import numpy as np

# Function to calculate the inverse of a matrix modulo 26
def mod_inverse(matrix, mod):
    det = int(np.round(np.linalg.det(matrix))) % mod  # Compute determinant
    det_inv = pow(det, -1, mod)  # Compute modular inverse of determinant
    matrix_adj = np.round(det * np.linalg.inv(matrix)).astype(int) % mod  # Compute adjugate matrix
    return (det_inv * matrix_adj) % mod  # Multiply by modular inverse and mod

# Function for Hill cipher encryption
def hill_encrypt(plaintext, key):
    mod = 26
    n = len(key)

    # Pad the plaintext to a multiple of the key size
    while len(plaintext) % n != 0:
        plaintext += 'X'  # Padding with 'X'

    # Convert plaintext to numerical values
    plaintext_numbers = [ord(char) - ord('A') for char in plaintext.upper()]
    
    # Encrypt the message
    ciphertext_numbers = []
    for i in range(0, len(plaintext_numbers), n):
        block = np.array(plaintext_numbers[i:i+n])
        encrypted_block = np.dot(key, block) % mod
        ciphertext_numbers.extend(encrypted_block)

    # Convert numerical ciphertext back to letters
    ciphertext = ''.join(chr(num + ord('A')) for num in ciphertext_numbers)
    return ciphertext

# Function for Hill cipher decryption
def hill_decrypt(ciphertext, key):
    mod = 26
    n = len(key)

    # Calculate the inverse of the key matrix modulo 26
    key_inv = mod_inverse(key, mod)

    # Convert ciphertext to numerical values
    ciphertext_numbers = [ord(char) - ord('A') for char in ciphertext.upper()]

    # Decrypt the message
    decrypted_numbers = []
    for i in range(0, len(ciphertext_numbers), n):
        block = np.array(ciphertext_numbers[i:i+n])
        decrypted_block = np.dot(key_inv, block) % mod
        decrypted_numbers.extend(decrypted_block)

    # Convert numerical decrypted message back to letters
    decrypted_text = ''.join(chr(int(num) + ord('A')) for num in decrypted_numbers)
    return decrypted_text

# Example usage:
if __name__ == "__main__":
    key_matrix = np.array([[6, 24, 1], [13, 16, 10], [20, 17, 15]])  # Example 3x3 matrix key
    plaintext = "HELLO"

    encrypted = hill_encrypt(plaintext, key_matrix)
    print(f"Encrypted: {encrypted}")

    decrypted = hill_decrypt(encrypted, key_matrix)
    print(f"Decrypted: {decrypted}")
