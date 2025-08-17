

typedef struct s_garbage_node
{
    void *data;
    struct s_garbage_node *next;
} t_garbage_node;

typedef struct s_garbage_lst
{
    t_garbage_node head;
} t_garbage_lst;