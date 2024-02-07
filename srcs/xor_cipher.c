/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor_cipher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepple <fepple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:03:59 by fepple            #+#    #+#             */
/*   Updated: 2024/02/07 22:53:50 by fepple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

char	*key_gen(unsigned int seed, unsigned int n)
{
	char	*key;
	int		i;

	srand(seed);
	key = malloc((n + 1) * sizeof(char));
	if (key == NULL)
		return (NULL);
	i = 0;
	while (n-- > 0)
	{
		key[i++] = rand() % 128;
	}
	key[i] = '0';
	return (key);
}

char	*xor_cipher(char *data, char *key)
{
	unsigned int	data_len;
	unsigned int	key_len;
	char			*res;
	unsigned int	i;

	data_len = strlen(data);
	key_len = strlen(key);
	if (key_len < data_len)
		return (NULL);
	res = malloc((data_len + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < data_len)
	{
		if (i % 2 == 0)
			res[i] = data[i] ^ key[key_len - 1 - i];
		else
			res[i] = data[i] ^ key[i % key_len];
		i++;
	}
	res[data_len] = '\0';
	return (res);
}
