#Author: michealkeines
import sys

if len(sys.argv) != 2:
    print("USAGE:" + "plot.py <sring of number seperated by space>")
    sys.exit(1)

val = [[" " for x in range(0,50)] for x in range(0,200)]
def draw(val,test):
    x = 100
    y = 0
    flip = True
    print("x="+ str(x) + "y="+str(y))
    for i in test:
        print("inside for i="+ str(i))
        count = i
        while count != 0:
            while(x <200 and y >= 0):
                if(count == 0 ):
                    flip = not flip
                    break
                if(flip):
                    print("count="+str(count))
                    
                    print("x="+str(x))
                    print("y="+str(y))
                    val[x][y] = "/"
                    print(val[x][y])
                    if(count -1 == 0):
                        y += 1 
                    else:
                        x -= 1
                        y += 1
                    
                else:
                    print("count="+str(count))
                    val[x][y] = "\\"
                    print("x="+str(x))
                    print("y="+str(y))
                    print(val[x][y])
                    if(count -1 == 0):
                        y += 1
                    else:
                        x += 1 
                        y += 1
                count -= 1
    got = False
    for k in range(0,200):
        if(got):
            break
        for y in range(0,50):
            if val[k][y] == "/":
                val[k-1][y] = "###"
                got = True
                break
            
                
    for i in range(0,200):
        for j in range(0,50):
            if val[i][j] == " ":
                print(" ", end=" ")
                #print("0", end=" ")
            else:
                print(val[i][j],end=" ")
        print()
s = sys.argv[1].split(" ")
test = [int(i) for i in s]
draw(val,test)
