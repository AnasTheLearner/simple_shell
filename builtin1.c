#include "shell.h"

/**
 * _pchistory - displays the history list
 * @info: Structure
 *  Return: 0.
 */

int _pchistory(inftm *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: struct
 * @str: string
 * Return: 0 on success, 1 if not
 */

int unset_alias(inftm *info, char *str)
{
	char *p, c;
	int art;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	art = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (art);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: string
 * Return: 0 on success, 1 if not
 */

int set_alias(inftm *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 * Return: 0 on success, 1 if not
 */

int print_alias(listm *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _pcalias - mimics the alias builtin
 * @info: Structure
 *  Return: 0.
 */

int _pcalias(inftm *info)
{
	int i = 0;
	char *p = NULL;
	listm *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
