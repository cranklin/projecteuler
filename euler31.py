#!/usr/bin/python
'''
In England the currency is made up of pound, L, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, L1 (100p) and L2 (200p).

It is possible to make L2 in the following way:

    1xL1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p

How many different ways can L2 be made using any number of coins?
'''
coins = [200,100,50,20,10,5,2,1]

def findcoincombo(amount):
    global coins
    counter = 1
    coincount = [0,0,0,0,0,0,0,0]

    for k,i in enumerate(coins):
        if amount==i:
            coincount[k] = 1

    done = False
    current = 0
    direction = "right"
    while not done:
        if coincount[current] == 0:
            if direction == "left":
                if current == 0:
                    done = True
                else:
                    current -= 1
            elif direction == "right":
                if current == len(coins)-2:
                    direction = "left"
                else:
                    current += 1
        else:
            direction = "right"
            coincount[current] -= 1
            leavealone = 0
            for i in range (0,len(coins)):
                if i <= current:
                    leavealone += coincount[i] * coins[i]
                    carryunder = amount - leavealone
                else: 
                    coincount[i] = 0
            coincount[current+1] += carryunder / coins[current+1]
            if (carryunder % coins[current+1]) > 0:
                coincount[current+2] += (carryunder % coins[current+1]) / coins[current+2]
                if current < len(coins)-3:
                    current += 2
                else:
                    current += 1
            elif current < len(coins)-2:
                current += 1
            counter += 1
            #print coincount
            #print current
            #print direction
    return counter

counter = findcoincombo(200)
print counter
