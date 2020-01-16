/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:21:57 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/16 18:27:28 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int main(void)
{
	char  buffer[144];

	(int)buffer[140] = 0;
	fgets(buffer + 40, 100, stdin);
	(int)buffer[140] == 0;

ok:

	if (strlen(buffer + 40) >= buffer[140])
	{
		printf(buffer + 40);
		exit(0);
	}
	else
	{
		int res = *(buffer + 40 + buffer[140]);

		if (res & 0xff <= 0x40 || res & 0xff > 0x5a)
		{
			(int)buffer[140]++;
			goto ok;
		}
		else
		{
			*(buffer + 40 + buffer[140]) ^= 0x20;
			(int)buffer[140]++;
			goto ok;
		}
	}
	return (0);
}
