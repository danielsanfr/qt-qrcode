/****************************************************************************
 *
 * Copyright (c) 2015 Daniel San, All rights reserved.
 * 
 *    Contact: daniel.samrocha@gmail.com
 *       File: main.qml
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

import QtQuick 2.4
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1

import QtQrCode.Component 1.0

Window {
    id: window
    property string qrCodeData: "Hello QR Code"
    title: qsTr("Hello World")
    width: 640
    height: 480
    visible: true

    ColumnLayout {
        spacing: 20
        anchors.margins: 40
        anchors.fill: parent
        Text {
            text: "The content of the QR code is:<br><b>" + window.qrCodeData + "</b>"
            horizontalAlignment: Text.AlignHCenter
            Layout.fillWidth: true
            font.pointSize: 25
            wrapMode: Text.WordWrap
        }
        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true
            QtQrCode {
                data: window.qrCodeData
                width: Math.min(parent.height, parent.width)
                height:  width
                anchors.centerIn: parent
            } // QtQrCode
        } // Rectangle
    } // ColumnLayout
} // Window
