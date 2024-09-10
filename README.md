# Algoritmos de Ordenação em C

Este repositório contém implementações de **21 algoritmos de ordenação** em C. O objetivo é fornecer exemplos de vários métodos de ordenação, desde algoritmos simples como o Bubble Sort até os mais complexos, como Tim Sort e Bitonic Sort. O projeto pode ser utilizado tanto para fins educacionais quanto para testes práticos de desempenho de algoritmos.

## Algoritmos Incluídos

Aqui estão os algoritmos implementados com links para a documentação na Wikipedia, tanto em português quanto em inglês (quando disponíveis):

1. **Bubble Sort** [Português](https://pt.wikipedia.org/wiki/Bubble_sort) | [Inglês](https://en.wikipedia.org/wiki/Bubble_sort)
2. **Selection Sort** [Português](https://pt.wikipedia.org/wiki/Selection_sort) | [Inglês](https://en.wikipedia.org/wiki/Selection_sort)
3. **Insertion Sort** [Português](https://pt.wikipedia.org/wiki/Insertion_sort) | [Inglês](https://en.wikipedia.org/wiki/Insertion_sort)
4. **Merge Sort** [Português](https://pt.wikipedia.org/wiki/Merge_sort) | [Inglês](https://en.wikipedia.org/wiki/Merge_sort)
5. **Quick Sort** [Português](https://pt.wikipedia.org/wiki/Quicksort) | [Inglês](https://en.wikipedia.org/wiki/Quicksort)
6. **Heap Sort** [Português](https://pt.wikipedia.org/wiki/Heapsort) | [Inglês](https://en.wikipedia.org/wiki/Heapsort)
7. **Counting Sort** [Inglês](https://en.wikipedia.org/wiki/Counting_sort)
8. **Radix Sort** [Português](https://pt.wikipedia.org/wiki/Radix_sort) | [Inglês](https://en.wikipedia.org/wiki/Radix_sort)
9. **Bucket Sort** [Inglês](https://en.wikipedia.org/wiki/Bucket_sort)
10. **Shell Sort** [Português](https://pt.wikipedia.org/wiki/Shell_sort) | [Inglês](https://en.wikipedia.org/wiki/Shellsort)
11. **Tim Sort** [Inglês](https://en.wikipedia.org/wiki/Timsort)
12. **Comb Sort** [Inglês](https://en.wikipedia.org/wiki/Comb_sort)
13. **Pigeonhole Sort** [Inglês](https://en.wikipedia.org/wiki/Pigeonhole_sort)
14. **Cycle Sort** [Inglês](https://en.wikipedia.org/wiki/Cycle_sort)
15. **Bitonic Sort** [Inglês](https://en.wikipedia.org/wiki/Bitonic_sorter)
16. **Gnome Sort** [Inglês](https://en.wikipedia.org/wiki/Gnome_sort)
17. **Odd-Even Sort** [Inglês](https://en.wikipedia.org/wiki/Odd%E2%80%93even_sort)
18. **Strand Sort** [Inglês](https://en.wikipedia.org/wiki/Strand_sort)
19. **Patience Sort** [Inglês](https://en.wikipedia.org/wiki/Patience_sorting)
20. **Bogo Sort** [Inglês](https://en.wikipedia.org/wiki/Bogosort)
21. **Stooge Sort** [Inglês](https://en.wikipedia.org/wiki/Stooge_sort)

## Como Usar

### Pré-requisitos

1. **Compilador C**: GCC (ou MinGW no Windows).
2. **Visual Studio Code** (VSCode).
3. Extensões recomendadas para VSCode:
   - **C/C++ Extension Pack** (fornece suporte para C/C++).
   - **Code Runner** (opcional, facilita rodar o código).

### Clonando o Repositório

Clone este repositório em sua máquina local:

```bash
git clone https://github.com/seuusuario/sorting-algorithms-c.git
cd sorting-algorithms-c
```

### Compilar e Executar no VSCode

1. **Abrindo o projeto**: No VSCode, vá em **Arquivo > Abrir Pasta** e selecione a pasta do projeto.

2. **Compilar e rodar**: Abra o terminal integrado (Ctrl + `) e compile os arquivos:

   - Para o teste de desempenho em vários tamanhos de vetores:
     ```bash
     gcc timing_test.c sorting_algorithms.c -o timing_test
     ./timing_test
     ```

   - Para o menu interativo:
     ```bash
     gcc interactive_menu.c sorting_algorithms.c -o interactive_menu
     ./interactive_menu
     ```

### Descrição dos Arquivos

- **`sorting_algorithms.h`**: Contém as declarações de todos os algoritmos de ordenação.
- **`sorting_algorithms.c`**: Implementação dos 21 algoritmos de ordenação.
- **`timing_test.c`**: Executa cada algoritmo de ordenação com vetores de 10 tamanhos diferentes (10.000 a 100.000 elementos) e imprime o tempo de execução de cada um.
- **`interactive_menu.c`**: Fornece um menu interativo onde o usuário pode escolher o tamanho do vetor e o algoritmo de ordenação a ser executado.

### Utilizando no Windows com MinGW

Se estiver usando o Windows, certifique-se de ter o **MinGW** instalado e o caminho do GCC configurado nas variáveis de ambiente. Você pode seguir [este guia de instalação do MinGW](https://www.mingw-w64.org/downloads/).

### Exemplos de Uso

1. **Testar o tempo de execução** de todos os algoritmos em diferentes tamanhos de vetor:

   ```bash
   ./timing_test
   ```

2. **Executar o menu interativo** onde o usuário escolhe o tamanho do vetor e o algoritmo:

   ```bash
   ./interactive_menu
   ```

### Contribuições

Contribuições são bem-vindas! Sinta-se à vontade para abrir issues, sugerir melhorias ou adicionar novos algoritmos de ordenação.

### Licença

Este projeto está licenciado sob a licença MIT.
