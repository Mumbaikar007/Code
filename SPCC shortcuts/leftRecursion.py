
numberOfProductions = int ( input ("Enter number of productions: ") )
productions = []
for _ in range(numberOfProductions):
    productions.append(input())

A,B =[], []

[A.append(prod[3:]) if prod[0] == prod[2] else B.append(prod[2:]) for prod in productions]

print ( productions[0][0] + "-" , end = ' ')
for b in B:
    print ( b + productions[0][0] + '\'', end = ' | ' )
print ("\n" + productions[0][0] + '\'-', end = ' ')
for a in A:
    print ( a + productions[0][0] + '\'', end = ' | ' )
print ( chr(157) )

