import binascii
for _ in range(int(input())):
    x=input()
    y=input()
    a=int(binascii.hexlify(x),2)
    print(a)