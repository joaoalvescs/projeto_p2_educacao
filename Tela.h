#ifndef TELA_H_INCLUDED
#define TELA_H_INCLUDED
#include <iostream>

using namespace std;

void fundo(){
    textbackground(WHITE);
    system("cls");
    textbackground(WHITE);
    system("cls");
    textbackground(WHITE);
    textcolor(BLACK);
}

void esquerda(){
    int i;
    textbackground(WHITE);
    for (i=2;i<=43;i++){
        gotoxy(1,i); textbackground(8); printf("%c",186);
    }
}

void superior(){
    int i;
    textbackground(8); gotoxy(1,1); printf("%c",201);
    textbackground(8); gotoxy(133,1); printf("%c",187);
    for (i=2;i<=132;i++){
        gotoxy(i,1); printf("%c",205);
    }
}

void direita(){
    int i;
    textbackground(WHITE);
    textbackground(8); gotoxy(1,44); printf("%c",200);
    for (i=2;i<=43;i++){
        textcolor(BLACK);
        gotoxy(133,i); printf("%c",186);
    }
}

void inferior(){
    int i;
    textbackground(WHITE);
    gotoxy(2,43); textbackground(8); printf("                ");
    gotoxy(15,43); textbackground(8); printf("                                                       ");
    gotoxy(59,43); textbackground(8); printf("                                                         ");
    gotoxy(106,43); textbackground(8); printf("        "); gotoxy(115,43); textbackground(8); printf("                  ");
    for (i=2;i<=132;i++){
       gotoxy(i,42); textbackground(8); printf("%c",205);
    }
    gotoxy(133,44); textbackground(8); printf("%c",188);
    for (i=2;i<=132;i++){
       gotoxy(i,44); textbackground(8); printf("%c",205);
    }
    gotoxy(1,45); textbackground(WHITE); textcolor(WHITE); printf("                         ");
}

void bordas(){
   fundo();
   superior();
   esquerda();
   direita();
   inferior();
}

void cliente(){
    int i,j;
        for (i=16;i<=27;i++){
            gotoxy(i,9); printf("%c",205);
        }
        gotoxy(28,9);printf("%c",187);
        for (i=10;i<=12;i++){
            gotoxy(28,i); printf("%c",186);
        }
        gotoxy(28,13); printf("%c",188);
        gotoxy(15,9); printf("%c",201);
        for (i=10;i<=12;i++){
            gotoxy(15,i); printf("%c\n",186);
        }
        gotoxy(15,13); printf("%c",200);
        for (i=16;i<=27;i++){
            gotoxy(i,13); printf("%c",205);
        }
        for(i=16;i<=27;i++){

            for(j=10;j<=12;j++){
                    gotoxy(i,j);
                textbackground(8);
                printf(" ");
            }
        }
        gotoxy(18,11);
        printf("PRODUTOS");
}

void enfeite(){
    int i;
    gotoxy(15,43); textbackground(8); textcolor(BLACK); printf("1 - ALUNO");
    gotoxy(60,43); textbackground(8); textcolor(BLACK); printf("2 - PROFESSOR");
    gotoxy(105,43); textbackground(8); textcolor(BLACK); printf("3 - DISCIPLINA");
    for (i=2;i<=132;i++){
       gotoxy(i,42); printf("%c",205);
    }
    gotoxy(133,44); printf("%c",188);
    for (i=2;i<=132;i++){
       gotoxy(i,44); printf("%c",205);
    }
}

void enfeite3(){
    int i;
    gotoxy(60,43); textbackground(8); textcolor(BLACK); printf(" ");
    gotoxy(85,43); textbackground(8); textcolor(BLACK); printf(" ");
    for (i=2;i<=132;i++){
       gotoxy(i,42); printf("%c",205);
    }
    gotoxy(133,44); printf("%c",188);
    for (i=2;i<=132;i++){
       gotoxy(i,44); printf("%c",205);
    }
}

void aluno1(){
        int i,j;

        for (i=16;i<=27;i++){
            gotoxy(i,9); textbackground(8); printf("%c",205);
        }
        gotoxy(28,9);printf("%c",187);
        for (i=10;i<=12;i++){
            gotoxy(28,i); textbackground(8); printf("%c",186);
        }
        gotoxy(28,13); printf("%c",188);
        gotoxy(15,9); printf("%c",201);
        for (i=10;i<=12;i++){
            gotoxy(15,i); textbackground(8); printf("%c\n",186);
        }
        gotoxy(15,13); printf("%c",200);
        for (i=16;i<=27;i++){
            gotoxy(i,13); textbackground(8); printf("%c",205);
        }
        gotoxy(16,10); textbackground(8); printf("            ");
        gotoxy(16,12); textbackground(8); printf("            ");
        gotoxy(16,11); textbackground(8); printf("  ALUNO     ");
}

void professor1(){
    int i;
    int j;
        for (i=60;i<=71;i++){
            gotoxy(i,9); textbackground(8); printf("%c",205);
        }
        gotoxy(72,9);printf("%c",187);
        for (i=10;i<=12;i++){
            gotoxy(72,i); textbackground(8); printf("%c",186);
        }
        gotoxy(72,13); printf("%c",188);
        gotoxy(60,9); printf("%c",201);
        for (i=10;i<=12;i++){
            gotoxy(60,i); textbackground(8); printf("%c\n",186);
        }
        gotoxy(60,13); printf("%c",200);
        for (i=61;i<=71;i++){
            gotoxy(i,13); textbackground(8); printf("%c",205);
        }
        gotoxy(61,10); textbackground(8); printf("           ");
        gotoxy(61,12); textbackground(8); printf("           ");
        gotoxy(61,11); textbackground(8); printf("PROFESSOR  ");
}


void disciplina1(){
    int i,j;
        for (i=105;i<=116;i++){
            gotoxy(i,9); textbackground(8); printf("%c",205);
        }
        gotoxy(117,9);printf("%c",187);
        for (i=10;i<=12;i++){
            gotoxy(117,i); textbackground(8); printf("%c",186);
        }
        gotoxy(117,13); printf("%c",188);
        gotoxy(105,9); printf("%c",201);
        for (i=10;i<=12;i++){
            gotoxy(105,i); textbackground(8); printf("%c\n",186);
        }
        gotoxy(105,13); printf("%c",200);
        for (i=106;i<=116;i++){
            gotoxy(i,13); textbackground(8); printf("%c",205);
        }
        gotoxy(106,10); textbackground(8); printf("           ");
        gotoxy(106,12); textbackground(8); printf("           ");
        gotoxy(106,11); textbackground(8); printf("DISCIPLINA ");
}


void colunas(){
    int j;
    for (j=4;j<=41;j++){
        gotoxy(16,j); printf("%c",186);
    }
    for (j=4;j<=41;j++){
        gotoxy(23,j); printf("%c",186);
    }
    for (j=4;j<=41;j++){
        gotoxy(68,j); printf("%c",186);
    }
    for (j=4;j<=41;j++){
        gotoxy(78,j); printf("%c",186);
    }
    for (j=4;j<=41;j++){
        gotoxy(92,j); printf("%c",186);
    }
}



void aviso(){
    int i;
        gotoxy(39,15); printf("%c",201);
        gotoxy(39,25); printf("%c",200);
        gotoxy(91,15); printf("%c",187);
        gotoxy(91,25); printf("%c",188);
        for (i=16;i<=24;i++){
            gotoxy(40,i); printf("                                                   ");
        }
        for (i=40;i<=90;i++){
            gotoxy(i,15); printf("%c",205);
        }
        for (i=40;i<=90;i++){
            gotoxy(i,25); printf("%c",205);
        }
        for (i=16;i<=24;i++){
            gotoxy(39,i); printf("%c",186);
        }
        for (i=16;i<=24;i++){
            gotoxy(91,i); printf("%c",186);
        }
}

void aviso1(){
    int i;
        textcolor(0); textbackground(RED);
        gotoxy(39,15); printf("%c",201);
        gotoxy(39,25); printf("%c",200);
        gotoxy(91,15); printf("%c",187);
        gotoxy(91,25); printf("%c",188);
        for (i=16;i<=24;i++){
            gotoxy(40,i); printf("                                                   ");
        }
        for (i=40;i<=90;i++){
            gotoxy(i,15); printf("%c",205);
        }
        for (i=40;i<=90;i++){
            gotoxy(i,25); printf("%c",205);
        }
        for (i=16;i<=24;i++){
            gotoxy(39,i); printf("%c",186);
        }
        for (i=16;i<=24;i++){
            gotoxy(91,i); printf("%c",186);
        }
        textcolor(0); textbackground(8);
        gotoxy(39,15); printf("%c",201);
        gotoxy(39,25); printf("%c",200);
        gotoxy(91,15); printf("%c",187);
        gotoxy(91,25); printf("%c",188);
        for (i=16;i<=24;i++){
            gotoxy(40,i); printf("                                                   ");
        }
        for (i=40;i<=90;i++){
            gotoxy(i,15); printf("%c",205);
        }
        for (i=40;i<=90;i++){
            gotoxy(i,25); printf("%c",205);
        }
        for (i=16;i<=24;i++){
            gotoxy(39,i); printf("%c",186);
        }
        for (i=16;i<=24;i++){
            gotoxy(91,i); printf("%c",186);
        }
}

void telamenu(){
   fundo();
   superior();
   esquerda();
   aluno1();
   professor1();
   disciplina1();
   direita();
   inferior();
   enfeite();
}

void telafim(){
   int i;
   fundo();
   superior();
   esquerda();
   direita();
   inferior();
   for (i=0;i<=10;i++){
        aviso1();
   }
}

void telaaviso(){
   fundo();
   superior();
   esquerda();
   aviso();
   direita();
   inferior();
}

void tela(){
    fundo();
    superior();
    esquerda();
    direita();
    inferior();
}


#endif
