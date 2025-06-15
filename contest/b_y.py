year = str(input())
year = str(int(year)+1)
s = set([c for c in year])
# print(s)

while (len(year) != len(s)):
    year = str(int(year)+1)
    s = set([c for c in year])

print(year)

