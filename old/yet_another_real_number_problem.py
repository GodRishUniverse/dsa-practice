
# needd to fix it
def sum_of_digits(a, i, j,  total_arr, counter = 0,):

    if j >= len(a):
            return total_arr
    
    if i ==j:
        total_arr[counter] = a[i]
        return sum_of_digits(a, i, j+1, total_arr, counter+1)    
    else:
        max_sum = sum(a[0:j+1])
        while a[i]%2 ==0:
            a[i] //=2
            a[j] *=2
            
            max_sum = max(max_sum, sum(a[0:j+1]))
            print(a, i, j, max_sum, counter)

        total_arr[counter] = max_sum

  
        if j >= len(a)-1:
            return total_arr
        return sum_of_digits(a, i+1, j+1, total_arr, counter+1)


    

t = int(input())

total_sums = []

for test_case in range(t):
    len_a = int(input())
    a = input()
    a = [int(x) for x in a.split(" ")]
    i = j = 0

    total_arr = [0]*len_a

    total_arr = sum_of_digits(a, i, j, total_arr,counter=0)

    total_sums.append(total_arr)

        
for s in total_sums:
    s = [val % (10**9 + 7) for val in s]
    print(*s)
