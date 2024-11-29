import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
Item {
    id: root
    width: 1500
    height: 1080
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 1500
        height: 1080
        color: "#f0f0f0"
        border.width: 0



        Rectangle {
            id: rectangle1
            x: 68
            y: 158
            width: 1365
            height: 785
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3
        }

        Button {
            id: button
            x: 1214
            y: 956
            width: 219
            height: 40
            text: qsTr("Register Doctor")
            font.bold: true
            font.pointSize: 20
            font.family: "Times New Roman"
            onClicked:{
               stackLayout.currentIndex = 3
            }
        }

        TextField {
            id: textField
            x: 1167
            y: 112
            width: 266
            height: 35
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 15
            font.family: "Times New Roman"
            placeholderText: qsTr("  Search Doctor...")
        }

        Text {
            id: _text
            x: 1101
            y: 117
            width: 67
            height: 30
            text: qsTr("Search")
            font.pixelSize: 22
            font.bold: false
            font.family: "Times New Roman"
        }

        Text {
            id: _text1
            x: 691
            y: 50
            width: 119
            height: 57
            text: qsTr("Doctor")
            font.pixelSize: 40
            font.family: "Times New Roman"
            font.bold: true
        }
    }
}
