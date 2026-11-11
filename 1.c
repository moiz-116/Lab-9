#include <stdio.h>
#include <string.h>
int main()
{
    char first[100], last[100], badge[100], fname[100];
    printf("Enter your first name:");
    fgets(first, sizeof(first), stdin);
    first[strcspn(first,"\n")]='\0';
    printf("Enter your last name:");
    fgets(last, sizeof(last), stdin);
    last[strcspn(last,"\n")]='\0';
    if (strlen(first) > 20)
    {
        printf("Error First Name length %zu is longer than maximum 20 characters length", strlen(first));
        return 1;
    }
    if (strlen(last) > 20)
    {
        printf("Error Last Name length %zu is longer than maximum 20 characters length", strlen(first));
        return 1;
    }
    strcpy(badge, last);
    strcat(badge, ", ");
    strcat(badge, first);

    strcpy(fname, first);
    strcat(fname, " ");
    strcat(fname, last);
    
    printf("Badge : %s \n", badge);
    printf("Full Name: %s\n", fname);
    printf("Length : %zu\n", strlen(fname));

}