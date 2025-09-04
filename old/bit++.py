statements= int(input())
x= 0

for i in range(statements):
    string = input()
    if string == "++X" or string == "X++":
        x+=1
    elif string == "--X" or string == "X--":
        x-=1
print(x)
