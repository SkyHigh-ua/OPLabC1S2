from datetime import datetime
from abc import ABC, abstractmethod
class Person(ABC):
    def __init__(self, name, date):
        self._name = name # Ім'я
        self._date = date # Дата народження
    
    # Підрахунок віку
    def years(self):
        curdate = datetime.now()
        inpdate = datetime.strptime(self._date, "%d.%m.%Y")
        res = (curdate-inpdate).days
        return int(res/365.2425)

    @abstractmethod
    def earn(self):
        pass

    # Поветрає ім'я
    def GetName(self):
        return self._name

    # Повертає дату народження
    def GetDate(self):
        return self._date