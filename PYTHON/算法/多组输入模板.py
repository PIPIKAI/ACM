def solve():
    x,a,y,b=map(int,input().split())
    if (x/a) == (y/b):
        print('=')
    elif (x/a) < (y/b): 
        print('<')
    else:
        print('>')
        
if __name__ == "__main__":
    try:
        while(True):
            solve()
    except:
        pass
#
# 
# import sys
#cin=lambda:map(int,sys.stdin.readline().split()) 要有这句话输入才够快