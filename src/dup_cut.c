/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: border <border@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 09:54:48 by border            #+#    #+#             */
/*   Updated: 2021/08/12 09:54:49 by border           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_cmd(int cmd_key, t_stacks *s)
{
	if (cmd_key == 1)
		ft_sa(s->a);
	else if (cmd_key == 2)
		ft_sb(s->b);
	else if (cmd_key == 3)
		ft_ss(s);
	else if (cmd_key == 4)
		ft_pa(s);
	else if (cmd_key == 5)
		ft_pb(s);
	else if (cmd_key == 6)
		ft_ra(&s->a);
	else if (cmd_key == 7)
		ft_rb(&s->b);
	else if (cmd_key == 8)
		ft_rr(s);
	else if (cmd_key == 9)
		ft_rra(&s->a);
	else if (cmd_key == 10)
		ft_rrb(&s->b);
	else if (cmd_key == 11)
		ft_rrr(s);
}

void	ft_putcmd(int cmd_key)
{
	if (cmd_key == 1)
		write(1, "sa\n", 3);
	else if (cmd_key == 2)
		write(1, "sb\n", 3);
	else if (cmd_key == 3)
		write(1, "ss\n", 3);
	else if (cmd_key == 4)
		write(1, "pa\n", 3);
	else if (cmd_key == 5)
		write(1, "pb\n", 3);
	else if (cmd_key == 6)
		write(1, "ra\n", 3);
	else if (cmd_key == 7)
		write(1, "rb\n", 3);
	else if (cmd_key == 8)
		write(1, "rr\n", 3);
	else if (cmd_key == 9)
		write(1, "rra\n", 4);
	else if (cmd_key == 10)
		write(1, "rrb\n", 4);
	else if (cmd_key == 11)
		write(1, "rrr\n", 4);
}

void	ft_dup_cut(int *cmd1, int cmd2)
{
	if ((*cmd1 == SA && cmd2 == SB) || (*cmd1 == SB && cmd2 == SA))
		*cmd1 = SS;
	else if ((*cmd1 == PA && cmd2 == PB) || (*cmd1 == PB && cmd2 == PA))
		*cmd1 = 0;
	else if ((*cmd1 == RA && cmd2 == RB) || (*cmd1 == RB && cmd2 == RA))
		*cmd1 = RR;
	else if ((*cmd1 == RRA && cmd2 == RRB) || (*cmd1 == RRB && cmd2 == RRA))
		*cmd1 = RRR;
	else
	{
		ft_putcmd(*cmd1);
		*cmd1 = cmd2;
	}
}

void	cmd_add(int cmd_key, t_stacks *s)
{
	if (cmd_key != 0)
	{
		ft_cmd(cmd_key, s);
		if (s->cmd == 0)
			s->cmd = cmd_key;
		else
			ft_dup_cut(&s->cmd, cmd_key);
	}
	else
		ft_putcmd(s->cmd);
}
