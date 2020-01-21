/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:21:57 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/21 12:46:35 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{
	char  buffer[144];

	int i = 0;
	fgets(buffer + 40, 100, stdin);
	i = 0;

	while (i < strlen(buffer + 40))
	{
		int res = buffer[40 + i];

		if (res & 0xff <= 0x40 || res & 0xff > 0x5a)
			i++;
		else
		{
			buffer[40 + i] ^= 0x20;
			i++;
		}
	}
	printf(buffer + 40);
	exit(0);
}
