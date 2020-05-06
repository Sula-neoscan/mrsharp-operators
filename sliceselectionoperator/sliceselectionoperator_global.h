//=============================================================================================================
/**
* @file     sliceselectionoperator_global.h
* @author   Christoph Dinh <dinh@neoscan-solutions.com>
* @version  1.0
* @date     January, 2018
*
* @section  LICENSE
*
* Copyright (C) 2018, Neoscan Solutions GmbH. All rights reserved.
*
* THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
* IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
* NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
*
*
* @brief    Contains the SliceSelectionOperator library export/import macros.
*
*/

#ifndef SLICESELCTIONOPERATOR_GLOBAL_H
#define SLICESELCTIONOPERATOR_GLOBAL_H


//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QtCore/qglobal.h>


//*************************************************************************************************************
//=============================================================================================================
// PREPROCESSOR DEFINES
//=============================================================================================================

#if defined(SLICESELECTION_OPERATOR)
#  define SLICESELECTIONOPERATORSHARED_EXPORT Q_DECL_EXPORT   /**< Q_DECL_EXPORT must be added to the declarations of symbols used when compiling a shared library. */
#else
#  define SLICESELECTIONOPERATORSHARED_EXPORT Q_DECL_IMPORT   /**< Q_DECL_IMPORT must be added to the declarations of symbols used when compiling a client that uses the shared library. */
#endif

#endif // SLICESELCTIONOPERATOR_GLOBAL_H
