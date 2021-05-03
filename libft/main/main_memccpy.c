/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memccpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:03:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/03 15:16:32 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void){

	char src1[6] = "12345";
	char dest1[6];
	int src_i1[3] = {1, 2, 3};
	int dest_i1[3];
	char src2[6] = "12345";
	char dest2[6];
	int src_i2[3] = {1, 2, 3};
	int dest_i2[3];


	write(1, src1, 6);
	write(1, "\n", 1);
	write(1, dest1, 6);
	write(1, "\n", 1);
	write(1, src2, 6);
	write(1, "\n", 1);
	write(1, dest2, 6);
	write(1, "\n", 1);

	for(int i = 0; i < 3; i++){
		printf("%d %d\n", src_i1[i], dest_i1[i]);
		printf("%d %d\n", src_i2[i], dest_i2[i]);
	}
	printf("\n");

	write(1, memccpy(dest1, src1, '3' , sizeof(char) * sizeof(src1)), 1);
	write(1, "\n", 1);
	write(1, memccpy(dest_i1, src_i1, 2, sizeof(int) * 3), 1);
	write(1, "\n", 1);
	write(1, ft_memccpy(dest2, src2, '3',sizeof(char) * sizeof(src2)), 1);
	write(1, "\n", 1);
	write(1, ft_memccpy(dest_i2, src_i2, 2, sizeof(int) * 3), 1);
	write(1, "\n", 1);
	write(1, "\n", 1);
	
	write(1, src1, 6);
	write(1, "\n", 1);
	write(1, dest1, 6);
	write(1, "\n", 1);
	write(1, src2, 6);
	write(1, "\n", 1);
	write(1, dest2, 6);
	write(1, "\n", 1);

	for(int i = 0; i < 3; i++){
		printf("%d %d\n", src_i1[i], dest_i1[i]);
		printf("%d %d\n", src_i2[i], dest_i2[i]);
	}
	printf("\n");

}
