/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 23:32:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/04/22 05:53:15 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* [0][0][0][0] 4D

D5 = *parse
D4 = **lex
D3 = *lex->**char
D2 = *char
D1 = char

D5 block //futur
D4 ordenenceur //execution paralle, sequentielle, conditionnel sequentiel, conditionnel parallele( "|", ";", "&&", "||", "&|" ) suivant flag
D3 commande
D2 instruction
D1 unsigned char

D4 D3 D2 D1
[0] ([0][0][0]) = echo "yoo man" > file
[0][0][0] ([0]) == echo
[0][0][1] ([0]) == yoo man
[0][0][2] ([0]) == >
[0][0][3] ([0]) == file
;
[0][1] ([0][0]) = cat file
[0][1][0] ([0]) == cat
[0][1][1] ([0]) == file
|
[1] ([0][0][0]) == ps au	> file
[1][0][0] ([0]) == ps
[1][0][1] ([0]) == au
[1][1][0] ([0]) == >
[1][2][0] ([0]) == file
*/

#include "interpret.h"

t_lex ***parse(char *script)
{
	t_lex ***matrix;
	t_flag *flag;
	t_word *word;
	int compt[2] = {-1, -1};

	flag = loc_flag();

	word = init_word(&script);
	matrix = (t_lex ***)malloc(sizeof(t_lex **));//block
	matrix[0] = (t_lex **)malloc(flag->nb_cmd * sizeof(t_lex *));//cmd
	while (++compt[0] <= flag->nb_cmd)
	{
		matrix[0][compt[0]] = (t_lex *)malloc(flag->nb_instr * sizeof(t_lex));//instr
		matrix[0][compt[0]][compt[1]]->instr = word->word[compt[0]];
	}
	return (matrix);
}

int interpret(char *script)
{
	t_parse *program;

	program->matrix = parse(script);
	program->methode = lex(program->matrix);
	ordenenceur(program);
}

int main()
{
	interpret("echo \"yoo\" > file ; cat file | ps au > file");
}

char **init_flag()
{
	char **flag;
	int compt;

	compt = -1;
	flag = (char **)malloc(6 * sizeof(char *));
	while (++compt < 5)
		flag[compt] = (char *)malloc(2);
	strncpy(flag[0], "|", 1);
	strncpy(flag[1], ";", 1);
	strncpy(flag[2], "&&", 2);
	strncpy(flag[3], "||", 2);
	strncpy(flag[4], "&|", 2);
	flag[6] = NULL;
	return (flag);
}
