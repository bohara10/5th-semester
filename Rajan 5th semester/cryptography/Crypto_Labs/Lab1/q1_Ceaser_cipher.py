def encryptMessage(plainText, key):
    cipherText = ''
    for letter in plainText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shiftedIndex = (index + key) % 26   
            cipherText += lowerCase[shiftedIndex]
        elif letter in upperCase:
            index = upperCase.index(letter)
            shiftedIndex = (index + key) % 26
            cipherText += upperCase[shiftedIndex]
        else:
            cipherText += letter  # Keep spaces and special characters unchanged
    return cipherText

def decryptMessage(ciphertext, key):
    plainText = ''
    for letter in ciphertext:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shiftedIndex = (index - key) % 26
            plainText += lowerCase[shiftedIndex]
        elif letter in upperCase:
            index = upperCase.index(letter)
            shiftedIndex = (index - key) % 26
            plainText += upperCase[shiftedIndex]
        else:
            plainText += letter  # Keep spaces and special characters unchanged
    return plainText

# Creating uppercase and lowercase alphabets
upperCase = [chr(i) for i in range(65, 91)]
lowerCase = [chr(j) for j in range(97, 123)]

# Input message and key
message = input('Enter your message here: ')
key = int(input('Enter your key here: '))

# Encrypt the message
ciphertext = encryptMessage(message, key)
print(f'Others will see: {ciphertext}')

# Decryption process
key2 = int(input('Please enter the key to decrypt your message: '))
plainText = decryptMessage(ciphertext, key2)
print(f'Hidden Message seen by receiver: {plainText}')
