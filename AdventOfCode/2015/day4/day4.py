#! python3 
# day4.py - Day 4 of advent of code 2015
from hashlib import md5
import sys

key = "bgvyzdsv"

# Part 1
number = 1
while True:
    codified = md5((key + str(number)).encode())
    coin = codified.hexdigest()
    #sys.stdout.write('\r')
    #sys.stdout.write("Coin: %s, number: %s" % (coin, number))
    #sys.stdout.flush()
    if coin[:5] == "00000":
        print("Coin: %s, number: %s" % (coin, number))
        break
    number += 1


# Part 2
number = 1
while True:
    codified = md5((key + str(number)).encode())
    coin = codified.hexdigest()
    #sys.stdout.write('\r')
    #sys.stdout.write("Coin: %s, number: %s" % (coin, number))
    #sys.stdout.flush()
    if coin[:6] == "000000":
        print("Coin: %s, number: %s" % (coin, number))
        break
    number += 1

