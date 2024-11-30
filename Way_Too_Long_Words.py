
count  = int(input())

list_words = []

for i in range(count):
    string = input()
    list_words.append(string)

for i in list_words:
    if len(i) > 10:
        print(i[0] + str(len(i) - 2) + i[-1])
    else:
        print(i)
    