#include "shell.h"

/**
 * _pcexit - exits shell
 * @info: Structure
 * Return: exit status 0 if info.argv[0] != "exit"
 */

int _pcexit(inftm *info)
{
	int chext;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		chext = _erratoi(info->argv[1]);
		if (chext == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _pccd - changes the current directory
 * @info: Structure
 * Return: 0.
 */

int _pccd(inftm *info)
{
	char *s, *dir, buffer[1024];
	int dir_ch;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			dir_ch = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			dir_ch = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		dir_ch = /* TODO: what should this be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		dir_ch = chdir(info->argv[1]);
	if (dir_ch == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _pchelp - change the current directory
 * @info: Structure
 * Return: 0.
 */

int _pchelp(inftm *info)
{
	char **arr_arg;

	arr_arg = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arr_arg); /* temp att_unused workaround */
	return (0);
}
