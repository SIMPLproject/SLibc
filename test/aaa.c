/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aaa.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouzali <ltouzali@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:53:49 by ltouzali          #+#    #+#             */
/*   Updated: 2025/04/04 19:31:12 by ltouzali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av) {
	if (ac != 2) {
		printf("Usage: %s <string>\n", av[0]);
		return 1;
	}

	const char *test_string = av[1];
	int len = strlen(test_string);
	printf("len = %d\n", len);
	
	int ptr_size = sizeof(char *);
	printf("ptr_size = %d\n", ptr_size);
	
	char *str1 = "Hello, World!";
	char *str2 = "Hello, World!ee";
	printf("cmp = %d\n", strcmp(str1, str2));
	return 0;
}
