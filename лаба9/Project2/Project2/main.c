#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int mod(int a, int b)
{
    return abs(((a % b) + b) % b);
}

int sign(int x)
{
    return (x > 0) - (x < 0);
}

int _max(int x, int y)
{
    return (x > y) ? x : y;
}

int _min(int x, int y)
{
    return (x < y) ? x : y;
}

int in_area(int x, int y)
{
    return (y <= -x - 10) && (y >= -x - 20);
}

int compute_i(int i, int j, int l, int k)
{
    return mod(abs(i - j) * l - abs(j - l) * i + abs(i - l) * j, 20) - k + 1;
}

int compute_j(int i, int j, int l, int k)
{
    return mod(_min(i, j) * _max(j, l) * _min(i, l), 25) + 5 * sign(i) + k;
}

int compute_l(int i, int j, int l, int k)
{
    return abs(l) * sign(i - j) - abs(i) * sign(j - l) + abs(j) * sign(i - l);
}


int main(void)
{
    int k;
    int I0, J0, L0;

    scanf("%d%d%d", &I0, &J0, &L0);

    int i_old = I0;
    int j_old = J0;
    int l_old = L0;

    int i = I0;
    int j = J0;
    int l = L0;

    for (k = 0; k < 50 && !in_area(i_old, j_old); ++k)
    {
        i = compute_i(i_old, j_old, l_old, k);
        j = compute_j(i_old, j_old, l_old, k);
        l = compute_l(i_old, j_old, l_old, k);

        i_old = i;
        j_old = j;
        l_old = l;
    }

    printf("%s\n", in_area(i, j) ? "Yes" : "No");
    printf("%d %d %d %d\n", i, j, l, k);

    return 0;
}