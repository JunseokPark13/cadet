/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:03:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/07 16:22:52 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

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
	
	size_t len = atoi(argv[5]);

	printf("%d\n", argc);
	printf("%s, %s, %ld\n", k, k2, len);

	memcpy(k, k2, len);
	ft_memcpy(k3, k4, len);

	write(1, k, strlen(k));
	write(1, "\n", 1);
	write(1, k3, strlen(k3));
	write(1, "\n", 1);

	free(k);
	free(k2);
	free(k3);
	free(k4);
}
