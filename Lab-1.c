#include <stdio.h>
#include <string.h>

struct User
{
    char name[50];
    int BMI;
};

void insertion(struct User (*arr)[2], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("Enter User Name: ");
            scanf("%s", arr[i][j].name);
            printf("Enter Body Mass Index (BMI): ");
            scanf("%d", &arr[i][j].BMI);
        }
    }
}

void modifyArray(struct User (*arr)[2], int rows, int cols)
{
    int row, col;

    printf("Enter row number (0-3) to modify: ");
    scanf("%d", &row);

    if (row < 0 || row >= rows)
    {
        printf("Invalid row number.\n");
        return;
    }

    printf("Enter column number (0-1) to modify: ");
    scanf("%d", &col);

    if (col < 0 || col >= cols)
    {
        printf("Invalid column number.\n");
        return;
    }

    printf("Enter User Name: ");
    scanf("%s", arr[row][col].name);
    printf("Enter Body Mass Index (BMI): ");
    scanf("%d", &arr[row][col].BMI);
}

void displayArray(struct User (*arr)[2], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j].BMI != -1)
            {
                printf("Name: %s, Body Mass Index (BMI): %d\t", arr[i][j].name, arr[i][j].BMI);
            }
            else
            {
                printf("Deleted\t");
            }
        }
        printf("\n");
    }
}

void mergeArrays(struct User (*array1)[2], struct User (*array2)[2], struct User (*array3)[2])
{
    int k = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            array3[k][0] = array1[i][j];
            array3[k][1] = array2[i][j];
            k++;
        }
    }
}

void deleteElement(struct User (*arr)[2], int rows, int cols)
{
    int row, col;

    printf("Enter row number (0-3) to delete: ");
    scanf("%d", &row);

    if (row < 0 || row >= rows)
    {
        printf("Invalid row number.\n");
        return;
    }

    printf("Enter column number (0-1) to delete: ");
    scanf("%d", &col);

    if (col < 0 || col >= cols)
    {
        printf("Invalid column number.\n");
        return;
    }
    strcpy(arr[row][col].name, "");
    arr[row][col].BMI = -1;
}

void addArrays(struct User (*array1)[2], struct User (*array2)[2], struct User (*resultArray)[2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sprintf(resultArray[i][j].name, "%s & %s", array1[i][j].name, array2[i][j].name);
            resultArray[i][j].BMI = array1[i][j].BMI + array2[i][j].BMI;
        }
    }
}

void subtractArrays(struct User (*array1)[2], struct User (*array2)[2], struct User (*resultArray)[2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sprintf(resultArray[i][j].name, "%s & %s", array1[i][j].name, array2[i][j].name);
            resultArray[i][j].BMI = array1[i][j].BMI - array2[i][j].BMI;
        }
    }
}

void display2x2Array(struct User (*arr)[2])
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("Name: %s, Body Mass Index (BMI): %d\t", arr[i][j].name, arr[i][j].BMI);
        }
        printf("\n");
    }
}

void linearSearch(struct User (*arr)[2], int rows, int cols, const char *searchName)
{
    int row = -1, col = -1;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (strcmp(arr[i][j].name, searchName) == 0)
            {
                row = i;
                col = j;
                printf("User found at row %d, column %d\n", row, col);
                return;
            }
        }
    }

    printf("User not found\n");
}

int main()
{
    int rows = 4, cols = 2;

    struct User array1[2][2];
    printf("Enter elements for the first array --> \n");
    insertion(array1, 2, 2);

    struct User array2[2][2];
    printf("\n\nEnter elements for the second array:\n");
    insertion(array2, 2, 2);

    struct User array3[4][2];

    int i;
    while (1)
    {
        printf("\nEnter your choice:\n1. Merge (Compulsory for 2,3,4)\n2. Delete in Merged Array\n3. Modify in Merged Array\n4. Linear Search in Merged Array\n5. Add the Two User-Inputed Arrays\n6. Subtract the Two User-Inputed Arrays\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            mergeArrays(array1, array2, array3);
            printf("\nAfter Merging --> \n");
            displayArray(array3, 4, 2);
            printf("\n");
            break;

        case 2:
            deleteElement(array3, 4, 2);
            printf("\nAfter Deletion --> \n");
            displayArray(array3, 4, 2);
            printf("\n");
            break;

        case 3:
            modifyArray(array3, 4, 2);
            printf("\nAfter Modification --> \n");
            displayArray(array3, 4, 2);
            printf("\n");
            break;

        case 4:
            char searchName[50];
            printf("\nEnter the name to search: \n");
            scanf("%s", searchName);
            linearSearch(array3, 4, 2, searchName);
            break;

        case 5:
            struct User addedArray[2][2];
            addArrays(array1, array2, addedArray);
            printf("\nAfter Adding --> \n");
            display2x2Array(addedArray);
            printf("\n");
            break;

        case 6:
            struct User subtractedArray[2][2];
            subtractArrays(array1, array2, subtractedArray);
            printf("\nAfter Subtracting --> \n");
            display2x2Array(subtractedArray);
            printf("\n");
            break;

        default:
            printf("\nInvalid Choice");
        }
    }

    return 0;
}
