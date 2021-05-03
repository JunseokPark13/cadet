/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jupark <jupark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 13:03:00 by jupark            #+#    #+#             */
/*   Updated: 2021/05/03 14:08:06 by jupark           ###   ########.fr       */
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
	
	bzero(k, 3 * sizeof(char));
	ft_bzero(k2, 3 * sizeof(char));
	write(1, k, 6);
	write(1, "\n", 1);
	write(1, k2, 6);
	write(1, "\n", 1);

}
