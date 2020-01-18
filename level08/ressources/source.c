/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 11:17:24 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/18 11:17:24 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


void log_wrapper(FILE *file, char *description, char *filename)
{
	char buffer[304];

	buffer[304 - 280 (= 24)] = file;
	buffer[304 - 288 (= 16)] = description;
	buffer[304 - 296 (= 8)] = filename;

	strcpy(buffer + 32, description);
}

int main(int argc, char **argv)
{
	char buffer[176];
	File *file;

	if (argc != 2)
	{
		printf("Usage: %s filename\n",  argv[0]);
		if ((file = fopen("./backups/.log", "w")) == NULL)
		{
			printf("ERROR: Failed to open %s\n", "./backups/.log");
			exit(1);
		}
		log_wrapper(file, "Starting back up: ", argv[1]);
	}
	return (0);
}
