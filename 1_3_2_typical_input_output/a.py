try:
    while True:
        a=list(map(int,input().split(' ')))
        s = 0
        for i in a[1:]:
            s += i
        print(s)
except EOFError:
    pass
