n = int(input())
s = str(input())

a =0 
d =0

for c in s:
    if c=="A":
        a+=1
    else:
        d+=1

if (a==d):
    print("Friendship")
elif(a>d):
    print("Anton")
else:
    print("Danik")
