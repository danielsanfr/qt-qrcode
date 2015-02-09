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

#include <QColor>
#include <QByteArray>
#include <QQuickPaintedItem>

#include <QtQrCode>
#include <QtQrCodePainter>

QT_BEGIN_NAMESPACE
class QPainter;
class QQuickItem;
QT_END_NAMESPACE

class QtQrCodeQuickItem : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(Qt::PenStyle pen READ pen WRITE setPen NOTIFY penChanged)
    Q_PROPERTY(QByteArray data READ data WRITE setData NOTIFY dataChanged)
    Q_PROPERTY(float margin READ margin WRITE setMargin NOTIFY marginChanged)
    Q_PROPERTY(QColor background READ background WRITE setBackground NOTIFY backgroundChanged)
    Q_PROPERTY(QColor foreground READ foreground WRITE setForeground NOTIFY foregroundChanged)
public:
    QtQrCodeQuickItem(QQuickItem *parent = 0);
    ~QtQrCodeQuickItem();
    static void registerQmlTypes();
    void paint(QPainter *painter);

    inline const Qt::PenStyle &pen() const { return m_qrCodePainter.pen().style(); }
    inline void setPen(Qt::PenStyle penStyle)
    {
        if (m_qrCodePainter.setPen(QPen(penStyle))) {
            update();
            emit penChanged(m_qrCodePainter.pen());
        }
    }

    inline float margin() const { return m_qrCodePainter.margin(); }
    inline virtual void setMargin(float margin)
    {
        if (m_qrCodePainter.setMargin(margin)) {
            update();
            emit marginChanged(m_qrCodePainter.margin());
        }
    }

    inline const QColor &background() const { return m_qrCodePainter.background().color(); }
    inline virtual void setBackground(QColor backgroundColor)
    {
        if (m_qrCodePainter.setBackground(backgroundColor)) {
            update();
            emit backgroundChanged(m_qrCodePainter.background());
        }
    }

    inline const QColor &foreground() const { return m_qrCodePainter.foreground().color(); }
    inline virtual void setForeground(QColor foregroundColor)
    {
        if (m_qrCodePainter.setForeground(foregroundColor)) {
            update();
            emit foregroundChanged(m_qrCodePainter.foreground());
        }
    }

    QByteArray data() const;
    void setData(const QByteArray &data);
signals:
    void penChanged(const QPen &pen);
    void dataChanged(const QByteArray &data);
    void marginChanged(int margin);
    void backgroundChanged(const QBrush &background);
    void foregroundChanged(const QBrush &foreground);
private:
    QtQrCode m_qrCode;
    QtQrCodePainter m_qrCodePainter;
};

#endif // QTQRCODEQUICKITEM_HPP
