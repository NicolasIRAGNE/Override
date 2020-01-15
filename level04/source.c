/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:24:33 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/15 18:55:41 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main(int argc, char **argv)
{
	char buffer[176];
	pid_t child;
	child_pid = fork();
	bzero(buffer + 32, 128); //-> 160
	buffer[28] = 0;
	buffer[168] = 0;

	if (child_pid) //parent
	{
		wait(buffer + 28);
		buffer[160] = *(buffer + 28);
		if (WTERMSIG(buffer[160]))
		{
			if (WIFSIGNALED(buffer[160]))
			{

			}
		}
		else
		{

		}
	}
	else //child
	{
		prctl(1, 1);
		ptrace(0, 0, 0, 0);
		puts("Give me some shellcode, k");
		gets(buffer + 32);
	}
	return (0);
}
