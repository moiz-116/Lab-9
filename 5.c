#include <stdio.h>
#include <string.h>
int main()
{
    int quantity=0, i;
    char name[10];
    FILE *ptr;
    float total=0, price=0, grand = 0;

    ptr = fopen("sales.txt", "a");
    if (ptr == NULL)
    {
        printf("Could not open sales.txt for writing\n");
        return 1;
    }
    for (i = 0; i < 3; i++)
    {
        printf("Item %d(name price quantity):", i + 1);
        scanf("%s %f %d", name, &price, &quantity);
        fprintf(ptr, "%s %.2f  %d\n", name, price, quantity);
    }
    fclose(ptr);
    ptr = fopen("sales.txt", "r");
    if (ptr == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }
    printf("Name\t\t     Price        Qty     Total\n");
    while (fscanf(ptr, "%s %f %d", name, &price, &quantity) == 3)
    {
        total = quantity * price;
        grand += total;
        printf("%-15s %10.2f %10d %10.2f\n", name, price, quantity, total);
    }
    printf("Grand Total:%.2f",grand);
    fclose(ptr);
}