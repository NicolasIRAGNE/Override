/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:17:24 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/18 16:03:38 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void log_wrapper(FILE *file, char *description, char *filename)
{
	char buffer[304];

	buffer[304 - 280 (= 24)] = file;
	buffer[304 - 288 (= 16)] = description;
	buffer[304 - 296 (= 8)] = filename;

	strcpy(buffer + 32, description);
	
	snprintf(buffer + 32 + strlen(buffer + 32), 254 - strlen(buffer + 32), filename);

	size_t ret = strcspn(buffer + 32, "\n");
	buffer[32 + ret] = 0;

	fprintf(buffer[24] (= file), "LOG: %s\n", buffer + 110);

	//check_canary();

	return (0);
}

int main(int argc, char **argv)
{
	char	buffer[176];
	FILE	*writefile;
	FILE	*readfile

	if (argc != 2)
	{
		printf("Usage: %s filename\n", *argv);
		if ((writefile = fopen("./backups/.log", "w")) == NULL) // - 0x88
		{
			printf("ERROR: Failed to open %s\n", "./backups/.log");
			exit(1);
		}

		log_wrapper(writefile, "Starting back up: ", argv[1]);
//+195
		if ((readFile = fopen(argv[1], "r")) == NULL) // - 0x80
		{
			printf("ERROR: Failed to open %s\n", argv[1]);
			exit(1);
		}

//+281

		buffer[64] = "./backups/"; // - 0x70

		strncat(buffer + 64, argv[1], 99 - strlen(buffer + 64));
//+311

		

	}
	return (0);
}
