from curses.ascii import isdigit
from Student import *
from Lecturer import *

# Створення масиву студентів
def crstud(): 
    res = []
    num = int(input("Введіть кількість студентів - "))
    while num<=0:
        num = int(input("Введіть дійсне число - "))
    print("Введіть студентів за форматом - Ім'я;Дата народження(DD.MM.YYYY);Номер групи;Середній рейтинговий бал")
    while num!=0:
        str = input()
        if valstud(str):
            res.append(Student(str))
            num-=1
    return res

# Створення масиву викладачів
def crlect():
    res = []
    num = int(input("Введіть кількість викладачів - "))
    while num<=0:
        num = int(input("Введіть дійсне число - "))
    print("Введіть викладачів за форматом - Ім'я;Дата народження(DD.MM.YYYY);Назва дисципліни;Кількість годин")
    while num!=0:
        str = input()
        if vallec(str):
            res.append(Lecturer(str))
            num-=1
    return res

# Валідація рядку, що описує студента
def valstud(string):
    if ";" not in string or string.count(";")!=3:
        print("Некоректно введені дані")
        return False
    lst = string.split(";")
    if not dateval(lst[1]):
        print("Некоректно введена дата")
        return False
    if not isnum(lst[2]):
        print("Некоректно вказаний номер групи")
        return False
    if not isnum(lst[3], "float"):
        print("Некоректно введений середній бал")
        return False
    if int(lst[3])<0 or int(lst[3])>100:
        print("Некоректно введений середній бал")
        return False
    return True

# Валідація рядку, що описує викладача
def vallec(string):
    if ";" not in string:
        print("Некоректно введені дані")
        return False
    lst = string.split(";")
    if len(lst)%2 != 0:
        print("Некоректно введені дані")
        return False
    if not dateval(lst[1]):
        print("Некоректно введена дата")
        return False
    for i in range(3, len(lst), 2):
        if not isnum(lst[i]):
            print("Некоректно введена кількість годин")
            return False
    return True

# Перевірка коректності введеної дати
def dateval(string):
    for ch in string:
        if not isdigit(ch) and ch!='.': return False
    if '.' not in string or string.count(".")>2 or string.count(".")<2: return False
    date = string.split(".")
    day = int(date[0])
    mon = int(date[1])
    year = int(date[2])
    if day < 1 or mon < 1 or mon > 12 or year <= 1900: return False
    val = [0,31,28,31,30,31,30,31,31,30,31,30,31] # Кількість днів у кожному місяці року
    if mon == 2 and (year%400==0)or((year%4==0)or(year%100!=0)) and day > 29:return False
    if day > val[mon]: return False
    return True

# Перевірка - чи є рядок числом
def isnum(string, type = "int"):
    for ch in string:
        if type == "int":
            if not isdigit(ch): return False
        else: 
            if not isdigit(ch) and ch != ".": return False
    return True

# Виведення студентів
def prints(studs):
    print("Список студентів:")
    for stud in studs:
        print(stud)

# Виведення икладачів
def printl(lects):
    print("Список викладачів:")
    for lect in lects:
        print(lect)

#  Підрахунок стипендії студентів
def calcsc(studs):
    for stud in studs:
        print(f"Розмір місячної стипендії студента {stud.GetName()} - {stud.earn()}({stud.GetStat()})")

# Підрахунок заробітньої плати викладачів
def calcpay(lects):
    nums = []
    for lect in lects:
        nums.append(lect.earn())
        print(f"Розмір місячної заробіньої плати викладача {lect.GetName()} - {nums[len(nums)-1]}")
    maxindx = nums.index(max(nums))
    print(f"Найбільшу заробітню плату має викладач {lects[maxindx].GetName()} ({lects[maxindx].years()}) - {nums[maxindx]}")