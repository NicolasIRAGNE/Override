/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:49:41 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/14 17:49:02 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	char buff[288];

	bzero(buff + 288 - 0x70, 96); // (buff 288 - 112 = buffer + 176) // USERNAME BUFFER (len 100)
	bzero(buff + 288 - 0xa0, 40); // (buff 288 - 160 = buffer + 128) // LEVEL03.PASS BUFFER (len 41)
	bzero(buff + 288 - 0x110, 96); // (buff 288 - 272 = buffer + 16) // PASSWORD BUFFER (len 100)

	(File *)(buff + 288 - 0x8) = fopen("/home/users/level03/.pass", "r");
	if (buff + 288 - 0x8 == NULL)
	{
		fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
		exit(1);
	}
//+210:
	buff[288 - 12] = fread(buff + 288 - 0xa0, 1, 41, buff + 288 - 0x8); // buff + 128
	int ret = strcspn(buff + 288 - 0xa0, "\n"); // buff + 16;
	buff[288 - 0xa0 + ret] = 0;	 // buff[128 + ret] = 0;
	if (buff[288 - 12] != 41)
	{
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		fwrite("ERROR: failed to read password file\n", 1, 36, stderr);
		exit(1);
	}
	else
	{
		puts("/*****************************************\\");
		puts("| You must login to access this system. |");
		puts("\\****************************************/");
		printf("--[ Username: ");
		fgets(buffer + 288 - 0x70 , 100, stdin);
		ret = strcspn(buffer + 288 - 0x70 , "\n");
		buffer[288 - 0x70 + ret] = 0;
		printf("--[ Password: ");
//+498
		fgets(buffer + 288 - 0x110, 100, stdin);
		ret = strcspn(buffer + 288 - 0x110, "\n");
		buffer[288 - 0x110 + ret] = 0;
		puts("*******************************************");
		if (strncmp(buffer + 288 - 0x110, buffer + 288 - 0xa0, 49) == 0)
		{
			printf("Greetings, %s!\n", buffer + 288 - 0x70);
			system("/bin/sh");
			return 0;
		}
		else
		{
			printf(buffer + 288 - 0x70); // ???: buff + 176
			puts(" does not have access!\n");
			exit(1);
		}
	}
	return (0);
}
