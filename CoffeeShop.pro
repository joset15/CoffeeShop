QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Data/OrderDiskDataSource.cpp \
    Model/BeverageBuilder.cpp \
    Model/BeverageFactory.cpp \
    Model/Cocoa.cpp \
    Model/Coffee.cpp \
    Adapter/OrderRepository.cpp \
    Model/Tea.cpp \
    UseCase/UseCase.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Data/OrderDiskDataSource.hpp \
    Adapter/IOrderDataSource.hpp \
    Model/BeverageBuilder.hpp \
    Model/BeverageFactory.hpp \
    Model/Cocoa.hpp \
    Model/Coffee.hpp \
    Model/IBeverage.hpp \
    Model/BeverageVariety.hpp \
    Model/Ingredient.hpp \
    Adapter/OrderRepository.hpp \
    Adapter/PrinterPresenter.hpp \
    Model/Tea.hpp \
    UseCase/IOrderOutput.hpp \
    UseCase/UseCase.hpp \
    UseCase/IOrderRepository.hpp \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
