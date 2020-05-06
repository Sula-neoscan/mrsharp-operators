#--------------------------------------------------------------------------------------------------------------
#
# @file     phaseencodingoperator.pro
# @author   Christoph Dinh <dinh@neoscan-solutions.com>
# @version  1.0
# @date     April, 2018
#
# @section  LICENSE
#
# Copyright (C) 2018, Neoscan Solutions GmbH. All rights reserved.
#
# THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
# IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
# NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
#
#
# @brief    This project file generates the makefile for the phaseencoding operator.
#
#--------------------------------------------------------------------------------------------------------------

TEMPLATE = lib

CONFIG += plugin

DEFINES += PHASEENCODING_OPERATOR

QT += core

TARGET = phaseencodingoperator

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
    phaseencodingoperator.cpp \

HEADERS += \
    phaseencodingoperator.h\
    phaseencodingoperator_global.h \

INCLUDEPATH += $${NEOSCAN_INCLUDE_DIR}

OTHER_FILES += phaseencodingoperator.json
