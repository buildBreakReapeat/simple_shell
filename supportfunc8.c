#include "main.h"
/**
* _realloc - reallocates mem
* @ptr: pointer to the memory previously allocated with a call to malloc
* @old_size: size of ptr
* @new_size: size of the new memory to be allocated
*
* Return: pointer to the address of the new memory block
*/

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *temp_block;
	unsigned int i;

	if (ptr == NULL)
	{
		temp_block = malloc(new_size);
		return (temp_block);
	}
	else if (new_size == old_size)
		return (ptr);

	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else
	{
		temp_block = malloc(new_size);
		if (temp_block != NULL)
		{
			for (i = 0; i < min(old_size, new_size); i++)
				*((char *)temp_block + i) = *((char *) ptr + i);
			free(ptr);
			return (temp_block);
		}
		else
			return (NULL);
	}
}

size_t betty_is_annoying(char **lineptr, size_t *n, FILE *stream, int *c )
{
    size_t pos;
	char *new_ptr;

	pos = 0;
    while (*c != EOF)
	{
	if (pos + 1 >= *n)
	{
		size_t new_size = *n + (*n >> 2);

		if (new_size < 128)
			new_size = 128;
		new_ptr = _realloc(lineptr, 128, new_size);
		if (new_ptr == NULL)
			return (-1);
		*n = new_size;
		*lineptr = new_ptr;
	}
	((unsigned char *)(*lineptr))[pos++] = *c;
	if (*c == '\n')
		break;
	*c = getc(stream);
	}
	(*lineptr)[pos] = '\0';

    return (pos);
}
