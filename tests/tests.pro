include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror -Wno-write-strings -Wno-sign-compare -std=c++0x
QMAKE_CFLAGS += -Wall -Wextra -Werror -Wno-write-strings -Wno-sign-compare

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS += \
../app/common.h\
../app/text/_text.h\
../app/text/text.h\
tests.h
    

SOURCES += \
../app/load.c\
../app/m.c\
../app/getcrsr.c\
../app/mwef.c\
../app/save.c\
../app/show.c\
../app/showrew.c\
../app/rt.c\
../app/text/append_line.c \
../app/text/change_cursor_position.c \
        ../app/text/create_text.c \
        ../app/text/delete_line.c \
        ../app/text/process_forward.c \
        ../app/text/remove_all.c \
main.cpp
INCLUDEPATH += ../app
