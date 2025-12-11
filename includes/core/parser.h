#ifndef JSON_CORE_PARSER_H
# define JSON_CORE_PARSER_H

# include "JSON.h"

/**
 * @brief
 * @param
 * @return
 */
t_JSON			parse_json(const char *data);

/**
 * @brief
 * @param
 * @return
 */
static void		skip_spaces(const char *data);

/**
 * @brief
 * @param
 * @return
 */
static t_JSON	*parse_value(const char *data);

/**
 * @brief
 * @param
 * @return
 */
static char		*parse_string(const char *data);

/**
 * @brief
 * @param
 * @return
 */
static double	parse_number(const char *data);

/**
 * @brief
 * @param
 * @return
 */
static t_JSON	*parse_object(const char *data);

#endif