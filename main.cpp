#include <iostream>
#include <time.h>
#include<stdlib.h>

using namespace std;
int main() {
    int jogadas=0;
    int endLoop=81;
    int dificuldade = 2;
    int voltar = 9;
    int menu, MG[9][9];
    int MP[9][9]{          //Matriz principal que sera usada para usar a gabarito
            {4, 9, 5, 2, 8, 7, 3, 6, 1},
            {7, 2, 8, 6, 1, 3, 4, 9, 5},
            {3, 6, 1, 9, 5, 4, 7, 2, 8},
            {6, 5, 3, 8, 4, 9, 2, 1, 7},
            {9, 8, 4, 1, 7, 2, 6, 5, 3},
            {2, 1, 7, 5, 3, 6, 9, 8, 4},
            {1, 3, 2, 4, 6, 5, 8, 7, 9},
            {5, 4, 6, 7, 9 ,8, 1, 3, 2},
            {8, 7, 9, 3, 2, 1, 5, 4, 6}
    };
    int MJ[9][9]{          //Matriz jogo
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0 ,0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };


    while(voltar == 9) {
        system("cls");

        srand(time(NULL));


        cout << "----------------SUDOKU----------------\n"     //Menu
                "(1)Jogar\n"
                "(2)Dificuldade\n"
                "(3)Sobre\n"
                "(4)Fim\n";
        cout << "Selecione a opcao: ";
        cin >> menu;

        if (menu <= 0 || menu >= 5) {              //Caso seja escolida uma opcao que nao esta no menu
            while (menu <= 0 || menu >= 5) {
                cout << "Selecione uma opcao valida: ";
                cin >> menu;
            }
        }
        int r=rand()%4+1;
        switch (menu) {         //seleciona a opcao escolida
            case 1: //Jogar

                system("cls");

                        ///Seleciona aleatoriamente algum dos casos para criar a Matrix Gabarito
                    if(r == 1){
                             //MP igual MG
                        for(int i=0;i<9;i++){
                            for(int j=0;j<9;j++){
                                MG[i][j] = MP[i][j];
                            }
                        }
                        }
                    if(r == 2){
                            //MG transposta da MP
                        for(int i=0; i<9;i++){
                            for(int j=0; j<9; j++){
                                MG[i][j] = MP[j][i];
                            }
                        }
                        }

                    if(r == 3){
                               //MG invertida por linha da MP
                        for(int i=0; i<9;i++){
                            for(int j=0; j<9; j++){
                                int y = 8;
                                MG[y - i][j] = MP[i][j];
                            }
                        }
                        }
                    if(r == 4){
                                //MG invertida por coluna da MP
                        for(int i=0; i<9;i++){
                            for(int j=0; j<9; j++){
                                int y = 8;
                                MG[i][j] = MP[i][y - j];
                            }
                        }

                        }

                            ///Verifica a dificuldade
                if(dificuldade == 1){       //facil: 40 numeros
                        int f = 1;
                        while(f  < 41){

                            int i=rand()%9;
                            int j=rand()%9;

                            if(MJ[i][j] == 0){
                                MJ[i][j] = MG[i][j];
                                f++;
                            }
                        }
                }
                if(dificuldade == 2){       //medio: 18 numeros
                    int f = 1;
                    while(f  < 19){
                        int i=rand()%9;
                        int j=rand()%9;

                        if(MJ[i][j] == 0){
                            MJ[i][j] = MG[i][j];
                            f++;
                        }
                    }
                }

                if(dificuldade == 3){   //dificil: 12 numeros
                    int f = 1;
                    while(f  < 13){

                        int i=rand()%9;
                        int j=rand()%9;

                        if(MJ[i][j] == 0){
                                MJ[i][j] = MG[i][j];
                                f++;
                        }
                    }
                }

                while(endLoop != 0) {       ///Loop para que o jogo continue enquanto nao completar todos os espacos
                    endLoop = 81;
                    system("cls");
                    int x = 0;
                    cout << "       0  1  2    3  4  5    6  7  8  \n"       //construcao do sudoku
                            "     ,________________________________,\n";
                    int linhas =1;
                    int quadrado=0;
                    for (int i = 0; i < 9; i++) {

                        cout << "   " << x << " | ";//variavel x inicialmente 0

                        for (int j = 0; j < 9; j++) {

                            if (MJ[i][j] == 0) {
                                quadrado++;
                                cout << " " << "  ";
                                if(quadrado%3 == 0){
                                    cout<<"| ";
                                }
                            } else {
                                quadrado++;
                                cout << MJ[i][j] << "  ";
                                if(quadrado%3 == 0){
                                    cout<<"| ";
                                }
                            }
                        }
                        if(linhas%3 == 0){
                            cout<<"\n     |__________|__________|__________|";
                        }
                        linhas++;
                        cout << endl;
                        x++;
                    }
                           //termino da construcao

                    int l, c, n;
                    cout << "Digite a linha e a coluna, respectivamente, da posicao onde deseja colocar o numero depois o numero que deseka colocar:\n";
                    cin >>l>>c>>n;
                    jogadas++;

                    if(MJ[l][c] == 0){
                        if(MG[l][c] == n){
                            cout<<"Voce acertou um numero!!\n Aperte quelquer tecla para continuar";
                            MJ[l][c] = MG[l][c];
                            system("pause");
                        }else{
                            cout<<"Voce errou, tente denovo\n Aperte quelquer tecla para continuar";
                            system("pause");
                        }
                    }else{
                        cout<<"Esse lugar ja esta preenchido\n Aperte quelquer tecla para continuar";
                        system("pause");
                    }

                    system("cls");

                for(int i=0; i<9; i++){ //verifica se todos os espacos estao preenchidos, se estao o jogo acaba
                    for(int j=0; j<9; j++){
                        if(MJ[i][j] != 0){
                            endLoop = endLoop - 1;
                        }
                    }
                }
                if(endLoop == 0){
                    cout<<"*************VOCE CONSEGUIO!!!************\n\n";
                    cout<<jogadas<<" jogadas";
                    switch (dificuldade) {
                        case 1:
                            cout<<"Dificuldade facil\n";
                            break;

                        case 2:
                            cout<<"Dificuldade media\n";
                            break;

                        case 3:
                            cout<<"Dificuldade dificil\n";
                            break;

                    }
                    cout<< "Aperte quelquer tecla para continuar";
                    system("pause");
                }

                }

                cout<<"Digite 9 para voltar ao menu: ";
                cin>>voltar;
                if (voltar != 9) {              //Caso seja escolida uma opcao que nao esta no menu
                    while (voltar != 9) {
                        cout << "Selecione uma opcao valida: ";
                        cin >> voltar;
                    }
                }

                break;

            case 2://Dificuldade
                system("cls");
                cout << "-----SELECIONE A DIFICULDADE-----\n"
                        "(1)Facil: exibe 50% dos valores \n"
                        "(2)Media: exibe 35% dos valores \n"
                        "(3)Dificil: exibe 15% dos valores \n";
                cin>>dificuldade;
                if (dificuldade <= 0 || dificuldade >= 4) {              //Caso seja escolida uma opcao que nao esta no menu
                    while (dificuldade <= 0 || dificuldade >= 4) {
                        cout << "Selecione uma opcao valida: ";
                        cin >> dificuldade;
                    }
                }
                cout<<"Digite 9 para voltar ao menu: ";
                cin>>voltar;
                if (voltar != 9) {              //Caso seja escolida uma opcao que nao esta no menu
                    while (voltar != 9) {
                        cout << "Selecione uma opcao valida: ";
                        cin >> voltar;
                    }
                }
                break;

            case 3://Sobre
                system("cls");
                cout << "Desenvolvido por Bryan Jardim morais\n"
                        "junho/2023\n"
                        "Professora Cristina Ono Horita\n\n";
                cout<<"Digite 9 para voltar ao menu: ";
                cin>>voltar;
                if (voltar != 9) {              //Caso seja escolida uma opcao que nao esta no menu
                    while (voltar != 9) {
                        cout << "Selecione uma opcao valida: ";
                        cin >> voltar;
                    }
                }
                break;

            case 4://Fim
                return 0;

        }
    }

    return 0;
}
