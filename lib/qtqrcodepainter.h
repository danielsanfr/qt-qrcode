/****************************************************************************
 *
 * Copyright (c) 2015 Daniel San, All rights reserved.
 *
 *    Contact: daniel.samrocha@gmail.com
 *       File: qtqrcodepainter.h
 *     Author: daniel
 * Created on: 03/02/2015
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

#ifndef QRCODEFACTORY_HPP
#define QRCODEFACTORY_HPP

#include <QPen>
#include <QImage>
#include <QBrush>
#include <QPainter>

#include "qtqrcode.h"

class QtQrCodePainter
{
public:
    static QtQrCodePainter *instance() {
        static QtQrCodePainter s_instance;
        return &s_instance;
    }
    ~QtQrCodePainter();

    void paint(QPainter &painter);
    void paint(QPainter &painter, QtQrCode qrCode);
    bool toSvg(const QString &fileName, int size);
    bool toSvg(const QString &fileName, int size, const QtQrCode &qrCode);
    QImage toImage(int size);
    QImage toImage(int size, const QtQrCode &qrCode);

    inline const QPen &pen() const { return m_pen; }
    inline void setPen(const QPen &pen) { m_pen = pen; }

    inline int margin() { return m_margin; }
    inline void setMargin(int margin) { m_margin = margin; }

    inline const QtQrCode &qrCode() const { return m_qrCode; }
    inline void setQrCode(const QtQrCode &qrCode) { m_qrCode = qrCode; }

    inline const QBrush &foreground() { return m_foreground; }
    inline void setForeground(const QBrush &foreground)
    { m_foreground = foreground; }

    inline const QBrush &background() { return m_background; }
    inline void setBackground(const QBrush &background)
    { m_background = background; }

private:
    QPen m_pen;
    int m_margin;
    QtQrCode m_qrCode;
    QBrush m_foreground;
    QBrush m_background;
    QtQrCodePainter();
};

#endif // QRCODEFACTORY_HPP
