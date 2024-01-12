QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    view/credit.cc \
    view/view.cc \
    view/plotview.cc \
    view/debit.cc \
    model/qcustomplot.cpp \
    model/model.cc \
    model/creditmodel.cc \
    model/debitmodel.cc \
    model/aditional_clases/token.cc \
    model/aditional_clases/parse.cc \
    model/aditional_clases/validation.cc \
    model/aditional_clases/convert_to_postfix.cc \
    controller/controller.cc \
    controller/creditcontroller.cc \
    controller/debitcontroller.cc \
    main.cc \


HEADERS += \
    view/credit.h \
    view/plotview.h \
    model/qcustomplot.h \
    model/model.h \
    model/creditmodel.h \
    model/debitmodel.h \
    model/aditional_clases/associativity.h \
    model/aditional_clases/function_type.h \
    model/aditional_clases/percedence.h \
    model/aditional_clases/token.h \
    model/aditional_clases/parse.h \
    model/aditional_clases/validation.h \
    model/aditional_clases/convert_to_postfix.h \
    view/view.h \
    view/debit.h \
    controller/controller.h \
    controller/creditcontroller.h \
    controller/debitcontroller.h \

FORMS += \
    view/credit.ui \
    view/plotview.ui \
    view/view.ui \
    view/debit.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    GPL.txt \
    4.icns

macx:ICON = $${PWD}/4.icns
