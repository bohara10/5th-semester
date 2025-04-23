import numpy as np

# Define the uppercase and lowercase alphabets
upperCase = [chr(i) for i in range(65, 91)]  # A-Z
lowerCase = [chr(i) for i in range(97, 123)]  # a-z

def encryptMessage(plainText, key):
    cipherText = ''
    keylen = int(np.ceil(len(plainText) / len(key)))  # Repeat key to match length of message
    key *= keylen
    count = 0
    for letter in plainText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count].lower())  # Ensure key is treated in lowercase
            shiftedIndex = (index + shifter) % 26
            cipherText += lowerCase[shiftedIndex]
            count += 1
        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count].lower())  # Ensure key is treated in lowercase
            shiftedIndex = (index + shifter) % 26
            cipherText += upperCase[shiftedIndex]
            count += 1
        else:
            cipherText += letter  # Non-alphabetical characters are not changed
            count += 1
    return cipherText

def decryptMessage(cipherText, key):
    plainText = ''
    count = 0
    keylen = int(np.ceil(len(cipherText) / len(key)))  # Repeat key to match length of cipher text
    key *= keylen
    for letter in cipherText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count].lower())  # Ensure key is treated in lowercase
            shiftedIndex = (index - shifter) % 26
            plainText += lowerCase[shiftedIndex]
            count += 1
        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = lowerCase.index(key[count].lower())  # Ensure key is treated in lowercase
            shiftedIndex = (index - shifter) % 26
            plainText += upperCase[shiftedIndex]
            count += 1
        else:
            plainText += letter  # Non-alphabetical characters are not changed
            count += 1
    return plainText

# Input from user
message = input('Enter your Message: ')
key = 'mykey'

# Encrypt the message
cipherText = encryptMessage(message, key)
print(f'Your encrypted Message: {cipherText}')

# Decrypt the message
key2 = input('Please enter the secret key to decrypt the message: ')
plainText = decryptMessage(cipherText, key2)
print(f'Your hidden message is : {plainText}')
