/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fepple <fepple@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:03:59 by fepple            #+#    #+#             */
/*   Updated: 2024/02/07 23:13:39 by fepple           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types.h"

int	handle_crypt(char *target_file, char *key_file)
{
	char	*target_content;
	char	*key_content;
	char	*crypted_content;
	time_t	current_time;
	int		success;

	target_content = NULL;
	key_content = NULL;
	crypted_content = NULL;
	success = 0;
	if (target_file == NULL)
	{
		printf("Error: Target file is NULL.\n");
		return (0);
	}
	target_content = file_get_content(target_file);
	if (target_content == NULL)
	{
		printf("Error: Failed to read target file: %s\n", target_file);
		return (0);
	}
	if (key_file == NULL)
	{
		current_time = time(NULL);
		srand((unsigned)current_time);
		key_content = key_gen((unsigned)current_time, (strlen(target_content)
					+ (rand() % 128)));
		key_file = ".key";
		if (file_put_content(key_file, key_content) == 0)
		{
			printf("Error: Failed to write key to file: %s\n", key_file);
			free(target_content);
			free(key_content);
			return (0);
		}
	}
	else
	{
		key_content = file_get_content(key_file);
		if (key_content == NULL)
		{
			printf("Error: Failed to read key file: %s\n", key_file);
			free(target_content);
			return (0);
		}
	}
	crypted_content = xor_cipher(target_content, key_content);
	if (crypted_content == NULL)
	{
		printf("Error: Encryption failed.\n");
		free(target_content);
		free(key_content);
		return (0);
	}
	if (file_put_content(target_file, crypted_content) == 0)
	{
		printf("Error: Failed to write encrypted content to file: %s\n",
			target_file);
		free(target_content);
		free(key_content);
		free(crypted_content);
		return (0);
	}
	success = 1;
	free(target_content);
	free(key_content);
	free(crypted_content);
	return (success);
}

int	main(int argc, char *argv[])
{
	char	*target;
	char	*key;

	key = NULL;
	if (argc < 2 || argc > 3)
	{
		printf("Usage: %s <target> [<key>]\n", argv[0]);
		return (1);
	}
	target = strdup(argv[1]);
	if (argc == 3)
	{
		key = strdup(argv[2]);
	}
	if (handle_crypt(target, key) == 0)
	{
		printf("Encryption failed for target file: %s\n", target);
		free(target);
		free(key);
		return (1);
	}
	printf("Encryption successful for target file: %s\n", target);
	free(target);
	free(key);
	return (0);
}
