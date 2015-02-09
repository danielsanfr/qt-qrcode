/****************************************************************************
 *
 * Copyright (c) 2015 Daniel San, All rights reserved.
 *
 *    Contact: daniel.samrocha@gmail.com
 *       File: qtqrcodepainter.cpp
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

#include "qtqrcodepainter.h"

#include <QSize>
#include <QRect>
#include <QRectF>
#include <QSvgGenerator>

QtQrCodePainter::QtQrCodePainter()
    : m_pen(Qt::NoPen), m_margin(0), m_offsetX(0), m_offsetY(0), m_qrCode(),
      m_background(Qt::transparent), m_foreground(Qt::black)
{
}

QtQrCodePainter::QtQrCodePainter(const QtQrCode &qrCode)
    : m_pen(Qt::NoPen), m_margin(0), m_offsetX(0), m_offsetY(0), m_qrCode(qrCode),
      m_background(Qt::transparent), m_foreground(Qt::black)
{
}

QtQrCodePainter::~QtQrCodePainter()
{
}

void QtQrCodePainter::paint(QPainter &painter) {
    this->paint(painter, m_qrCode);
}

void QtQrCodePainter::paint(QPainter &painter, const QtQrCode &qrCode)
{
    this->paint(painter, qrCode, qrCode.width() + m_margin * 2);
}

void QtQrCodePainter::paint(QPainter &painter, const QtQrCode &qrCode, int width, int height)
{
    m_offsetX = 0;
    m_offsetY = 0;
    int painterWidt = 0;
    float aspect = width/(float) height;
    if (aspect > 1.0) {
        painterWidt = height;
        m_offsetX = width/2.0 - painterWidt/2.0;
    } else {
        painterWidt = width;
         m_offsetY = height/2.0 - painterWidt/2.0;
    }
    this->paint(painter, qrCode, painterWidt);
}

void QtQrCodePainter::paint(QPainter &painter, const QtQrCode &qrCode, int painterWidth)
{
    if (qrCode.data().isEmpty())
        return;
    unsigned char *data = (unsigned char *) qrCode.data().constData();
    int width = qrCode.width();
    if (width < 0)
        width = 1;
    QRect rectangle(m_offsetX, m_offsetY, painterWidth, painterWidth);
    double scale = (painterWidth - 2.0*m_margin)/width;
    painter.setPen(m_pen);
    painter.setBrush(m_foreground);
    painter.setClipRect(rectangle);
    // Make solid background
    painter.fillRect(rectangle, m_background);

    for(int y = 0; y < width; ++y) {
        for(int x = 0; x < width; ++x, ++data) {
            if(*data & 0x1)
                painter.drawRect(QRectF(m_offsetX + m_margin + x*scale,
                                        m_offsetY + m_margin + y*scale, scale, scale));
        }
    }
}

bool QtQrCodePainter::toSvg(const QString &fileName, int size)
{
    return this->toSvg(fileName, size, m_qrCode);
}

bool QtQrCodePainter::toSvg(const QString &fileName, int size, const QtQrCode &qrCode)
{
    if (fileName.isEmpty() || size < 0 || qrCode.data().isEmpty())
        return false;

    QSvgGenerator svgGenerator;
    svgGenerator.setFileName(fileName);
    svgGenerator.setSize(QSize(size, size));
    int width = qrCode.width() + m_margin * 2;
    svgGenerator.setViewBox(QRect(0, 0, width, width));

    QPainter painter;
    painter.begin(&svgGenerator);
    this->paint(painter);
    painter.end();
    return true;
}

QImage QtQrCodePainter::toImage(int size)
{
    return this->toImage(size, m_qrCode);
}

QImage QtQrCodePainter::toImage(int size, const QtQrCode &qrCode)
{
    if (size < 0 || qrCode.data().isEmpty())
        return QImage();

    int width = qrCode.width() + m_margin * 2;
    QImage img(width, width, QImage::Format_ARGB32);
    img.fill(Qt::transparent);

    QPainter painter;
    painter.begin(&img);
    this->paint(painter);
    painter.end();

    if (size > 0)
        return img.scaled(size, size);
    return img;
}
