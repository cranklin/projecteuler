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

def findcoincombo(amount,startindex=0):
    global counter
    global coins
    if amount == 0:
        counter+=1
        return
    for k,i in enumerate(coins):
        if amount >= i and k >= startindex:
            for j in range(0,(amount/i)+1):
                testamount = amount-j*i
                findcoincombo(testamount,k+1)
findcoincombo(10)
print counter
