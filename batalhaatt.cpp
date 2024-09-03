#include <iostream>

using namespace std;

int escolhamodo;
const int SIZE = 15; // Tamanho do tabuleiro

// Fun��o para inicializar o tabuleiro
void inicializaTabuleiro(char tabuleiro[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            tabuleiro[i][j] = ' '; // '' representa �gua
        }
    }
}

// Fun��o para imprimir o tabuleiro (escondendo navios do advers�rio)
void imprimeTabuleiro(char tabuleiro[SIZE][SIZE], bool esconderNavios) {
    cout << "   ";
    for (int i = 1; i <= SIZE; i++) {
        if (i < 10) cout << " " << i << " ";  // Espa�amento para manter alinhamento
        else cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << (char)('A' + i) << " "; // Imprime as letras das linhas
        if(i < 9) cout << " "; // Adiciona um espa�o adicional para alinhar
        for (int j = 0; j < SIZE; j++) {
            if (esconderNavios && tabuleiro[i][j] == 'N') {
                cout << "~  "; // Esconde os navios do advers�rio
            } else {
                cout << tabuleiro[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

// Fun��o para verificar se o navio pode ser colocado em uma posi��o espec�fica
bool podePosicionarNavio(char tabuleiro[SIZE][SIZE], int x, int y, int tamanho, char direcao) {
    if (direcao == 'H') { // Horizontal
        if (y + tamanho > SIZE) return false; // Verifica se h� espa�o
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x][y + i] != '~') return false; // Verifica se o espa�o est� livre
        }
    } else if (direcao == 'V') { // Vertical
        if (x + tamanho > SIZE) return false; // Verifica se h� espa�o
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[x + i][y] != '~') return false; // Verifica se o espa�o est� livre
        }
    }
    return true;
}

// Fun��o para posicionar um navio no tabuleiro
void posicionaNavio(char tabuleiro[SIZE][SIZE], int tamanho) {
    char linhaChar;
    int x, y;
    char direcao;
    bool posicionado = false;

    while (!posicionado) {
        cout << "Posicione o navio de tamanho " << tamanho << " (linha coluna dire��o [H/V]): ";
        cin >> linhaChar >> y >> direcao;

        x = linhaChar - 'A'; // Converte a linha de char para um �ndice de 0 a 14
        y -= 1; // Ajusta a coluna para �ndice de 0 a 14

        if (direcao != 'H' && direcao != 'V') {
            cout << "Dire��o inv�lida, use 'H' para horizontal ou 'V' para vertical." << endl;
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
            cout << "Posi��o inv�lida ou espa�o ocupado, tente novamente." << endl;
        }
    }
}

// Fun��o para processar um tiro
bool atirar(char tabuleiro[SIZE][SIZE], int x, int y) {
    if (tabuleiro[x][y] == 'N') {
        tabuleiro[x][y] = 'X'; // 'X' representa um acerto
        cout << "Voc� acertou um navio!" << endl;
        return true;
    } else if (tabuleiro[x][y] == '~') {
        tabuleiro[x][y] = 'O'; // 'O' representa um tiro na �gua
        cout << "Tiro na �gua!" << endl;
        return false;
    } else {
        cout << "Voc� j� atirou aqui antes!" << endl;
        return false;
    }
}

//inclus�o de fun��es de menu
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


// Fun��o principal
int main() {
    char tabuleiroJogador1[SIZE][SIZE];
    char tabuleiroJogador2[SIZE][SIZE];

    menu1();



    inicializaTabuleiro(tabuleiroJogador1);
    inicializaTabuleiro(tabuleiroJogador2);

    cout << "Jogador 1, posicione seus navios:" << endl;
    posicionaNavio(tabuleiroJogador1, 2); // Navio de 2 espa�os
    posicionaNavio(tabuleiroJogador1, 3); // Navio de 3 espa�os
    posicionaNavio(tabuleiroJogador1, 5); // Navio de 5 espa�os

    cout << "Jogador 2, posicione seus navios:" << endl;
    posicionaNavio(tabuleiroJogador2, 2); // Navio de 2 espa�os
    posicionaNavio(tabuleiroJogador2, 3); // Navio de 3 espa�os
    posicionaNavio(tabuleiroJogador2, 5); // Navio de 5 espa�os

    int acertosJogador1 = 0;
    int acertosJogador2 = 0;
    int totalAcertos1 = 2 + 3 + 5; // Total de acertos necess�rios para vencer
    int totalAcertos2 = 2 + 3 + 5;
    char linhaChar;
    int x, y;
    int jogadas = 0;

    while (acertosJogador1 < totalAcertos1 && acertosJogador2 < totalAcertos2) {
        cout << "Jogada " << ++jogadas << ": " << endl;
        if (jogadas % 2 == 1) {
            cout << "Jogador 1, sua vez de atirar!" << endl;
            imprimeTabuleiro(tabuleiroJogador2, true); // Esconde navios do Jogador 2
            cout << "Atire em uma posi��o (linha coluna): ";
            cin >> linhaChar >> y;

            x = linhaChar - 'A'; // Converte a linha de char para um �ndice de 0 a 14
            y -= 1; // Ajusta a coluna para �ndice de 0 a 14

            if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
                if (atirar(tabuleiroJogador2, x, y)) {
                    acertosJogador1++;
                }
            } else {
                cout << "Coordenadas inv�lidas, tente novamente." << endl;
            }
        } else {
            cout << "Jogador 2, sua vez de atirar!" << endl;
            imprimeTabuleiro(tabuleiroJogador1, true); // Esconde navios do Jogador 1
            cout << "Atire em uma posi��o (linha coluna): ";
            cin >> linhaChar >> y;

            x = linhaChar - 'A'; // Converte a linha de char para um �ndice de 0 a 14
            y -= 1; // Ajusta a coluna para �ndice de 0 a 14

            if (x >= 0 && x < SIZE && y >= 0 && y < SIZE) {
                if (atirar(tabuleiroJogador1, x, y)) {
                    acertosJogador2++;
                }
            } else {
                cout << "Coordenadas inv�lidas, tente novamente." << endl;
            }
        }
    }

    if (acertosJogador1 == totalAcertos1) {
        cout << "Parab�ns, Jogador 1! Voc� venceu!" << endl;
    } else {
        cout << "Parab�ns, Jogador 2! Voc� venceu!" << endl;
    }

    return 0;
}
