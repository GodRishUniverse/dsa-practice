t = int(input())

for i in range(t):
    word = str(input())
    if (len(word)>10):
        print(word[0]+str(len(word)-2)+word[-1])
    else:
        print(word)
