typedef struct node {
    char name[20];
    char surname[20];
    char telnumber[10];
    char email[30];

    struct node *next; 
} node;

int list_print(node *head);
int node_print(node *el);
void list_addback(node **head, node *new);
int list_add(node **head, node *new, int k);
void list_delall(node **head);
node* list_getid(node *head, int k);
node* list_getname(node *head, char* name);
int list_delid(node **head, int k);