
def string_to_dict_freq(string):
    freq_dict = {}
    for char in string:
        if char not in freq_dict:
            freq_dict[char] = 1
        else:    
            freq_dict[char] += 1
    return len(set(freq_dict.values()))

x = input()
possible = False
length = len(set(x))
char_dict = {}
for i in range(len(x)):
    
    new_str = x[:i] + x[i+1:]
    print(new_str)
    if string_to_dict_freq(new_str) == 1:
        
        possible = True
        break
print(possible)
