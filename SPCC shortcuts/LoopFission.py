
import time

u,x,y,z = [],[],[],[]

ta = time.time()

for i in range (1, 50):
    u.append(0)
    x.append(0)

tb =time.time()

for i in range (1, 50):
    y.append(0)

for i in range (1, 50):
    z.append(0)

tc = time.time()

print (tb-ta)
print (tc-tb)
