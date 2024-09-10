# Algoritmos de Ordenação em C

Este repositório contém implementações de **21 algoritmos de ordenação** em C. O objetivo é fornecer exemplos de vários métodos de ordenação, desde algoritmos simples como o Bubble Sort até os mais complexos, como Tim Sort e Bitonic Sort. O projeto pode ser utilizado tanto para fins educacionais quanto para testes práticos de desempenho de algoritmos.

## Algoritmos Incluídos

- Bubble Sort
- Selection Sort
- Insertion Sort
- Merge Sort
- Quick Sort
- Heap Sort
- Counting Sort
- Radix Sort
- Bucket Sort
- Shell Sort
- Tim Sort
- Comb Sort
- Pigeonhole Sort
- Cycle Sort
- Bitonic Sort
- Gnome Sort
- Odd-Even Sort
- Strand Sort
- Patience Sort
- Bogo Sort
- Stooge Sort

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
