#include <stdio.h>
#include <string.h>
int main()
{
    int i, present=0, absent=0,a=1;
    char names[5][30], marks[5];
    for (i = 0; i < 5; i++)
    {
        printf("Enter Name %d:", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
        names[i][strcspn(names[i], "\n")] = '\0';
    }
    printf("Mark Attendance (P/A)\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s:", names[i]);
        scanf(" %c", &marks[i]);
        (marks[i] == 'P') ? present++ : absent++;
    }
    printf("\n------Attendance Sheet-------\n\n");
    for (i = 0; i < 5; i++)
    {
        printf("%d.%s:", i + 1, names[i]);
        (marks[i] == 'P' || marks[i] == 'p') ? printf("Present\n") : printf("Absent\n");
    }
    printf("\nPresent:%d , Absent:%d\n",present,absent);
    printf("\nAbsent Students:");
    for (i = 0; i < 5; i++)
    {
        if(marks[i]=='A'||marks[i]=='a'){
            printf("%s ",names[i]);
            a=0;
        }
    }
    if(a){
        printf("None");
    }
}