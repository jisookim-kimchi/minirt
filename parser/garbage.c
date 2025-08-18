// #include "garbage.h"

// void init_garbage_list (t_garbage_lst *garbage)
// {
//     garbage->head.data = NULL;
//     garbage->head.next = NULL;
// }

// t_garbage_node *do_malloc(void *indata, t_garbage_lst *garbage)
// {
//     t_garbage_node *new_node = malloc(sizeof(t_garbage_node));
//     if (!new_node)
//     {
//         ft_putstr_fd("do_malloc failed\n", 1);
//         garbage_lst_release(garbage);
//         exit(1);
//     }
//     new_node->data = indata;
//     new_node->next = NULL;

//     return new_node;
// }

// void add_to_garbage_list(t_garbage_lst *garbage, t_garbage_node *new_node)
// {
//     t_garbage_node *temp = &garbage->head;
//     while (temp->next != NULL)
//         temp = temp->next;
//     temp->next = new_node;
// }

// void garbage_lst_release(t_garbage_lst *garbage)
// {
//     t_garbage_node *temp = garbage->head.next;
//     t_garbage_node *prev = &garbage->head;
//     while (temp != NULL)
//     {
//         prev->next = temp->next;
//         free(temp->data);
//         free(temp);
//         temp = prev->next;
//     }
//     garbage->head.next = NULL;
// }

// void print_list(t_garbage_lst *garbage)
// {
//     t_garbage_node *temp = garbage->head.next;
//     while (temp != NULL)
//     {
//         ft_putstr_fd(temp->data, 1);
//         temp = temp->next;
//     }
// }