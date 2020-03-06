
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