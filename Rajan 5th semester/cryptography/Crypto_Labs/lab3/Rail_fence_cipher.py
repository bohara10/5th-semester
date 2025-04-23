def encryptMessage(message, key):
    cipherText = ''
    c = 0
    r = 0
    i = 0
    down = True
    
    # Create a matrix with 'key' rows and enough columns to fit the message length
    matrix = [['' for _ in range(len(message))] for _ in range(key)]
    
    # Fill the matrix in a zigzag manner (down and up)
    while c < len(message):
        matrix[r][c] = message[i]
        
        # Move down or up depending on the direction
        if down:
            r += 1
        else:
            r -= 1
        
        # Change direction if the bottom or top of the matrix is reached
        if r == key:
            down = False
            r -= 2  # Ensure we stay within bounds
        elif r == -1:
            down = True
            r += 2  # Ensure we stay within bounds
        
        c += 1
        i += 1
    
    # Read the matrix row by row to form the ciphertext
    for row in matrix:
        for item in row:
            if item != '':
                cipherText += item

    return cipherText

# Test the function
print(encryptMessage('CRYPTOGRAPHY', 2))  # Example with key 2
