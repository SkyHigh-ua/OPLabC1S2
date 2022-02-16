# Введення файлу через консоль
def inputfile(path, num):
    file = open(path, "w")
    string = input("Введіть текст " + str(num) + "-го файлу:\n")
    while chr(1) not in string: #Ознака кінця введення файлу Ctrl+A
        file.write(string+'\n')
        string = input()
    file.close()

# Створення вихідного файлу
def croutfile(path1, path2, path3):  
    outf = open(path3, 'w')  
    for i in matchlines(path1, path2):
        outf.write(i)  
    outf.close()

# Пошук однакових рядків
def matchlines(path1, path2): 
    inpf1 = lstlines(path1)
    inpf2 = lstlines(path2)
    lst=[]
    for i in inpf1:
        if i not in inpf2:
            lst.append(i)
    return lst

# Створення списка з файлу
def lstlines(path):
    file = open(path)
    lst = file.readlines()
    file.close()
    return lst

# Визначення кількості рядків у файлі
def filelen(path):
    with open(path) as file:
        return len(file.readlines())

# Вивід файлу в консоль
def printfile(path): 
    print("Зміст файлу", path.split("/")[-1:][0])
    lst = lstlines(path)
    if len(lst)!=0:
        for i in lst:
            print(i, end="")
    else:
        print("Файл пустий")