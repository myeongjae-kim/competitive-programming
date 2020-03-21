n = int(input())
for i in range(n):
    a = list(map(int,input().split(' ')))
    a.sort()
    print("Case ",i+1,": ", a[1], sep='')
