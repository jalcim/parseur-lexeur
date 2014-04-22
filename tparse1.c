/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tparse1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 03:53:44 by jalcim            #+#    #+#             */
/*   Updated: 2014/04/22 04:03:02 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
