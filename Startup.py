t = int (input())

profit = []

for test_case in range(t):
    n_k = input()
    n_k = [int(x) for x in n_k.split(" ")]
    n = n_k[0]
    k = n_k[1]

    dict_list = {}


    for bottles in range(k):
        brand_cost  = input()
        brand_cost = [int(x) for x in brand_cost.split(" ")]

        if brand_cost[0] not in dict_list:
           dict_list[brand_cost[0]] = 0

        dict_list[brand_cost[0]] += brand_cost[1]
    
    if n <k :
        vals = sorted(dict_list.values(), reverse=True)
        profit.append(sum(vals[:n]))
    else:
        profit.append(sum(dict_list.values()))
        
for i in profit:
    print(i)
