
from itertools import combinations
import numpy as np
import sys

def cmp(bit): return [
    '_' if bt == '_' else 
    '1' if bt =='0' else '0' 
    for bt in bit
]

class qarr():
    def __init__(self, BT):
        self.bit = ['_'] * BT
        self.unkown = list(range(BT))
        self.read(10)
        self.run()

    def read(self, nn):
        for _ in range(nn):
            i = self.unkown.pop()
            self.bit[i] = self.readbits(i+1)
            self.unkown = self.unkown[::-1]
        self.updatestates()

    def readbits(self, i):
        print(i, flush=True)
        return input()

    def updatestates(self):
        self.bitsc  = cmp(self.bit)
        self.bitscr = self.bitsc[::-1]
        self.bitsr  = cmp(self.bitscr)
        self.state = [self.bit, self.bitsc, self.bitscr, self.bitsr]

    def get_test_index(self):
        candid = list(set(range(BB)) - set(self.unkown))
        maxstates = len(set(map(tuple, self.state)))
        for index in combinations(candid, 2):
            numstates = len(set(
                tuple(np.take(state, index))
                for state in self.state
            ))
            if numstates == maxstates: return index

    def colle(self):        
        test_index = self.get_test_index()
        test = [self.readbits(i+1) for i in test_index]
                
        self.bit = next(state
            for state in self.state
            if test == list(np.take(state, test_index))
        )

    def run(self):
        while True:
            self.colle()
            try: self.read(8)
            except IndexError: break
    

tt, BB = map(int, input().split())
print('B:', BB, file=sys.stderr)
for _ in range(tt): 
    array = qarr(BB)
    print('guess:', ''.join(array.bit), file=sys.stderr)
    print(''.join(array.bit), flush=True)
    if input() == 'N': sys.exit() 