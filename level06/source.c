/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 11:35:03 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/17 14:53:02 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int auth(char *login, unsigned int serial)
{
	char buffer[40];

	int ret = strcspn(login, "\n");
	login[ret] = 0;

	int len = strnlen(login, 32);
	if (len <= 5)
		return 0;
	if (ptrace(PTRACE_TRACEME, 0, 1, 0) == -1)
	{
		puts(GREEN"---------------------------.");
		puts(RED "| !! TAMPERING DETECTED !!  |");
		puts(GREEN"---------------------------\'");
		return (1);
	}
	int hash = (((login[3] & 0xff) ^ 0x1337) + 6221293) * 0x539;
	int i = 0;
	while (i < len)
	{
		if (login[i] & 0xff < 31)
			return 1;
		hash += (login[i] & 0xff) ^ hash >> 1;
		i++;
	}
	if (serial == hash)
		return (0);
	else
		return (1);
}

int main()
{
	char buffer[32];
	unsigned int value;

	puts("***********************************");
	puts("*				level06		 		*");
	puts("***********************************");
	printf("-> Enter Login: ");
	
	fgets(buffer, 32, stdin);

	puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
	printf("-> Enter Serial: ");
	scanf("%u", &value);
	
	if (auth(buffer, value) == 0)
	{
		puts("Authenticated!");
		system("/bin/sh");
		return 0;
	}
	else
		return 1;
}
