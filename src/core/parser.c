#include "parser.h" // Home header
#include <stdio.h>
#include <ctype.h>

t_JSON			parse_json(const char *data);

static void		skip_spaces(const char *data)
{
	char	*ptr;

	ptr = data;
	while (isspace(*ptr))
		*ptr++;
	return (ptr);
}

static t_JSON	*parse_value(const char *data);

static char		*parse_string(const char *data);

static double	parse_number(const char *data);

static t_JSON	*parse_object(const char *data);