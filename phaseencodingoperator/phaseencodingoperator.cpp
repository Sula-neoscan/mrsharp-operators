//=============================================================================================================
/**
* @file     phaseencodingoperator.cpp
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
* @brief    Contains the implementation of the PhaseEncodingOperator class.
*
*/

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "phaseencodingoperator.h"

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
PhaseEncodingOperator::PhaseEncodingOperator(const QString& uid, QObject *parent)
: IOperator(uid, QString("Phase Encoding operator info"), 0, 0, UnitDescription(), parent)
{
    addRequiredParameterSlot("FOV");
    addRequiredParameterSlot("Resolution");
    addRequiredParameterSlot("pItFOV");
}

//=============================================================================================================
/**
* Creates an instance of the operator
* @param[in] uid    the unique id of the new operator
* @return the new operator
*/
QSharedPointer<IOperator> PhaseEncodingOperator::create(const QString &uid) const
{
    PhaseEncodingOperator::SPtr pPhaseEncodingOperator(new PhaseEncodingOperator(uid));
    return pPhaseEncodingOperator;
}

//=============================================================================================================
/**
* This pure virtual method returns the operator id
* @return the function id
*/
QString PhaseEncodingOperator::id() const
{
    return QString("PhaseEncodingOperator");
}

//=============================================================================================================
/**
* Returns the operator name
*
* @return the operator name
*/
QString PhaseEncodingOperator::name() const
{
    return QString("Phase Encoding");
}

//=============================================================================================================
/**
* Evaluates the operator - Physics happens here
* @return 0 when successful, otherwise the error code
*/
int PhaseEncodingOperator::eval()
{
    if(!checkParameterSlots()) {
        qWarning() << "PhaseEncodingOperator: Parameter not set!";
        return SQNCS_OPERATOR_ERROR;
    }

    double phaseencoding = (1.0 / (parameter("FOV")->value() * gamma_1H)) * (parameter("pItFOV")->value() - parameter("Resolution")->value()/2);
    setValue(phaseencoding);

    return SQNCS_NO_ERROR;
}
