#!/usr/bin/python
'''
In England the currency is made up of pound, L, and pence, p, and there are eight coins in general circulation:

    1p, 2p, 5p, 10p, 20p, 50p, L1 (100p) and L2 (200p).

It is possible to make L2 in the following way:

    1xL1 + 1x50p + 2x20p + 1x5p + 1x2p + 3x1p

How many different ways can L2 be made using any number of coins?
'''
coins = [200,100,50,20,10,5,2,1]
counter = 0
coincount = [0,0,0,0,0,0,0,0]

def findcoincombo(amount):
    global counter
    global coins
    global coincount

    for k,i in enumerate(coins):
        if amount==i:
            coincount[k] = 1

    getcombocount(coincount,amount)

def getcombocount(coincountlist,amount):
    global counter
    global coins

    remainder = 0
    start = 0
    for k,i in enumerate(coincountlist):
        if start==1 or i>0:
            start = 1
            if i*coins[k] == amount and (len(coins)-1) > (k+1):
                coincountlist[k] -= 1
                carryunder = amount - coincountlist[k]
                coincountlist[k+1] = carryunder / coins[k+1]
                if (carryunder % coins[k+1]) > 0:
                    coincountlist[k+2] += 1
                getcombocount(coincountlist,amount)
            else:
                

findcoincombo(10)
print counter
print coincount
