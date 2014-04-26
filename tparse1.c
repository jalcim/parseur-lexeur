/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tparse1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 03:53:44 by jalcim            #+#    #+#             */
/*   Updated: 2014/04/26 15:21:16 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int compt_word(char *str);
t_word *init_word(char *script)
{
	t_word *word;
	int nb;
	int compt;
	int cpt_sequ;
	int cpt_thread;
	int tmp[2] = {0, 0};

	t_ord *ord;

	ord = save_ord(NULL);//RECUPERATION des infos d'ordenancements

	word = (t_word *)malloc(sizeof(t_word));
	word->word = (unsigned char ***)malloc(ord->nb_sequance * sizeof(unsigned char **));
	cpt_thread = -1;
	while (++cpt_thread <= ord->nb_thread)
	{
		cpt_sequ = -1;
		while (++cpt_sequ <= ord->nb_sequance[cpt_thread])
		{
			word->word[!!!] = (unsigned char **)malloc(nb * sizeof(unsigned char *));
			compt = -1;
			while(++compt <= ord->nb_instr && script[tmp[0]])//mettre chaque mot dans un char *
			{
				while ((script[tmp[0]] == ' ' || script[tmp[0]] == '\t') && script[tmp[0]])
					tmp[0]++;
				tmp[1] = tmp[0];
				while ((script[tmp[1]] != ' ' || script[tmp[1]] != '\t') && script[tmp[1]])
					tmp[1]++;
				if (tmp[1])
				{
					word->word[compt] = (unsigned char *)malloc(tmp[1] * sizeof(unsigned char));
					memcpy(&word->word[compt], tmp[0], tmp[1]);
				}
				tmp[0] = tmp[1];
				if (script[tmp[0]])
					tmp[0]++;
			}
		}
	}
	return (word);
}

int compt_word(char *str)
{
	int compt;
	int nb_word;
	int indic;

	indic = 0;
	nb_word = 0;
	compt = -1;
	while (str[++compt])
	{
		if (str[compt] == ' ' || str[compt] == '\t')//si on arrive sur un espace
		{
			if (indic)
				nb_word++;//si on etais sur un mot(un de plus)
			indic = 0;//sinon on est toujours pas sur un mot
		}
		else
			indic = 1;//si on est sur autre chose qu'un espace(un mot)
	}
	return (nb_word);
}

char *loc_word(char **script)
{
	char *instr;
	int compt;

	compt = 0;
	while ((*script)[compt] == ' ' || (*script)[compt] == '\t')
		compt++;
	strcpy((*script), &((*script)[compt]));

	if (flag(&(*script)[0]) >= 0)
	{
		instr = (char *)malloc(2);
		strncpy(instr, (*script), 2);
		return (instr);
	}

	compt = 0;
	while (flag(&(*script)[compt]) == -1 &&
		   (*script)[compt] != ' ' && (*script)[compt] != '\t')
		compt++;

	if (!compt)
		return (NULL);
	instr = (char *)malloc(compt);
	strncpy(instr, (*script), compt);
	return (instr);
}

int flag(char *c)
{
	static char **flag = NULL;
	int compt;

	if (flag = NULL)
		flag = init_flag();
	compt = -1;
	while (++compt < 5)
		if (!memcmp(c, flag[compt], 2))
			return (compt);
	return (-1);
}
