
class State:
    def __init__(self):
        stateProductions = []
        startOfProductions = []
        toNextState = []
allStates = []

numberOfProductions = int ( input() )
givenProductions = []
for _ in range(numberOfProductions):
    givenProductions.append(input())

terminals, nonTerminals = set(), set()
[terminals.add(ch) if ( 'a' <= ch <= 'z' ) else nonTerminals.add(ch) if ch != '-' else None for prod in givenProductions for ch in prod]

givenProductions = [ 'Z-' + givenProductions[0][0]] + givenProductions 
theProds,  nonTerminalsAdded = [0], []
for prod in theProds:
    currentProductionBeingScanned = givenProductions[prod]
    if currentProductionBeingScanned[2] in nonTerminals:
        if currentProductionBeingScanned[2] not in nonTerminalsAdded:
            nonTerminalsAdded.append(currentProductionBeingScanned[2])
            [theProds.append(k) if givenProductions[k][0] == currentProductionBeingScanned[2] else None for k in range(len(givenProductions))]
sorted(theProds)
startFortheProds = [ (i, 2) for i in theProds]
st00 = State()
st00.stateProductions, st00.startOfProductions = theProds, startFortheProds
allStates.append(st00)

currentStateBeingChecked = 0
while ( currentStateBeingChecked < len(allStates) ):
    jumpsMade = []
    s1 = allStates[currentStateBeingChecked]
    for i in range (len(s1.startOfProductions)):
        a, b = s1.startOfProductions[i]
        if givenProductions[a][b] not in jumpsMade:
            jumpsMade.append(givenProductions[a][b])
            pi, sop, nta = [], [], []
            for j in range(i, len(s1.startOfProductions)):
                c, d = s1.startOfProductions[j]
                if d < len (givenProductions[c]) and givenProductions[c][d] == givenProductions[a][b]:
                    pi.append(c)
                    sop.append((c,d+1))
            
            for x, y in sop:
                currentProductionBeingScanned = givenProductions[prod]
                if y < len(currentProductionBeingScanned):
                    if currentProductionBeingScanned[y] in nonTerminals:
	                if currentProductionBeingScanned[y] not in nonTerminalsAdded:
	                nonTerminalsAdded.append(currentProductionBeingScanned[y])
	                for k in range (len(givenProductions)):
                            if currentProductionBeingScanned[y] == givenProductions[k][0]:
                                pi.append(k)
                                sop.append((k,2))
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
 














