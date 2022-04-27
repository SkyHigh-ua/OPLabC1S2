from datetime import datetime
from os import stat
from os.path import exists
import pickle

# Введення файлу через консоль
def inputfile(path):
    if exists(path):
        if stat(path).st_size != 0:
            ans = input("Очистити файл? Y/N ")
            while ans.lower() != "y" and ans.lower() != "n":
                ans = input("Введіть Y або N ")
            if ans.lower() == "y":
                lst = []
            else:
                lst = lstlines(path) 
        else:
            lst = []
    else:
        lst = []
    file = open(path, "wb")
    string = input("Введіть данні покупців за шаблоном Прізвище;Стать(M/W);Дата народження(DD.MM.YYYY);Кількість товару\n")
    while chr(1) not in string: #Ознака кінця введення файлу Ctrl+A
        if validation(string):
            lst.append(strtostruct(string))
        string = input()
    pickle.dump(lst,file)
    file.close()

# Перевірка введених даних
def validation(string):
    if ";" not in string or string.count(";")!=3:
        print("Некоректно введені дані")
        return False
    lst = string.split(";")
    age = years(lst[2])
    if lst[1].lower()!="w" and lst[1].lower()!="m":
        print("Некоректно введена стать")
        return False
    if age<16 or age>=122:
        if age>=0:
            if age<16:
                print("Введена дата замала")
            else:
                print("Введена дата завелика")
        else:
            print("Некоректно введена дата")
        return False
    if int(lst[3])<=0:
        print("Некоректно введена кількість товару")
        return False
    return True

# Переведення зі строки в структуру
def strtostruct(string):
    cust = {}
    lst = string.split(";")
    cust["surn"] = lst[0]
    cust["sex"] = lst[1]
    cust["age"] = lst[2]
    cust["amt"] = int(lst[3])
    return cust

# Визначення кількості років 
def years(date):
    val = [0,31,28,31,30,31,30,31,31,30,31,30,31]
    tdate = date.split(".")
    if int(tdate[1])<13 and int(tdate[1])>0:
        if int(tdate[0])>0 and int(tdate[0])<=val[int(tdate[1])]:
            curdate = datetime.now()
            inpdate = datetime.strptime(date, "%d.%m.%Y")
            res = (curdate-inpdate).days
            return int(res/365.2425)
        return -1
    else:
        return -1

# Створення вихідного файлу
def croutfile(path1, path2):
    res = []
    inpf = lstlines(path1)
    outf = open(path2, "wb")
    ans = input("Виводити вартість товарів? Y/N ")
    while ans.lower() != "y" and ans.lower() != "n":
        ans = input("Введіть Y або N ")
    if ans.lower() == "y":
        swpr = True
    for dct in inpf:
        price = disc(dct["age"], dct["amt"])
        if(price>250):
            res.append(dct)
        if(swpr):
            print(dct["surn"], " - ", price)
    pickle.dump(res,outf)
    outf.close()

# Визначення ціни зі знижкою
def disc(date, amt):
    n=amt*100 
    age=years(date)
    if age<60:
        n-=n*age*0.01
    elif age>=95:
        n-=n*0.99
    else:
        n-=n*((age*0.01)+0.05)
    return int(n)

# Створення списка з файлу
def lstlines(path):
    file = open(path, "rb")
    lst = pickle.load(file)
    file.close()
    return lst

# Вивід файлу в консоль
def printfile(path): 
    print("Зміст файлу", path.split("/")[-1:][0])
    lst = lstlines(path)
    if len(lst)!=0:
        for i in lst:
            prt = []
            for key in i:
                prt.append(str(i[key]))
            print(";".join(prt))
    else:
        print("Файл пустий")