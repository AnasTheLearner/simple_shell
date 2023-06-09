#include "shell.h"

/**
 * _pcenv - prints the current environment
 * @info: Structure
 * Return: 0.
 */

int _pcenv(inftm *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - get the value of an environ variable
 * @info: Structure
 * @name: environ name
 * Return: value
 */

char *_getenv(inftm *info, const char *name)
{
	listm *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _pcsetenv - Initialize a new environment variable
 * or modify an existing one
 * @info: Structure
 *  Return: 0.
 */

int _pcsetenv(inftm *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _pcunsetenv - Remove an environment variable
 * @info: Structure
 * Return: 0.
 */

int _pcunsetenv(inftm *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure
 * Return: 0.
 */

int populate_env_list(inftm *info)
{
	listm *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
