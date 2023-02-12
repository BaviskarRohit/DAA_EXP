#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void selection_sort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = i;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

void insertion_sort(int arr[], int size)
{

    int i, key, j;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main(void)
{
    clock_t a, b, c;
    int arr[100000], arr2[100000];
    double d, e;
    FILE *fptr;
    int num;

    fptr = fopen("integers", "w");

    if (fptr != NULL)
    {
        printf("File created successfully!\n");
    }
    else
    {
        printf("Failed to create the file.\n");

        return -1;
    }

    int i = 0;
    while (i != 100000)
    {
        num = rand() % 100000;
        if (num != -1)
        {
            putw(num, fptr);
        }
        else
        {
            break;
        }
        ++i;
    }

    fclose(fptr);

    fptr = fopen("integers", "r");

    i = 0;
    while ((num = getw(fptr)) != EOF)
    {
        arr[i] = num;
        arr2[i] = num;
        i++;
    }

    printf("\nEnd of file.\n");

    fclose(fptr);

    for (int j = 100; j <= 100000; j += 100)
    {
        a = clock();
        selection_sort(arr, j);
        b = clock();

        d = (double)(b - a) / CLOCKS_PER_SEC;
        printf("%f\n", d);
        c = clock();
        printf("\t");
        insertion_sort(arr2, j);
        e = (double)(c - b) / CLOCKS_PER_SEC;
        printf("%f\n", e);
    }
    d = (double)(b - a) / CLOCKS_PER_SEC;
    printf("%f", d);

    return 0;
}
