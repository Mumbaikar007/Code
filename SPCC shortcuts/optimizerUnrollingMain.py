
import time
import os

lines = []
with open('optimizerUnrolling.py') as f:
    while 
    lines.append(f.readline())

print (len(lines))
ta = time.time()

os.system("python ~/Projects/Code/SPCC\ shortcuts/optimizerUnrolling.py")

tb = time.time()

lines[0] = lines[0][0:-3]
print (lines[1])

os.system("touch ~/Projects/Code/SPCC\ shortcuts/optimizedUnrolling2.py")
fw = open('optimizedUnrolling2.py', "w+")

for l in lines:
    fw.write(l)

#os.system("python ~/Projects/Code/SPCC\ shortcuts/optimizedUnrolling.py")

tc = time.time()


print (tb-ta)
print (tc-tb)


