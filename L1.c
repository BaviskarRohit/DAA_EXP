#include <stdio.h>
#include <math.h>

void fun1(int n)
{ // n cube
    int res = n * n * n;
    printf("%d\t", res);
}

void fun2(int n)
{ // log n
    double res = log(n);
    printf("%.3f\t", res);
}

void fun3(int n)
{ // nlogn
    double res = n * log(n);
    printf("%.3f\t", res);
}

void fun4(int n)
{ // 2^logn

    double res = pow(2, log(n));
    printf("%.3f\t", res);
}

void fun5(int n)
{
    double res = pow(log2(n), 0.5); // sqrt(log2n)
    printf("%.3f\t", res);
}

void fun6(int n)
{ // log2 n
    double res = log2(n);
    printf("%.3f\t", res);
}

void fun7(int n)
{ // ln ln n
    double res = log(log(n));
    printf("%.3f\t", res);
}

void fun8(int n)
{ // (root 2)^ log2n
    double res = pow(1.4142, log2(n));
    printf("%.3f\t", res);
}

void fun9(int n)
{ // n^ (lglgn)
    double res = pow(2, 2 * log2(n));
    printf("%.2f\t", res);
}

void fun10(int n)
{ // log2 n
    double res = pow(log2(n), 2);
    printf("%.3f\t", res);
}
int main()
{
    printf("n\t");
    printf("fun1\t");
    printf("fun2\t");
    printf("fun3\t");
    printf("fun4\t");
    printf("fun5\t");
    printf("fun6\t");
    printf("fun7\t");
    printf("fun8\t");
    printf("fun9\t");
    printf("fun10\t");
    printf("\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t", i);
        fun1(i);
        fun2(i);
        fun3(i);
        fun4(i);
        fun5(i);
        fun6(i);
        fun7(i);
        fun8(i);
        fun9(i);
        fun10(i);
        printf("\n");
    }

    return 0;
}