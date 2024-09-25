#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <cstdlib>
#endif

using namespace std;

const int b_size = 15;
int navios[5] = {2, 2, 3, 3, 4};

void inicializaTabuleiro(char tabuleiro[b_size][b_size]) {
  for (int i = 0; i < b_size; i++) {
    for (int j = 0; j < b_size; j++) {
      tabuleiro[i][j] = '0';
    }
  }
}

void imprimeTabuleiro(const char tabuleiro[b_size][b_size],
                      bool revelarNavios = false) {
  cout << endl;
  cout << "    ";
  for (int i = 1; i <= b_size; i++) {
    cout << setw(3) << i;
  }
  cout << endl;
  for (int i = 0; i < b_size; i++) {
    cout << " " << (char)('A' + i) << " |";
    for (int j = 0; j < b_size; j++) {
      if (!revelarNavios && tabuleiro[i][j] == 'N') {
        cout << setw(3) << '0';
      } else {
        cout << setw(3) << tabuleiro[i][j];
      }
    }
    cout << endl;
  }
}

bool podePosicionarNavioManual(const char tabuleiro[b_size][b_size], int linha,
                               int coluna) {
  return tabuleiro[linha][coluna] == '0';
}

bool posicaoEhAdjacente(int linhaAnterior, int colunaAnterior, int linhaAtual,
                        int colunaAtual) {
  return (abs(linhaAnterior - linhaAtual) <= 1 &&
          abs(colunaAnterior - colunaAtual) <= 1);
}

void posicionarNavioManual(char tabuleiro[b_size][b_size], int tamanho,
                           const string &jogador) {
  char linhaChar;
  int x, y;
  bool posicionado = false;

  vector<pair<int, int>> partesNavio;

  for (int i = 0; i < tamanho; i++) {
    while (!posicionado) {
      cout << endl
           << jogador << ", posicione a parte " << i + 1
           << " do navio de tamanho " << tamanho << " (linha coluna): ";
      cin >> linhaChar >> y;

      linhaChar = toupper(linhaChar);

      if (cin.fail()) {
        cout << "Entrada inválida. Tente novamente." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
      }

      x = linhaChar - 'A';
      y -= 1;

      if (x >= 0 && x < b_size && y >= 0 && y < b_size &&
          podePosicionarNavioManual(tabuleiro, x, y)) {
        if (i == 0 || posicaoEhAdjacente(partesNavio.back().first,
                                         partesNavio.back().second, x, y)) {
          tabuleiro[x][y] = 'N';
          partesNavio.push_back(make_pair(x, y));
          posicionado = true;
        } else {
          cout << "Posição inválida. Tente novamente." << endl;
        }
      } else {
        cout << "Posição inválida ou já ocupada. Tente novamente." << endl;
      }
    }
    posicionado = false;
  }
}

bool atirar(char tabuleiro[b_size][b_size], int linha, int coluna) {
  if (tabuleiro[linha][coluna] == 'N') {
    tabuleiro[linha][coluna] = 'X';
    return true;
  } else if (tabuleiro[linha][coluna] == '0') {
    tabuleiro[linha][coluna] = 'M';
  }
  return false;
}

int contarPartesNaviosRestantes(const char tabuleiro[b_size][b_size]) {
  int partesRestantes = 0;
  for (int i = 0; i < b_size; i++) {
    for (int j = 0; j < b_size; j++) {
      if (tabuleiro[i][j] == 'N') {
        partesRestantes++;
      }
    }
  }
  return partesRestantes;
}

void limparTela() {
#ifdef _WIN32
  (void)system("cls");
#else
  (void)system("clear");
#endif
}

int main() {
  int escolhajogo;
  bool executando = true;

  while (executando) {
    cout << "================" << endl;
    cout << "Escolha o jogo: " << endl;
    cout << "1. Batalha naval" << endl;
    cout << "2. Jogo 2" << endl;
    cout << "3. Sair" << endl;
    cout << "================" << endl;

    while (true) {
      cout << "Digite sua escolha: ";
      cin >> escolhajogo;

      if (cin.fail() || escolhajogo < 1 || escolhajogo > 3) {
        cout << "Opção inválida! Tente novamente." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
      } else {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        break;
      }
    }

    switch (escolhajogo) {
    case 1: {
      cout << endl;
      cout << "* BATALHA NAVAL *" << endl;
      int escolhamodo;

      cout << "=======================" << endl;
      cout << "Escolha o modo de jogo: " << endl;
      cout << "1. PvP" << endl;
      cout << "2. PvBot" << endl;
      cout << "3. BotvBot" << endl;
      cout << "4. Sair" << endl;
      cout << "=====================" << endl;

      while (true) {
        cout << "Digite sua escolha: ";
        cin >> escolhamodo;

        if (cin.fail() || escolhamodo < 1 || escolhamodo > 4) {
          cout << "Opção inválida! Tente novamente." << endl;
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          break;
        }
      }

      switch (escolhamodo) {
      case 1: {
        cout << endl;
        cout << "* Escolheu PvP *\n" << endl;

        char tabuleiro1[b_size][b_size];
        char tabuleiro2[b_size][b_size];
        inicializaTabuleiro(tabuleiro1);
        inicializaTabuleiro(tabuleiro2);

        cout << "O jogo começou!!\n" << endl;

        cout << "Jogador 1, posicione seus navios:" << endl;
        imprimeTabuleiro(tabuleiro1, true);
        for (int i = 0; i < 5; i++) {
          posicionarNavioManual(tabuleiro1, navios[i], "Jogador 1");
          cout << endl << "Tabuleiro atual:" << endl;
          imprimeTabuleiro(tabuleiro1, true);
        }

        cout << "\nJogador 1 posicionou seus navios. Agora, as tabelas não são "
                "visíveis.\n";
        cout << "\n==========================================================";
        cout << "\nPressione Enter para o Jogador 2 posicionar seus navios..."
             << endl;
        cout << "==========================================================\n";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        limparTela();

        cout << "Jogador 2, posicione seus navios:" << endl;
        imprimeTabuleiro(tabuleiro2, true);
        for (int i = 0; i < 5; i++) {
          posicionarNavioManual(tabuleiro2, navios[i], "Jogador 2");
          cout << endl << "Tabuleiro atual:" << endl;
          imprimeTabuleiro(tabuleiro2, true);
        }
        cout << "Jogador 2 posicionou seus navios." << endl;

        limparTela();
        bool jogoAtivo = true;

        while (jogoAtivo) {
          char linhaChar;
          int x, y;

          while (true) {
            cout << "\nJogador 1, atire no tabuleiro do Jogador 2 (linha "
                    "coluna): ";
            cin >> linhaChar >> y;

            linhaChar = toupper(linhaChar);
            x = linhaChar - 'A';

            if (cin.fail()) {
              cout << "Entrada inválida. Tente novamente." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              continue;
            }

            y -= 1;

            if (x >= 0 && x < b_size && y >= 0 && y < b_size) {
              break;
            } else {
              cout << "Posição inválida. Tente novamente." << endl;
            }
          }

          if (atirar(tabuleiro2, x, y)) {
            cout << "Acertou!" << endl;
          } else {
            cout << "Errou!" << endl;
          }
          cout << "\nTabuleiro atual do Jogador 2:" << endl;
          imprimeTabuleiro(tabuleiro2, false);

          if (contarPartesNaviosRestantes(tabuleiro2) == 0) {
            cout << "\nJogador 1 venceu!\n" << endl;
            jogoAtivo = false;
            break;
          }

          while (true) {
            cout << "\nJogador 2, atire no tabuleiro do Jogador 1 (linha "
                    "coluna): ";
            cin >> linhaChar >> y;

            linhaChar = toupper(linhaChar);
            x = linhaChar - 'A';

            if (cin.fail()) {
              cout << "Entrada inválida. Tente novamente." << endl;
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              continue;
            }

            y -= 1;

            if (x >= 0 && x < b_size && y >= 0 && y < b_size) {
              break;
            } else {
              cout << "Posição inválida. Tente novamente." << endl;
            }
          }

          if (atirar(tabuleiro1, x, y)) {
            cout << "Acertou!" << endl;
          } else {
            cout << "Errou!" << endl;
          }
          cout << "\nTabuleiro atual do Jogador 1:" << endl;
          imprimeTabuleiro(tabuleiro1, false);

          if (contarPartesNaviosRestantes(tabuleiro1) == 0) {
            cout << "\nJogador 2 venceu!\n" << endl;
            jogoAtivo = false;
            break;
          }
        }
        break;
      }

      case 2:
        cout << "Escolheu a opção 2" << endl;
        break;
      case 3:
        cout << "Escolheu a opção 3" << endl;
        break;
      case 4:
        cout << "Saindo do programa..." << endl;
        break;
      }
      break;
    }

    case 2:
      cout << "Nada..." << endl;
      break;
    case 3:
      cout << "Saindo..." << endl;
      executando = false;
      break;
    }
  }
}
