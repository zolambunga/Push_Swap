/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zombunga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 20:11:23 by zombunga          #+#    #+#             */
/*   Updated: 2024/09/27 14:47:33 by zombunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../libft/libft.h"

int	is_sorted(char **av)
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
				return (0);
			j++;
		}
		i++;
	}
	exit(0);
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

char	**ft_verify_args(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 0;
	j = 0;
	if (ft_isnvalid(av))
		ft_error();
	printf("antes do único!\n");
	if ((ac == 1) || (ac == 2 && !ft_strchr(av[0], ' ')) || (ac == 2 && av[0] == ""))
	{
		printf("ao sair de (ac == 1) || (ac == 2 && !ft_strchr(av[0], ' ')) || (ac == 2 && av[0] == '')\n");
		exit(1);
	}
	else if (ac == 2)
		av = ft_split(av[0], ' ');
	/*if (ac == 1 || (ac == 2 && ft_strchr(av[0], ' ')) || (ac == 2 && av[0] != ""))
	{
		printf("ao sair av[0]=|%s|", av[0]);
		exit(1);
	}*/
	check_duplicates(av, 0, 0);
	while(av[i])
	{
		j = 0;
		while (av[i][j])
		{
			printf("depois do único =>> |%c|\n", av[i][j]);
			j++;
		}
		i++;
	}
	return (av);
}
