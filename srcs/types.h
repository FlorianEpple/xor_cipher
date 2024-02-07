/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepple <fepple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:37:24 by fepple            #+#    #+#             */
/*   Updated: 2024/02/07 23:00:53 by fepple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

char	*file_get_content(char *file);
int		file_put_content(char *file, char *content);

char	*key_gen(unsigned int seed, unsigned int n);
char	*xor_cipher(char *data, char *key);

#endif // TYPES_H
