from collections import deque
# 1 1 1
# 6 5 7 8
# 6 11 18 20 15 8
#
#

def compute(l1, l2):
    len_l1 = len(l1)
    len_l2 = len(l2)

    len_compute = 0

    if len_l1 < len_l2:
        len_compute = len_l1
    else:
        len_compute = len_l2 
    ans = 0
    for i in range(len_compute):
        ans += l1[i] * l2[i]

    return ans



def convolution_1d(f, g):
    len_f = len(f)
    len_g = len(g)

    if(len_g > len_f):
        convolution_1d(g, f)

    len_total = len_f + len_g - 1

    added = [0 for i in range(len_f)]
    g = g + added

    #sliding window
    conved = [] #output
    q = []

    conv_len = len_f 

    for t in range(len_total):
        q.append(g[t])

        if len(q) > conv_len:
            q.pop(0)
        conved.append(compute(f, q))
    
    return conved



f = [1, 1, 1]
g = [6, 5, 7, 8]

conv1 = convolution_1d(f,g)
print(conv1)