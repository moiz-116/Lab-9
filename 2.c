#include <stdio.h>
#include <string.h>
int main()
{
    int i;
    char code[100];
    printf("Enter Product Code:");
    fgets(code, sizeof(code), stdin);
    code[strcspn(code, "\n")] = '\0';
    if (strlen(code) != 8)
    {
        printf("Code must 8 characters long");
        return 1;
    }
    if (strchr(code, '-') != code + 3)
    {
        printf("The 4th character must '-'");
        return 1;
    }
    for (i = 4; i < 8; i++)
    {
        char ch = code[i];
        if (!(ch >= '0' && ch <= '9'))
        {
            printf("Last 4 characters must be digits");
            return 1;
        }
    }
    if (strncmp(code, "ELE", 3) == 0)
    {
        printf("Valid Code:Electronics");
    }
    else if (strncmp(code, "GRO", 3) == 0)
    {
        printf("Valid Code:Grocery");
    }
    else if (strncmp(code, "CLO", 3) == 0)
    {
        printf("Valid Code:Clothing");
    }else{
        printf("Unknown Category");
        return 1;
    }
}