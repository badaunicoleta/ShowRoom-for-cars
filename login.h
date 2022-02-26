#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#define MAX_USERNAME 10
#define MAX_PASSWORD 20

#define USER_NOT_FOUND "Username nu exista"
#define DUPLICATE_USER "Va rugam sa alegeti alt nume de utilizator!"
#define INCORRECT_PASSWORD "Parola incorecta!"

#define ERROR_PASSWORD_LONG "Parola trebuie sa contina cel putin 7 caractere"
#define ERROR_PASSWORD_NOT_USERNAME "Parola trebuie sa nu contina numele de  utilizator"
#define ERROR_PASSWORD_SPECIAL_CHAR "Parola trebuie sa contina unul din urmatoarele caractere: {'.','_','!','?'}"
#define ERROR_PASSWORD_DIGITS "Parola trebuie sa contina cifre"
#include <stdbool.h>



void Logare_Inregistrare(); /*Functie care inglobeaza functiile de verificare user/parola
                              Apeleaza functiile din admin.h, respectiv client.h*/


int validareUsername(char username[10]);
int validareParola(char  parola[20], char username[10]);
int lungime(char  parola[20]);
int nuContineUsername(char  parola[20],char username[10]);
int contineCaractereSpeciale(char parola[20]);
int contineCifre(char parola[10]);
void ParolaNouaIncorecta(char  parola[20], char username[10]);

void citire_parola(char parola[20]); // Permite scrierea parolei cu caractere * pentru ascunderea parolei


#endif //LOGIN_H_INCLUDED
