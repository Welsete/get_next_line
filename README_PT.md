*This project has been created as part of the 42 curriculum by wtavares.*

#  get_next_line

##  Descrição

O **get_next_line** é um projeto da 42 cujo objetivo é implementar uma função capaz de **ler um arquivo linha por linha**, a partir de um *file descriptor (fd)*.  
O desafio principal é lidar com leituras parciais e gerenciar corretamente a memória, garantindo que cada chamada da função retorne **exatamente uma linha**, mesmo quando o *buffer* usado é menor que o tamanho da linha.

### 🎯 Objetivos
- Ler de qualquer *file descriptor* até encontrar `\n` ou o fim do arquivo.  
- Retornar cada linha separadamente, incluindo o caractere `\n` quando presente.  
- Manter o conteúdo não lido em uma variável `static`, para ser usado na próxima chamada.  
- Funcionar corretamente com qualquer valor de `BUFFER_SIZE`.  

Esse projeto reforça o uso de leitura de arquivos, ponteiros e alocação dinâmica em C, preparando para trabalhos maiores que exigem manipulação segura de memória.

---

##  Instruções

###  Compilação obrigatória (conforme o subject)

De acordo com o *subject oficial*, a **compilação obrigatória** deve ser feita **somente com os arquivos do projeto**, sem incluir um `main.c` (https://github.com/Welsete/get_next_line).

Exemplo:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

Você pode alterar o valor de `BUFFER_SIZE` para testar diferentes tamanhos:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1 get_next_line.c get_next_line_utils.c
cc -Wall -Wextra -Werror -D BUFFER_SIZE=9999 get_next_line.c get_next_line_utils.c
```

---

###  Compilação opcional (para testes pessoais)

Caso deseje testar o projeto localmente, você pode adicionar um `main.c` (https://github.com/Welsete/get_next_line) e compilar com:
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl
```

Depois execute:
```bash
./gnl tests/test1.txt
```

Esse método é **opcional** e serve apenas para facilitar testes pessoais.  
Durante a avaliação da 42, **não use `main.c` nem gere executáveis** - apenas os arquivos obrigatórios devem ser compilados.

---

###  Makefile (uso opcional)

Um **Makefile bônus** foi incluído apenas para **facilitar os testes automáticos**.  
Ele **não faz parte da avaliação obrigatória**, mas ajuda a demonstrar o funcionamento com diferentes *buffers* e arquivos de teste.

Exemplo de uso:
```bash
make b42 empty      # BUFFER_SIZE = 42, arquivo tests/empty.txt
make b1 small       # BUFFER_SIZE = 1, arquivo tests/small.txt
make b1000 large    # BUFFER_SIZE = 1000, arquivo tests/large.txt
make b23921         # BUFFER_SIZE = 23921, arquivo tests/test1.txt
```

Comandos adicionais disponíveis:
```bash
make            # Compila a biblioteca get_next_line.a
make run        # Compila e executa o teste automaticamente
make clean      # Remove os arquivos objeto (.o)
make fclean     # Remove objetos e binários
make re         # Executa fclean e recompila do zero
```

⚠️ **Importante:**  
Durante a avaliação, o avaliador deve compilar **manualmente**, conforme indicado no subject.  
O Makefile serve apenas como ferramenta de apoio para demonstração e autoavaliação.

---

##  Estrutura de Testes

Arquivos de teste sugeridos (não obrigatórios pelo subject):

```
tests/
├── test1.txt
├── empty.txt
├── small.txt
├── large.txt
└── no_newline.txt
```

Esses arquivos permitem testar:
- Arquivo vazio (`empty.txt`)  
- Arquivo com várias linhas (`test1.txt`)  
- Linhas curtas (`small.txt`)  
- Linhas longas (`large.txt`)  
- Arquivo sem quebra de linha final (`no_newline.txt`)  

---

##  Explicação do Algoritmo

O funcionamento do `get_next_line` é dividido em quatro partes principais:

1. **`read_and_stash()`** - lê do *file descriptor* e acumula o conteúdo no *stash* até encontrar um `\n` ou o fim do arquivo.  
2. **`extract_line()`** - separa a próxima linha completa a ser retornada.  
3. **`create_line()`** - aloca dinamicamente a linha e copia o conteúdo correto.  
4. **`update_stash()`** - mantém o que sobrou após o `\n` para a próxima chamada.  

Essa estrutura garante:
- Compatibilidade com qualquer `BUFFER_SIZE`;  
- Leitura contínua e segura;  
- Nenhum vazamento de memória;  
- Comportamento previsível e estável em qualquer cenário.

---

##  Recursos

### Referências Oficiais
- [Funções da biblioteca C - read(), malloc(), free(), static variable] - DevDocs (https://devdocs.io/)
- [Subject oficial do get_next_line (42)] - Intra 42SP
- [XaveCoding - Curso: Dominando Estrutura de Dados 1] - Professor Samuka (https://www.youtube.com/@xavecoding)
- [Variável estática] - StackOverflow (https://pt.stackoverflow.com/questions/164808/vari%C3%A1vel-static-e-define )

---

##  Uso de Inteligência Artificial

Ferramentas de IA (**ChatGPT / ScholarGPT**) foram utilizadas **somente para:**
- Revisão estrutural e explicação do fluxo de memória;  
- Auxílio na criação de arquivos de teste e Makefile auxiliar;  
- Padronização e clareza deste README.  

Todo o código e a lógica foram escritos e testados manualmente por **wtavares**.
