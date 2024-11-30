test_cases = int(input())

for _ in range(test_cases):
    n = int(input())
    if n % 2 ==0:
        print("3"*(n-2) + "66")
    elif n ==1 or n ==3:
        print(-1)
    else:
        print("3"*(n-5) + "36366")
