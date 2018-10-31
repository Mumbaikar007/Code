
numberOfProductions = int ( input() )
givenProductions = []
for _ in range (0, numberOfProductions):
  givenProductions.append(input())
print ( givenProductions )

terminals, nonTerminals = set (), set()
[terminals.add(ch) if ( 'a' <= ch <= 'z' or ch in ( '+', '*', '(', ')','/','~')) else nonTerminals.add(ch) if (ch != '-' ) else None for prod in givenProductions for ch in prod]
print (terminals, nonTerminals)

first =  { nt : set() for nt in nonTerminals }
def RecursiveFirst(ch):
  if (len(first[ch]) == 0):
    for prod in givenProductions:
      if prod[0] == ch:
        flagEnded = 0
        for i in range (2, len(prod)):
          if flagEnded == 1:
            break
          if prod[i] in terminals:
            first[ch].add(prod[i])
            flagEnded = 1
            break
          else :
            if len(first[prod[i]]) == 0:
              RecursiveFirst(prod[i])
            if 'e' in first[prod[i]]:
              first[ch] |= first[prod[i]]
              first[ch].remove('e')
            else:
              first[ch] |= first[prod[i]]        
              flagEnded = 1
        if flagEnded == 0:
          first[ch].add('e')
for ch in nonTerminals:
  RecursiveFirst (ch)
print ( first )

print ("*************************************")
follow =  { nt : set() for nt in nonTerminals }
follow[givenProductions[0][0]].add('$')
def RecursiveFollow(ch):
  for prod in givenProductions:
    for i in range (2,len(prod)):
      if ( prod[i] == ch):
        hopingForNext = 1
        for j in range(i+1,len(prod)):
          if prod[j] in terminals:
            follow[ch].add(prod[j])
            hopingForNext = 0
            break
          else:
            if 'e' in first[prod[j]]:
              follow[ch] |= first[prod[j]]
              follow[ch].remove('e')
            else :
              follow[ch] |= first[prod[j]]
              hopingForNext = 0
              break
        if ( hopingForNext == 1):
          if ch == prod[0]:
            continue
          [RecursiveFollow(prod[0]) if len(follow[prod[0]]) == 0 else None]
          follow[ch] |= follow[prod[0]]
[RecursiveFollow(ch) for ch in nonTerminals]
[RecursiveFollow(ch) for ch in nonTerminals]
print(follow)

