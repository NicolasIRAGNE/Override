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

void secret_backdoor(void)
{
	buffer[128];

	fgets(buffer, 128, stdin);
	system(buffer);
}

void set_username(char *msgBuffer)
{
	char buffer[160];

	buffer[8] = msgBuffer;
	bzero(buffer + 16, 128); // ->buffer + 140
	puts(">: Enter your username");
	printf("'>>: '");

	fgets(buffer + 16, 128, stdin); // ->buffer + 140

	int i = 0;
//+112
	while (i <= 40 && buffer[16 + i] != 0)
	{
		msgBuffer[140 + i] = buffer[16 + i];
		i++;
	}
	printf(">: Welcome, %s", msgBuffer + 140);
}

void set_msg(char *msgBuffer)
{
	char buffer[1040];

	buffer[8] = msgBuffer;
	bzero(buffer + 16, 1024);  // buffer + 1040

//+47

	puts(">: Msg @Unix-Dude");
	printf(">>: ");
	fgets(buffer + 16, 1024, stdin); //buffer + 1040

	strncpy(msgBuffer, buffer + 16, (size_t)*(int*)(msgBuffer + 180)); //modified by set_username

//	strncpy(msgBuffer, buffer + 16, 140); // ->buffer + 156

}

void handle_msg(void)
{
	char buffer[192];

	bzero(buffer + 140, 40);

	buffer[180] = 140;

	set_username(buffer);	// buffer + 140	-> buffer + 180
	set_msg(buffer);		// buffer + 0	-> buffer + 140

	//buffer 0 -> 180

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
