for w in range(2):
    for x in range(2):
        for y in range(2):
            for z in range(2):
                if not( (not x and not y) or (y==z) or w ):
                    print('w','x','y','z')
                    print(w,x,y,z)
                    print()
# B60549
# otvet = zwyx
