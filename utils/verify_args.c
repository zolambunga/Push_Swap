/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:23 by zombunga          #+#    #+#             */
/*   Updated: 2024/10/02 16:23:53 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	is_not_sorted(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) > ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	ft_free(av, NULL);
	exit(0);
}

static int	ft_check_mat(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (ft_strlen(av[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnvalid(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= 58) || (av[i][j] <= 31) || av[i][j] == 33
					|| av[i][j] == 44 || av[i][j] == 46 || av[i][j] == 47)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	check_duplicates(char **av, int i, int j)
{
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
			{	
				printf("YOU DUPLICATED NUMBERS!");
				ft_error();
			}j++;
		}
		i++;
	}
}

void	**ft_verify_args(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_isnvalid(av))
		ft_error();
	printf("antes do único!\n");
	if ((ac == 1) || (ac == 2 && !ft_strchr(av[0], ' ')) || (ac >= 2 && ft_check_mat(av) == 1))
	{
		printf("ao sair de (ac == 1) || (ac == 2 && !ft_strchr(av[0], ' ')) || (ac == 2 && av[0] == '')\n");
		exit(1);
	}
	check_duplicates(av, 0, 0);
	while(av[i])
	{
		printf("depois do único =>> |%s|\n", av[i]);
		i++;
	}
}
