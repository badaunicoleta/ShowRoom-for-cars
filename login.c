#include "login.h"
#include "admin.h"
#include "client.h"
#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include <windows.h>
#include <conio.h>
#include "declarari.h"



int validareUsername(char username[10])
{

    if(strcmp(username,"admin")==0)
        return 1;
    return 0;
}
int validareParola(char parola[20], char username[10])
{
    if(lungime(parola) && nuContineUsername(parola, username)&& contineCaractereSpeciale(parola)&& contineCifre(parola))
        return 1;
    return 0;

}
int lungime(char parola[20])
{
    if(strlen(parola)>=7)
        return 1;
    return 0;

}
int nuContineUsername(char parola[20],char username[10])
{
    if(!strstr(parola, username))
        return 1;
    return 0;
}
int contineCaractereSpeciale (char parola[20])
{

    if(strpbrk(parola, ".,_!"))
        return 1;
    return 0;

}
int contineCifre(char parola[20])
{
    if(strpbrk(parola,"0123456789"))
        return 1;
    return 0;
}
void ParolaNouaIncorecta(char parola[20], char username[10])
{
    if(!lungime(parola))
        printf("%s\n", ERROR_PASSWORD_LONG);
    if(!nuContineUsername(parola,username))
        printf("%s\n", ERROR_PASSWORD_NOT_USERNAME);
    if(!contineCaractereSpeciale(parola))
        printf("%s\n", ERROR_PASSWORD_SPECIAL_CHAR);
    if(!contineCifre(parola))
        printf("%s\n", ERROR_PASSWORD_DIGITS);

}

void citire_parola(char parola[20])
{
    int index = 0;
    do
    {
        parola[index]=getch();
        if((parola[index]!='\r'))
        {
            if(parola[index]=='\b')
            {
                printf("\b \b");
                parola[index-1] = '\0';
                index--;
            }
            else
            {
                printf("*");
                index++;
            }

        }

    }
    while(parola[index]!='\r');
    parola[index]='\0';

}

void Logare_Inregistrare()
{
    int index_alternativ = 0;
    int log_in=0;
    int login_choice = 0;
    char username[10], parola[20];
    int choice;

    while(log_in == 0)
    {
        switch (login_choice)
        {
        case 0:
            printf("///////////////////////////////////////////////////////////////\n");
            printf("///////////////////////////////////////////////////////////////\n");
            printf("///////////////////                 ///////////////////////////\n");
            printf("///////////////////  YOUR SHOWROOM  ///////////////////////////\n");
            printf("///////////////////                 ///////////////////////////\n");
            printf("///////////////////////////////////////////////////////////////\n");
            printf("///////////////////////////////////////////////////////////////\n");
            printf("\n\n");
            printf("Bine ati venit! Pentru a continua este necesar sa va logati.\n");
            printf("In cazul in care nu aveti un cont este necesar sa va inregistrati.\n");
            printf("Va rugam alegeti o optiune dintre urmatoarele.\n");
            printf(" a) Logare\n b) Utilizator nou\n");
            choice = getchar() - 'a' + 1;
            getchar();
            login_choice += choice;
            break;

        case 1:
            printf("Introduceti username: \n");
            scanf("%s",username);

            int user_gasit = 0;
            int user_index = 0;
            for(int i=0; i< nrpers; i++)
            {
                if(strcmp(pers[i].user, username) == 0)
                {
                    user_gasit = 1;
                    user_index = i;
                }
            }
            if(user_gasit == 1)
            {
                printf("Introduceti parola: \n");
                citire_parola(parola);
                if(strcmp(pers[user_index].parola, parola) == 0)
                {
                    printf("\nV-ati logat cu succes!\n");
                    Sleep(600);
                    log_in = 1;
                    system("cls");
                    index_alternativ = user_index;
                    break;
                }
                else
                {
                    printf("Parola incorecta\n");
                    break;
                }
            }
            else
            {
                printf("Utilizator inexistent\n\n");
                break;
            }
            break;

        case 2:

            printf("Introduceti username: \n");
            scanf("%s",username);
            int ok = 1;
            for(int i=0; i< nrpers; i++)
            {

                if(strcmp(pers[i].user, username) == 0)
                {
                    printf("User deja existent\n");
                    ok=0;
                    break;
                }
            }
            if(ok == 1)
            {
                printf("Introduceti parola: \n");
                citire_parola(parola);

                printf("\n");

                if(validareParola(parola, username) == 1)
                {
                    printf("\nV-ati inregistrat cu succes!\n");
                    Sleep(600);
                    log_in = 1;
                    system("cls");
                    index_alternativ = nrpers;
                    printf("Va rugam introduceti numele si prenumele dvs.\n");
                    scanf("%s %s", pers[nrpers].nume, pers[nrpers].prenume);
                    pers[nrpers].admin = 2;
                    pers[nrpers].masina_id = -1;
                    strcpy(pers[nrpers].user, username);
                    strcpy(pers[nrpers].parola, parola);
                    nrpers++;
                    break;
                }
                else
                {
                    ParolaNouaIncorecta(parola, username);
                }
                break;
            }

        }
    }
    if(pers[index_alternativ].admin == 2)
    {
        afisare_client(pers[index_alternativ],index_alternativ);
    }
    else
        afisare_admin(pers[index_alternativ],nrpers);
}




