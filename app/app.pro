TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage -O0

SOURCES += editor.c\
    getcrsr.c\
    load.c\
    m.c\
    mwef.c\
    rt.c\
    text/process_forward.c\
    save.c\
    show.c\
    showrew.c\
    text/append_line.c\
    text/change_cursor_position.c\
    text/create_text.c\
    text/delete_line.c\
    text/remove_all.c\


HEADERS += \
    common.h\
    data.h\
    text/text.h\
    text/_text.h


QMAKE_CFLAGS += -Wall -Wextra  

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
