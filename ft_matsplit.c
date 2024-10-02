/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:26:39 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/02 09:44:46 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <string.h>

static int	numwords(char **s, char c)
{
	printf("\n\033[31m numwords \033[0m\n");
	int	i;
	int	word_num;
	char	*token;
	char	*copy;

	i = 0;
	word_num = 0;
	while (s[i])
	{
		copy = ft_strdup(s[i]);
		token = ft_strtok(copy, &c);
		while (token)
		{
			word_num++;
			printf("\n\033[32m token %d : %s \033[0m\n", i, token);
			token = ft_strtok(NULL, &c);
		}
		free(copy);
		i++;
		//printf("\n\033[32m sai de i %d : %s \033[0m\n", i, token);
	}
	printf("\n\033[32m wordnum %d \033[0m\n", word_num);
	return (word_num);
}

static int	split_words(char **result, char **s, char c)
{
	printf("\n\033[31m split_words \033[0m\n");
	int	i;
	int	word;
	char	*token;
	char	*copy;

	word = 0;
	i = 0;
	while (s[i])
	{
		copy = ft_strdup(s[i]);
		token = ft_strtok(copy, &c);
		while (token)
		{
			result[word] = malloc(ft_strlen(token) + 1);
			if (!result[word])
			{
				/*while (word > 0)
					free(result[--word]);*/
				return (0);
			}
			ft_strlcpy(result[word], token, (ft_strlen(token) + 1));
			printf("\033[31mAlocado: %s\n\033[0m", result[word]);
			word++;
			token = ft_strtok(NULL, &c);
			printf("\033[36mTOKEN: %s\n\033[0m", token);
		}
		free(copy);
		i++;
	}
	printf("\033[35m\nSAÍ DE SPLIT WORDS\n\033[0m");
	result[word] = NULL;
	return (1);
}

char	**ft_matsplit(char **s, char c)
{
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (numwords(s, c) + 1));
	if (!result)
		return (NULL);
	if (!split_words(result, s, c))
	{
		free(result);
		return (NULL);
	}
	return (result);
}

// Exemplo de uso
int main(int ac, char **av) {
    /*if (ac < 4) {
        printf("Uso: ./main 1 2 \"3 4 6\" 7\n");
        return 1;
    }*/

    char **result = ft_matsplit(av+1, ' '); // Passa a partir de av[3]

    if (result) {
        int i = 0;
        while (result[i] != NULL) {
            printf("Palavra %d: %s\n", i, result[i]);
            //free(result[i]);  Liberar cada palavra após uso
            i++;
        }printf("\033[31mSAIU\033[0m");
        free(result); // Liberar a matriz de ponteiros
    } else {
        printf("Erro ao dividir a string.\n");
    }

    return 0;
}
