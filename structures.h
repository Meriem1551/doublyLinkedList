typedef struct Nodes node;
struct Nodes{
    int data;
    struct Nodes*next;
    struct Nodes*previous;
}*head;