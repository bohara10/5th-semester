import hashlib

def generate_sha256_hash(message):
    """Generate SHA-256 hash of the input message."""
    # Convert string to bytes and compute 256-bit SHA-256 hash, return as hex
    return hashlib.sha256(message.encode()).hexdigest()

def main():
    try:
        # Prompt user for a string to hash
        message = input("Enter a message to hash with SHA-256: ")
        # Ensure input is not empty to avoid invalid hashing
        if not message:
            print("Error: Message cannot be empty.")
            return
        # Calculate SHA-256 hash of the input message
        hash_value = generate_sha256_hash(message)
        # Output the 64-character hexadecimal hash
        print(f"SHA-256 Hash: {hash_value}")
    except Exception as e:
        # Catch encoding issues or other unexpected errors
        print(f"Error: {e}")

if __name__ == "__main__":
    main()