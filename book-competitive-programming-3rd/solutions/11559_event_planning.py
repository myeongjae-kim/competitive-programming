try:
    while True:
        n,b,h,w=map(int,input().split(' '))
        p_min=-1
        for i in range(h):
            p=int(input())
            weeks=list(map(int, input().split(' ')))
            if n*p>b:
                continue
            for k in weeks:
                if k>=n:
                    if p_min == -1:
                        p_min=n*p
                    else:
                        p_min=min(p_min,n*p)
                    break

        if p_min==-1:
            print('stay home')
        else:
            print(p_min)

except EOFError:
    pass
