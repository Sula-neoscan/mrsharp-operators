//=============================================================================================================
/**
* @file     sliceselectionoperator.h
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
* @brief    Contains the declaration of the SliceSelectionOperator class.
*
*/

#ifndef SLICESELECTIONOPERATOR_H
#define SLICESELECTIONOPERATOR_H

//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "sliceselectionoperator_global.h"
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
class SLICESELECTIONOPERATORSHARED_EXPORT SliceSelectionOperator : public IOperator
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "sqncslib/1.0" FILE "sliceselectionoperator.json") //New Qt5 Plugin system replaces Q_EXPORT_PLUGIN2 macro
    // Use the Q_INTERFACES() macro to tell Qt's meta-object system about the interfaces
    Q_INTERFACES(SQNCSLIB::IOperator)

public:
    typedef QSharedPointer<SliceSelectionOperator> SPtr;              /**< Shared pointer type. */
    typedef QSharedPointer<const SliceSelectionOperator> ConstSPtr;   /**< Const shared pointer type. */

    SliceSelectionOperator(const QString& uid = QString(), QObject *parent = Q_NULLPTR);

    /**
    * Destructor
    */
    ~SliceSelectionOperator() = default;

    virtual QSharedPointer<IOperator> create(const QString& uid) const override;

    virtual QString id() const override;

    virtual int eval() override;
};

} // NAMESPACE

#endif // SLICESELECTIONOPERATOR_H
