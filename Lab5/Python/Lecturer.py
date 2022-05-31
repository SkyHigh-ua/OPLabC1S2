from Person import *
class Lecturer(Person):
    def __init__(self, string):
        lst = string.split(";")
        super().__init__(lst[0], lst[1])
        self.__dis = {"disname": [], "hours": []}
        for i in range(2, len(lst), 2):
            d, h = lst[i:i + 2][0], lst[i:i + 2][1]
            self.__dis["disname"].append(d)
            self.__dis["hours"].append(int(h))

    # Підрахунок місячної заробітньої плати
    def earn(self):
        hours = 0
        for hour in self.__dis["hours"]:
            hours += hour
        return 100*hours

    # Повертає список дисциплін
    def GetDis(self):
        return self.__dis

    # Перевантаження виведення
    def __str__(self):
        res = f"{self._name};{self._date}"
        dis = self.__dis
        for i in range(len(dis["hours"])):
            res += ";{};{}".format(dis["disname"][i],dis["hours"][i])
        return res