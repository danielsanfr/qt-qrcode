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
    inline  bool setPen(const QPen &pen)
    {
        if (m_pen != pen) {
            m_pen = pen;
            return true;
        }
        return false;
    }

    inline float margin() const { return m_margin; }
    inline  bool setMargin(float margin)
    {
        if (m_margin != margin) {
            m_margin = margin;
            return true;
        }
        return false;
    }

//    inline  bool setOffset(float offsetX, float offsetY)
//    {
//        if (m_offsetX != offsetX || m_offsetY != offsetY) {
//            m_offsetX = offsetX;
//            m_offsetY = offsetY;
//            return true;
//        }
//        return false;
//    }

//    inline float offsetX() { return m_offsetX; }
//    inline  bool setOffsetX(float offsetX)
//    {
//        if (m_offsetX != offsetX) {
//            m_offsetX = offsetX;
//            return true;
//        }
//        return false;
//    }

//    inline float offsetY() { return m_offsetY; }
//    inline  bool setOffsetY(float offsetY)
//    {
//        if (m_offsetY != offsetY) {
//            m_offsetY = offsetY;
//            return true;
//        }
//        return false;
//    }

    inline const QtQrCode &qrCode() const { return m_qrCode; }
    inline  bool setQrCode(const QtQrCode &qrCode)
    {
        if (m_qrCode != qrCode) {
            m_qrCode = qrCode;
            return true;
        }
        return false;
    }

    inline const QBrush &background() const { return m_background; }
    inline  bool setBackground(const QBrush &background)
    {
        if (m_background != background) {
            m_background = background;
            return true;
        }
        return false;
    }

    inline const QBrush &foreground() const { return m_foreground; }
    inline  bool setForeground(const QBrush &foreground)
    {
        if (m_foreground != foreground) {
            m_foreground = foreground;
            return true;
        }
        return false;
    }

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
