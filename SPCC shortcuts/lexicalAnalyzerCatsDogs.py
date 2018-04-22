
ss = input("Enter string:")

ss = ss.replace("hate","V")
ss = ss.replace("love","V")
ss = ss.replace("if","i")
ss = ss.replace("then","t")
ss = ss.split()

print (ss) 

for i in range (len(ss)):
    if ss[i] not in ('they', 'i', 't', 'V'):
        ss[i] = 'N'


ss = "".join(ss)

ss = ss.replace("theyN","A")
ss = ss.replace("NVN","P")
ss = ss.replace("iPtA","L")

#print (ss)

valid = 1
for ch in ss:
    if ch != 'L':
        valid = 0
        break

print ( "Valid" if (valid or ss == "") else "Invalid") 

'''
if dogs hate cats then they bark. if cats love milk then they drink.
'''

