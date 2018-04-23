
nonTerminals = [ 'E', 'B' ]
terminals = [ 'c', 'd', '$']
cols = terminals + nonTerminals

givenProductions = [ 'Z-E', 'E-BB', 'B-cB', 'B-d']

table = [ [ 3, 4, -1, 1, 2], [ -1, -1, 'A', -1, -1], [ 3, 4, -1, -1, 5], [ 3, 4, -1, -1, 6], [ 10, 10, 10, -1, -1], [ 11, 11, 11, -1, -1], [ 12, 12, 12, -1, -1] ] 

stack = [ '$', 0 ]
string = 'ccdd$'

parsed = 0
try:
    while True:
        print (stack[-1])
        if stack[-1] >= 10: 
            prod = givenProductions[table[stack[-1] - 10][cols.index(string[0])]][2:]
            while prod:
                stack.pop()
                stack.pop()
                prod = prod[:len(prod)-1]
            stack.append(givenProductions[table[stack[-1]][cols.index(string[0])] - 10][0])
            stack.append(table[stack[-2]][cols.index(givenProductions[table[stack[-1]][cols.index(string[0])] - 10][0])])
        elif 0 <= table[stack[-1]][cols.index(string[0])] <= 10:
            toAdd = [ string[0], table[stack[-1]][cols.index(string[0])] ]
            stack += toAdd
            string = string [1:]
            print (string, stack)
        elif table[stack[-1]][cols.index(string[0])] > 10:
            prod = givenProductions[table[stack[-1]][cols.index(string[0])] - 10][2:]
            while prod:
                stack.pop()
                stack.pop()
                prod = prod[:len(prod)-1]
            stack.append(givenProductions[table[stack[-1]][cols.index(string[0])] - 10][0])
            stack.append(table[stack[-2]][cols.index(givenProductions[table[stack[-1]][cols.index(string[0])] - 10][0])])
        else:
            print ("-1")
            parsed = 1
            break

except Exception as e: 
    print ('' + e)
    parsed = 0

print ( "Valid" if parsed == 1 else "Invalid" )
