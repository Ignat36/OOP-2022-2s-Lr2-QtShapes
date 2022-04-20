QT += widgets

TEMPLATE = lib
DEFINES += SEGMENT_LIBRARY

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    segment.cpp \
    D:\Windows\OOP-2022-2s-Lr2-QtShapes\Shapes\figure.cpp \
    D:\Windows\OOP-2022-2s-Lr2-QtShapes\Shapes\globeflags.cpp \

HEADERS += \
    segment_global.h \
    segment.h \
    D:\Windows\OOP-2022-2s-Lr2-QtShapes\Shapes\figure.h \
    D:\Windows\OOP-2022-2s-Lr2-QtShapes\Shapes\globeflags.h \

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
