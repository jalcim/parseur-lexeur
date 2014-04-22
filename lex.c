/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex.x                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 03:05:07 by jalcim            #+#    #+#             */
/*   Updated: 2014/04/22 05:39:28 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* [0][0][0][0] 4DM

M5 block //futur(1 block == 1 tache) //script //mutex
M4 thread
M3 sequance(id)
M2 instruction(chemin (ptr_fct **))
M1 ptr_fct(ptr_fct *)

(echo "yoo man" > file ; cat file)

M5 M4 M3 M2 M1
(echo "yoo man" > file)
[0][0][0] ([0][0]) == (init_arg, open, execve, redirfd)
[0][0][0][0][0] == init_arg("yoo man")
[0][0][0][0][1] == open(file)
[0][0][0][0][2] == exec(echo)
[0][0][0][0][3] == redirfd(0, file)
;
(cat file)
[0][0][1] ([1][0]) == (init_arg, exec)
[0][0][1][1][0] == init_arg(file)
[0][0][1][1][1] == exec(cat)
|
(ps au > file)
[0][1][0] ([0][0]) == (init_arg, Predirfd, exec, Rredirfd)
[0][1][0][0][0] == init_arg(au)
[0][1][0][0][1] == Predirfd()
[0][1][0][0][2] == exec(ps)
[0][1][0][0][3] == Rredirfd()
*/

void *lex(t_lex ***matrix)
{
	t_ord *ord;
	t_metod ****method;
	//t_generic *(****method)(t_generic *gen);
	int compt[3] = {-1, -1, -1};

	ord = save_ord(NULL);
	method = (t_method ****)malloc(1 * sizeof(t_method ***));//block
	method[0] = (t_method ***)malloc(ord->nb_thread * sizeof(t_method **));//thread
	while (++compt[0] <= ord->nb_thread)
		{
			method[0][compt[0]] = (t_method ***)malloc(ord->nb_sequance * sizeof(t_method **));//thread
			while (++compt[1] <= ord->nb_sequance)
			{
				method[0][compt[0]][compt[1]] = (t_method**)malloc(ord->nb_instr * sizeof(t_method *));
				while (++compt[2] <= ord->nb_instr)
					method[0][compt[0]][compt[1]][compt[2]] = init_fct(matrix[0][compt[1]][compt[2]]->instr);
			}
		}
}
