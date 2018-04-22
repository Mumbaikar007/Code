
lexstr = input ()

lexstr = lexstr.replace("id", "F")
print (lexstr)
while ( lexstr.find("*") > -1):
    a = lexstr.find("*")
    if lexstr[a-1] == 'F' and lexstr[a+1] == 'F':
         lexstr.replace("F*F", "T", 1)
    elif lexstr[a-1] == 'T' and lexstr[a+1] == 'F':
        lexstr = lexstr.replace("T*F", "T", 1)

lexstr = lexstr.replace("F", "T")

while ( lexstr.find("+") > -1):
    a = lexstr.find("+")
    if lexstr[a-1] == 'T' and lexstr[a+1] == 'T':
        lexstr = lexstr.replace("T+T", "E", 1)
    elif lexstr[a-1] == 'E' and lexstr[a+1] == 'T':
        lexstr = lexstr.replace("E+T", "E", 1)

print ("Valid") if lexstr == "E" else print ("Invalid")
   
