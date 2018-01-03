import cs50
import sys

#check to see if key is entered correctly
if len(sys.argv) != 2:
    print("missing command line argument")
    exit(1)

#check if key is all letters
if str.isalpha(sys.argv[1]) == False:
    exit(2)
    
#grab key
key = sys.argv[1]

#ask user for plaintext
print("Plaintext: ", end="")
plaintext = cs50.get_string()

print("Ciphertxt: ", end="")

#set key letter to start
key_letter = 0

#run through and encrypt the letters
for i in range(len(plaintext)):
    
    #find the new letter
    if ord(plaintext[i]) > 96 and ord(plaintext[i]) < 123:
        new_letter = (ord(plaintext[i]) + (ord(key[key_letter]) % 97)) % 123
        if new_letter < 97:
            new_letter = new_letter + 97
        #set key letter for next character
        key_letter = (key_letter + 1) % len(key)
    elif ord(plaintext[i]) > 64 and ord(plaintext[i]) < 91:
        new_letter = (ord(plaintext[i]) + (ord(key[key_letter]) % 97)) % 91
        if new_letter < 65:
            new_letter = new_letter + 65
        #set key letter for next character
        key_letter = (key_letter + 1) % len(key)
    else:
        new_letter = ord(plaintext[i])

    print(chr(new_letter), end="")

print("")    