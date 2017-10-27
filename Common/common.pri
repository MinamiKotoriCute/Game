PROJECT_PATH = $$PWD

INCLUDEPATH += $${PROJECT_PATH}

HEADERS  += $${PROJECT_PATH}\logcontroller.h \
    $$PWD/tcpsocket.h

SOURCES += $${PROJECT_PATH}\logcontroller.cpp \
    $$PWD/tcpsocket.cpp
