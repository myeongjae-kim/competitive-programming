n = int(input())
while n != 0:
    x,y=map(int,input().split(' '))

    for i in range(n):
        w,z=map(int,input().split(' '))
        if w == x or z == y:
            print('divisa')
        else:
            if w > x and z > y:
                print('NE')
            elif w > x and z < y:
                print('SE')
            elif w < x and z > y:
                print('NO')
            elif w < x and z < y:
                print('SO')
    n = int(input())
