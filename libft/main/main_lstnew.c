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


int main(int argc, char* argv[])
{
	t_list *node1;

	node1 = ft_lstnew(argv[argc - 1]);
	print_all_list(node1);
}
