/**
* mwcrsr -- реализует перемещение курсора
*
* Copyright (c) 2018, Mokerova Daria <mokerova@petrsu.ru>
*
* This code is licensed under a MIT-style license.
*/

#include "common.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

void m(text txt, int index, int cursor);

static void mwef_c(int index, char *contents, int cursor, void *data);

void mwef(text txt)
{

    process_forward(txt, mwef_c, txt);
    
}

/* функция ставящая курсор в конец слова, если это возможно */

static void mwef_c(int index, char *contents, int cursor, void *data) {

    /* Находим позицию, на которую нужно поставить наш курсор */
    
    for(unsigned i = cursor; !isspace(contents[i]) && i < strlen(contents); i++)
{ 
cursor++; 
} 
    m((text)data, index+1, cursor+1);
}

