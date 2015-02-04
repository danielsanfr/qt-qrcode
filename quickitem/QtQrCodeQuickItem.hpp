/****************************************************************************
 *
 * Copyright (c) 2015 Daniel San, All rights reserved.
 *
 *    Contact: daniel.samrocha@gmail.com
 *       File: QtQrCodeQuickItem.hpp
 *     Author: daniel
 * Created on: 04/02/2015
 *    Version:
 *
 * This file is part of the Qt QRCode library.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 *
 ***************************************************************************/

#ifndef QTQRCODEQUICKITEM_HPP
#define QTQRCODEQUICKITEM_HPP

#include <QByteArray>
#include <QQuickPaintedItem>

#include <QtQrCode>

QT_BEGIN_NAMESPACE
class QPainter;
class QQuickItem;
QT_END_NAMESPACE

class QtQrCodeQuickItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QByteArray data READ data WRITE setData NOTIFY dataChanged)
public:
    QtQrCodeQuickItem(QQuickItem *parent = 0);
    ~QtQrCodeQuickItem();
    static void registerQmlTypes();
    void paint(QPainter *painter);

    QByteArray data() const;
    void setData(const QByteArray &data);
signals:
    void dataChanged(const QByteArray &data);
private:
    QtQrCode m_qrCode;
};

#endif // QTQRCODEQUICKITEM_HPP
