num=int(input())
for i in range(0,num):
    string=""
    vet=[]
    msg=input()
    for x in msg:
        vet.append(x)
    if not vet[0]==" ":
        print(vet[0],end="")
    for y in range(1,len(vet)):
        if not vet[y]==" " and vet[(y-1)]==" ":
            string+=vet[y]
    print(string)