#include "func.h"

int main()
{
    int len, num;
    char ch;
    Text *texts = inputtexts(&len);
    addtotexts(texts, len);
    print(texts, len);
    countintext(texts, len);
    ch = findmax(texts, len, &num);
    std::cout << "Найчастіше зустрічається символ '" << ch << "' - " << num << std::endl;
    delete []texts;
    return 0;
}