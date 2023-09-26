/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:58:31 by ade-beco          #+#    #+#             */
/*   Updated: 2023/09/26 20:25:26 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dup;

	i = ft_strlen(src) + 1;
	dup = malloc(sizeof(char) * (i));
	if (dup == NULL)
		return (NULL);
	ft_strcpy(dup, src);
	return (dup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	int			i;

	tab = (malloc(sizeof(t_stock_str) * (ac + 1)));
	i = 0;
	if (!tab)
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		if (!tab[i].copy)
		{
			while (i-- > 0)
				free(tab[i].copy);
			free(tab);
			return (NULL);
		}
		i++;
	}
	tab[i].str = 0;
	return (tab);
}

/*int main(int argc, char **argv)
{
    t_stock_str *result = ft_strs_to_tab(argc - 1, &argv[1]);
    if (result == NULL)
	{
        printf("Memory allocation error!\n");
        return 1;
    }
    ft_show_tab(result);
    int i = 0;
    while (result[i].str != NULL)
	{
        free(result[i].copy);
        i++;
    }
    free(result);
    return 0;
}*/