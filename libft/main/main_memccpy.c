/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:03:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/07 16:48:32 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

void		ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int main(int argc, char* argv[]){

	char *k, *k2, *k3, *k4;
	k = (char*)malloc(sizeof(char) * atoi(argv[2]));
	k2 = (char*)malloc(sizeof(char) * atoi(argv[4]));
	k3 = (char*)malloc(sizeof(char) * atoi(argv[2]));
	k4 = (char*)malloc(sizeof(char) * atoi(argv[4]));

	for(int i = 0; i < (int)strlen(argv[1]); i++)
	{
		k[i] = argv[1][i];
		k3[i] = argv[1][i];
	}
	for(int i = 0; i < (int)strlen(argv[3]); i++)
	{
		k2[i] = argv[3][i];
		k4[i] = argv[3][i];
	}

	k[strlen(argv[1])] = '\0';
	k3[strlen(argv[1])] = '\0';
	
	k2[strlen(argv[3])] = '\0';
	k4[strlen(argv[3])] = '\0';
	
	char	c = argv[5][0];
	size_t len = atoi(argv[6]);

	printf("%d\n", argc);
	printf("%s, %s, %c, %ld\n", k, k2, c, len);

	void *m1 = k;
	void *m2 = k3;
	k = memccpy(k, k2, c, len);
	k3 = ft_memccpy(k3, k4, c, len);


	//ft_print_result(k);
	write(1, "\n", 1);
	write(1, m1, strlen(m1));
	write(1, "\n\n", 2);

	//ft_print_result(k3);
	write(1, "\n", 1);
	write(1, m2, strlen(m2));
	write(1, "\n\n", 2);

	free(k);
	free(k2);
	free(k3);
	free(k4);
}
