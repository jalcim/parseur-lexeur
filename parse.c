/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 23:32:51 by jalcim            #+#    #+#             */
/*   Updated: 2014/04/22 01:34:00 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_parse t_parse;
typedef struct s_lex t_lex;

/*
[0][0][0][0] 4D

D4 ordenenceur //execution paralle, sequentielle, conditionnel ( '|', ';', "&&", "|| ) suivant flag
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
[1] ([0][0][0]) = ps au	> file
[1][0][0] ([0]) == ps
[1][0][1] ([0]) == au
[1][1][0] ([0]) == >
[1][2][0] ([0]) == file
*/

/*
M2 sequance(id)
M1 instruction(chemin (ptr_fct **))
ptr_fct(ptr_fct *)

(echo "yoo man" > file ; cat file)
M2 M1
(echo "yoo man" > file)
([0][0]) == (init_arg, open, execve, redirfd)
[0][0] == init_arg("yoo man")
[0][1] == open(file)
[0][2] == exec(echo)
[0][3] == redirfd(0, file)

(cat file)
([1][0]) == (init_arg, exec)
[1][0] == init_arg(file)
[1][1] == exec(cat)

(ps au > file)
([0][0]) == (init_arg, Predirfd, exec, Rredirfd)
[0][0] == init_arg(au)
[0][1] == Predirfd()
[0][2] == exec(ps)
[0][3] == Rredirfd()
*/

/* (>)

[Predirfd]
fd = open(file)
dup2(1, pipe[1]);
[Predirfd]

exec

[Rredirfd]
read(pipe[0], char *)
write(fd , char *);
[Rredirfd]
*/

struct s_parse
{
	t_lex ****matrix;

	void (***methode)(void *);
};

struct s_lex
{
	char flag;

	char *cmd;
};

int main()
{
	parse("echo \"yoo\" > file ; cat file | ps au > file");
}
