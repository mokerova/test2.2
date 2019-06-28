/**
 * common.h -- прототипы функций реализации команд редактора
 * 
 * Copyright (c) 2017, Mokerova Daria  <mokerova@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef COMMON_H
#define COMMON_H

#include "text/text.h"

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Выводит содержимое указанного файла на экран
 */
void show(text txt);

/**
 * Загружает содержимое указанного файла
 */
void load(text txt, char *filename);

void save(text txt, char *filename);

void showrew(text txt);

void rt(text txt);

void m(text txt, int line, int position);

void mwef(text txt);

#endif
