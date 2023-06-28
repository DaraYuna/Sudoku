#include <stdio.h>
#include <stdlib.h>

#define reset "\e[0m\n"
#define yellow "\e[1;93m"
#define white "\e[4;37m"
#define green "\e[42m"
#define green2 "\e[1;92m"
#define red "\e[1;31m"
#define pink "\e[4;35m"


int opcao = -1;

int main() {
  while (1) {
    system("clear");
   printf("                                                                \n");
printf(""yellow""
  "     _______. __    __   _______    ______    __  ___  __    __  \n");
printf("    /       ||  |  |  | |       \\  /  __  \\  |  |/  / |  |  |  | \n");
printf("   |   (----`|  |  |  | |  .--.  ||  |  |  | |  '  /  |  |  |  | \n");
printf("    \\   \\    |  |  |  | |  |  |  ||  |  |  | |    <   |  |  |  | \n");
printf(".----)   |   |  `--'  | |  '--'  ||  `--'  | |  .  \\  |  `--'  | \n");
printf("|_______/     \\______/  |_______/  \\______/  |__|\\__\\  \\______/  "
  ""reset"\n");
    printf("                                                               \n");
    printf(""pink"  ✿ すどく✿   Seja Bem vindo ao Jogo! se divirta!  ✿ すどく✿  "reset"\n");
    printf("                                                               \n");
    printf("                        1 - Jogar 9X9                            \n");
    printf("                        2 - Jogar 4X4                            \n");
    printf("                        3 - Como jogar                           \n");
    printf("                        4 - Créditos                             \n");
    printf("                        0 - Sair                                 \n");
    printf("                                                               \n");
    printf("                     Entre com uma opção: ");
    scanf("%d", &opcao);
    getchar();

    switch (opcao) {
    case 0: {
      printf(""red"Saindo..."reset"\n");
      exit(0);
    }
    case 1: {
      int tabuleiro[9][9] = {
          {5, 3, 0, 0, 7, 0, 0, 0, 0}, {6, 0, 0, 1, 9, 5, 0, 0, 0},
          {0, 9, 8, 0, 0, 0, 0, 6, 0}, {8, 0, 0, 0, 6, 0, 0, 0, 3},
          {4, 0, 0, 8, 0, 3, 0, 0, 1}, {7, 0, 0, 0, 2, 0, 0, 0, 6},
          {0, 6, 0, 0, 0, 0, 2, 8, 0}, {0, 0, 0, 4, 1, 9, 0, 0, 5},
          {0, 0, 0, 0, 8, 0, 0, 7, 9}};

      while (1) {
        // Verificar se o jogador deseja desistir
        printf(""green2"Deseja desistir? (0 - Sim, 1 - Não): "reset"");
        int opcaoDesistir;
        scanf("%d", &opcaoDesistir);

        if (opcaoDesistir == 0) {
          break; // Sair do loop interno e voltar para o menu principal
        }
        // Imprimindo o tabuleiro original 9X9
        printf("Tabuleiro original:"yellow"\n");
        printf("-------------------------\n");
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
            if (j % 3 == 0)
              printf("| ");
            printf("%d ", tabuleiro[i][j]);
          }
          printf("|\n");
          if ((i + 1) % 3 == 0)
            printf("-------------------------\n");
        }

        // Preencher os espaços vazios
        printf(""reset"Preencha os espaços vazios:\n");
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
            if (tabuleiro[i][j] == 0) {
              int valor;
              do {
                printf("Digite o valor para o espaço (%d, %d): ", i + 1, j + 1);
                scanf("%d", &valor);
                if (valor < 1 || valor > 9) {
                  printf(""red"Valor inválido!"reset" Digite um número entre 1 e 9.\n");
                }
              } while (valor < 1 || valor > 9);
              tabuleiro[i][j] = valor;
            }
          }
        }

        // Verificar tabuleiro preenchido corretamente
        int tabuleiroCorreto = 1;

        // Verificar linhas e colunas
        for (int i = 0; i < 9; i++) {
          int numerosUtilizadosLinhas[10] = {0};
          int numerosUtilizadosColunas[10] = {0};
          for (int j = 0; j < 9; j++) {
            int valorLinha = tabuleiro[i][j];
            int valorColuna = tabuleiro[j][i];

            if (valorLinha != 0) {
              if (numerosUtilizadosLinhas[valorLinha] == 1) {
                tabuleiroCorreto = 0; // Valor repetido na linha
                break;
              }
              numerosUtilizadosLinhas[valorLinha] = 1;
            }

            if (valorColuna != 0) {
              if (numerosUtilizadosColunas[valorColuna] == 1) {
                tabuleiroCorreto = 0; // Valor repetido na coluna
                break;
              }
              numerosUtilizadosColunas[valorColuna] = 1;
            }
          }
          if (tabuleiroCorreto == 0) {
            break;
          }
        }

        // Verificar subgrades 3x3
        if (tabuleiroCorreto == 1) {
          for (int subgrade = 0; subgrade < 9; subgrade++) {
            int numerosUtilizados[10] = {0};
            int linhaInicio = (subgrade / 3) * 3;
            int colunaInicio = (subgrade % 3) * 3;
            for (int i = linhaInicio; i < linhaInicio + 3; i++) {
              for (int j = colunaInicio; j < colunaInicio + 3; j++) {
                int valor = tabuleiro[i][j];
                if (valor != 0) {
                  if (numerosUtilizados[valor] == 1) {
                    tabuleiroCorreto = 0; // Valor repetido na subgrade 3x3
                    break;
                  }
                  numerosUtilizados[valor] = 1;
                }
              }
              if (tabuleiroCorreto == 0) {
                break;
              }
            }
            if (tabuleiroCorreto == 0) {
              break;
            }
          }
        }

        // Imprimir resultado da verificação
        printf("Tabuleiro preenchido %s:"yellow"\n",
               tabuleiroCorreto ? "corretamente" : "incorretamente");
        printf("-------------------------\n");
        for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
            if (j % 3 == 0)
              printf("| ");
            printf("%d ", tabuleiro[i][j]);
          }
          printf("|\n");
          if ((i + 1) % 3 == 0)
            printf("-------------------------\n");
        }

        // Reiniciar tabuleiro se estiver incorreto
        if (tabuleiroCorreto == 0) {
          printf(""reset"\n");
          printf(""red"Tabuleiro incorreto. Reiniciando..."reset"\n");
          for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
              tabuleiro[i][j] = 0;
            }
          }
        }
        if (tabuleiroCorreto) {
          printf(""green2"Ganhou!"reset"\n");
        } else {
          printf(""green2"Tabuleiro reiniciou..."red"\n");
        }
      }
      break;
    }
    case 2: {
      int tabuleiro[4][4] = {
          {4, 0, 2, 0}, {0, 0, 0, 0}, {0, 3, 0, 0}, {0, 0, 0, 1}};

      while (1) {
        // Verificar se o jogador deseja desistir
        printf(""green2"Deseja desistir? (0 - Sim, 1 - Não): "reset"");
        int opcaoDesistir;
        scanf("%d", &opcaoDesistir);

        if (opcaoDesistir == 0) {
          break; // Sair do loop interno e voltar para o menu principal
        }
        // Imprimindo o tabuleiro original 4X4
        printf("Tabuleiro original:"yellow"\n");
        printf("-------------\n");
        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
            if (j % 2 == 0)
              printf("| ");
            printf("%d ", tabuleiro[i][j]);
          }
          printf("|\n");
          if ((i + 1) % 2 == 0)
            printf("-------------\n");
        }

        // Preencher os espaços vazios
        printf(""reset"Preencha os espaços vazios:\n");
        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
            if (tabuleiro[i][j] == 0) {
              int valor;
              do {
                printf("Digite o valor para o espaço (%d, %d): ", i + 1, j + 1);
                scanf("%d", &valor);
                if (valor < 1 || valor > 4) {
                  printf(""red"Valor inválido!"reset" Digite um número entre 1 e 4.\n");
                }
              } while (valor < 1 || valor > 4);
              tabuleiro[i][j] = valor;
            }
          }
        }

        // Verificar tabuleiro preenchido corretamente
        int tabuleiroCorreto = 1;

        // Verificar linhas e colunas
        for (int i = 0; i < 4; i++) {
          int numerosUtilizadosLinhas[5] = {0};
          int numerosUtilizadosColunas[5] = {0};
          for (int j = 0; j < 4; j++) {
            int valorLinha = tabuleiro[i][j];
            int valorColuna = tabuleiro[j][i];

            if (valorLinha != 0) {
              if (numerosUtilizadosLinhas[valorLinha] == 1) {
                tabuleiroCorreto = 0; // Valor repetido na linha
                break;
              }
              numerosUtilizadosLinhas[valorLinha] = 1;
            }

            if (valorColuna != 0) {
              if (numerosUtilizadosColunas[valorColuna] == 1) {
                tabuleiroCorreto = 0; // Valor repetido na coluna
                break;
              }
              numerosUtilizadosColunas[valorColuna] = 1;
            }
          }
          if (tabuleiroCorreto == 0) {
            break;
          }
        }

        // Imprimir resultado da verificação
        printf("Tabuleiro preenchido %s:"yellow"\n",
               tabuleiroCorreto ? "corretamente" : "incorretamente");
        printf("-------------\n");
        for (int i = 0; i < 4; i++) {
          for (int j = 0; j < 4; j++) {
            if (j % 2 == 0)
              printf("| ");
            printf("%d ", tabuleiro[i][j]);
          }
          printf("|\n");
          if ((i + 1) % 2 == 0)
            printf("-------------\n");
        }

        // Reiniciar tabuleiro se estiver incorreto
        if (tabuleiroCorreto == 0) {
          printf(""reset"\n");
          printf(""red"Tabuleiro incorreto. Reiniciando..."reset"\n");
          for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
              tabuleiro[i][j] = 0;
            }
          }
        }
        if (tabuleiroCorreto) {
          printf(""green2"Ganhou!"reset"\n");
        } else {
          printf(""green2"Tabuleiro reiniciou..."reset"\n");
          // Resto do código para reiniciar o tabuleiro
        }
      }

      break;
    }
    case 3: { // Explicando como funciona e as regras do jogo
      system("clear");
      printf("" yellow "COMO JOGAR E REGRAS:         "reset "\n");
      printf("✿ O sudoku é um jogo de raciocínio e lógica. \n");
      printf("✿ O objetivo do jogo é completar todos os quadrados utilizando "
             "números de 1 a 9 ou de 1 a 4.\n");
       printf("                                                               \n");
      printf("" yellow
             "Para completá-los basta seguir as seguintes REGRAS:" reset
             "\n");
      printf(" 1 ▶ Alguns números iniciais são fornecidos e você deve preencher "
             "os espaços vazios com números de 1 a 9.\n");
      printf(" 2 ▶ Cada número só pode aparecer uma vez em cada linha, coluna e "
             "subgrade 3x3.\n");
      printf(" 3 ▶ O jogo está completo quando todas as células estiverem "
             "preenchidas corretamente."
             "\n");
      printf("                                                               \n");
      printf("" white " Pressione " green2 "ZERO" reset
             "" white " para Voltar" reset "\n");
      scanf("%d", &opcao);
      getchar();
      break;
    }
    case 4: { // Informações sobre o desenvolvedor
      system("clear");
      printf("" yellow "✿ Desenvolvido por: Dara Yuna   \n");
      printf("                                                               \n");
      printf("✿ Github: DaraYuna        \n");
      printf("                                                               \n");
      printf("✿ Instrutor: Jose Reginaldo  \n");
      printf("                                                               \n");
      printf("✿ Lingaguem de programação: C  \n");
      printf("                                                               \n");
      printf("✿ Versão: 1.0" reset"\n");
      printf("                                                               \n");
      printf("" white " Pressione " green2 "ZERO" reset
             "" white " para Voltar"reset "\n");
      scanf("%d", &opcao);
      getchar();
      break;
    }
    default: {
      printf("Opção inválida.\n");
      printf("" white " Pressione " green2 "ENTER" reset
             "" white " para Voltar" reset "\n");
      getchar();
      break;
    }
    }
  }
  return 0;
}
