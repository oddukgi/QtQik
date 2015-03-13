/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the Qt Quick Controls module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.2
import QtQuick.Controls.Styles 1.2
import QtQuick.Particles 2.0

Window {
    id: window
    width: 640
    height: 480
    visible: true
    title: qsTr("Styles Example")

    property int columnWidth: window.width / 5

    GridLayout {
        rowSpacing: 12
        columnSpacing: 30
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalleft
        anchors.margins: 30

        TabView {
            Layout.row: 6
            Layout.columnSpan: 3
            Layout.fillWidth: true
            implicitHeight: 30
            Tab { title: "" ; Item { id: item1}}
            Tab { title: "" ; Item { id: item2 ;opacity: 1}}
            style: tabViewStyle
        }
    }
    // Style delegates:

//    property Component buttonStyle: ButtonStyle {
//        background: Rectangle {
//            implicitHeight: 22
//            implicitWidth: columnWidth
//            color: control.pressed ? "darkGray" : control.activeFocus ? "#cdd" : "#ccc"
//            antialiasing: true
//            border.color: "gray"
//            radius: height/2
//            Rectangle {
//                anchors.fill: parent
//                anchors.margins: 1
//                color: "transparent"
//                antialiasing: true
//                visible: !control.pressed
//                border.color: "#aaffffff"
//                radius: height/2
//            }
//        }
//    }

//    property Component textFieldStyle: TextFieldStyle {
//        background: Rectangle {
//            implicitWidth: columnWidth
//            color: "#f0f0f0"
//            antialiasing: true
//            border.color: "gray"
//            radius: height/2
//            Rectangle {
//                anchors.fill: parent
//                anchors.margins: 1
//                color: "transparent"
//                antialiasing: true
//                border.color: "#aaffffff"
//                radius: height/2
//            }
//        }
//    }

//    property Component sliderStyle: SliderStyle {
//        handle: Rectangle {
//            width: 18
//            height: 18
//            color: control.pressed ? "darkGray" : "lightGray"
//            border.color: "gray"
//            antialiasing: true
//            radius: height/2
//            Rectangle {
//                anchors.fill: parent
//                anchors.margins: 1
//                color: "transparent"
//                antialiasing: true
//                border.color: "#eee"
//                radius: height/2
//            }
//        }

//        groove: Rectangle {
//            height: 8
//            implicitWidth: columnWidth
//            implicitHeight: 22

//            antialiasing: true
//            color: "#ccc"
//            border.color: "#777"
//            radius: height/2
//            Rectangle {
//                anchors.fill: parent
//                anchors.margins: 1
//                color: "transparent"
//                antialiasing: true
//                border.color: "#66ffffff"
//                radius: height/2
//            }
//        }
//    }

//    property Component progressBarStyle: ProgressBarStyle {
//        background: BorderImage {
//            source: "images/progress-background.png"
//            border.left: 2 ; border.right: 2 ; border.top: 2 ; border.bottom: 2
//        }
//        progress: Item {
//            clip: true
//            BorderImage {
//                anchors.fill: parent
//                anchors.rightMargin: (control.value < control.maximumValue) ? -4 : 0
//                source: "images/progress-fill.png"
//                border.left: 10 ; border.right: 10
//                Rectangle {
//                    width: 1
//                    color: "#a70"
//                    opacity: 0.8
//                    anchors.top: parent.top
//                    anchors.bottom: parent.bottom
//                    anchors.bottomMargin: 1
//                    anchors.right: parent.right
//                    visible: control.value < control.maximumValue
//                    anchors.rightMargin: -parent.anchors.rightMargin
//                }
//            }
//            ParticleSystem { id: bubbles; running: visible }
//            ImageParticle {
//                id: fireball
//                system: bubbles
//                source: "images/bubble.png"
//                opacity: 0.7
//            }
//            Emitter {
//                system: bubbles
//                anchors.bottom: parent.bottom
//                anchors.margins: 4
//                anchors.bottomMargin: -4
//                anchors.left: parent.left
//                anchors.right: parent.right
//                size: 4
//                sizeVariation: 4
//                acceleration: PointDirection { y: -6; xVariation: 3 }
//                emitRate: 6 * control.value
//                lifeSpan: 3000
//            }
//        }
//    }

//    property Component progressBarStyle2: ProgressBarStyle {
//        background: Rectangle {
//            implicitWidth: columnWidth
//            implicitHeight: 24
//            color: "#f0f0f0"
//            border.color: "gray"
//        }
//        progress: Rectangle {
//            color: "#ccc"
//            border.color: "gray"
//            Rectangle {
//                color: "transparent"
//                border.color: "#44ffffff"
//                anchors.fill: parent
//                anchors.margins: 1
//            }
//        }
//    }

    property Component tabViewStyle: TabViewStyle {
        tabOverlap: 16
        frameOverlap: 2
        tabsMovable: true

        frame: Rectangle {
            gradient: Gradient {
                GradientStop { color: "#e5e5e5" ; position: 0 }
                GradientStop { color: "#e0e0e0" ; position: 1 }
            }
            border.color: "#898989"
            Rectangle { anchors.fill: parent ; anchors.margins: 1 ; border.color: "white" ; color: "transparent" }
        }
        tab: Item {

                property int totalOverlap: tabOverlap * (control.count - 1)
            implicitWidth: Math.min ((styleData.availableWidth + totalOverlap)/control.count-2 , image.sourceSize.width)
            implicitHeight: image.sourceSize.height
            BorderImage {
                id: image
                anchors.fill: parent
                source: styleData.selected ? "res/Img.png" : "res/Imgpush_1.jpg"
                border.left: 30
                smooth: false
                border.right: 30
            }
            Text {
                text: styleData.title
                anchors.centerIn: parent
            }
        }
        leftCorner: Item { implicitWidth: 12 }
    }
}
