#--------------------------------------------------------------------------------------------------------------
#
# @file     sliceselectionoperator.pro
# @author   Stefan Roell <roell@neoscan-solutions.com>
# @version  1.0
# @date     April, 2019
#
# @section  LICENSE
#
# Copyright (C) 2019, Neoscan Solutions GmbH. All rights reserved.
#
# THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
# IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
# NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
#
#
# @brief    This project file generates the makefile for the sliceselection operator.
#
#--------------------------------------------------------------------------------------------------------------

TEMPLATE = lib

CONFIG += plugin

DEFINES += SLICESELECTION_OPERATOR

QT += core

TARGET = sliceselectionoperator

include(../build_config.pri)

LIBS += -L$${NEOSCAN_LIBRARY_DIR}
CONFIG(debug, debug|release) {
    LIBS += \
        -lneo_mathd \
        -lneo_dispd \
        -lneo_dvcd \
        -lneo_sqncsd
}
else {
    LIBS += \
        -lneo_math \
        -lneo_disp \
        -lneo_dvc \
        -lneo_sqncs
}

DESTDIR = $${NEOSCAN_BINARY_DIR}/operators

SOURCES += \
    sliceselectionoperator.cpp \

HEADERS += \
    sliceselectionoperator.h\
    sliceselectionoperator_global.h \

INCLUDEPATH += $${NEOSCAN_INCLUDE_DIR}

OTHER_FILES += sliceselectionoperator.json
