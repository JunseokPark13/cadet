/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:03:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/07 16:02:41 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]){

	char *k, *k2;
	k = (char*)malloc(sizeof(char) * atoi(argv[2]));
	k2 = (char*)malloc(sizeof(char) * atoi(argv[2]));
	for(int i = 0; i < (int)strlen(argv[1]); i++)
	{
		k[i] = argv[1][i];
		k2[i] = argv[1][i];
	}
	k[strlen(argv[1])] = '\0';
	k2[strlen(argv[1])] = '\0';
	
	char c = argv[3][0];
	size_t len = atoi(argv[4]);

	printf("%d\n", argc);
	printf("%s, %s, %c, %ld\n", k, k2, c, len);

	memset(k, c, len);
	ft_memset(k2, c, len);

	write(1, k, strlen(k));
	write(1, "\n", 1);
	write(1, k2, strlen(k2));
	write(1, "\n", 1);
}
