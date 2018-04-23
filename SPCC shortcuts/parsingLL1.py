
nonTerminals = [ 'E', 'D', 'T', 'U', 'F' ]
terminals = [ 'i', '+', '*', '(', ')', '$']

givenProductions = [ 'E-TD', 'D-+TD', 'D-e', 'T-FU', 'U-*FU', 'U-e', 'F-(E)', 'F-i']

table = [ [ 0, -1, -1, 0, -1, -1], [ -1, 1, -1, -1, 2, 2], [ 3, -1, -1, 3, -1, -1], [-1, 5, 4, -1, 5, 5], [ 7, -1, -1, 6, -1, -1] ] 

stack = [ '$', 'E' ]
string = 'i+i*i$'

parsed = 1
try:
    while True:
        if stack [-1] in nonTerminals:
            if table[nonTerminals.index(stack [-1])][terminals.index(string[0])] != -1:
                stack += list(givenProductions[table[nonTerminals.index(stack.pop())][terminals.index(string[0])]][2:])[::-1]
            else :
                parsed = 0
                break
        elif stack [-1] != '$' and stack [-1] == string[0]:
            stack = stack [:len(stack)-1]
            string = string [1:]
        else :
            print ('here')
            if stack == ['$'] and string == '$': 
                break     
            if stack[-1] == 'e':
                stack.pop()
            else :
                parsed = 0
                break
except: 
    parsed = 0

print ( "Valid" if parsed == 1 else "Invalid" )
