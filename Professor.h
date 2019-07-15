#ifndef PROFESSOR_H_INCLUDED
#define PROFESSOR_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <conio2.h>
#include <iomanip>
#include <stdio.h>
#include <unistd.h>
#include <locale.h>
#include "Aluno.h"
#include "Disciplina.h"
#include "Tela.h"

using namespace std;

namespace Professores{
    struct Professor{
        char nome[40], disciplina[40], departamento[40];
        int matricula;
    }professor;
}

using namespace Professores;

int cadastroProfessor();
int exibirProfessor();
void gravarProfessor();
void saidaProfessor();
int buscarProfessor();
int atualizarProfessor();
int removerProfessor();
void menuProfessor();

int cadastroProfessor(){
    system("cls");
    tela();
    gotoxy(25,5); textcolor(BLACK); textbackground(WHITE); cout << " Informe a matricula do professor(a) " << endl;
    gotoxy(25,6); textcolor(BLACK); textbackground(WHITE); cin >> professor.matricula;
    gotoxy(25,7); textcolor(BLACK); textbackground(WHITE); cout << " Informe o nome do(a) professor(a) \n";
    gotoxy(25,8); textcolor(BLACK); textbackground(WHITE); cin.ignore(); cin.getline(professor.nome,40);
    gotoxy(25,9); textcolor(BLACK); textbackground(WHITE); cout << " Informe a disciplina que " << professor.nome << " ministra \n";
    gotoxy(25,10); textcolor(BLACK); textbackground(WHITE); cin.getline(professor.disciplina,40);
    gotoxy(25,11); textcolor(BLACK); textbackground(WHITE); cout << " Informe o departamento do(a) prof(a) " << professor.nome << endl;
    gotoxy(25,12); textcolor(BLACK); textbackground(WHITE); cin.getline(professor.departamento,40);
    if (opcao("Deseja cadastrar mais professores?")==0){
        gravarProfessor();
        return 0;
    }else{
        gravarProfessor();
        return 1;
    }
}

int exibirProfessor(){
    fstream arquivo("professor.dat",ios::in|ios::binary);
        arquivo.read((char*)&professor,sizeof(Professor));
        while(!arquivo.eof()){
                if (professor.matricula!=0){
                    saidaProfessor();
                }
                arquivo.read(reinterpret_cast<char*>(&professor),sizeof(Professor));
        }
    arquivo.close();
    int resultado;
    cout << "\n \n DIGITE 2 PARA VOLTAR AO MENU PROFESSOR  \n";
    cout << " \n \n DIGITE 0 PARA VOLTAR AO MENU PRINCIPAL \n";
    cin >> resultado;
    return resultado;
}

void gravarProfessor(){
    fstream arquivo("professor.dat",ios::app|ios::binary);
    arquivo.write((char*)&professor,sizeof(Professor));
    arquivo.close();
}

int buscarProfessor(){
    system("cls");
    tela();
    fstream arquivo("professor.dat",ios::in|ios::binary);

    int valor;

    gotoxy(10,5); textcolor(BLACK); textbackground(WHITE); cout << " Informe o matricula do professor. \n";
    gotoxy(10,6); textcolor(BLACK); textbackground(WHITE); cin >> valor;
    arquivo.seekg((valor-1)*sizeof(professor));
    arquivo.read((char*)(&professor),sizeof(professor));
    if (professor.matricula!=0){
        arquivo.seekp((valor-1)*sizeof(professor));
        gotoxy(10,7); saidaProfessor();
    }else{
        gotoxy(10,15); cerr << " NAO ENCONTRADO NO SISTEMA! . \n";
    }
    if (opcao("Deseja buscar mais professores?")==0){
        return 0;
    }else{
        return 1;
    }
}

int atualizarProfessor(){
    system("cls");
    tela();
    fstream arquivo("professor.dat");
    int valor;
    gotoxy(10,5); textcolor(BLACK); textbackground(WHITE); cout << " Informe o matricula do professor que deseja atualizar. \n";
    gotoxy(10,6); textcolor(BLACK); textbackground(WHITE); cin >> valor;

    arquivo.seekg((valor-1)*sizeof(professor));
    arquivo.read((char*)(&professor),sizeof(professor));

    if(professor.matricula!=0){
        gotoxy(10,8); textcolor(BLACK); textbackground(WHITE); cout << " Matricula: " << endl;
        gotoxy(10,9); textcolor(BLACK); textbackground(WHITE); cin >> professor.matricula;
        gotoxy(10,10); textcolor(BLACK); textbackground(WHITE); cout << " Nome: " << endl;
        gotoxy(10,11); textcolor(BLACK); textbackground(WHITE); cin.ignore(); cin.getline(professor.nome,40);
        gotoxy(10,12); textcolor(BLACK); textbackground(WHITE); cout << " Disciplina: " << endl;
        gotoxy(10,13); textcolor(BLACK); textbackground(WHITE); cin.getline(professor.disciplina,40);
        gotoxy(10,14); textcolor(BLACK); textbackground(WHITE); cout << " Departamento: " << endl;
        gotoxy(10,15); textcolor(BLACK); textbackground(WHITE); cin.getline(professor.departamento,40);
        gotoxy(10,16); textcolor(BLACK); textbackground(WHITE); cout << " PROFESSOR ATUALIZADO COM SUCESSO! \n";
        gotoxy(5,20); saidaProfessor();
        arquivo.seekp((valor-1)*sizeof(professor));
        arquivo.write((const char*)(&professor),sizeof(professor));
    }
    if (opcao("Deseja atualizar mais professores?")==0){
        return 0;
    }else{
        return 1;
    }
}

int removerProfessor(){
    system("cls");
    tela();
    fstream arquivo("professor.dat");

    int valor;
    Professor vazio = {0,' ',' ',' '};

    gotoxy(5,10); textcolor(BLACK); textbackground(WHITE); cout << " Informe o codigo da disciplina que deseja remover. \n";
    gotoxy(5,11); textcolor(BLACK); textbackground(WHITE); cin >> valor;

    arquivo.seekg((valor-1)*sizeof(professor));
    arquivo.read((char*)(&professor),sizeof(professor));

    if (professor.matricula!=0){
        arquivo.seekp((valor-1)*sizeof(professor));
        arquivo.write((const char*)(&vazio),sizeof(professor));
        gotoxy(5,13); textcolor(BLACK); textbackground(WHITE); cout << " PROFESSOR REMOVIDO! \n";
    }else{
        gotoxy(5,13); cerr << " PROFESSOR JA FOI REMOVIDO! \n";
    }
    if (opcao("Deseja remover mais professores?")==0){
        return 0;
    }else{
        return 1;
    }
}

void saidaProfessor(){
   cout << left
         << setw(5) << professor.matricula
         << setw(40) << professor.nome
         << setw(40) << professor.disciplina
         << setw(40) << professor.departamento << endl;
}

void menuProfessor(){
    gotoxy(25,13); textcolor(BLACK); textbackground(WHITE); cout << " 0 - SAIR \n";
    gotoxy(25,14); textcolor(BLACK); textbackground(WHITE); cout << " 1 - CADASTRAR PROFESSOR \n";
    gotoxy(25,15); textcolor(BLACK); textbackground(WHITE); cout << " 2 - EXIBIR TODOS OS PROFESSORES \n";
    gotoxy(25,16); textcolor(BLACK); textbackground(WHITE); cout << " 3 - BUSCAR PROFESSOR \n";
    gotoxy(25,17); textcolor(BLACK); textbackground(WHITE); cout << " 4 - ATUALIZAR PROFESSOR \n";
    gotoxy(25,18); textcolor(BLACK); textbackground(WHITE); cout << " 5 - REMOVER PROFESSOR \n";
}

#endif
