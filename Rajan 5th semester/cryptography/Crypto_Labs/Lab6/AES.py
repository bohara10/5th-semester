
from Crypto.Cipher import AES
import binascii
import os

# Function to pad data to be a multiple of 16 bytes
def pad(text):
    while len(text) % 16 != 0:
        text += ' '  # Padding with spaces
    return text

# Function to encrypt plaintext using AES in CBC mode
def aes_encrypt(plaintext, key):
    key = key.ljust(16, b'\0')[:16]  # Ensure key is exactly 16 bytes
    iv = os.urandom(16)  # Generate a random 16-byte IV
    cipher = AES.new(key, AES.MODE_CBC, iv)  # AES in CBC mode
    padded_text = pad(plaintext).encode()  # Ensure text is 16-byte aligned
    encrypted_text = cipher.encrypt(padded_text)  # Encrypt
    return binascii.hexlify(iv + encrypted_text).decode()  # Return IV + ciphertext in hex

# Function to decrypt ciphertext using AES in CBC mode
def aes_decrypt(ciphertext, key):
    key = key.ljust(16, b'\0')[:16]  # Ensure key is exactly 16 bytes
    ciphertext = binascii.unhexlify(ciphertext)  # Convert hex to bytes
    iv, encrypted_text = ciphertext[:16], ciphertext[16:]  # Extract IV and ciphertext
    cipher = AES.new(key, AES.MODE_CBC, iv)  # AES in CBC mode
    decrypted_text = cipher.decrypt(encrypted_text).decode().strip()  # Decrypt and remove padding
    return decrypted_text

# Implementation
key = b"aabbccddeSecretKey"  # AES requires a 16-byte key
plaintext = "Hello Rajan!"

ciphertext = aes_encrypt(plaintext, key)
print(f"Ciphertext: {ciphertext}")

decrypted_text = aes_decrypt(ciphertext, key)
print(f"Decrypted text: {decrypted_text}")
