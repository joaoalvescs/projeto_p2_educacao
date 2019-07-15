#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <cstdlib>
#include <conio2.h>
#include <locale.h>
#include "Aluno.h"
#include "Professor.h"
#include "Disciplina.h"
#include "Tela.h"

using namespace std;

int main(){
    int op;
    int controle, controle1, controle2;
    do{
        telamenu();
        gotoxy(25,30); textcolor(WHITE); textbackground(WHITE); cin >> op;
        switch(op){
            case 0:
                controle = 0;
                cout << "SAINDO... \n";
            break;
            case 1:
                do{
                    tela();
                    menuAluno();
                    gotoxy(25,19); cin >> op;
                    switch(op){
                        case 1:
                            do{
                                system("cls");
                                controle2 = cadastroAluno();
                            }while(controle2!=0);
                        break;
                        case 2:
                                system("cls");
                                controle1 = exibirAluno();
                        break;
                        case 3:
                            do{
                                system("cls");
                                controle2 = buscarAluno();
                            }while(controle2!=0);
                        break;
                        case 4:
                            do{
                                system("cls");
                                controle2 = atualizarAluno();
                            }while(controle2!=0);
                        break;
                        case 5:
                            do{
                                system("cls");
                                controle2 = removerAluno();
                            }while(controle2!=0);
                        break;
                        default:
                            controle1 = 0;
                    }
                }while(controle1!=0);
            break;
            case 2:
                do{
                    system("cls");
                    tela();
                    menuProfessor();
                    gotoxy(25,19); cin >> op;
                    switch(op){
                        case 1:
                            do{
                                system("cls");
                                controle2 = cadastroProfessor();
                            }while(controle2!=0);
                        break;
                        case 2:
                            system("cls");
                            controle1 = exibirProfessor();
                        break;
                        case 3:
                            do{
                                system("cls");
                                controle2 = buscarProfessor();
                            }while(controle2!=0);
                        break;
                        case 4:
                            do{
                                system("cls");
                                controle2 = atualizarProfessor();
                            }while(controle2!=0);
                        break;
                        case 5:
                            do{
                                system("cls");
                                controle2 = removerProfessor();
                            }while(controle2!=0);
                        break;
                        default:
                            controle1 = 0;
                    }
                }while(controle1!=0);
            break;
            case 3:
                do{
                    tela();
                    menuDisciplina();
                    gotoxy(25,19); cin >> op;
                    switch(op){
                        case 1:
                            do{
                                system("cls");
                                controle2 = cadastroDisciplina();
                            }while(controle2!=0);
                        break;
                        case 2:
                            system("cls");
                            controle1 = exibirDisciplina();
                        break;
                        case 3:
                            do{
                                system("cls");
                                controle2 = buscarDisciplina();
                            }while(controle2!=0);
                        break;
                        case 4:
                            do{
                                system("cls");
                                controle2 = atualizarDisciplina();
                            }while(controle2!=0);
                        break;
                        case 5:
                            do{
                                system("cls");
                                controle2 = removerDisciplina();
                            }while(controle2!=0);
                        break;
                        default:
                            controle1 = 0;
                    }
                }while(controle1!=0);
            break;
            default:
                cerr << " VALOR INVALIDO! \n";
        }
    }while(controle!=0);
    return 0;
}
