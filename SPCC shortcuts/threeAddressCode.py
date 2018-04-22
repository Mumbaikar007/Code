

OPERATORS = set ( ['+', '-', '*', '/', '(', ')' ] )
PRIORITY = { '+': 1, '-': 1, '*': 2, '/': 2 }
tagsInTagged = []
tagged = {}

def Infix_to_postfix ( formula ) :
    stack = []
    output = ''
    for ch in formula:
        if ch not in OPERATORS:
            output += ch
        elif ch == '(':
            stack.append('(')
        elif ch == ')':
            while stack and stack[-1] != '(':
                output += stack.pop()
            stack.pop()
        else:
            while stack and stack[-1] != '(' and PRIORITY[ch] <= PRIORITY[stack[-1]]:
                output += stack.pop()
            stack.append(ch)

    while stack: 
        output += stack.pop()
    print (output)
    return output

def Evaluate_postfix ( formula ):
    stack = []
    tags = ord('A') 
    for ch in formula:
        if ch not in OPERATORS:
            stack.append(ch)
        else :
            b = stack.pop()
            a = stack.pop()
            if (a,ch,b) not in tagsInTagged:
                tagged [(a,ch,b)] = chr(tags)
                tagsInTagged.append((a,ch,b))
                tags += 1
            stack.append(tagged [(a,ch,b)])

Evaluate_postfix ( Infix_to_postfix ( input() ) )
sorted(tagged, key= lambda x: x[1])
for key,val in tagged.items():
    print (key, "=>", val)
