n_p_q_r = input().split(" ")
n = int(n_p_q_r[0])
p = int(n_p_q_r[1])
q = int(n_p_q_r[2])
r = int(n_p_q_r[3])


# 5 1 2 3
# 1 2 3 4 5

# #  i= j = k 
#     change to case 2
# #  i =j < k 
#     change to case 2 or case 3 or case 4
# #  i < j = k
#     change case 1 or case 3 or  case 4
# #  i <j < k
#     change to case 2 or case 3 or cse 4

"""
GETTING RUNTIME ERROR ON TEST CASE 5 on code forces
"""

# def f(a, i, j, k, memo):
#     calculation = p*a[i] + q*a[j] + r*a[k]
#     # print(calculation)
    
#     if (i, j, k) in memo:
#         return memo[(i, j, k)]

#     memo[(i, j, k)] = calculation

#     if k == len(a)-1:
#         if j ==k and i < j:
#             return max(calculation, f(a, i+1, j, k, memo))
#         if i==j and j < k:
#             return max(calculation, f(a, i, j+1, k, memo))
#         if i<j and j < k:
#             return max(calculation, f(a, i+1, j, k, memo), f(a, i, j+1, k, memo))
#         if i==j and j == k:
#             return calculation
#     else:
#         if i==j and j == k:
#             return max(calculation, f(a, i, j, k+1,memo))
#         if i==j and j < k:
#             return max(calculation, f(a, i, j, k+1, memo), f(a, i, j+1, k, memo))
#         if i<j and j == k:
#             return max(calculation, f(a, i+1, j, k, memo), f(a, i, j, k+1, memo))
#         if i<j and j < k:
#             return max(calculation, f(a, i+1, j, k, memo), f(a, i, j+1, k, memo), f(a, i, j, k+1, memo))
    
# arr = input().split(" ")
# arr = [int(x) for x in arr]

# print(f(arr, 0, 0, 0, {}))


def f(a):
    i = j = k = 0
    memo = []
    while i != len(a) or j != len(a)-1 or k != len(a)-1:
        calculation = p*a[i] + q*a[j] + r*a[k]
        memo.append(calculation)
        # print(calculation, i, j , k)

        if k == len(a)-1:
            if j==k:
                if i ==j:
                    break
                else:
                    i+=1

            else:
                j+=1
        else:
            k+=1
    
    # print(memo)
    return max(memo)

        

    
arr = input().split(" ")
arr = [int(x) for x in arr]

print(f(arr))
