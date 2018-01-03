import cs50

print("Number: ", end="")
credit_card = cs50.get_int()
credit_card_list = []
number_of_digits = 0
checksum = 0

#this get the digits and makes the nnumber into a list
while(credit_card != 0):
    number_of_digits += 1
    credit_card, r = divmod(credit_card, 10)
    credit_card_list.insert(0,r)

#checks if number of digits are valid
if(number_of_digits != 13 and number_of_digits != 15 and number_of_digits != 16):
    print("INVALID")
#run through digits and get checksum
else:
    for i in range(number_of_digits):
        if(number_of_digits % 2 == 0):
            if(i % 2 == 0):
                if(credit_card_list[i] > 4): #if product is more than two digits
                    checksum += credit_card_list[i] * 2 % 10 + 1
                else:
                    checksum += credit_card_list[i] * 2
            else:
                checksum += credit_card_list[i]
        else:
            if(i % 2 != 0):
                if(credit_card_list[i] > 4):
                    checksum += credit_card_list[i] * 2 % 10 + 1
                else:
                    checksum += credit_card_list[i] * 2
            else:
                checksum += credit_card_list[i]
    
    #see if checksum amounts to a real card
    if(checksum % 10 == 0):
        if(credit_card_list[0] == 3):
            print("AMEX");
        if(credit_card_list[0] == 5):
            print("MASTERCARD");
        if(credit_card_list[0] == 4):
            print("VISA");
    else:
        print("INVALID")