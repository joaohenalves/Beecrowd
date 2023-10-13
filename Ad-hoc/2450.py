linha,coluna=map(int,input().split())
mat=[]
for m in range(0,linha):
    num=list(map(int,input().split()))
    mat.append(num)
escada=True
c=0
l=0
while l < linha:
    if mat[l][c]==0:
        for test1 in range(l+1,linha):
            if mat[test1][c]!=0:
                escada=False
        c+=1
    elif mat[l][c]!=0:
        l+=1
        for test2 in range(l,linha):
            if mat[test2][c]!=0:
                escada=False
        c+=1
    if c==coluna:
        break
if (escada):
    print("S")
else:
    print("N")