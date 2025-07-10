melodies = int (input())
yess_or_no  = [ ]
for i in range(melodies):
    melody = int(input())

    inp = input()
    str_i = inp.split(" ")

    str_i = [ int(x) for x in str_i ]

    count = 0 
    for j in range(melody -1 ):
        if (abs(str_i[j] - str_i[j+1])  == 5  or abs(str_i[j] - str_i[j+1]) == 7):
            count+=1
    
    if count == melody-1:
        yess_or_no.append("YES")
    else:
        yess_or_no.append("NO")

for i in yess_or_no:
    print(i)

