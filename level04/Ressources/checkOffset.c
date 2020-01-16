/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkOffset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldedier <ldedier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:38:56 by ldedier           #+#    #+#             */
/*   Updated: 2020/01/16 15:39:52 by ldedier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

/*
** gcc -m32 -o test checkOffset.c && ./test
**
** returns 44 as orig_eax offset
*/

#include </usr/include/sys/user.h>
#define OFFSETOF(TYPE, ELEMENT) ((size_t)&(((TYPE *)0)->ELEMENT))

int main(void)
{
	printf("%zu\n", sizeof(long int));
	printf("wordsize: %d\n", __WORDSIZE);
//	printf("%d\n", OFFSETOF(struct user_regs_struct, esi));
	printf("%d\n", OFFSETOF(struct user_regs_struct, orig_eax));
	return 0;
}

