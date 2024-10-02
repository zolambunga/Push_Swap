/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:26:39 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/02 13:31:16 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <string.h>

static int	numwords(char **s, char *delim)
{
	int		i;
	int		word_num;
	char	*token;
	char	*copy;

	i = 0;
	word_num = 0;
	while (s[i])
	{
		copy = ft_strdup(s[i]);
		token = ft_strtok(copy, delim);
		while (token)
		{
			word_num++;
			token = ft_strtok(NULL, delim);
		}
		free(copy);
		i++;
	}
	return (word_num);
}

static int	split_words(char **result, char **s, char *delim)
{
	int		i;
	int		word;
	char	*token;
	char	*copy;

	word = 0;
	i = 0;
	while (s[i])
	{
		copy = ft_strdup(s[i]);
		token = ft_strtok(copy, delim);
		while (token)
		{
			result[word] = malloc(ft_strlen(token) + 1);
			if (!result[word])
			{
				while (word > 0)
					free(result[--word]);
				return (0);
			}
			ft_strlcpy(result[word], token, (ft_strlen(token) + 1));
			word++;
			token = ft_strtok(NULL, delim);
		}
		free(copy);
		i++;
	}
	result[word] = NULL;
	return (1);
}

char	**ft_matsplit(char **s, char c)
{
	char	**result;
	char	*delim;

	if (!s)
		return (NULL);
	delim = (char *)malloc(sizeof(char) * 2);
	if (!delim)
		return (NULL);
	delim[0] = c;
	delim[1] = '\0';
	result = (char **)malloc(sizeof(char *) * (numwords(s, delim) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, delim))
	{
		free(result);
		return (NULL);
	}
	free(delim);
	return (result);
}

int	main(int ac, char **av)
{
	int		i;
	char	**result;

	result = ft_matsplit(av + 1, ' ');
	if (result)
	{
		i = 0;
		while (result[i] != NULL)
		{
			printf("Palavra %d: %s\n", i, result[i]);
			free(result[i]);
			i++;
		}
		printf("\033[31mSAIU\033[0m");
		free(result);
	}
	else
		printf("Erro ao dividir a string.\n");
	return (0);
}
