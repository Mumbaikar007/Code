
lexstr = input()
lexstr = lexstr.replace(" ", "")

lexstr = lexstr.replace("a++","A")
lexstr = lexstr.replace("b++","A")

lexstr = lexstr.replace("a>b","C")
lexstr = lexstr.replace("a<b","C")

lexstr = lexstr.replace("if","i")
lexstr = lexstr.replace("then","t")

lexstr = lexstr.replace("iCtA", "S")

valid = 1
for ch in lexstr:
    if ch != 'S':
        valid = 0
        break

print ( "Valid" if (valid or lexstr == "") else "Invalid") 
