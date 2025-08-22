#include <stdio.h>



int main() {

#include <stdio.h>
#define HEALTH 3

    //Definindo os navios que serão inseridos no tabuleiro
    int shipH[1] = {HEALTH};
    int shipV[1] = {HEALTH};
    int shipD1[1] = {HEALTH};
    int shipD2[1] = {HEALTH};

    //Definindo  o tabuleiro
    int board[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    

    //Definindo local dos navios
    int placeHorizontal[2] = {5, 2}; // Ponto inicial do barco
    int placeVertical[2] = {5, 5};
    int placeDiagonal1[2] = {3,7};
    int placeDiagonal2[2] = {0,0};

    //Código para inserir o navio na horizontal
    for (int h = 3; h>0; h--){
        if ((board[placeHorizontal[0]][placeHorizontal[1]] == 0) && (placeVertical[1] <= 9)){
            board[placeHorizontal[0]][placeHorizontal[1]] = shipH[0];
            placeHorizontal[1]+=1;
        }else{
            printf("Local inválido!!! Horizontal\n");
            break;
        }
    }

    //Código para inserir o navio na vertical
    for (int v = 3; v > 0; v--){
        if ((board[placeVertical[0]][placeVertical[1]] == 0) && (placeVertical[1] <= 9)){
            board[placeVertical[0]][placeVertical[1]] = shipV[0];
            placeVertical[0]+=1;
        }else{
            printf("Local inválido!!! Vertucak\n");
            break;
        }
        
    }

    //Código para inserir o navio na diagonal1
    for (int d1 = 3; d1 > 0; d1--){
        if ((board[placeDiagonal1[0]][placeDiagonal1[1]] == 0) && (placeDiagonal1[0] <=9 && placeDiagonal1[1] <=9)){
            board[placeDiagonal1[0]][placeDiagonal1[1]] = shipD1[0];
            placeDiagonal1[0]+=1;
            placeDiagonal1[1]+=1;
        } else{
            printf("Local inválido!!! Diagonal1\n");
            break;
        }
    }

    //Código para inserir o navio na diagonal2
    for (int d2 = 3; d2 > 0; d2--){
        if ((board[placeDiagonal2[0]][placeDiagonal2[1]] == 0) && (placeDiagonal2[0] <=9 && placeDiagonal2[1] <=9)){
            board[placeDiagonal2[0]][placeDiagonal2[1]] = shipD2[0];
            placeDiagonal2[0]+=1;
            placeDiagonal2[1]+=1;
        } else{
            printf("Local inválido!!! Diagonal2\n");
            break;
        }
    }


//Aqui ficarão as habilidades e localizações
    //Definindo habilidade em cone
    int cone[3][5] = {
        {0,0,5,0,0},
        {0,5,5,5,0},
        {5,5,5,5,5}
    };

    //Definindo habilidade em cruz
    int cruz[3][5] = {
        {0,0,5,0,0},
        {5,5,5,5,5},
        {0,0,5,0,0},
    };

    //Definindo habilidade em octaedro
    int octaedro[3][5] = {
        {0,0,5,0,0},
        {0,5,5,5,0},
        {0,0,5,0,0},
    };

    //Ponto de origem das habilidades

    int placeCone[2] = {5,6};

    int placeCruz[2] = {7,3};

    int placeOctaedro[2] = {2,2};

    //Aqui será o código que coloca a habilidades cone no tabuleiro
    if (placeCone[0] >= 1 && placeCone[1] >= 2 && placeCone[0] + 1 < 10 && placeCone[1] + 2 < 10) {
    int startRow = placeCone[0] - 1;
    int startColumn = placeCone[1] - 2;
    for (int i = 0; i < 3; i++) { // 3 linhas da habilidade
        for (int j = 0; j < 5; j++) { // 5 colunas da habilidade
            int row = startRow + i;
            int column = startColumn + j;
            if (row >= 0 && row < 10 && column >= 0 && column < 10) {
                if (board[row][column] < cone[i][j]) {
                    board[row][column] = cone[i][j];
                }
            }
        }
    }
    } else {
        printf("Fora do escopo.\n");
    }

    //Aqui será o código que coloca a habilidades cruz no tabuleiro
    if (placeCruz[0] >= 1 && placeCruz[1] >= 2 && placeCruz[0] + 1 < 10 && placeCruz[1] + 2 < 10) { //aqui confirma que a habilidade estará dentro do tabuleiro
    int startRow = placeCruz[0] - 1; //crio uma variável para a linha inicial no tabuleiro. (-1 pois será informado o centro da habilidade, o início deve ser uma linha acima)
    int starColumn = placeCruz[1] - 2; //crio uma variável para a coluna inicial no tabuleiro. (-2 pois será informado o centro da habilidade, o início deve ser duas colunas a esquerda)
    for (int i = 0; i < 3; i++) { //caminho pelas linhas da habilidade
        for (int j = 0; j < 5; j++) { //caminho pelas colunas da habilidade
            int row = startRow + i; //defino uma variável que será o ponto no tabuleiro (enquanto percorro a habilidade, ao mesmo tempo percorro o tabuleiro)
            int column = starColumn + j;//defino uma variável que será o ponto no tabuleiro (enquanto percorro a habilidade, ao mesmo tempo percorro o tabuleiro)
            if (row >= 0 && row < 10 && column >= 0 && column < 10) { //aqui eu confirmo para saber se o ponto inicial não sirá da área do tabuleiro
                if (board[row][column] < cruz[i][j]) { // comparo para saber se a habilidade realmente atingiu o navio. se algum "0" atingiu o 3 do navio, não deve ser substituído. caso algum 5 atinga o 3 do navio, será substituído indicando que foi atingido
                    board[row][column] = cruz[i][j]; // altera os valores confirmando o acerto
                }
            }
        }
    }
    } else {
        printf("Fora do escopo.\n");
    }


    //Aqui será o código que coloca a habilidades octaedro no tabuleiro
    if (placeOctaedro[0] >= 1 && placeOctaedro[1] >= 2 && placeOctaedro[0] + 1 < 10 && placeOctaedro[1] + 2 < 10) {
    int startRow = placeOctaedro[0] - 1;
    int startColumn = placeOctaedro[1] - 2;
    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 5; j++) { 
            int row = startRow + i;
            int column = startColumn + j;
            if (row >= 0 && row < 10 && column >= 0 && column < 10) {
                if (board[row][column] < octaedro[i][j]) {
                    board[row][column] = octaedro[i][j];
                }
            }
        }
    }
    } else {
        printf("Fora do escopo.\n");
    }


    //Imprimindo o tabuleiro
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}
