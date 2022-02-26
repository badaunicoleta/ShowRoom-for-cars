#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED
#include "declarari.h"


void afisare_client(persoana m,int id_pers);
int  citire_persoane();
void afisare_masini();
void stergere_comanda(persoana m,int id_pers);
void alegere_client(persoana m,int alegere,int id_pers);
void date_contact(persoana m,int id_pers);
void cumparare_masina(persoana m,int id_pers);
int  citire_masina();
void afisare_testing();
void informatii_companie();
void masina_cumparata(int id_pers);
#endif // CLIENT_H_INCLUDED
