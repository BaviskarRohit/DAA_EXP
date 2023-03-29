
  #include <stdio.h>
#include <time.h>
int main()
{
int a[100][100], b[100][100], c[100][100], i, j;
int m1, m2, m3, m4, m5, m6, m7;

printf("Enter the 4 elements of first matrix: ");
for (i = 0; i < 2; i++)
for (j = 0; j < 2; j++)
scanf("%d", &a[i][j]);

printf("Enter the 4 elements of second matrix: ");
for (i = 0; i < 2; i++)
for (j = 0; j < 2; j++)
scanf("%d", &b[i][j]);

printf("\nThe first matrix is\n");
for (i = 0; i < 2; i++)
{
printf("\n");
for (j = 0; j < 2; j++)
printf("%d\t", a[i][j]);
}

printf("\nThe second matrix is\n");
for (i = 0; i < 2; i++)
{
printf("\n");
for (j = 0; j < 2; j++)
printf("%d\t", b[i][j]);
}

clock_t start, end;
double cpu_time_used;
start = clock();

m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
m2 = (a[1][0] + a[1][1]) * b[0][0];
m3 = a[0][0] * (b[0][1] - b[1][1]);
m4 = a[1][1] * (b[1][0] - b[0][0]);
m5 = (a[0][0] + a[0][1]) * b[1][1];
m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

c[0][0] = m1 + m4 - m5 + m7;
c[0][1] = m3 + m5;
c[1][0] = m2 + m4;
c[1][1] = m1 - m2 + m3 + m6;


printf("\nAfter multiplication using \n");
for (i = 0; i < 2; i++)
{
printf("\n");
for (j = 0; j < 2; j++)
printf("%d\t", c[i][j]);
}

end = clock();
cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("\nStressen's time : %d\n", cpu_time_used);
return 0;
}