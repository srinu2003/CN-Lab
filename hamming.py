a,b = 3,6
print(list(map(bin,[a,b])))
print((a^b),bin(a^b))
msg = [ 0,0,0,1,
        1,0,1,0,
        1,0,1,0,
        1,0,0,1 ]
# msg = [ 1,0,1,1,
#         0,1,1,0,
#         0,0,0,1,
#         0,0,1,0 ]
p =0
for i in range(1,len(msg)):
    if(msg[i]==1):
        p ^=i
print(bin(p))
print(p)