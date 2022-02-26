#ifndef DECLARARI_H_INCLUDED
#define DECLARARI_H_INCLUDED

typedef struct
{
    char nume[50],prenume[50];
    int admin;
    int masina_id;
    char user[50],parola[50];

} persoana;

typedef struct
{
    char nume[50],marca[50];
    int pret, nrstoc;
} masina;


masina car[30];
int nrmasini;

persoana pers[200];
int nrpers;
float euro;

#endif // DECLARARI_H_INCLUDED
