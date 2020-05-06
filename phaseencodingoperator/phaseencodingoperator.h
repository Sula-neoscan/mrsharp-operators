//=============================================================================================================
/**
* @file     phaseencodingoperator.h
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
* @brief    Contains the declaration of the PhaseEncodingOperator class.
*
*/

#ifndef PHASEENCODINGOPERATOR_H
#define PHASEENCODINGOPERATOR_H

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "phaseencodingoperator_global.h"
#include <sqncs/IOperator.h>

//=============================================================================================================
// DEFINE NAMESPACE SQNCSLIB
//=============================================================================================================

namespace SQNCSLIB
{

//=============================================================================================================
/**
* Phase encoding operator definition
*
* @author   Christoph Dinh
* @date     January, 2018
*/
class PHASEENCODINGOPERATORSHARED_EXPORT PhaseEncodingOperator : public IOperator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "sqncslib/1.0" FILE "phaseencodingoperator.json") //New Qt5 Plugin system replaces Q_EXPORT_PLUGIN2 macro
    // Use the Q_INTERFACES() macro to tell Qt's meta-object system about the interfaces
    Q_INTERFACES(SQNCSLIB::IOperator)

public:
    typedef QSharedPointer<PhaseEncodingOperator> SPtr;              /**< Shared pointer type. */
    typedef QSharedPointer<const PhaseEncodingOperator> ConstSPtr;   /**< Const shared pointer type. */

    PhaseEncodingOperator(const QString& uid = QString(), QObject *parent = Q_NULLPTR);

    /**
    * Destructor
    */
    ~PhaseEncodingOperator() = default;

    virtual QSharedPointer<IOperator> create(const QString& uid) const override;

    virtual QString id() const override;

    virtual int eval() override;
};

} // NAMESPACE

#endif // PHASEENCODINGOPERATOR_H
