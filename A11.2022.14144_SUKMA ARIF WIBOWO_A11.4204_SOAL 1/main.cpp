#include "stdio.h"
#include "conio.h"
using namespace std;

int bagi(int a,int b)
{
    if(a<b)
    {
        return 0;
    }
    else
    {
        return 1+bagi(a-b, b);
    }
}


int main ()
{
    int a,b;
    printf("Masukan bilangan a = ");
    scanf("%d", &a);
    printf("Masukan bilangan b = ");
    scanf("%d", &b);
    printf("Hasil dari %d / %d = ", a,b);
	printf("%d", bagi(a,b));

    getch();
}
