test = int(input())




for _ in range(test):
    n_a_b = input().split(" ")
    n = int(n_a_b[0])
    a = int(n_a_b[1])
    b = int(n_a_b[2])

    dir_string = input()
    dir_string = [x for x in dir_string]

    # print(dir_string)

    x= 0
    y = 0 

    for _ in range (100):

        for c in dir_string:
            if dir_string[x] == "E":
                x+=1
            elif dir_string[x] == "W":
                x-=1
            elif dir_string[x] == "N":
                y+=1
            else:
                y-=1
                
            if x == a and y == b:
                print("YES")
                break
    
            




# f(x,y) = x+1, y+1
# list till a,b
# memo = [(x,y)] - break and say no
