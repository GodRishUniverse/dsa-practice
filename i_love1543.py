test_cases = int(input())

# solution is correct but time limit exceeded - optimize (can be done if we check for cycles - maybe use DFS)
for _ in range(test_cases):
    n, m = map(int, input().split(" "))
    matrix = []
    for _ in range(n):
        matrix.append([int(x) for x in list(input())])
    
    # [[ [1,2], [], [], [] ], ]
    temp_r = 0
    temp_c = 0
    hold_arr = []
    edge_one = [0,m-1]
    edge_two = [n-1,m-1]
    edge_three = [n-1,0]
    edge_four = [temp_r,temp_c]

    

    while temp_r <= (n-1)//2 and temp_c <= (m-1)//2:
        count = 1
        val_r = temp_r 
        val_c = temp_c

        temp_arr= []
        while count != 2*2*(edge_two[0] + edge_two[1]):
            if matrix[val_r][val_c] == 1:
                if len(temp_arr) == 0:
                    temp_arr.append([1,val_r, val_c])
                else:
                    temp_arr= []
                    temp_arr.append([1,val_r, val_c])
            elif matrix[val_r][val_c] == 5:
                if len(temp_arr) == 1:
                    if temp_arr[-1][0] ==1 :
                        temp_arr.append([5,val_r, val_c])
                    else:
                        temp_arr= []
            elif matrix[val_r][val_c] == 4:
                if len(temp_arr) == 2:
                    if temp_arr[-2][0] ==1 and temp_arr[-1][0] ==5:
                        temp_arr.append([4,val_r, val_c])
                    else:
                        temp_arr= []
            elif matrix[val_r][val_c] == 3:
                if len(temp_arr) == 3:
                    if temp_arr[-3][0] ==1 and temp_arr[-2][0] ==5 and temp_arr[-1][0] ==4:
                        temp_arr.append([3,val_r, val_c])
                        if temp_arr not in hold_arr:
                            hold_arr.append(temp_arr)
                        temp_arr = []
                    else:
                        temp_arr= []
            else:
                temp_arr= []
            
            if val_r ==edge_one[0] and val_c < edge_one[1]:
                val_c+=1
            elif val_r < edge_two[0] and val_c == edge_two[1]:
                val_r+=1
            elif val_r == edge_three[0] and val_c > edge_three[1]:
                val_c-=1
            elif val_r > edge_four[0] and val_c == edge_four[1]:
                val_r-=1

            count+=1

        temp_r+=1
        temp_c+=1

        edge_one = [temp_r, m-1-temp_c]         # Top edge
        edge_two = [n-1-temp_r, m-1-temp_c]     # Right edge
        edge_three = [n-1-temp_r, temp_c]       # Bottom edge
        edge_four = [temp_r, temp_c]            # Left edge


    print(len(hold_arr))
    # print(hold_arr)
