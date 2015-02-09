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

#ifndef QRCODEPAINTER_H
#define QRCODEPAINTER_H

#include <QPen>
#include <QImage>
#include <QBrush>
#include <QPainter>

#include "qtqrcode.h"

class QtQrCodePainter
{
public:
    QtQrCodePainter();
    QtQrCodePainter(const QtQrCode &qrCode);
    ~QtQrCodePainter();

    void paint(QPainter &painter);
    void paint(QPainter &painter, const QtQrCode &qrCode);
    void paint(QPainter &painter, const QtQrCode &qrCode, int width, int height);
    void paint(QPainter &painter, const QtQrCode &qrCode, int painterWidth);
    bool toSvg(const QString &fileName, int size);
    bool toSvg(const QString &fileName, int size, const QtQrCode &qrCode);
    QImage toImage(int size);
    QImage toImage(int size, const QtQrCode &qrCode);

    inline const QPen &pen() const { return m_pen; }
    inline void setPen(const QPen &pen) { m_pen = pen; }

    inline float margin() { return m_margin; }
    inline void setMargin(float margin) { m_margin = margin; }

//    inline void setOffset(float offsetX, float offsetY)
//    { m_offsetX = offsetX; m_offsetY = offsetY; }

//    inline float offsetX() { return m_offsetX; }
//    inline void setOffsetX(float offsetX) { m_offsetX = offsetX; }

//    inline float offsetY() { return m_offsetY; }
//    inline void setOffsetY(float offsetY) { m_offsetY = offsetY; }

    inline const QtQrCode &qrCode() const { return m_qrCode; }
    inline void setQrCode(const QtQrCode &qrCode) { m_qrCode = qrCode; }

    inline const QBrush &background() { return m_background; }
    inline void setBackground(const QBrush &background)
    { m_background = background; }

    inline const QBrush &foreground() { return m_foreground; }
    inline void setForeground(const QBrush &foreground)
    { m_foreground = foreground; }

private:
    QPen m_pen;
    float m_margin;
    float m_offsetX;
    float m_offsetY;
    QtQrCode m_qrCode;
    QBrush m_background;
    QBrush m_foreground;
};

#endif // QRCODEPAINTER_H
