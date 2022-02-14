def inputfile(path, num):
    file = open(path, "w")
    string = input("Введіть текст " + str(num) + "-го файлу:\n")
    while chr(1) not in string: #Ознака кінця введення файлу Ctrl+A
        file.write(string+'\n')
        string = input()
    file.close()

inputfile('Lab1/Python/input1.txt', 1)
inputfile('Lab1/Python/input2.txt', 2)
outfile = open('Lab1/Python/output.txt', 'w')
