/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:26:39 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/02 15:56:20 by zombunga         ###   ########.fr       */
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

static int	allocate_words(char **result, char *token, char *copy, int word)
{
	result[word] = (char *)malloc(ft_strlen(token) + 1);
	if (!result[word])
	{
		while (word > 0)
			free(result[--word]);
		free(copy);
		return (0);
	}
	ft_strlcpy(result[word], token, ft_strlen(token) + 1);
	return (1);
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
			if (!allocate_words(result, token, copy, word))
				return (0);
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
	char	delim[2];

	if (!s)
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
	return (result);
}

/*
int	main(int ac, char **av)
{
	int		i;
	char	**result;

	if (ac == 1)
	{
		printf("\033[31;1mERROR\n\033[35mExemplo de uso:");
		printf("\033[32m./a.out 1 \"2 3 4\" 5 6\n\033[0m");
		return (1);
	}
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
}*/
