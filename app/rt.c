/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Mokerova Daria <mokerova@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"
#define  MAX 1024


static void rt_line(int index, char *contents, int cursor, void *data);


int q=0;
void rt(text txt)
{
    q=0;
    
    process_forward(txt, rt_line, NULL);
    
    /* вызываем функцию по удалению нужной строки */
    
    delete_line(txt,q);
}

static void rt_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);


    /* Декларируем неиспользуемые параметры */


    UNUSED(data);
    UNUSED(index);
    UNUSED(cursor);
    q++;

}
