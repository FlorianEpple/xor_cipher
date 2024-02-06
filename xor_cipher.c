#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	xor_encrypt_decrypt(unsigned char *data, int data_length,
		unsigned char *key, int key_length)
{
	int	i;

	i = 0;
	while (i < data_length)
	{
		data[i] ^= key[i % key_length];
		i++;
	}
}

int	main(int argc, char *argv[])
{
	FILE			*file;
	unsigned long	file_size;
	unsigned char	*data;
	unsigned char	*key;
	int				key_length;

	if (argc != 3)
	{
		printf("Usage: %s <file_path> <key>\n", argv[0]);
		return (1);
	}
	file = fopen(argv[1], "rb+");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);
	data = (unsigned char *)malloc(file_size);
	if (data == NULL)
	{
		perror("Memory allocation failed");
		fclose(file);
		return (1);
	}
	if (fread(data, 1, file_size, file) != file_size)
	{
		perror("Error reading file");
		fclose(file);
		free(data);
		return (1);
	}
	key = (unsigned char *)argv[2];
	key_length = strlen((char *)key);
	xor_encrypt_decrypt(data, file_size, key, key_length);
	fseek(file, 0, SEEK_SET);
	if (fwrite(data, 1, file_size, file) != file_size)
	{
		perror("Error writing to file");
		fclose(file);
		free(data);
		return (1);
	}
	fclose(file);
	free(data);
	return (0);
}
