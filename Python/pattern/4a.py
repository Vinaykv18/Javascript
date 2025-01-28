rows = 5
for i in range(rows):
    print(" " * (rows - i), end="")
    val = 1
    for j in range(i + 1):
        print(val, end=" ")
        val = val * (i - j) // (j + 1)
    print()

#--------------------------------------
rows = 5
for i in range(rows, 0, -1):
    print(" " * (rows - i) + "*" * (2 * i - 1))
for i in range(2, rows + 1):
    print(" " * (rows - i) + "*" * (2 * i - 1))
