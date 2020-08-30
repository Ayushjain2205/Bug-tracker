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
void add(int id, char name[30], char type[30], char priority[30]);
void write();
void update(int id);
void list_user(char *user);
void list_type(char *type);
void list_status(char *status);