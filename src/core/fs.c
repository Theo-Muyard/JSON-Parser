#include "fs.h" // Home Header
#include "log.h"
#include <stdio.h> // Standard libs
#include <stdlib.h>

char	*fs_read(const char *path)
{
	FILE		*_f;
	char		*_buffer;
	__ssize_t	_size;
	__ssize_t	_read;

	_f = fopen(path, "r");
	if (NULL == _f)
		return (log_error("Failed to open the file at %s.", path), NULL);
	fseek(_f, 0, SEEK_END);
	_size = ftell(_f);
	rewind(_f);

	_buffer = malloc((_size + 1) * sizeof(char));
	if (NULL == _buffer)
		return (fclose(_f), log_error("Allocation memory failed."), NULL);

	_read = fread(_buffer, 1, _size, _f);
	if (_size != _read)
		return (fclose(_f), free(_buffer), log_error("Failed to correctly read the file at %s", path), NULL);
	_buffer[_size] = '\0';
	fclose(_f);
	return (_buffer);
}

int		fs_write(const char *path, const char *data)
{
	FILE		*_f;

	_f = fopen(path, "w");
	if (NULL == _f)
		return (log_error("Failed to open the file at %s.", path), 1);
	if (fprintf(_f, "%s", data) < 0)
		return (log_error("Failed to write the file at %s.", path), 1);
	fclose(_f);
	return (0);
}
