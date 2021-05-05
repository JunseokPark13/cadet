/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:03:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/05 10:56:08 by jupark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void){

	char k[6] = "12345";
	char k2[6] = "12345";

	write(1, k, 6);
	write(1, "\n", 1);
	write(1, k2, 6);
	write(1, "\n", 1);
	
	write(1, memset(k, 'a', 3 * sizeof(char)), 5);
	write(1, "\n", 1);
	write(1, ft_memset(k2, 'a', 3 * sizeof(char)), 5);
	write(1, "\n", 1);
	write(1, k, 6);
	write(1, "\n", 1);
	write(1, k2, 6);
	write(1, "\n", 1);

}
