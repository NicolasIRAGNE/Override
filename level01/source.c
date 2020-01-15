/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:44:04 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/15 14:27:12 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char name[256];

int verify_user_name()
{
	puts("verifying username....\n");
	return strcmp(name, "dat_wil");
}

int verify_user_pass(char *buffer)
{
	return strcmp(buffer, "admin");
}

int main()
{
	char buff[92];
	int res;

	bzero(buff + 28, 16);
	res = 0;
	puts("********* ADMIN LOGIN PROMPT *********");
	printf("Enter Username: ");
	fgets(name, 256, stdin);
	if ((res = verify_user_name()) == 0)
	{
		puts("Enter Password: ");
		fgets(buff + 28, 100, stdin);
		if ((res = verify_user_pass(buff + 28)) != 0)
		{
			puts("nope, incorrect password...\n");
			return 1;
		}
	}
	else
	{
		puts("nope, incorrect username...\n");
		return 1;
	}
	return (0);
}
