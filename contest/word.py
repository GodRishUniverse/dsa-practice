s = str(input())

u =0
l =0
for c in s:
    if c.upper()==c:
        u+=1
    else:
        l+=1 

print(s.upper() if (u>l) else s.lower())
