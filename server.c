#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define ROWS 200
#define COLUMNS 100

struct bug
{
    int id;
    char name[30];
    char type[30];
    char priority[30];
    char status[30];
    char assigned_to[30];
};
struct bug buglist[20];
int count;

void add(int id, char name[30], char type[30], char priority[30])
{
    buglist[count].id = id;
    strcpy(buglist[count].name, name);
    strcpy(buglist[count].type, type);
    strcpy(buglist[count].priority, priority);
    strcpy(buglist[count].status, "NotAssigned");
    strcpy(buglist[count].assigned_to, "NULL");
    count++;
}

void write()
{
    FILE *f1 = fopen("data.txt", "a");
    for (int num = 0; num < count; num++)
    {
        fprintf(f1, "%d\t%s\t%s\t%s\t%s\t%s\n", buglist[num].id, buglist[num].name, buglist[num].type, buglist[num].priority, buglist[num].status, buglist[num].assigned_to);
    }
}

void update(int id)
{
    int count = 0;
    int total = 0;
    char line[ROWS][COLUMNS];
    FILE *f2 = fopen("data.txt", "r");
    FILE *f3 = fopen("temp.txt", "w");

    while (fgets(line[count], COLUMNS, f2))
    {
        line[count][strlen(line[count]) - 1] = '\0';
        count++;
    }
    total = count;
    for (int counter = 0; counter < total; counter++)
    {
        char line_o[200];
        strcpy(line_o, line[counter]);

        int i = 0;
        char *p = strtok(line[counter], "\t");
        char *array[6];
        char assigned_to[30];
        char status[30];
        while (p != NULL)
        {
            array[i++] = p;
            p = strtok(NULL, "\t");
        }

        if (atoi(array[0]) == id) //if the id matches with the id to check
        {
            printf("Who do you want to assign this bug to? : ");
            scanf("%s", assigned_to);
            printf("Who do you want to change the status to? : ");
            scanf("%s", status);
            fprintf(f3, "%s\t%s\t%s\t%s\t%s\t%s\n", array[0], array[1], array[2], array[3], status, assigned_to);
            continue;
        }
        else
        { //else line is copied as it is into the file
            fputs(line_o, f3);
            fputs("\n", f3);
        }
    }
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void list_user(char *user)
{
    int count = 0;
    int total = 0;
    int flag = 0;
    char line[ROWS][COLUMNS];
    FILE *f2 = fopen("data.txt", "r");
    while (fgets(line[count], COLUMNS, f2))
    {
        line[count][strlen(line[count]) - 1] = '\0';
        count++;
    }
    total = count;
    for (int counter = 0; counter < total; counter++)
    {
        char line_o[200];
        strcpy(line_o, line[counter]);

        int i = 0;
        char *p = strtok(line[counter], "\t");
        char *array[6];
        while (p != NULL)
        {
            array[i++] = p;
            p = strtok(NULL, "\t");
        }

        if (strcmp(user, array[1]) == 0) //if the id matches with the id to check
        {
            flag = 1;
            printf("%s\n", line_o);
            continue;
        }
    }
    if (flag == 0)
    {
        printf("No entry found with username - %s\n", user);
    }
}
void list_type(char *type)
{
    int count = 0;
    int total = 0;
    int flag = 0;
    char line[ROWS][COLUMNS];
    FILE *f2 = fopen("data.txt", "r");
    while (fgets(line[count], COLUMNS, f2))
    {
        line[count][strlen(line[count]) - 1] = '\0';
        count++;
    }
    total = count;
    for (int counter = 0; counter < total; counter++)
    {
        char line_o[200];
        strcpy(line_o, line[counter]);

        int i = 0;
        char *p = strtok(line[counter], "\t");
        char *array[6];
        while (p != NULL)
        {
            array[i++] = p;
            p = strtok(NULL, "\t");
        }

        if (strcmp(type, array[2]) == 0) //if the id matches with the id to check
        {
            flag = 1;
            printf("%s\n", line_o);
            continue;
        }
    }
    if (flag == 0)
    {
        printf("No entry found with type - %s\n", type);
    }
}

void list_status(char *status)
{
    int count = 0;
    int total = 0;
    int flag = 0;
    char line[ROWS][COLUMNS];
    FILE *f2 = fopen("data.txt", "r");
    while (fgets(line[count], COLUMNS, f2))
    {
        line[count][strlen(line[count]) - 1] = '\0';
        count++;
    }
    total = count;
    for (int counter = 0; counter < total; counter++)
    {
        char line_o[200];
        strcpy(line_o, line[counter]);

        int i = 0;
        char *p = strtok(line[counter], "\t");
        char *array[6];
        while (p != NULL)
        {
            array[i++] = p;
            p = strtok(NULL, "\t");
        }

        if (strcmp(status, array[4]) == 0) //if the id matches with the id to check
        {
            flag = 1;
            ;
            printf("%s\n", line_o);
            continue;
        }
    }
    if (flag == 0)
    {
        printf("No entry found with status - %s\n", status);
    }
}