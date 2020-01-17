/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:35:03 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/17 11:35:03 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int auth(char *login, unsigned int serial)
{
	char buffer[40];

	buffer[4] = strcspn(login, "\n");
	login[buffer[4]] = 0;

	buffer[44 - 12 (=32)] = strnlen(login, 32);
	//push(buffer[32])
	//pop(buffer[32]) -> eax
	if (buffer[32] <= 5)
		return 0;
//+78
	//ptrace

	
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char buffer[80];

	buffer[28] = argv;
	buffer[76] = 0x14; // gs:0x14?
	//push(0);
	//pop(0); -> eax

	puts("***********************************");
	puts("*				level06		 		*");
	puts("***********************************");
	printf("-> Enter Login: ");
	
	fgets(buffer + 44, 32, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", buffer + 40);
	
	if (auth(buffer + 44, buffer + 40) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return 0;
	}
	else
	{
		return 1;
	}

	return (0);
}
