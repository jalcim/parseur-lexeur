/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpret.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 03:52:03 by jalcim            #+#    #+#             */
/*   Updated: 2014/04/22 05:34:34 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_parse t_parse;
typedef struct s_lex t_lex;
typedef struct s_info t_info;
typedef struct s_flag t_flag;
typedef struct s_ord t_ord;
typedef struct s_word t_word;
typedef struct s_generic t_generic;
typedef t_generic *(t_metod)(t_generic *);

struct s_parse
{
	t_lex ***matrix;

	t_method ****method;
//	t_generic *(****method)(t_generic *gen);
};

struct s_lex
{
	t_info *info;

	char **instr;
};

struct s_info	//info ordenancement (par commande)
{
	char flag[2]; //("|\0", ";\0", "&&", "||", "&|")
};

struct s_flag t_flag;
{
	int nb_cmd;
	int nb_instr;
}

struct s_ord
{
	int nb_block;
	int nb_thread;
	int nb_sequance;
	int nb_instr;
};

struct s_word
{
	char ***word;
}

struct s_generic
{
	void **param;
};
