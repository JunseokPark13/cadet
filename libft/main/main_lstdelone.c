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

void delete_node (void *content){
	free(content);
}

int main(int argc, char* argv[])
{
	t_list *node1;

	node1 = ft_lstnew(argv[argc - 1]);

	print_this_node(node1);
	printf("\n");
	//delete_node(node1->content);
	//free(node1);
	ft_lstdelone(node1, &delete_node);
	print_this_node(node1);
}
