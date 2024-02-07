/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepple <fepple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:36:43 by fepple            #+#    #+#             */
/*   Updated: 2024/02/07 23:09:31 by fepple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

char	*file_get_content(char *file)
{
	FILE			*f_file;
	unsigned long	file_size;
	char			*data;

	f_file = fopen(file, "r");
	if (f_file == NULL)
		return (NULL);
	fseek(f_file, 0, SEEK_END);
	file_size = ftell(f_file);
	rewind(f_file);
	if (file_size <= 0)
	{
		fclose(f_file);
		return (NULL);
	}
	data = (char *)malloc(file_size + 1);
	if (data == NULL)
	{
		fclose(f_file);
		return (NULL);
	}
	if (fread(data, 1, file_size, f_file) != file_size)
	{
		fclose(f_file);
		free(data);
		return (NULL);
	}
	data[file_size] = '\0';
	fclose(f_file);
	return (data);
}

int	file_put_content(char *file, char *content)
{
	FILE	*f_file;
	size_t	content_size;

	f_file = fopen(file, "w");
	if (f_file == NULL)
	{
		perror("Error opening file");
		return (0);
	}
	content_size = strlen(content);
	if (fwrite(content, 1, content_size, f_file) != content_size)
	{
		perror("Error writing to file");
		fclose(f_file);
		return (0);
	}
	fclose(f_file);
	return (1);
}
