class State:
    def __init__ (self):
        self.statesProductions = []
        self.startOfProductions = []
        self.toNextState = []
        self.somethingJustReduced = []
allStates = []

numberOfProductions = int ( input() )
givenProductions = []
for _ in range (0, numberOfProductions):
  givenProductions.append(input())

terminals, nonTerminals = set(), set()
[terminals.add(ch) if ( 'a' <= ch <= 'z') else nonTerminals.add(ch) if (ch != '-') else None for prod in givenProductions for ch in prod]

givenProductions = [ 'Z-' + givenProductions[0][0] ] + givenProductions
theProds, nonTerminalsAdded = [0],  []
for prods in theProds:
    currentProd = givenProductions[prods]
    if currentProd[2] in nonTerminals:
        if currentProd[2] not in nonTerminalsAdded:
            nonTerminalsAdded.append(currentProd[2])
            [theProds.append(k) if givenProductions[k][0] == currentProd[2] else None for k in range (0, len(givenProductions) )]
sorted(theProds)
startingForTheProds = [ (i,2) for i in theProds ]
state00 = State()
state00.statesProductions, state00.startOfProductions = theProds,  startingForTheProds
print (state00.startOfProductions)
allStates.append(state00)
currentStateBeingChecked = 0
while (currentStateBeingChecked < len(allStates)):
    jumpsMade = []
    s1 = allStates[currentStateBeingChecked]
    for i in range(len(s1.startOfProductions)):
        a, b = s1.startOfProductions[i]
        if b < len(givenProductions[a]):
            if givenProductions[a][b] not in jumpsMade:
                jumpsMade.append(givenProductions[a][b])
                productionsIndexes, productionsIndexesAddinfProductions, startingProductions, productionNonTerminals = [], [], [], []
                for j in range(i, len(s1.startOfProductions)):
                    c,d = s1.startOfProductions[j]
                    if d >= len(givenProductions[c]) :
                        s1.somethingJustReduced.append((c,d))
                    elif givenProductions[a][b] == givenProductions[c][d]:
                        productionsIndexes.append (c)
                        startingProductions.append((c,d+1))
                for x,y in startingProductions:
                    currentProductionsBegingScanned = givenProductions[x]
                    if y < len(currentProductionsBegingScanned):
                        if currentProductionsBegingScanned[y] in nonTerminals:
                            if currentProductionsBegingScanned[y] not in productionNonTerminals:
                                productionNonTerminals.append(currentProductionsBegingScanned[y])
                                for k in range(len(givenProductions)):
                                    if givenProductions[k][0] == currentProductionsBegingScanned[y] :
                                        productionsIndexes.append(k)
                                        startingProductions.append((k,2))
                sorted(productionsIndexes)
                sorted(startingProductions, key=lambda x:x[0])
                stateNew = State()
                stateNew.statesProductions, stateNew.startOfProductions = productionsIndexes,startingProductions
                flag, zz = 1, 0
                for ss in allStates:
                    if ss.startOfProductions == startingProductions:
                        allStates[currentStateBeingChecked].toNextState.append((givenProductions[a][b], zz) )
                        flag = 0
                        break
                    zz += 1
                if flag == 1:
                    allStates.append(stateNew)
                    allStates[currentStateBeingChecked].toNextState.append((givenProductions[a][b], len(allStates) - 1))
    currentStateBeingChecked += 1

terminals = list(terminals)
nonTerminals = list(nonTerminals)
terminals.append('$')

rows = len(allStates)
cols = len(nonTerminals) + len(terminals) + 1
a = ['-'] * rows
for i in range(rows):
    a[i] = ['-'] * cols
for i in range(len(allStates)):
    a[i][0] = 'I' + str(i)
    if ( i == 1):
       	a[1][len(terminals)] = 'Accept'
    if len(allStates[i].toNextState) == 0 and i != 1:
        if len(allStates[i].somethingJustReduced) != 0:
            
    for m,n in allStates[i].toNextState :
        if m in terminals:
            a[i][terminals.index(m)+1] = 'S'+str(n)
        else:
            a[i][nonTerminals.index(m)+1+len(terminals)] = str(n)
print ('%-12s' % ('Table'), end = ' ' )
for i in terminals:
    print ('%-12s' % (i), end = ' ' )
for i in nonTerminals:
    print ('%-12s' % (i), end = ' ' )
print ()
for i in range(rows):
    for j in range(cols):
        print ('%-12s' % a[i][j], end = ' ')
    print ()
