#include <stdio.h>
#include <string.h>

char line[11];
char line_second[11];//linii date programate

int verficare_parola_admin()
{
    char parola[]="sunt_admin";
    char parola_data[20];
    printf("Introduceti parola: ");
    scanf("%s",parola_data);

    if(strcmp(parola,parola_data)==0)
        return 1;
    else
        return 0;

}

void citire_date(char date[][11])

{
    FILE *data_d;
    data_d = fopen("date_disponibile", "r");
    int j=0;
    while(fscanf(data_d, "%[^\n]\n", line) > 0)
    {
        if(strlen(line) == 10)
        {
            strcpy(date[j], line);
            j++;
        }
    }
    fclose(data_d);
}

int f_numarDeDate()
{
    int numar = 0;
    FILE *data_d;
    data_d = fopen("date_disponibile", "r");

    while(fscanf(data_d, "%[^\n]\n", line) > 0)
    {
        if(strlen(line) == 10)
            numar++;
    }
    fclose(data_d);

    return numar;
}

void afisare_date_disponibile(char date[][11])

{
    int index = f_numarDeDate();

    if(index == 0)
        printf("Nicio data disponibila!");

    else
    {
        for(int i = 0; i < index; i++)
        {
            printf("%s\n", date[i]);
        }
    }
}

void afisare_date_programate(char date_programate[][11])

{
    FILE *data_p;
    data_p = fopen("date_programate", "r");

    int k=0;
    while(fscanf(data_p, "%[^\n]\n", line_second) > 0)
    {
        if(strlen(line_second) == 10)
        {
            strcpy(date_programate[k], line_second);
            k++;
        }
    }

    if(k == 0)
        printf("Nicio data programata!");

    else
    {
        for(int l = 0; l < k; l++)
        {
            printf("%s\n", date_programate[l]);
        }
    }

    fclose(data_p);

}

void sterge_date( char data[][11],char s[11] )
{
    FILE *data_d;
    int index = 0;
    index = f_numarDeDate();

    data_d = fopen("date_disponibile", "w");
    for(int i = 0; i < index; i++)
    {
        if(strcmp(data[i], s) != 0)
            fprintf(data_d, "%s\n", data[i]);
    }
    fclose(data_d);
}


void programare_date( char date[][11])
{
    char s[11];

    FILE *data_d, *data_p;
    data_d = fopen("date_disponibile", "r");
    data_p = fopen("date_programate", "a");


    int index = f_numarDeDate();

    printf("Introduceti o data:\n");
    scanf("%s", s);

    int ok = 0;
    for(int i = 0; i < index; i++)
    {
        if(strcmp(date[i], s) == 0)
        {
            ok = 1;
        }
    }
    if(ok == 1)
    {
        printf("Data este disponibila\n");
        fprintf(data_p,"%s\n",s);
        sterge_date(date,s);
        fclose(data_d);
        printf("Data programata cu succes!\n");

    }
    else
    {
        printf("Data nu e disponibila\n");
    }

    fclose(data_p);
}


void introducere_date(char date[][11])
{
    char s[11];

    FILE *data_d ;
    data_d = fopen("date_disponibile", "a+");

    int index = f_numarDeDate();

    printf("Introduceti o noua data in calendar:\n");
    scanf("%s", s);

    int ok = 0;
    for(int i = 0; i < index; i++)
    {
        if(strcmp(date[i], s) == 0)
        {
            ok = 1;
        }
    }

    if(ok == 1)
    {
        printf("Data deja prezenta in calendar\n");

    }
    else
    {
        fprintf(data_d,"%s\n",s);
        printf("Data introdusa cu succes!");
    }

    fclose(data_d);
}
