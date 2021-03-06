#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "client.h"
#include "testing.h"
#include "admin.h"
#include "login.h"

int  citire_persoane()/// da numarul de afisare ca si return
{
    FILE *fp;
    int i;
    int nr;
    fp=fopen("persoane.in","r+");
    fscanf(fp,"%d",&nr);
    for(i=0; i<nr; i++)
    {
        fscanf(fp,"%s",pers[i].prenume);

        fscanf(fp,"%s",pers[i].nume);

        fscanf(fp,"%d",&pers[i].admin);

        fscanf(fp,"%d",&pers[i].masina_id);

        fscanf(fp,"%s",pers[i].user);

        fscanf(fp,"%s",pers[i].parola);


    }
    fclose(fp);
    return nr;
}

int  citire_masina()
{
    FILE *fp;
    int i;
    int nr;
    fp=fopen("masini.in","r+");
    fscanf(fp,"%f",&euro);
    fscanf(fp,"%d",&nr);
    for(i=0; i<nr; i++)
    {
        fscanf(fp,"%s",car[i].nume);

        fscanf(fp,"%s",car[i].marca);

        fscanf(fp,"%d",&car[i].pret);

        fscanf(fp,"%d",&car[i].nrstoc);


    }
    return nr;
    fclose(fp);
}



void afisare_testing()
{
    char date[365][11];
    char date_programate[365][11];

    char    choice;

    printf("Apasa a pentru a afisa datele disponibile.\n");
    printf("Apasa b pentru a face o programare.\n");
    printf("Apasa c pentru a afisa datele programate.\n");
    printf("Apasa d pentru a iesi.\n");
    printf("\nAlegeti optiunea: ");
    scanf(" %c", &choice);
    while (choice != 'd')
    {
        citire_date(date);
        switch (choice)
        {
        case 'a':
            printf("\n");
            afisare_date_disponibile(date);
            break;
        case 'b':
            printf("\n");
            programare_date( date);
            break;
        case 'c':
            printf("\n");
            afisare_date_programate(date_programate);

            break;

        default:
            printf("\n");
            printf("Invalid choice.");

            break;
        }

        printf("\n\nApasa a pentru a afisa datele disponibile.\n");
        printf("Apasa b pentru a face o programare.\n");
        printf("Apasa e pentru a afisa datele programate.\n");
        printf("Apasa d pentru a iesi.\n");
        printf("\nAlegeti optiunea: ");
        scanf(" %c", &choice);
    }
}


void afisare_client(persoana m,int id_pers)
{
    system("cls");
    salvare_date();
    salvare_masini();
    printf("Bine ati venit %s %s .\n",m.prenume,m.nume);
    printf("Cu ce va putem ajuta?\n");
    printf("1.Vedeti masinile disponibile.\n");
    printf("2.Cumparati o masina.\n");
    printf("3.Sterge comanda.\n");
    printf("4.Ce masina am comandat si cat am de platit?\n");
    printf("5.Inscrierea pentru testdrive.\n");
    printf("6.Contactare administratie/mentenanta.\n");
    printf("7.Detalii companie.\n");
    printf("8.Delogare.\n");
    int alegere;
    scanf("%d",&alegere);
    getchar();
    if(alegere<=8&&alegere>=1)
        alegere_client(m,alegere,id_pers);
    else

    {
        printf("Alegere incorecta. Trebuie sa alegeti un numar intre 1 si 8.");
        printf("/nApasati orice tasta pentru a continua.");
        getch();
        afisare_client(m,id_pers);
    }
}

void cumparare_masina(persoana m,int id_pers)
{
    printf("Care este ID-ul masinii pe care doriti sa o achizitionati?(Va puteti achizitiona doar o masina.)\n");
    int ID;
    scanf("%d",&ID);
    while(ID>nrmasini||ID<0)
    {
        printf("Valoarea trebuie sa fie mai mica decat %d .Reintroduceti. \n",nrmasini);
        scanf("%d",&ID);
    }


    printf("\nSunteti sigur ca doriti sa achizitionati masina %s %s? Aceasta costa %d de euro(y(yes)/n(no)).",car[ID].marca,car[ID].nume,car[ID].pret);
    char raspuns[50];
    scanf("%s",raspuns);
    while(strcmp(raspuns,"y")!=0&&strcmp(raspuns,"n")!=0)
    {
        printf("/nRaspuns invalid. Reintroduceti.");
        scanf("%s",raspuns);
    }
    if(strcmp(raspuns,"y")==0&&pers[id_pers].masina_id==-1&&car[ID].nrstoc!=0)
    {
        pers[id_pers].masina_id=ID;
        printf("Felicitari, tocmai ati achizitionat %s %s in valoare de %d de euro. Va multumim!\n",car[ID].marca,car[ID].nume,car[ID].pret);
        printf("\nApasati orice tasta pentru a continua.");
        car[ID].nrstoc--;
        getch();
        system("cls");
        afisare_client(m,id_pers);
    }
    else
    {
        if(pers[id_pers].masina_id!=-1)
            printf("Imposibil, aveti deja o masina cumparata.\n");
        else if(car[ID].nrstoc==0)
        {
            printf("Imposibil, nu mai avem aceasta masina pe stoc.\n");
        }
        printf("Ce doriti sa faceti in continuare? \n");
        printf("1.Reincercati.\n");
        printf("2.Reveniti la meniul principal.\n");
        int choose;
        scanf("%d",&choose);
        while(choose!=2&&choose!=1)
        {
            printf("Alegere invalida. Reincercati.\n");
            scanf("%d",&choose);
        }
        if(choose==1)
            cumparare_masina(m,id_pers);
        else if(choose==2)
        {
            system("cls");
            afisare_client(m,id_pers);
        }
    }
    printf("Apasati orice tasta pentru a reveni la meniu.");
    getch();
    system("cls");
}

void afisare_masini()
{
    system("cls");
    int i;
    for(i=0; i<nrmasini; i++)
    {

        printf("\n");
        printf("Masina cu ID-ul %d este: %s %s ",i,car[i].marca,car[i].nume);
        printf("\nPretul este de %d de euro.",car[i].pret);
        (car[i].nrstoc>0)? printf("\nDisponibila in stoc"):printf("\nAceasta masina nu este disponibila decat la comanda. ");
        printf("\n");

    }
    printf("Apasati orice tasta pentru a reveni la meniu.");
    getch();
    system("cls");
}

void date_contact(persoana m,int id_pers)
{
    char numar[15]="0771481731";
    char numar2[15]="0771434112";
    printf("Pentru a raporta disfunctionalitati ale platformei, apelati numarul %s.\n",numar);
    printf("Pentru reclamatii apelati numarul de telefon %s .\n",numar2);
    printf("Apasati orice tasta pentru a reveni la meniul principal.");
    getch();
    system("cls");
    afisare_client(m,id_pers);
    printf("Apasati orice tasta pentru a reveni la meniu.");
    getch();
    system("cls");
}
void  stergere_comanda(persoana m,int id_pers)
{
    if(pers[id_pers].masina_id==-1)
        printf("Trebuie sa aveti o masina comandata pentru a va sterge comanda.\n");
    else
    {
        printf("Sunteti sigur ca doriti sa anulati comanda dumneavoastra?\n");
        printf("Comanda dumneavoastra este: %s %s in valoare de %d de euro.",car[pers[id_pers].masina_id].marca,car[pers[id_pers].masina_id].nume,car[pers[id_pers].masina_id].pret);
        printf("\n (y/n)");

        char raspuns[50];
        scanf("%s",raspuns);

        while(strcmp(raspuns,"y") != 0 && strcmp(raspuns,"n") != 0)
        {
            printf("/nRaspuns invalid. Reintroduceti.");
            scanf("%s",raspuns);
        }

        if(strcmp(raspuns,"y")==0)
        {
            printf("Comanda anulata cu succes. Acum puteti comanda alta masina.\n");
            car[pers[id_pers].masina_id].nrstoc++;
            pers[id_pers].masina_id=-1;

        }

        printf("Apasati orice tasta pentru a reveni la meniul pricipal.\n");

        getch();
        system("cls");

        //afisare_client(m,id_pers);

    }
}
void informatii_companie()
{
    printf("Numele platformei este: CarsRo.");
    printf("\nAdresa:");
    printf(" Strada Motilor nr. 34, localitatea Sibiu, judetul Sibiu, Romania.\n");
    printf("Numar secretariat: 0771431791.");
    printf("\nData infiintarii: 12.01.2009.");
    printf("\nCEO's: Badau Nicoleta, Popa Laurentiu si Clotan Paul.");
    printf("\n\n\nApasati orice tasta pentrua continua.");
    getch();
    system("cls");
}
void masina_cumparata(int id_pers)
{
    if(pers[id_pers].masina_id!=-1)
    {
        float pret2=car[pers[id_pers].masina_id].pret*euro;
        printf("Ati comandat masina %s %s in valoare de %d de euro(%f de lei).",car[pers[id_pers].masina_id].marca,car[pers[id_pers].masina_id].nume,car[pers[id_pers].masina_id].pret,pret2);
        printf("\nPretul masinii este cel final(include toate taxele necesare cumpararii+TVA)\n");
        printf("Veti putea intra in posesia masinii in maxim 3 luni de la data cumpararii.\nPentru detalii cu privire la livrare va rugam sunati la secretariat.");
    }
    else
        printf("Nu aveti nici o masina comandata. Va puteti achizitiona una din Meniul principal->Cumparati o masina.\n");
    printf("\n");
    printf("Apasati orice tasta pentru a reveni la meniul principal.");
    getch();
    system("cls");
}
void alegere_client(persoana m,int alegere,int id_pers)
{
    switch(alegere)
    {


    case 1 :
    {
        afisare_masini();
        afisare_client(m,id_pers);
    }
    case 2:
    {
        cumparare_masina(m,id_pers);
    }
    case 3:
    {
        stergere_comanda(m,id_pers);
        afisare_client(m,id_pers);
    }
    case 4 :
    {
        masina_cumparata(id_pers);
        afisare_client(m,id_pers);
    }
    case 5 :
    {
        afisare_testing();
        afisare_client(m,id_pers);
    }
    case 6 :
    {
        date_contact(m,id_pers);
        afisare_client(m,id_pers);
    }
    case 7:
    {
        informatii_companie();
        afisare_client(m,id_pers);
    }
    case 8:
    {
        Sleep(150);
        system("cls");
        Logare_Inregistrare();
    }
    }
}
