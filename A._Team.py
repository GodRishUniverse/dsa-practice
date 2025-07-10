count  = int(input())

binary_split = []

for i in range(count):
    string = input()
    binary_split.append(string)

problems_solved = 0
for i in binary_split:
    get_yes = [int(x) for x in i.split(" ")]
    if sum(get_yes) >= 2:
        problems_solved += 1
print(problems_solved)
