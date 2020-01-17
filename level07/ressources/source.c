/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:02:29 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/17 17:50:19 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int get_unum(void)
{
	unsigned int res;

	scanf("%u", &res);
	return res;
}

int store_number(char *mem)
{
	unsigned int number = 0;
	unsigned int index = 0;

	printf(" Number: ");
	number = get_unum(); //0x10
	printf(" Index: ");
	index = get_unum(); //0xc
	
	int hash = unintelligible_hash(index);

	if (hash != 0)
	{
		if (number >> 24 != 0xb7) //start of system functions
		{
			mem[index >> 2] = number;
			return (0);
		}
	}
	puts(" *** ERROR! ***");
	puts("   This index is reserved for wil! ");
	puts(" *** ERROR! ***");
	return (1);
}

int read_number(char *mem)
{
	unsigned int index;

	index = 0;
	printf(" Index: ");
	index = get_unum();
	printf(" Number at data[%u] is %u\n", index, mem[index >> 2]);
	return (0);
}

int main(int argc, char **argv, char **env) //0xc -> argv , 0x10 -> env
{
	(void)argc;

	char buffer[464];

	buffer[28] = argv;
	buffer[24] = env;

	bzero(buffer + 36, 400);
	
	while (*buffer[28] != NULL)
	{
		int len = strlen(*buffer[28]);
		memset(*buffer[28], 0, strlen(*buffer[28]));
		buffer[28]++;
	}
	while (*buffer[24] != NULL)
	{
		int len = strlen(*buffer[24]);
		memset(*buffer[24], 0, strlen(*buffer[24]));
		buffer[24]++;
	}

	puts("Welcome to wil's crappy number service!  {...} \n\n\n\n");

	while (1)
	{
		printf("Input command: ");
		fgets(buffer + 440, 20, stdin);

		int len = strlen(buffer + 440) - 1;

		buffer[440 + len] = 0;
		if (strcmp(buffer + 440, "store"))
		{
			buffer[436] = store_number(buffer + 36);
		}
		else if (strcmp(buffer + 440, "read"))
		{
			buffer[436] = read_number(buffer + 36);
		}
		else if (strcmp(buffer + 440, "quit"))
		{
			return 0;
		}
		if (buffer[436] == 0)
			printf(" Completed %s command successfully\n", buffer + 440);
		else
			printf(" Failed to do %s command\n", buffer + 440);
		*(int *)buffer + 440 = 0;
		*(int *)buffer + 440 + 4 = 0;
		*(int *)buffer + 440 + 8 = 0;
		*(int *)buffer + 440 + 12 = 0;
		*(int *)buffer + 440 + 16 = 0;
	}
	return (0);
}
