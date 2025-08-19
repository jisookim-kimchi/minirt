#include "garbage.h"

void init_garbage_list (t_garbage_lst *garbage)
{
    garbage->head.data = NULL;
    garbage->head.next = NULL;
}

t_garbage_node *do_malloc(void *indata, t_garbage_lst *garbage)
{
    t_garbage_node *new_node = malloc(sizeof(t_garbage_node));
    if (!new_node)
    {
       	printf("do_malloc failed\n");
        garbage_lst_release(garbage);
        exit(1);
    }
    new_node->data = indata;
    new_node->next = NULL;

    return new_node;
}

void add_to_garbage_list(t_garbage_lst *garbage, t_garbage_node *new_node)
{
    t_garbage_node *temp = &garbage->head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

void garbage_lst_release(t_garbage_lst *garbage)
{
    t_garbage_node *temp = garbage->head.next;
    t_garbage_node *prev = &garbage->head;
    while (temp != NULL)
    {
        prev->next = temp->next;
        free(temp->data);
        free(temp);
        temp = prev->next;
    }
    garbage->head.next = NULL;
}

void print_garbage_list(t_garbage_lst *garbage)
{
    t_garbage_node *temp = garbage->head.next;
    while (temp != NULL)
    {
        printf("garbage print_list temp->data[%p]", temp->data);
        temp = temp->next;
    }
}


// int main ()
// {
//     t_garbage_lst g_lst;
//     init_garbage_list(&g_lst);

//     char *a = malloc(1);
//     char *b = malloc(2);
//     char *c = malloc(3);
//     int  *d = malloc(sizeof(int) * 2);

//     add_to_garbage_list(&g_lst, do_malloc(a, &g_lst));
//     add_to_garbage_list(&g_lst, do_malloc(b, &g_lst));
//     add_to_garbage_list(&g_lst, do_malloc(c, &g_lst));
//     add_to_garbage_list(&g_lst, do_malloc(d, &g_lst));

//     print_garbage_list(&g_lst);

//     garbage_lst_release(&g_lst);
	
// 	if (g_lst.head.next == NULL)
// 		printf("null\n");
//     return 0;
// }
