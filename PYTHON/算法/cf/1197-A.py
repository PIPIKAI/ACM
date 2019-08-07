for _ in range(int(input())):
    n=int(input())
    print( min(n-2,sorted( map(int,input().split()))[-2]-1 ))