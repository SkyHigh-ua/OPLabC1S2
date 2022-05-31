from Person import *
class Student(Person):
    def __init__(self, string):
        lst = string.split(";")
        super().__init__(lst[0], lst[1])
        self.__grpnum = int(lst[2]) # Номер групи
        self.__avratsc = int(lst[3]) # Середній рейтинговий бал
        if self.__avratsc > 95: self.__scholstat = "Підвищена"
        elif self.__avratsc > 85: self.__scholstat = "Звичайна"
        else: self.__scholstat = "Немає"

    # Підрахунок стипендії
    def earn(self):
        stat = self.__scholstat
        if stat == "Підвищена": return 2000
        elif stat == "Звичайна": return 1000
        else: return 0

    # Повертає номер групи
    def GetGrnum(self):
        return self.__grpnum

    # Повертає Середній рейтинговий бал
    def GetAvrat(self):
        return self.__avratsc

    # Повертає статус отримання стипендії    
    def GetStat(self):
        return self.__scholstat

    # Перевантаження виведення
    def __str__(self):
        return f"{self._name};{self._date};{self.__grpnum};{self.__avratsc}"