#ifndef DISCIPLINA_H_INCLUDED
#define DISCIPLINA_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <conio2.h>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include "Professor.h"
#include "Aluno.h"
#include "Tela.h"

using namespace std;

namespace Disciplinas{
    struct Disciplina{
        int codigo;
        char nome[40], ementa[50], departamento[40];
    }disciplina;
}

using namespace Disciplinas;

int opcao(string mensagem);
int cadastroDisciplina();
int exibirDisciplina();
void gravarDisciplina();
void saidaDisciplina();
int buscarDisciplina();
int atualizarDisciplina();
int removerDisciplina();
void menuDisciplina();

int cadastroDisciplina(){
    system("cls");
    tela();
    gotoxy(25,6); textcolor(BLACK); textbackground(WHITE); cout << " Informe o codigo da disciplina. \n";
    gotoxy(25,7); textcolor(BLACK); textbackground(WHITE); cin >>  disciplina.codigo;
    gotoxy(25,8); textcolor(BLACK); textbackground(WHITE); cout << " Informe o nome da disciplina. \n";
    gotoxy(25,9); textcolor(BLACK); textbackground(WHITE); cin.ignore(); cin.getline(disciplina.nome,40);
    gotoxy(25,10); textcolor(BLACK); textbackground(WHITE); cout << " Informe a ementa de " << disciplina.nome << endl;
    gotoxy(25,11); textcolor(BLACK); textbackground(WHITE); cin.getline(disciplina.ementa,50);
    gotoxy(25,12); textcolor(BLACK); textbackground(WHITE); cout << " Informe o departamento da disciplina " << disciplina.nome << endl;
    gotoxy(25,13); textcolor(BLACK); textbackground(WHITE); cin.getline(disciplina.departamento,40);
    if (opcao("Deseja cadastrar mais disciplinas?")==0){
        gravarDisciplina();
        return 0;
    }else{
        gravarDisciplina();
        return 1;
    }
}

int exibirDisciplina(){
        fstream arquivo("disciplina.dat",ios::in|ios::binary);
        arquivo.read((char*)&disciplina,sizeof(Disciplina));
        while(!arquivo.eof()){
                if (disciplina.codigo!=0){
                    saidaDisciplina();
                }
                arquivo.read(reinterpret_cast<char*>(&disciplina),sizeof(Disciplina));
        }
        arquivo.close();
    int resultado;
    cout << "\n \n DIGITE 2 PARA VOLTAR AO MENU DISCIPLINA  \n";
    cout << " \n \n DIGITE 0 PARA VOLTAR AO MENU PRINCIPAL \n";
    textcolor(WHITE); textbackground(WHITE); cin >> resultado;
    return resultado;
}

void gravarDisciplina(){
    fstream arquivo("disciplina.dat",ios::app|ios::binary);
    arquivo.write((char*)&disciplina,sizeof(Disciplina));
    arquivo.close();
}

int buscarDisciplina(){
    system("cls");
    tela();
    fstream arquivo("disciplina.dat",ios::in|ios::binary);

    int valor;

    gotoxy(10,5); textcolor(BLACK); textbackground(WHITE); cout << " Informe o codigo da disciplina. \n";
     gotoxy(10,6);textcolor(BLACK); textbackground(WHITE);cin >> valor;
    arquivo.seekg((valor-1)*sizeof(disciplina));
    arquivo.read((char*)(&disciplina),sizeof(disciplina));
    if (disciplina.codigo!=0){
        arquivo.seekp((valor-1)*sizeof(disciplina));
        gotoxy(10,7); saidaDisciplina();
    }else{
        gotoxy(10,15); cerr << " NAO ENCONTRADO NO SISTEMA! \n";
    }
    if (opcao("Deseja buscar mais disciplinas?")==0){
        return 0;
    }else{
        return 1;
    }
}

int atualizarDisciplina(){
    system("cls");
    tela();
    fstream arquivo("disciplina.dat");
    int valor;gotoxy(10,5); textcolor(BLACK); textbackground(WHITE);
    gotoxy(10,5); textcolor(BLACK); textbackground(WHITE); cout << " Informe o codigo da disciplina que deseja atualizar. \n";
    gotoxy(10,6); textcolor(BLACK); textbackground(WHITE); cin >> valor;

    arquivo.seekg((valor-1)*sizeof(disciplina));
    arquivo.read((char*)(&disciplina),sizeof(disciplina));

    if(disciplina.codigo!=0){
        gotoxy(10,8); textcolor(BLACK);textbackground(WHITE); cout << " Codigo: " << endl;
        gotoxy(10,9); textcolor(BLACK);textbackground(WHITE); cin >> disciplina.codigo;
        gotoxy(10,10); textcolor(BLACK);textbackground(WHITE);cout << " Nome: " << endl;
        gotoxy(10,11); textcolor(BLACK);textbackground(WHITE);cin.ignore(); cin.getline(disciplina.nome,40);
        gotoxy(10,12); textcolor(BLACK);textbackground(WHITE);cout << " Ementa: " << endl;
        gotoxy(10,13); textcolor(BLACK);textbackground(WHITE); cin.getline(disciplina.ementa,50);
        gotoxy(10,14); textcolor(BLACK);textbackground(WHITE); cout << " Departamento: " << endl;
        gotoxy(10,15); textcolor(BLACK);textbackground(WHITE); cin.getline(disciplina.departamento,40);
        gotoxy(10,16); textcolor(BLACK);textbackground(WHITE); cout << " DISCIPLINA ATUALIZADA COM SUCESSO! \n";
        gotoxy(5,20); saidaDisciplina();
        arquivo.seekp((valor-1)*sizeof(disciplina));
        arquivo.write((const char*)(&disciplina),sizeof(disciplina));
    }
    if (opcao("Deseja atualizar mais disciplinas?")==0){
        return 0;
    }else{
        return 1;
    }
}

int removerDisciplina(){
    system("cls");
    tela();
    fstream arquivo("disciplina.dat");

    int valor;
    Disciplina vazio = {0,' ',' ',' '};

    gotoxy(5,10); textcolor(BLACK); textbackground(WHITE); cout << " Informe a matricula da disciplina que deseja remover. \n";
    gotoxy(5,11); textcolor(BLACK); textbackground(WHITE); cin >> valor;

    arquivo.seekg((valor-1)*sizeof(disciplina));
    arquivo.read((char*)(&disciplina),sizeof(disciplina));

    if (disciplina.codigo!=0){
        arquivo.seekp((valor-1)*sizeof(disciplina));
        arquivo.write((const char*)(&vazio),sizeof(disciplina));
        gotoxy(5,13); textcolor(BLACK); textbackground(WHITE); cout << " DISCIPLINA REMOVIDA! \n";
    }else{
        gotoxy(5,13); cerr << " DISCIPLINA JA FOI REMOVIDA! \n";
    }
    if (opcao("Deseja remover mais disciplinas?")==0){
        return 0;
    }else{
        return 1;
    }
}

void saidaDisciplina(){
    cout << left
        << setw(5) << disciplina.codigo
        << setw(40) << disciplina.nome
        << setw(50) << disciplina.ementa
        << setw(40) << disciplina.departamento << endl;
}

void menuDisciplina(){
    gotoxy(25,13); textcolor(BLACK); textbackground(WHITE); cout << " 0 - SAIR \n";
    gotoxy(25,14); textcolor(BLACK); textbackground(WHITE); cout << " 1 - CADASTRAR DISCIPLINA \n";
    gotoxy(25,15); textcolor(BLACK); textbackground(WHITE); cout << " 2 - EXIBIR TODAS AS DISCIPLINAS \n";
    gotoxy(25,16); textcolor(BLACK); textbackground(WHITE); cout << " 3 - BUSCAR DISCIPLINAS \n";
    gotoxy(25,17); textcolor(BLACK); textbackground(WHITE); cout << " 4 - ATUALIZAR DISCIPLINAS \n";
    gotoxy(25,18); textcolor(BLACK); textbackground(WHITE); cout << " 5 - REMOVER DISCIPLINA \n";
}

#endif
