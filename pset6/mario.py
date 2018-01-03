import cs50

while True:
    print("Height: ", end="")
    h = cs50.get_int();
    if h >= 0 or h < 24:
        break
    
for i in range(h):
    
    for spaces in range(h - (1 + i)):
        print(" ", end="")
        
    for hash in range(1 + i):
        print("#", end="")
        
    print("  ", end="")
    
    for hash_two in range(1 + i):
        print("#", end="")
    
    print("")
    