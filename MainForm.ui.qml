import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1

Item {
    width: 640
    height: 480

    property alias button3: button3
    property alias button2: btn_exit
    property alias button1: btn_min

    RowLayout {
        anchors.centerIn: parent
    }

    Button {
        id: btn_min
        x: 569
        y: 15
        width: 25
        height: 30
        text: qsTr("--")
        //onClicked: button1
    }

    Button {
        id: btn_exit
        x: 600
        y: 15
        width: 25
        height: 30
        text: qsTr("X")
    }
}
