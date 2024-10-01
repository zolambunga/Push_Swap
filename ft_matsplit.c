/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <zombunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:26:39 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/01 08:26:03 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

static int	numwords(char **s, char c)
{
	int	i;
	int	cur;
	int	word_num;

	i = 0;
	word_num = 0;
	while (s[i])
	{
		cur = 0;
		while (s[i][cur] != 0)
		{
			if (s[i][cur] != c && (s[i][cur + 1] == c || s[i][cur + 1] == 0))
				word_num++;
			cur++;
		}
		i++;
	}
	return (word_num);
}

static int	split_words(char **result, char **s, char c, int word)
{
	int	i;
	int	start_cur;
	int	end_cur;

	i = 0;
	start_cur = 0;
	while (s[i])
	{
		end_cur = 0;
		while (s[i][end_cur])
		{
			if (s[i][end_cur] == c || s[i][end_cur] == 0)
				start_cur = end_cur + 1;
			if (s[i][end_cur] != c && (s[i][end_cur + 1] == c || s[i][end_cur + 1] == 0))
			{
				result[word] = malloc(sizeof(char) * (end_cur - start_cur + 2));
				if (!result[word])
				{
					while (word++)
						free(result[word]);
					return (0);
				}
				ft_strlcpy(result[word], (s[i] + start_cur), end_cur - start_cur + 2);
				word++;
			}
			end_cur++;
		}
		i++;
	}
	result[word] = 0;
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
	if (!split_words(result, s, c, 0))
		return (NULL);
	return (result);
}

int main(int ac, char **av) {
    // Matriz de strings para teste
    char **result = ft_matsplit(av, ' ');

    if (result) {
        // Imprimir resultados
        for (int i = 0; result[i] != NULL; i++) {
            printf("Palavra %d: %s\n", i + 1, result[i]);
            free(result[i]); // Liberar memória de cada palavra
        }
        free(result); // Liberar memória da matriz de resultado
    } else {
        printf("Erro ao dividir a matriz de strings.\n");
    }
    return 0;
}
