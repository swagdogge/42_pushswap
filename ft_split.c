/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razimmer <razimmer@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:48:29 by razimmer          #+#    #+#             */
/*   Updated: 2026/01/10 18:50:12 by razimmer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static	int	count_substrings(char const *s, char c)
{
	int	i;
	int	substr_count;

	i = 0;
	substr_count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			substr_count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (substr_count);
}

static	int	get_substr_len(char	const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

static	char	*copy_substr(char const *s, int *i, char c, char *dest)
{
	int		j;

	j = 0;
	while (s[*i] && s[*i] != c)
	{
		dest[j] = s[*i];
		(*i)++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

static	char	**freeall(char **tab, int current_substr)
{
	int	j;

	j = 0;
	while (j < current_substr)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		current_substr;

	if (!s)
		return (NULL);
	tab = (char **)malloc ((count_substrings(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	current_substr = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		tab[current_substr] = malloc(get_substr_len(s, c, i) + 1);
		if (!tab[current_substr])
			return (freeall(tab, current_substr));
		tab[current_substr] = copy_substr(s, &i, c, tab[current_substr]);
		current_substr++;
	}
	tab[current_substr] = NULL;
	return (tab);
}
