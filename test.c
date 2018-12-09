/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nouhaddo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 21:52:28 by nouhaddo          #+#    #+#             */
/*   Updated: 2018/12/09 00:32:10 by nouhaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char r[50];
	int c;

	c = 1;
	while (c)
	{
		c = read(0, r, 10);
		r[c] = '\0';
		printf("%s\n", r);
	}
	return 0;
}
