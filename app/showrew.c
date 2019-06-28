/**
 * show.c -- реализует команду вывода хранимого текста на экран
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

#define  MAX 1024


static void showrew_line(int index, char *contents, int cursor, void *data);

/**
 * Выводит содержимое указанного файла на экран
 */
int k=0;
void showrew(text txt)
{
    k=0;
    char* sesh[MAX];
    process_forward(txt, showrew_line, sesh);

    for (int i=k-1; i>=0; i--){
	printf("%s", sesh[i]);
	
    }
    	printf("\n");
}
/**

 * Выводит содержимое указанного файла на экран
 */
static void showrew_line(int index, char *contents, int cursor, void *data)
{
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    
    
    char** sesh = (char**)data;
    UNUSED(index);
    UNUSED(cursor);
    sesh[k]=contents;
    k++;

     char line[MAXLINE];
  char output_line[MAXLINE];
  strcpy(line, contents);

  if (cursor >= 0){
    strncpy(output_line, line, cursor);
    output_line[cursor] = '|';
    strcpy(output_line+cursor+1, line+cursor);
    printf("%s", output_line);
  } else {
    printf("%s", line);
}
}
