/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:03:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/03 16:42:58 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void){

	char src1[] = "BlockDMask";
	char dest1[] = "fffffdddddzzzzz";
	int src_i1[3] = {1, 2, 3};
	int dest_i1[3];

	char src2[] = "BlockDMask";
	char dest2[] = "fffffdddddzzzzz";
	int src_i2[3] = {1, 2, 3};
	int dest_i2[3];


	write(1, src1, 10);
	write(1, "\n", 1);
	write(1, dest1, 15);
	write(1, "\n", 1);
	write(1, src2, 10);
	write(1, "\n", 1);
	write(1, dest2, 15);
	write(1, "\n", 1);

	for(int i = 0; i < 3; i++){
		printf("%d %d\n", src_i1[i], dest_i1[i]);
		printf("%d %d\n", src_i2[i], dest_i2[i]);
	}
	printf("\n");

	memmove(src1, src1 + 2, sizeof(char) * 4);
	memmove(dest_i1, src_i1, sizeof(int) * 3);
	ft_memmove(src2, src2 + 2, sizeof(char) * 4);
	ft_memmove(dest_i2, src_i2, sizeof(int) * 3);
	write(1, "\n", 1);
	
	write(1, src1, 10);
	write(1, "\n", 1);
	write(1, dest1, 15);
	write(1, "\n", 1);
	write(1, src2, 10);
	write(1, "\n", 1);
	write(1, dest2, 15);
	write(1, "\n", 1);

	for(int i = 0; i < 3; i++){
		printf("%d %d\n", src_i1[i], dest_i1[i]);
		printf("%d %d\n", src_i2[i], dest_i2[i]);
	}
	printf("\n");

}
