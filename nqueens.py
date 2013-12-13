#!/usr/bin/env python

def nqueens(num = 8):
    search_queen([0]*num, 0, num)

def search_queen(queens, row, num):
    if row == num:
        print_queenmat(queens, num)
    else:
        for col in range(num):
            if not conflit(queens, row, col):
                queens[row] = col
                search_queen(queens, row+1, num)

def conflit(queens, row, col):
    for r in range(row):
        if abs(col-queens[r]) in (0, abs(row-r)):
            return True
    return False

def print_queenmat(queens, length):
    for q in queens:
        print '. '*q + 'X ' + '. '*(length-1-q)
    print '\n'

nqueens()