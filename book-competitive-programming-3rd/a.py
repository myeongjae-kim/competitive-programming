try:
    while True:
        ary = list(map(int, input().split(' ')))
        ary = ary[0:-1] # remove last element

        ans = -20000000000000 # small enough
        product = 1

        for i in range(0, len(ary)):
            product = 1
            for k in range(i, len(ary)):
                product *= ary[k];
                ans = max(ans, product)
                if product == 0:
                    break
        print(ans)

except EOFError:
    pass
