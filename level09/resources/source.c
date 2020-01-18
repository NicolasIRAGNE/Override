/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:57:02 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/18 18:28:33 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void set_username(char *msgBuffer)
{
	char buffer[160];

	bzero(buffer + 16, 128);
	puts(">: Enter your username");
	printf("'>>: '");

	fgets(buffer + 16, 128, stdin);

	int i = 0;
//+112
	while (i < 40 && buffer[16 + i] != 0)
	{
		msgBuffer[140 + i] = buffer[16 + i];
		i++;
	}
}

void set_msg(char *msgBuffer)
{
	char buffer[1040];

	buffer[8] = msgBuffer;
	bzero(buffer + 16, 1024);
//+47
	
}

void handle_msg(void)
{
	char buffer[192];

	bzero(buffer + 140, 40);
	buffer[180] = 140;

	set_username(buffer);
	set_msg(buffer);
	puts(">: Msg sent!");
}

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	puts(
"--------------------------------------------
|   ~Welcome to l33t-m$n ~    v1337        |
--------------------------------------------");

	handle_msg();
	return (0);
}
