#include "admin.h"
#include "login.h"
#include "testing.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>




void salvare_date()
{
    ///PERSOANE
    FILE *fp=fopen("persoane.in","w");
    fprintf(fp,"%d",nrpers);
    fprintf(fp,"%s","\n");
    int i;
    for(i=0; i<nrpers; i++)
    {
        fprintf(fp,"%s",pers[i].prenume);
        fprintf(fp,"%s"," ");

        fprintf(fp,"%s",pers[i].nume);
        fprintf(fp,"%s"," ");

        fprintf(fp,"%d",pers[i].admin);
        fprintf(fp,"%s"," ");

        fprintf(fp,"%d",pers[i].masina_id);
        fprintf(fp,"%s"," ");

        fprintf(fp,"%s",pers[i].user);
        fprintf(fp,"%s"," ");

        fprintf(fp,"%s",pers[i].parola);
        fprintf(fp,"%s","\n");


    }
    fclose(fp);




}

void salvare_masini()
{
    int i;
    ///Masini
    FILE *fp1;
    fp1=fopen("masini.in","w");
    fprintf(fp1,"%f",euro);
    fprintf(fp1,"%s","\n");
    fprintf(fp1,"%d",nrmasini);
    fprintf(fp1,"%s","\n");
    for(i=0; i<nrmasini; i++)
    {
        fprintf(fp1,"%s",car[i].nume);
        fprintf(fp1,"%s"," ");

        fprintf(fp1,"%s",car[i].marca);
        fprintf(fp1,"%s"," ");

        fprintf(fp1,"%d",car[i].pret);
        fprintf(fp1,"%s"," ");

        fprintf(fp1,"%d",car[i].nrstoc);
        fprintf(fp1,"%s","\n");


    }
    fclose(fp1);

}



void afisare_useri(persoana pers[20],int nrpers)///pers- vector de persoane
{
    for(int i=0; i<nrpers; i++)
    {
        printf("\n");
        printf("User %d: %s %s\n",i,pers[i].prenume,pers[i].nume);
        printf("Statut: ");
        if(pers[i].admin==0)
            printf("Detinator al platformei.");
        else if(pers[i].admin==1)
            printf("Administrator.");
        else
            printf("Client.");

    }
    printf("\n");
}



void afisare_admin(persoana m,int nrpers)
{
    salvare_date();
    salvare_masini();
    printf("\nBine ati venit %s %s\n",m.prenume,m.nume);
    printf("Ce operatiuni doriti sa efectuati?\n");
    printf("1.Afisati userii existenti.\n");///merge
    printf("2.Acordati statut de administrator.\n");
    printf("3.Revocati statutul unui administrator(doar pentru detinatori).\n");
    printf("4.Adaugati o data in calendarul de programari testdrive.\n");
    printf("5.Adaugati un nou model de masina.\n");
    printf("6.Afisati toate modelele de masini.\n");
    printf("7.Schimbati pretul unei masini.\n");
    printf("8.Suplimentati stocul unei masini existente.\n");
    printf("9.Introduceti valoarea actuala a unui euro.\n");
    printf("10.Deconectare.\n");
    int optiune;
    scanf("%d",&optiune);
    getchar();
    if(optiune<=10&&optiune>0)
    {
        system("cls");
        alegere(optiune,m,nrpers);
    }
    else
    {
        printf("Optiune invalida, reintroduceti optiunea (trebuie sa fie cuprinsa intre 1 si 10)\n");
        afisare_admin(m,nrpers);
    }



}
void acordare_admin()
{
    printf("Numarul userului pe care doriti sa il promovati la rank-ul de administrator:");
    int numar;
    scanf("%d",&numar);
    while(numar>=nrpers)
    {
        printf("Reintroduceti. Valoarea trebuie sa fie mai mica decat %d.\n",nrpers);
        scanf("%d",&numar);
    }
    if(pers[numar].admin==2)
    {
        pers[numar].admin=1;
        printf("Userul este acum administrator.");
    }
    else if(pers[numar].admin==1)
        printf("Userul este deja administrator al platformei.");
    else if(pers[numar].admin==0)
        printf("Imposibil. Persoana va este superioara in rank.");
    printf("\n");
    printf("Apasati orice tasta pentru a reveni la meniu.");
    getch();
    system("cls");
}
void suplimentare_stoc()
{
    printf("\n ID-ul masinii pentru care doriti sa suplimentati stocul este:");
    int id,nrstoc;
    scanf("%d",&id);
    printf("\n Numarul de masini cu care se sumplimenteaza stocul este:");
    scanf("%d",&nrstoc);
    car[id].nrstoc=nrstoc+car[id].nrstoc;
    printf("Succes\n");
}
void revocare_admin(persoana m)
{
    if(m.admin==0)
    {
        printf("Atentie. Pentru a putea retrograda pe cineva aceasta trebuie sa aiba un rang inferior sau egal cu al dumneavoastra.\n");
        printf("Persoana pe care doriti sa o retrogadati are ID-ul? :");
        int numar;
        scanf("%d",&numar);
        int rang;
        printf("Rangul pe care doriti sa il acordati este:  ");
        printf("(2- User,1-Administrator| Este posibila doar retrogradarea). \n");
        scanf("%d",&rang);
        while(rang!=1&&rang !=2)
        {
            printf("Valoare invalida. Reintroduceti");
            scanf("%d",&rang);
        }



        if(pers[numar].admin==0)
            printf("Operatiune imposibila. Persoana detine serverul.");
        else if(rang==1&&pers[numar].admin==1)
            printf("Userul este deja administrator. Nu il puteti retrograda la acelasi grad./n");
        else if(rang==0)
            printf("Nu puteti retrograda pe cineva la rangul de detinator al serverului.");
        else if(rang==2&&pers[numar].admin==2)
        {
            pers[numar].admin=2;
            printf("Nu puteti retrodraga pe cineva la acelasi statut./n" );
        }
        if(pers[numar].admin==1&&rang==2)
        {
            pers[numar].admin=2;
            printf("Administratorul %s %s are acum statutul de user.\n",pers[numar].prenume,pers[numar].nume);
        }
    }
    else
        printf("Drepturi insuficiente. Trebuie sa detineti platforma.\n");

    printf("Apasati orice tasta pentru a reveni la meniu.");
    getch();
    system("cls");
}

void adaugare_masina()
{
    printf("Marca masinii pe care doriti sa o adaugati:");
    scanf("%s",car[nrmasini].marca);
    printf("\n Numele masini pe care doriti sa o adaugati:");
    scanf("%s",car[nrmasini].nume);
    printf("\n Pretul masinii:");
    scanf("%d",&car[nrmasini].pret);
    printf("\n Cate masini vor fi in stoc?:");
    scanf("%d",&car[nrmasini].nrstoc);
    printf("Ati adaugat cu succes masina cu marca:%s modelul: %s.\n",car[nrmasini].marca,car[nrmasini].nume);
    printf("Pretul acesteia este %d de euro, iar in stoc avem %d exemplare.\n",car[nrmasini].pret,car[nrmasini].nrstoc);
    printf("\nApasati orice tasta pentru a reveni la meniu.");
    nrmasini++;
    getch();
    system("cls");

}

void pret_masina()
{
    printf("ID-ul masinii careia doriti sa ii schimbati pretul: ");
    int id;
    scanf("%d",&id);
    while(id>=nrmasini||id<0)
    {
        printf("Reintroduceti.\n");
        scanf("%d",&id);
    }
    int pret;
    printf("Introduceti noul pret al masinii: ");
    scanf("%d",&pret);
    car[id].pret=pret;
    printf("Noul pret al masinii %s %s este: %d de euro \n",car[id].marca, car[id].nume,car[id].pret);
    printf("Apasati orice tasta pentru a reveni la meniu.");
    getch();
    system("cls");
}

void afisare_car()
{
    printf("\n");
    for(int i=0; i<nrmasini; i++)
    {
        printf("\n ID-ul masinii: %d ",i);
        printf("  Marca:  ");
        printf("%s",car[i].marca);
        printf("  Numele:  ");
        printf("%s",car[i].nume);
        printf("  Pretul:  ");
        printf("%d",car[i].pret);
        printf("  Numar de exemplare in stoc:  ");
        printf("%d",car[i].nrstoc);
        printf("\n");
    }
    printf("\n");
    printf("Apasati orice tasta pentru a reveni la meniu.");
    getch();
    system("cls");
}
void schimbare_euro()
{
    printf("Pretul din sistem al monedei euro este: %f .\n",euro);
    printf("Noul pret al monedei euro este: ");
    float euronou;
    scanf("%f",&euronou);
    euro=euronou;
    printf("\n Noua valoare din sistem a monedei euro este: %f .\n",euro);
    printf("Apasati orice tasta pentru a reveni la meniu.");
    getch();
    system("cls");
}
void alegere(int optiune,persoana m,int nrpers)
{

    switch(optiune)
    {
    case 1:
    {
        afisare_useri(pers,nrpers);
        afisare_admin(m,nrpers);

    }
    case 2  :
    {
        acordare_admin();
        afisare_admin(m,nrpers);

    }
    case 3 :
    {
        revocare_admin(m);
        afisare_admin(m,nrpers);

    }
    case 4 :
    {
        char date[365][11];
        citire_date(date);
        int validare = 0;

        while(validare == 0)
        {
            validare = verficare_parola_admin();
            if (validare == 1)
                introducere_date(date);
        }
        Sleep(400);
        system("cls");
        afisare_admin(m,nrpers);
        break;
    }
    case 5 :
    {
        adaugare_masina();
        afisare_admin(m,nrpers);
        break;
    }
    case 6 :
    {
        afisare_car();
        afisare_admin(m,nrpers);

    }
    case 7 :
    {
        pret_masina();
        afisare_admin(m,nrpers);

    }
    case 8 :
    {
        suplimentare_stoc();
        printf("\nApasati orice tasta pentru a continua.");
        getch();
        system("cls");
        afisare_admin(m,nrpers);

    }
    case  9 :
    {
        schimbare_euro();
        afisare_admin(m,nrpers);

    }
    case 10 :
    {
        Logare_Inregistrare();
    }
    }
}


