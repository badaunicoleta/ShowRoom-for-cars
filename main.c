#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
/////////////////////
#include "client.h"
#include "testing.h"
#include "admin.h"
#include "login.h"
////////////////////

int main()
{
    nrpers=citire_persoane();
    nrmasini=citire_masina();

    Logare_Inregistrare();

    return 0;
}
