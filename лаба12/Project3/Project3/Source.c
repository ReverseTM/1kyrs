#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void)
{
    long long c, k, ost;
    long long start = 0;
    long long start1, start2, start3;

    while (scanf("%lli", &start) == 1) {
        start1 = (start);
        start2 = (start);
        k = 1;
        //k должен быть равен 0
        c = 0;

        while (start1 / 10 != 0) {
            start1 = start1 / 10;
            k++;
        }

        for (int i = 0; i < 3; ++i) {
            ost = start2 % 10;
            start2 = start2 / 10;
            start2 += ost * pow(10, k);
        }

        start3 = start2;

        while (start3 / 10 != 0) {
            start3 = start3 / 10;
            c++;
        }

        long long difference = k - c;

        if (start2 > 0) {
            //должно быть <0
            printf("-");
        }

        start2 = llabs(start2);

        for (int g = 0; g < difference; ++g) {
            printf("0");
        }
        
        printf("%lli\n", start2);
    }
    return 0;
}