/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtavares <wtavares@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:15:25 by wtavares          #+#    #+#             */
/*   Updated: 2025/12/21 11:15:44 by wtavares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

/*
 * main.c — Teste genérico para o get_next_line
 * Uso:
 *   ./gnl_test <arquivo>
 * Exemplo:
 *   ./gnl_test tests/test1.txt
 *
 * Este main é compatível com o Makefile dinâmico.
 * Exemplo de uso:
 *   make b42 small
 *   make b1 empty
 *   make b1000 large
 *   make b23921
 */

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		line_count;

	if (argc != 2)
	{
		printf("❌ Uso: ./gnl_test <arquivo>\n");
		return (1);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Erro ao abrir o arquivo");
		return (1);
	}

	printf("📂 Lendo arquivo: %s\n", argv[1]);
	printf("📏 BUFFER_SIZE = %d\n\n", BUFFER_SIZE);

	line_count = 0;
	while ((line = get_next_line(fd)))
	{
		printf("🟩 Linha %d: %s", ++line_count, line);
		free(line);
	}

	if (line_count == 0)
		printf("⚠️  Nenhuma linha lida (arquivo vazio ou erro).\n");

	close(fd);
	printf("\n✅ Leitura finalizada. Linhas lidas: %d\n", line_count);
	return (0);
}
