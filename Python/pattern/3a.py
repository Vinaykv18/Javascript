rows = 5
for i in range(1,rows + 1):
   for j in range(1, i + 1):
      print(j,end=" ")
   print()

 #--------------------------------------------------------------
print("\n")   
for i in range(1,rows+1):
  print(" " * (rows-i)+" ".join(str(j) for j in range(1,i+1)))
#------------------------------------------------
rows = 5
num = 1
for i in range(1, rows + 1):
    for j in range(1, i + 1):
        print(num,end=" ")
        num += 1
    print()
