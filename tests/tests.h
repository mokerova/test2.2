#include <limits.h>
#include <string.h>
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C" {
    #include "../app/text/_text.h"
    #include "../app/text/text.h"
    #include "../app/common.h"
}

using namespace testing;

    // Объект структуры создался?
TEST(test1, tests)
{
    EXPECT_NE(create_text(), nullptr);
}
    // Загрузился несуществующий файл?
TEST(test2, tests)
{
    text txt = create_text();
    load(txt, "<filename>");

    EXPECT_EQ(txt->length, 0);
}
    // Нет прав на файл?
TEST(test3, tests)
{
    text txt = create_text();
    load(txt, "/etc/shadow");

    EXPECT_EQ(txt->length, 0);
}
    // Обычный тескт

    // Текст вывелся в консоль?
TEST(test4, tests)
{
    text txt = create_text();
    show(txt);
    showrew(txt);

    EXPECT_EQ(txt->cursor->position, 0);
}

// Текст сохранился?
TEST(test5, tests)
{
    text txt = create_text();
    const char* contents = "TEST";
    load(txt, "input.txt");

    EXPECT_NO_FATAL_FAILURE(append_line(txt, contents););
    EXPECT_NE(txt->length, 0);
}
// К тексту возможно добавить строку?
TEST(test7, tests)
{
text txt = create_text();
const char* contents = "TEST";
load(txt, "input.txt");

EXPECT_NO_FATAL_FAILURE(append_line(txt, contents););
EXPECT_NE(txt->length, 0);
}

// К тексту возможно добавить слишком длинную строку?
TEST(test8, tests)
{
text txt = create_text();
char contents[10000];
load(txt, "input.txt");
for (; strlen(contents) < 10000; strcat(contents, "TEST"));

EXPECT_EXIT(append_line(txt, contents), ::testing::ExitedWithCode(EXIT_FAILURE), "");
}


// Возможно удалить все строки из текста?
TEST(test11, tests)
{
text txt = create_text();
load(txt, "input.txt");
remove_all(txt);

EXPECT_NE(txt, nullptr);
EXPECT_EQ(txt->length, 0);
}
// Возможно удалить все строки из пустого текста?
TEST(test12, tests)
{
text txt = nullptr;
remove_all(txt);

EXPECT_EQ(txt, nullptr);
}
// Возможно переместить курсор на данную позицию?
TEST(test13, tests)
{
text txt = create_text();
load(txt, "input.txt");
m(txt, 1, 2);

EXPECT_EQ(txt->cursor->position, 1);//5
}
// Возможно переместить курсор на позицию с отрицательными координатами?
TEST(test14, tests)
{
text txt = create_text();
load(txt, "input.txt");
m(txt, 1, 2);
m(txt, -1, -1);

EXPECT_EQ(txt->cursor->position, 1);
}



TEST(test15, tests)
{
text txt = create_text();
load(txt, "inputLONG.txt");
m(txt, 1, 2);
showrew(txt);
EXPECT_EQ(txt->cursor->position, 1);
}

TEST(test17, tests)
{
text txt = create_text();
load(txt, "inputLONG.txt");
m(txt, 3, 3);
rt(txt);
EXPECT_EQ(txt->cursor->position, 2);
}

TEST(test200, tests)
{
text txt = create_text();
load(txt, "inputLONG.txt");
txt->cursor->position = 1;
show(txt);
EXPECT_EQ(txt->cursor->position, 1);
}

// Перемещение курсора в конец слова
TEST(test18, tests)
{
text txt = create_text();
load(txt, "input1.txt");
m(txt, 1, 2);
mwef(txt);

EXPECT_EQ(txt->cursor->position, 4);
}

TEST(test19, tests)
{
text txt = create_text();
load(txt, "input1.txt");
m(txt, 1, 6);
mwef(txt);

EXPECT_EQ(txt->cursor->position, 9);
}
