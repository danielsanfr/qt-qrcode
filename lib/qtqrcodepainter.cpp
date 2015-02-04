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

#include <QRect>
#include <QSize>
#include <QSvgGenerator>

QtQrCodePainter::QtQrCodePainter()
    : m_pen(Qt::NoPen), m_qrCode(),
      m_background(Qt::NoBrush), m_foreground(Qt::SolidPattern)
{
    m_margin = 0;
}

QtQrCodePainter::~QtQrCodePainter()
{
}

void QtQrCodePainter::paint(QPainter &painter)
{
    this->paint(painter, m_qrCode);
}

void QtQrCodePainter::paint(QPainter &painter, QtQrCode qrCode)
{
    if (qrCode.data().isEmpty())
        return;
    int width = qrCode.width() + m_margin * 2;
    painter.setClipRect(QRect(0, 0, width, width));
    painter.setPen(m_pen);
    painter.setBrush(m_foreground);

    /* Make solid background */
    painter.fillRect(QRect(0, 0, width, width), m_background);

    /* Write data */
    width = qrCode.width();
    unsigned char *row, *data;
    data = (unsigned char *) qrCode.data().constData();
    for(int y = 0; y < width; ++y) {
        row = (data + y * width);
        /* no RLE */
        for(int x = 0; x < width; ++x) {
            if(*(row + x) & 0x1)
                painter.drawRect(m_margin + x, m_margin + y, 1, 1);
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
