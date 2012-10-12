#!/usr/bin/python
'''
Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

    1634 = 1^4 + 6^4 + 3^4 + 4^4
    8208 = 8^4 + 2^4 + 0^4 + 8^4
    9474 = 9^4 + 4^4 + 7^4 + 4^4

As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.
'''
dict = {'0':0}

def prep():
    for i in range(1,10):
        dict[str(i)] = i**5
    return

def find():
    finalanswer = 0
    for i in range(2,999999):
        tempsum = 0
        for j in range(0,len(str(i))):
            tempsum += dict[str(i)[j]]
        if tempsum == i:
            print "found! ",tempsum
            finalanswer += tempsum
        #else:
            #print "ehh... ",tempsum
    print "final answer: ",finalanswer
    return
prep()
find()
