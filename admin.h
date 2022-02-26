#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "declarari.h"


void afisare_admin(persoana m,int nrpers);
void afisare_useri(persoana pers[20],int nrpers);///pers- vector de persoane
void alegere(int optiune,persoana m,int nrpers);
void revocare_admin(persoana m);
void revocare_admin();
void adaugare_masina();
void afisare_car();
void suplimentare_stoc();
void pret_masina();
void suplimentare_stoc();
void schimbare_euro();
void salvare_date();
void salvare_masini();
#endif // ADMIN_H_INCLUDED
