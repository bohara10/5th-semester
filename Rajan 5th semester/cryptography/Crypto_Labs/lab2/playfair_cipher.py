import numpy as np

# Define the alphabet letters excluding 'J' (we'll treat I and J as the same letter in the Playfair cipher)
letters = [chr(i) for i in range(65, 91) if chr(i) != 'J']

def findIndex(matrix, letter):
    # Find the row and column of the letter in the matrix
    for r, row in enumerate(matrix):
        if letter in row:
            return r, row.index(letter)

def generateMatrix(key):
    matrix = []
    keyMatrix = [[None for _ in range(5)] for _ in range(5)]

    # Add unique letters from the key (treat 'I' and 'J' as the same letter)
    key = key.upper().replace('J', 'I')
    for char in key:
        if char not in matrix and char in letters:
            matrix.append(char)

    # Fill the remaining matrix with letters A-Z (excluding J)
    for char in letters:
        if char not in matrix:
            matrix.append(char)

    # Fill the 5x5 matrix
    count = 0
    for row in range(5):
        for col in range(5):
            keyMatrix[row][col] = matrix[count]
            count += 1

    print(keyMatrix)
    return keyMatrix

def encryptMessage(message, key):
    # Generate the Playfair key matrix
    keyMatrix = generateMatrix(key)

    # Remove spaces from the message and convert to uppercase
    message = message.replace(" ", "").upper()
    
    # Prepare the message for encryption (divide into digraphs)
    messageList = list(message)
    cipherText = ''
    
    # Handle digraphs
    i = 0
    while i < len(messageList):
        # If both letters are the same, insert an 'X'
        if i + 1 < len(messageList) and messageList[i] == messageList[i + 1]:
            cipherText += messageList[i] + 'X'
            i += 1
        # If we have a single letter left, add 'X' to make a digraph
        elif i + 1 == len(messageList):
            cipherText += messageList[i] + 'X'
            i += 1
        else:
            cipherText += messageList[i] + messageList[i + 1]
            i += 2

    # Now encrypt the digraphs
    encryptedText = ''
    for i in range(0, len(cipherText), 2):
        digraph = cipherText[i:i+2]
        r1, c1 = findIndex(keyMatrix, digraph[0])
        r2, c2 = findIndex(keyMatrix, digraph[1])
        
        # Case 1: Same row (same column index)
        if r1 == r2:
            encryptedText += keyMatrix[r1][(c1 + 1) % 5]
            encryptedText += keyMatrix[r2][(c2 + 1) % 5]
        # Case 2: Same column (same row index)
        elif c1 == c2:
            encryptedText += keyMatrix[(r1 + 1) % 5][c1]
            encryptedText += keyMatrix[(r2 + 1) % 5][c2]
        # Case 3: Rectangle (different row and column)
        else:
            encryptedText += keyMatrix[r1][c2]
            encryptedText += keyMatrix[r2][c1]

    return encryptedText

# Example run
message = "CRYPTOGRAPHY"
key = "ACHS"
encryptedMessage = encryptMessage(message, key)
print(f'Encrypted Message: {encryptedMessage}')
