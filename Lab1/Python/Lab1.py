def inputfile(file):
    string = input("Введіть текст:\n")
    while True:
        try:
            file.write(string+'\n')
            string = input()
        except EOFError:
            break
        
file1 = open('finput.txt', 'w+')
inputfile(file1)
file2 = open('sinput.txt', 'w+')
inputfile(file2)