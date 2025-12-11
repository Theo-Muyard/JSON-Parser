#ifndef JSON_JSON_H
# define JSON_JSON_H

# include <stdio.h>

typedef enum
{
	JSON_OBJECT = 0u,
	JSON_STRING,
	JSON_NUMBER,
	JSON_BOOL,
	JSON_NULL
}	JSON_type;

typedef struct	s_JSON
{
	JSON_type		type;
	void			*value;
}	t_JSON;

typedef struct	s_JSON_pair
{
	char				*key;
	t_JSON				*value;
	struct s_JSON_pair	*next;
}	t_JSON_pair;

/**
 * @brief
 * @param
 * @return
 */
t_JSON	*JSON_init_file(FILE *f);

/**
 * @brief
 * @param
 * @return
 */
t_JSON	*JSON_init_string(const char *str);

/**
 * @brief
 * @param
 * @return
 */
t_JSON	*JSON_get(t_JSON *root, const char *key);

/**
 * @brief
 * @param
 * @return
 */
int		JSON_write_file(t_JSON *root, FILE *f);

/**
 * @brief
 * @param
 * @return
 */
char	*JSON_write_string(t_JSON *root);

/**
 * @brief
 * @param
 * @return
 */
void	JSON_destroy(t_JSON *root);

#endif /* JSON_JSON_H */