from func import *

path1 = 'Lab1/Python/input1.txt'
path2 = 'Lab1/Python/input2.txt'
path3 = 'Lab1/Python/output.txt'
inputfile(path1, 1)
inputfile(path2, 2)
croutfile(path1, path2, path3)
flen = filelen(path3)
print("Знайдено", flen, "рядків")
printfile(path1)
printfile(path2)
printfile(path3)