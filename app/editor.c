/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Mokerova Daria <mokerova@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

	/* сохраняем содержимое файла в новый файл */
	if (strcmp(cmd, "save") == 0) {
	    if ((arg = strtok(NULL, " \n")) == NULL) {
		fprintf(stderr, "Usage: save filename\n");
	    } else {
		save(txt, arg);
	    }
	    continue;
	}

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

	/* Помещаем курсор в конец слова */

	if (strcmp(cmd, "mwef") == 0) {
            mwef(txt);
            continue;
        }

	/* Выводим строчки текста в обратном порядке */
	
	if (strcmp(cmd, "showrew") == 0) {
            showrew(txt);
            continue;
        }

	/* Удаляет последнюю строку */

	if (strcmp(cmd, "rt") == 0) {
            rt(txt);
            continue;
        }

	/* Переносит курсор на нужную позицию */

	 if (strcmp(cmd, "m") == 0){
      char* line = strtok(NULL, " \n"), *position = strtok(NULL, " \n");
      if (line && position)
      m(txt, atoi(line), atoi(position));
      else
      printf("Uasge: mwcrsr line position");
      continue;
    }

	
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
