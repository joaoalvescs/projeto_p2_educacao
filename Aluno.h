#ifndef ALUNO_H_INCLUDED
#define ALUNO_H_INCLUDED

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include <stdio.h>
#include <conio2.h>
#include <locale.h>
#include "Professor.h"
#include "Disciplina.h"
#include "Tela.h"

using namespace std;

namespace Alunos{
    struct Aluno{
        char nome[50], curso[50];
        int matricula, idade, periodo;
    }aluno;
}

using namespace Alunos;

int opcao(string mensagem);
int cadastroAluno();
int exibirAluno();
void gravarAluno();
void saidaAluno();
int atualizarAluno();
int removerAluno();
void menuAluno();
int buscarAluno();

int opcao(string mensagem){
    int resultado;
    gotoxy(25,25); textcolor(BLACK); textbackground(WHITE); cout << mensagem << endl;
    gotoxy(25,26); textcolor(BLACK); textbackground(WHITE); cout << " 0 - NAO \n";
    gotoxy(25,27); textcolor(BLACK); textbackground(WHITE); cout << " 1 - SIM \n";
    gotoxy(25,28); textcolor(WHITE); textbackground(WHITE); cin >> resultado;
    if (resultado==0){
        return 0;
    }else{
        return 1;
    }
}

int cadastroAluno(){
    system("cls");
    tela();
    gotoxy(25,5); textcolor(BLACK); textbackground(WHITE); cout << " Informe a matricula do(a) aluno(a) ";
    gotoxy(25,6); textcolor(BLACK); textbackground(WHITE); cin >> aluno.matricula; cin.ignore();
    gotoxy(25,7); textcolor(BLACK); textbackground(WHITE); cout << " Informe o nome do(a) aluno(a)";
    gotoxy(25,8); textcolor(BLACK); textbackground(WHITE); cin.getline(aluno.nome,50);
    gotoxy(25,9); textcolor(BLACK); textbackground(WHITE); cout << " Informe a idade de " << aluno.nome;
    gotoxy(25,10); textcolor(BLACK); textbackground(WHITE); cin >> aluno.idade;
    gotoxy(25,11); textcolor(BLACK); textbackground(WHITE); cout << " Informe o curso de " << aluno.nome;
    gotoxy(25,12); textcolor(BLACK); textbackground(WHITE);cin.ignore(); cin.getline(aluno.curso,50);
    gotoxy(25,13); textcolor(BLACK); textbackground(WHITE);cout << " Informe o periodo de " << aluno.nome;
    gotoxy(25,14); textcolor(BLACK); textbackground(WHITE);cin >> aluno.periodo;
    if (opcao("Deseja cadastrar mais alunos?")==0){
        gravarAluno();
        return 0;
    }else{
        gravarAluno();
        return 1;
    }
}

void gravarAluno(){
    fstream arquivo("aluno.dat",ios::app|ios::binary);
    arquivo.write((char*)&aluno,sizeof(Aluno));
    arquivo.close();
}

int exibirAluno(){
    fstream arquivo("aluno.dat",ios::in|ios::binary);
    arquivo.read((char*)&aluno,sizeof(Aluno));
        while(!arquivo.eof()){
            if (aluno.matricula!=0){
                saidaAluno();
            }
            arquivo.read(reinterpret_cast<char*>(&aluno),sizeof(Aluno));
        }
        arquivo.close();
    int resultado;
    cout << "\n \n DIGITE 2 PARA VOLTAR AO MENU ALUNO \n";
    cout << " \n \n DIGITE 0 PARA VOLTAR AO MENU PRINCIPAL \n";
    textcolor(WHITE); textbackground(WHITE); cin >> resultado;
    return resultado;
}

int buscarAluno(){
    system("cls");
    tela();
    fstream arquivo("aluno.dat",ios::in|ios::binary);

    int valor;

    gotoxy(10,5); textcolor(BLACK); textbackground(WHITE); cout << " Informe o numero da matricula. \n";
    gotoxy(10,6); textcolor(BLACK); textbackground(WHITE); cin >> valor;
    arquivo.seekg((valor-1)*sizeof(aluno));
    arquivo.read((char*)(&aluno),sizeof(aluno));
    if (aluno.matricula!=0){
        arquivo.seekp((valor-1)*sizeof(aluno));
        gotoxy(10,7); saidaAluno();
    }else{
        gotoxy(10,15); cerr << " NAO ENCONTRADO NO SISTEMA! \n";
    }
    if (opcao("Deseja buscar mais alunos?")==0){
        return 0;
    }else{
        return 1;
    }
}

int atualizarAluno(){
    system("cls");
    tela();
    fstream arquivo("aluno.dat");
    int valor;
    gotoxy(10,5); textcolor(BLACK); textbackground(WHITE); cout << " Informe a matricula do aluno que deseja atualizar. \n";
    gotoxy(10,6); textcolor(BLACK); textbackground(WHITE); cin >> valor;

    arquivo.seekg((valor-1)*sizeof(aluno));
    arquivo.read((char*)(&aluno),sizeof(aluno));

    if(aluno.matricula!=0){
        gotoxy(10,8); textcolor(BLACK); textbackground(WHITE); cout << " Matricula: " << endl;
        gotoxy(10,9); textcolor(BLACK); textbackground(WHITE); cin >> aluno.matricula;
        gotoxy(10,10); textcolor(BLACK); textbackground(WHITE); cout << " Nome: " << endl;
        gotoxy(10,11); textcolor(BLACK); textbackground(WHITE); cin.ignore(); cin.getline(aluno.nome,50);
        gotoxy(10,12); textcolor(BLACK); textbackground(WHITE); cout << " Idade: " << endl;
        gotoxy(10,13); textcolor(BLACK); textbackground(WHITE); cin >> aluno.idade; cin.ignore();
        gotoxy(10,14); textcolor(BLACK); textbackground(WHITE); cout << " Curso: " << endl;
        gotoxy(10,15); textcolor(BLACK); textbackground(WHITE); cin.getline(aluno.curso,50);
        gotoxy(10,16); textcolor(BLACK); textbackground(WHITE); cout << " Periodo: " << endl;
        gotoxy(10,17); textcolor(BLACK); textbackground(WHITE); cin >> aluno.periodo;
        gotoxy(12,22); textcolor(BLACK); textbackground(WHITE); cout << " ALUNO ATUALIZADO COM SUCESSO! \n";
        gotoxy(5,20); saidaAluno();
        arquivo.seekp((valor-1)*sizeof(aluno));
        arquivo.write((const char*)(&aluno),sizeof(aluno));
    }
    if (opcao("Deseja atualizar mais alunos?")==0){
        return 0;
    }else{
        return 1;
    }
}

int removerAluno(){
    system("cls");
    tela();
    fstream arquivo("aluno.dat");

    int valor;
    Aluno vazio = {0,' ',0,' ',0};
    gotoxy(5,10); textcolor(BLACK); textbackground(WHITE); cout << " Informe a matricula do aluno que deseja remover. \n";
    gotoxy(5,11); textcolor(BLACK); textbackground(WHITE); cin >> valor;

    arquivo.seekg((valor-1)*sizeof(aluno));
    arquivo.read((char*)(&aluno),sizeof(aluno));

    if (aluno.matricula!=0){
        arquivo.seekp((valor-1)*sizeof(aluno));
        arquivo.write((const char*)(&vazio),sizeof(aluno));
        gotoxy(5,13); textcolor(BLACK); textbackground(WHITE); cout << " ALUNO REMOVIDO! \n";
    }else{
        gotoxy(5,13); cerr << " ALUNO JA FOI REMOVIDO! \n";
    }
    if (opcao("Deseja remover mais alunos?")==0){
        return 0;
    }else{
        return 1;
    }
}

void saidaAluno(){
    cout << left
         << setw(5) << aluno.matricula
         << setw(30) << aluno.nome
         << setw(5) << aluno.idade
         << setw(30) << aluno.curso
         << setw(2) << aluno.periodo << endl;
}

void menuAluno(){
    gotoxy(25,13); textcolor(BLACK); textbackground(WHITE); cout << " 0 - SAIR \n";
    gotoxy(25,14); textcolor(BLACK); textbackground(WHITE); cout << " 1 - CADASTRAR ALUNO \n";
    gotoxy(25,15); textcolor(BLACK); textbackground(WHITE); cout << " 2 - EXIBIR TODOS OS ALUNOS \n";
    gotoxy(25,16); textcolor(BLACK); textbackground(WHITE); cout << " 3 - BUSCAR ALUNO \n";
    gotoxy(25,17); textcolor(BLACK); textbackground(WHITE); cout << " 4 - ATUALIZAR ALUNO \n";
    gotoxy(25,18); textcolor(BLACK); textbackground(WHITE); cout << " 5 - REMOVER ALUNO \n";
}

#endif
