#include <stdio.h>
#include <stdbool.h>

bool isSafe(int board[][10], int row, int col, int N)
{
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

bool solveNQUtil(int board[][10], int col, int N)
{
    if (col >= N)
        return true;

    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col, N))
        {
            board[i][col] = 1;

            if (solveNQUtil(board, col + 1, N))
                return true;

            board[i][col] = 0;
        }
    }

    return false;
}

void printSolution(int board[][10], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void solveNQ(int N)
{
    int board[10][10] = {0};

    if (solveNQUtil(board, 0, N) == false)
    {
        printf("Solution does not exist");
        return;
    }

    printSolution(board, N);
}

int main()
{
    int N;

    printf("Enter the number of queens: ");
    scanf("%d", &N);

    solveNQ(N);

    return 0;
}
