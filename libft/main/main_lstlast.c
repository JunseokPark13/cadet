#include "../libft.h"

#include <stdio.h>

void print_all_list (t_list *lst)
{
	while (lst)
	{
		printf("content = %s\n", (char*)lst->content);
		lst = lst->next;
	}
}

void print_this_node (t_list *lst){	
	printf("content = %s\n", (char*)lst->content);
}	

int main(int argc, char* argv[])
{
	t_list *first;
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew(argv[argc - 3]);
	node2 = ft_lstnew(argv[argc - 2]);
	node3 = ft_lstnew(argv[argc - 1]);

	ft_lstadd_front(&first, node1);
	ft_lstadd_front(&node1, node2);
	ft_lstadd_front(&node2, node3);

	print_all_list(node3);
	printf("\n");
	print_this_node(ft_lstlast(node3));
}
