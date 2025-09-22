n = int(input())
while (n!=0):
    m,o,s = [*input().split(" ")]
    if (s =="+"):
        print(f"{int(m)*int(o)/100}")
    else:
        print(f"{float(float(m)/float(o)*100):.5f}")

    n-=1
