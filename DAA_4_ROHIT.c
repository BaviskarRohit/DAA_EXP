\#include<stdio.h>
#include<string.h>
 
int i,j,m,n,c[20][20];
char x[20],y[20],b[20][20];
int max(int a, int b);

void print(int i,int j)
{
    if(i==0 || j==0)
        return;
    if(b[i][j]=='c')
    {
        print(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='u')
        print(i-1,j);
    else
        print(i,j-1);
}
 
void lcs()
{
    m=strlen(x);
    n=strlen(y);
    for(i=0;i<=m;i++){
        c[i][0]=0;
        for(i=0;i<=n;i++){
            c[0][i]=0;
                                
            //c, u and l denotes cross, upward and downward directions respectively
            for(i=1;i<=m;i++){
                for(j=1;j<=n;j++)
                {
                    if(x[i-1]==y[j-1])
                    {
                        c[i][j]=c[i-1][j-1]+1;
                        b[i][j]='c';
                    }
                    else if(c[i-1][j]>=c[i][j-1])
                    {
                        c[i][j]=c[i-1][j];
                        b[i][j]='u';
                    }
                    else
                    {
                        c[i][j]=c[i][j-1];
                        b[i][j]='l';
                    }
                }
            }
        }
    }
}

int max(int a, int b)
{ 
    if(a>b){
        return a;
    }
    else
        return b;
}
 
// Returns length of LCS for X[0..m-1], Y[0..n-1]
int lcs_length(char* x, char* y,int m,int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (x[m - 1] == y[n - 1])
        return 1 + lcs_length(x, y, m - 1, n - 1);
    else
        return max(lcs_length(x, y, m, n - 1), lcs_length(x, y, m - 1, n));
}

int main()
{
    printf("\n\t--Longest Common Subsequence--\n");
    printf("\nEnter 1st sequence: ");
    scanf("%s",x);
    printf("Enter 2nd sequence: ");
    scanf("%s",y);
    printf("\nLength of LCS is %d", lcs_length(x, y, m, n));
    printf("\nThe Longest Common Subsequence is: ");
    lcs();
    print(m,n);
    
    return 0;
}