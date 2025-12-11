# Architecture

JSON-Parser is a simple parser for JSON.

## Globale structure

```bash
.
├── docs # Documentation
├── includes # Headers
├── src # Source files
└── tests # Tests
```

## Types / Functions

```C
// Types
typedef enum
{
	JSON_OBJECT,
	JSON_STRING,
	JSON_NUMBER,
	JSON_BOOL,
	JSON_NULL
}	JSON_type;

typedef struct	s_JSON
{
	char			*key;
	JSON_type		type;
	void			*value;
	struct s_JSON	*next;
}	t_json;

// Functions
t_JSON	*JSON_init_file(FILE *f); // Initialize a json content from a file
t_JSON	*JSON_init_string(const char *str); // Initialize a json content from a file
t_JSON	*JSON_get(t_JSON *root, const char *key); // Get a JSON object from a root
int		JSON_write_file(t_JSON *root, FILE *f); // Write the content of root into the file
char	*JSON_write_string(t_JSON *root); // Write the content of root in
void	JSON_destroy(t_JSON *root); // Free a root
```