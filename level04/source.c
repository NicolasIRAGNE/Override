/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 18:24:33 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/16 15:59:50 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include </usr/include/sys/user.h>

#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

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
			buffer[168] = ptrace(PTRACE_PEEKUSER, child_pid, OFFSETOF(struct user_regs_struct, orig_eax), NULL);
			//get value of orig_eax (offset 44) of child
			if (buffer[168] == 11)
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
		prctl(PR_SET_PDEATHSIG, 1);
		ptrace(PTRACE_TRACEME, 0, 0, 0); // make me traced by my parent
		puts("Give me some shellcode, k");
		gets(buffer + 32);
	}
	return (0);
}
