/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:24:33 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/15 21:16:49 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(int argc, char **argv)
{
	char	buffer[176];
	pid_t	child;

	child_pid = fork();
	bzero(buffer + 32, 128); //-> 160
	buffer[28] = 0;
	buffer[168] = 0;
	if (child_pid) //parent
	{
parent_beginning:
		wait(buffer + 28);
		buffer[160] = *(buffer + 28);
		if (WTERMSIG(buffer[160]) == 0 || WIFSIGNALED(buffer[160]) > 0) 
		{
			// WTERMSIG returns the numeric value of the signal that was raised by the process
			// WIFSIGNALED indicates that the child process exited because it raised a signal
			puts("child is exiting...");
		}
		else
		{
			res = ptrace(3, child_pid, 44, 0);
			buffer[168] = res;
			if (res == 11)
			{
				puts("no exec() for you");
				kill(child_pid, 9);
			}
			else
				goto parent_beginning;
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
