#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#define ROWS 200
#define COLUMNS 100
#include"header.h"

int main(int argc, char *argv[])
{
    if (argc == 2 && strcmp(argv[1], "-user") == 0)
    {
        int id;
        char name[30];
        char type[30];
        char priority[30];
        printf("Enter bug id: ");
        scanf("%d", &id);
        printf("Enter bug name: ");
        scanf("%s", name);
        printf("Enter bug type: ");
        scanf("%s", type);
        printf("Enter priority level: ");
        scanf("%s", priority);
        add(id, name, type, priority);
        write();
    }
    if (argc == 2 && strcmp(argv[1], "-manager") == 0)
    {
        int id;
        printf("Enter id of bug : ");
        scanf("%d", &id);
        update(id);
    }
    if (argc == 3 && strcmp(argv[1], "-list") == 0 && strcmp(argv[2], "-name") == 0)
    {
        char name[20];
        printf("Enter name to filter :");
        scanf("%s", name);
        list_user(name);
    }
    if (argc == 3 && strcmp(argv[1], "-list") == 0 && strcmp(argv[2], "-type") == 0)
    {
        char type[20];
        printf("Enter type to filter :");
        scanf("%s", type);
        list_type(type);
    }
    if (argc == 3 && strcmp(argv[1], "-list") == 0 && strcmp(argv[2], "-status") == 0)
    {
        char status[20];
        printf("Enter status to filter :");
        scanf("%s", status);
        list_status(status);
    }

    return 0;
}