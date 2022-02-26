#ifndef TESTING_H_INCLUDED
#define TESTING_H_INCLUDED

int f_numarDeDate(); //Citeste numar de date din fisier

int verficare_parola_admin(); //Citeste si verifica parola data de admin pentru a introduce noi date

void programare_date(char date[][11]); //Verfica daca data introdusa este disponibila si o scrie ca programata

void sterge_date(char date[][11], char s[11]); //Sterge datele programate din fisierul de date disponibile

void afisare_date_disponibile(char date[][11]); //Afiseaza datele disponibile pentru programare

void citire_date(char date[][11]);/*Citeste datele din fisier, linie cu linie si pe introduce intr-un
                                        vector de char uri*/

void introducere_date(char date[][11]); //Permite admin ului sa introduca noi date dispponibile

void afisare_date_programate(char date_programate[][11]); //Afiseaza datele programate



#endif // TESTING_H_INCLUDED
