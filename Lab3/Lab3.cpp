#include "func.h"

int main()
{
    int len;
    Text *texts = inputtexts(&len);
    addtotexts(texts, len);
    print(texts, len);
    countintext(texts, len);
    delete []texts;
    return 0;
}