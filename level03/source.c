/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:46:36 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/15 17:55:55 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void decrypt()
{
	...
		system("/bin/sh");
	...
}

void test(int input, int goal)
{
	int value;

	if ((value = (goal - input)) < 21)
	{
		...
		value << 2;
		...
		decrypt(value);
	}
}

int main(void)
{
	srand(time(NULL));
	puts("***********************************");
	puts("*\t\tlevel03\t\t**");
	puts("***********************************");

	printf("Password:");
	scanf("%d", ret);
	test(ret, 0x1337d00d);
	return (0);
}
