#include "func.h"

int main()
{
    int n, m;
    Student *stud = crstud(&n);
    Lecturer *lect = crlect(&m);
    print(stud, n);
    print(lect, m);
    calcsc(stud, n);
    calcpay(lect, m);
    delete []stud;
    delete []lect;
    return 0;
}