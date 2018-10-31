
nonTerminals = [ 'E', 'B' ]
terminals = [ 'c', 'd', '$']
cols = terminals + nonTerminals

givenProductions = [ 'Z-E', 'E-BB', 'B-cB', 'B-d']

table = [ [ 3, 4, -1, 1, 2], [ -1, -1, 'A', -1, -1], [ 3, 4, -1, -1, 5], [ 3, 4, -1, -1, 6], [ 13, 13, 13, -1, -1], [ 11, 11, 11, -1, -1], [ 12, 12, 12, -1, -1] ] 

stack = [ '$', 0 ]
string = 'cc1dd$'

parsed = 0
try:
    while True:
        if stack [-1] == 1 and string == '$':
            parsed = 1
            break
        if 0 <= table[stack[-1]][cols.index(string[0])] < 10:
            toAdd = [ string[0], table[stack[-1]][cols.index(string[0])] ]
            stack += toAdd
            string = string [1:]
            print (string, stack)
        elif table[stack[-1]][cols.index(string[0])] >= 10:
            a = givenProductions[ table[stack[-1]][cols.index(string[0]) ] - 10][0]
            prod = givenProductions[ table[stack[-1]][cols.index(string[0]) ] - 10][2:]
            while prod:
                stack.pop()
                stack.pop()
                prod = prod[:-1]
            
            lis = [ a, table[stack[-1]][cols.index(a)] ]
            
            stack += lis
            print ( stack )
        else:
            print ("-1")
            parsed = 1
            break

except Exception as e: 
    #print ('' + e)
    parsed = 0

print ( "Valid" if parsed == 1 else "Invalid" )
