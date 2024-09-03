#include <iostream>

using namespace std;

int escolhamodo;
const int SIZE = 15; // Tamanho do tabuleiro

// Função para inicializar o tabuleiro
void inicializaTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' '; // '' representa água
        }
    }
}

// Função para imprimir o tabuleiro (escondendo navios do adversário)
void imprimeTabuleiro(char tabuleiro[SIZE][SIZE], bool esconderNavios) {
    cout << "   ";
    for (int i = 1; i <= SIZE; i++) {
        if (i < 10) cout << " " << i << " ";  // Espaçamento para manter alinhamento
        else cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << (char)('A' + i) << " "; // Imprime as letras das linhas
        if(i < 9) cout << " "; // Adiciona um espaço adicional para alinhar
        for (int j = 0; j < SIZE; j++) {
            if (esconderNavios && tabuleiro[i][j] == 'N') {
                cout << "~  "; // Esconde os navios do adversário
            } else {
                cout << tabuleiro[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

// Função para verificar se o navio pode ser colocado em uma posição específica
bool podePosicionarNavio(char tabuleiro[SIZE][SIZE], int x, int y, int tamanho, char direcao) {
    if (direcao == 'H') { // Horizontal
        if (y + tamanho > SIZE) return false; // Verifica se há espaço
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x][y + i] != '~') return false; // Verifica se o espaço está livre
        }
    } else if (direcao == 'V') { // Vertical
        if (x + tamanho > SIZE) return false; // Verifica se há espaço
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y] != '~') return false; // Verifica se o espaço está livre
        }
    }
    return true;
}

// Função para posicionar um navio no tabuleiro
void posicionaNavio(char tabuleiro[SIZE][SIZE], int tamanho) {
    char linhaChar;
    int x, y;
    char direcao;
    bool posicionado = false;

    while (!posicionado) {
        cout << "Posicione o navio de tamanho " << tamanho << " (linha coluna direção [H/V]): ";
        cin >> linhaChar >> y >> direcao;

        x = linhaChar - 'A'; // Converte a linha de char para um índice de 0 a 14
        y -= 1; // Ajusta a coluna para índice de 0 a 14

        if (direcao != 'H' && direcao != 'V') {
            cout << "Direção inválida, use 'H' para horizontal ou 'V' para vertical." << endl;
            continue;
        }

        if (x >= 0 && x < SIZE && y >= 0 && y < SIZE && podePosicionarNavio(tabuleiro, x, y, tamanho, direcao)) {
            if (direcao == 'H') {
                for (int i = 0; i < tamanho; i++) {
                    tabuleiro[x][y + i] = 'N';
                }
            } else if (direcao == 'V') {
                for (int i = 0; i < tamanho; i++) {
                    tabuleiro[x + i][y] = 'N';
                }
            }
            posicionado = true;
        } else {
            cout << "Posição inválida ou espaço ocupado, tente novamente." << endl;
        }
    }
}

// Função para processar um tiro
bool atirar(char tabuleiro[SIZE][SIZE], int x, int y) {
    if (tabuleiro[x][y] == 'N') {
        tabuleiro[x][y] = 'X'; // 'X' representa um acerto
        cout << "Você acertou um navio!" << endl;
        return true;
    } else if (tabuleiro[x][y] == '~') {
        tabuleiro[x][y] = 'O'; // 'O' representa um tiro na água
        cout << "Tiro na água!" << endl;
        return false;
    } else {
        cout << "Você já atirou aqui antes!" << endl;
        return false;
    }
}

//inclusão de funções de menu
menu1(){
  int escolhamodo;
  int jogotipo;
  cout << "=======================" << endl;
  cout << "Escolha uma opcao de jogo: " << endl;
  cout << "1. Matrizes e Vetores" << endl;
  cout << "2. " << endl;
  cout << "3. " << endl;
  cout << "4. " << endl;
  cout << "=====================" << endl;
  cout << "Digite sua escolha: ";
  cin >> escolhamodo;

  switch (escolhamodo) {

  case 1: {
  cout << "=======================" << endl;
  cout << "Escolha uma opcao de jogo: " << endl;
  cout << "1. Batalha Naval" << endl;
  cout << "2. " << endl;
  cout << "3. " << endl;
  cout << "4. " << endl;
  cout << "=====================" << endl;
  cout << "Digite sua escolha: ";
  cin >> escolhamodo;

    if(escolhamodo = 1){
      cout << "=======================" << endl;
      cout << "Escolha uma opcao de jogo: " << endl;
      cout << "1. Player x Player" << endl;
      cout << "2. Player x CPU " << endl;
      cout << "3. CPU x CPU" << endl;
      cout << endl;
      cout << "=====================" << endl;
      cout << "Digite sua escolha: ";
      cin >> jogotipo;
      return 0;
      }
     }
    }
   }


// Função principal
int main() {
    char tabuleiroJogador1[SIZE][SIZE];
    char tabuleiroJogador2[SIZE][SIZE];

    menu1();



    inicializaTabuleiro(tabuleiroJogador1);
    inicializaTabuleiro(tabuleiroJogador2);

    cout << "Jogador 1, posicione seus navios:" << endl;
    posicionaNavio(tabuleiroJogador1, 2); // Navio de 2 espaços
    posicionaNavio(tabuleiroJogador1, 3); // Navio de 3 espaços
    posicionaNavio(tabuleiroJogador1, 5); // Navio de 5 espaços

    cout << "Jogador 2, posicione seus navios:" << endl;
    posicionaNavio(tabuleiroJogador2, 2); // Navio de 2 espaços
    posicionaNavio(tabuleiroJogador2, 3); // Navio de 3 espaços
    posicionaNavio(tabuleiroJogador2, 5); // Navio de 5 espaços

    int acertosJogador1 = 0;
    int acertosJogador2 = 0;
    int totalAcertos1 = 2 + 3 + 5; // Total de acertos necessários para vencer
    int totalAcertos2 = 2 + 3 + 5;
    char linhaChar;
    int x, y;
    int jogadas = 0;

    while (acertosJogador1 < totalAcertos1 && acertosJogador2 < totalAcertos2) {
        cout << "Jogada " << ++jogadas << ": " << endl;
        if (jogadas % 2 == 1) {
            cout << "Jogador 1, sua vez de atirar!" << endl;
            imprimeTabuleiro(tabuleiroJogador2, true); // Esconde navios do Jogador 2
            cout << "Atire em uma posição (linha coluna): ";
            cin >> linhaChar >> y;

            x = linhaChar - 'A'; // Converte a linha de char para um índice de 0 a 14
            y -= 1; // Ajusta a coluna para índice de 0 a 14

            if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
                if (atirar(tabuleiroJogador2, x, y)) {
                    acertosJogador1++;
                }
            } else {
                cout << "Coordenadas inválidas, tente novamente." << endl;
            }
        } else {
            cout << "Jogador 2, sua vez de atirar!" << endl;
            imprimeTabuleiro(tabuleiroJogador1, true); // Esconde navios do Jogador 1
            cout << "Atire em uma posição (linha coluna): ";
            cin >> linhaChar >> y;

            x = linhaChar - 'A'; // Converte a linha de char para um índice de 0 a 14
            y -= 1; // Ajusta a coluna para índice de 0 a 14

            if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
                if (atirar(tabuleiroJogador1, x, y)) {
                    acertosJogador2++;
                }
            } else {
                cout << "Coordenadas inválidas, tente novamente." << endl;
            }
        }
    }

    if (acertosJogador1 == totalAcertos1) {
        cout << "Parabéns, Jogador 1! Você venceu!" << endl;
    } else {
        cout << "Parabéns, Jogador 2! Você venceu!" << endl;
    }

    return 0;
}
