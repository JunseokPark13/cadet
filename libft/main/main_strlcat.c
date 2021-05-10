/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:03:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/08 13:27:47 by jupark           ###   ########.fr       */
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

	printf("argc = %d\n", argc);
	printf("%s, %s, %ld\n", k, k2, len);
	printf("dst_len = %ld\n", strlen(k));
	printf("src_len = %ld\n", strlen(k2));
	printf("dstsize = %ld\n", len);

	int n1 = strlcat(k, k2, len);
	int n2 = ft_strlcat(k3, k4, len);

	write(1, k, atoi(argv[2]));
	write(1, "\n", 1);
	write(1, k3, atoi(argv[2]));
	write(1, "\n", 1);

	printf("n1 = %d\nn2 = %d\n", n1, n2);
	free(k);
	free(k2);
	free(k3);
	free(k4);
}
