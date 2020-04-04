
from itertools import combinations
import numpy as np
import sys

def cmp(bit):
 return [
    '_' if bt == '_' else 
    '1' if bt =='0' else '0' 
    for bt in bit
]

class qarr():
    def __init__(self, bt):
        self.bit = ['_'] * bt
        self.unkown = list(range(bt))
        self.read(10)
        self.run()

    def read(self, no):
        for _ in range(no):
            k = self.unkown.pop()
            self.bit[k] = self.readbits(k+1)
            self.unkown = self.unkown[::-1]
        self.updatestates()

    def readbits(self, k):. #reading bits
        print(k, flush=True)
        return input()

    def updatestates(self):
        self.bitsc  = cmp(self.bit)
        self.bitscr = self.bitsc[::-1]
        self.bitsr  = cmp(self.bitscr)
        self.state = [self.bit, self.bitsc, self.bitscr, self.bitsr]

    def getestindex(self):
        candid = list(set(range(bb)) - set(self.unkown))
        maxstates = len(set(map(tuple, self.state)))
        for index in combinations(candid, 2):
            numstates = len(set(
                tuple(np.take(state, index))
                for state in self.state
            ))
            if numstates == maxstates: return index

    def colp(self):        #collapse function
        test_index = self.getestindex()
        test = [self.readbits(k+1) for k in test_index]
                
        self.bit = next(state
            for state in self.state
            if test == list(np.take(state, test_index))
        )

    def run(self):.  #function to run
        while True:
            self.colp()
            try: self.read(8)
            except IndexError: break
    

tt, bb = map(int, input().split()) #input and join bit in array
print('B:', bb, file=sys.stderr)
for _ in range(tt): 
    array = qarr(bb)
    print('guess:', ''.join(array.bit), file=sys.stderr)
    print(''.join(array.bit), flush=True)
    if input() == 'N': sys.exit() 
