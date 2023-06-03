#!/usr/bin/python3
"""python factorizing file for natural numbers"""
import os


with open("tests/test00", "r", encoding="utf-8") as file1:
    numstr = file1.readline()
    num = int(numstr)
    while(numstr):
        for i in range(num):
            if i > 1:
                if (num % i) == 0:
                    gtfact1 = num % i
                    print("{}={}*{}".format(num, gtfact1,i))
                    continue
        numstr = file1.readline()
                
