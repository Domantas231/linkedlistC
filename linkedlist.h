typedef struct node {
    char name[20];
    char surname[20];
    char telnumber[10];
    char email[30];

    struct node *next; 
} node;

void list_print(struct node *head);
void node_print(struct node *el);
void list_addback(struct node **head, struct node *new);
void list_add(struct node **head, struct node *new, int k);
void list_delall(struct node *head);
struct node* list_getid(struct node *head, int k);
struct node* list_getname(struct node *head, char* name);
void list_delid(struct node **head, int k);