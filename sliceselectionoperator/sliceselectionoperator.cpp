//=============================================================================================================
/**
* @file     sliceselectionoperator.cpp
* @author   Christoph Dinh <dinh@neoscan-solutions.com>
* @version  1.0
* @date     January, 2018
*
* @section  LICENSE
*
* Copyright (C) 2017, Neoscan Solutions GmbH. All rights reserved.
*
* THIS DOCUMENT CONTAINS PROPRIETARY INFORMATION.
* IT IS THE EXCLUSIVE CONFIDENTIAL PROPERTY OF
* NEOSCAN SOLUTIONS GMBH AND IT'S AFFILIATES.
*
*
* @brief    Contains the implementation of the SliceSelectionOperator class.
*
*/

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "sliceselectionoperator.h"

//=============================================================================================================
// Qt INCLUDES
//=============================================================================================================

#include <QDebug>

//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace SQNCSLIB;

//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================

//=============================================================================================================
/**
* Constructor
* @param[in] uid        The operator identifier
* @param[in] parent     The parent of the QObject.
*/
SliceSelectionOperator::SliceSelectionOperator(const QString& uid, QObject *parent)
: IOperator(uid, QString("Slice selection operator info"), 0, 0, UnitDescription(), parent)
{
    addRequiredParameterSlot("BWTP");
    addRequiredParameterSlot("Thickness");
    addRequiredParameterSlot("Duration");
}

//=============================================================================================================
/**
* Creates an instance of the operator
* @param[in] uid    the unique id of the new operator
* @return the new operator
*/
QSharedPointer<IOperator> SliceSelectionOperator::create(const QString &uid) const
{
    SliceSelectionOperator::SPtr pSliceSelectionOperator(new SliceSelectionOperator(uid));
    return pSliceSelectionOperator;
}

//=============================================================================================================
/**
* This pure virtual method returns the operator id
* @return the function id
*/
QString SliceSelectionOperator::id() const
{
    return QString("SliceSelectionOperator");
}

//=============================================================================================================
/**
* Evaluates the operator - Physics happens here
* @return 0 when successful, otherwise the error code
*/
int SliceSelectionOperator::eval()
{
    if(!checkParameterSlots()) {
        qWarning() << "SliceSelectionOperator: Parameter not set!";
        return SQNCS_OPERATOR_ERROR;
    }

    double sliceselection = parameter("BWTP")->value() / (gamma_1H * parameter("Thickness")->value() * parameter("Duration")->value());
    setValue(sliceselection);

    return SQNCS_NO_ERROR;
}
