#ifndef JSON_CORE_FS_H
# define JSON_CORE_FS_H

/**
 * @brief Read the contents of the file at the given path
 * @param path The path of the file you want to read
 * @return The contents of the file read
 */
char	*fs_read(const char *path);

/**
 * @brief Writes the data to the given path
 * @param path The path of the file you want to read
 * @param data The data that will be written
 * @return 1 for error and 0 for success
 */
int		fs_write(const char *path, const char *data);

#endif