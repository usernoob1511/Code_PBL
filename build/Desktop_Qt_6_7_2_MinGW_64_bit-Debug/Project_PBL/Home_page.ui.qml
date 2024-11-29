import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 1920
    height: 1080

    Image {
        id: image
        x: 426
        y: 0
        anchors.right: root.right
        width: 1500
        height: 1080
        source: "://Images/anhnenbenhvien.jpg"
        fillMode: Image.PreserveAspectFit

        Text {
            id: _text
            x: 203
            y: 19
            width: 1094
            height: 79
            color: "#ffffff"
            text: qsTr("Welcome to Hospital Management System")
            font.pixelSize: 60
            font.bold: true
            font.family: "Times New Roman"
        }
    }
}
