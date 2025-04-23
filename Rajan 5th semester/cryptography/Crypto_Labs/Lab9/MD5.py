import hashlib

def generate_md5_hash(message):
    """Generate MD5 hash of the input message."""
    return hashlib.md5(message.encode()).hexdigest()  # Encode string and compute MD5 hash

def main():
    try:
        message = input("Enter a message to hash with MD5: ")  # Get user input
        if not message:
            print("Error: Message cannot be empty.")  # Check for empty input
            return
        hash_value = generate_md5_hash(message)  # Generate hash
        print(f"MD5 Hash: {hash_value}")  # Display hash in hex format
    except Exception as e:
        print(f"Error: {e}")  # Handle encoding or other errors

if __name__ == "__main__":
    main()