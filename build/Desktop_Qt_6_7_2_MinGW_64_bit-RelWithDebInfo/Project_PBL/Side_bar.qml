import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root
    width: 1920
    height: 1080

    signal sidebarItemSelected(string item)

    Rectangle {
        id: rectangle
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.topMargin: 0
        width: 420
        height: 1080
        color: "#0b98bc"

        Image {
            id: image
            x: 96
            y: 80
            width: 228
            height: 197
            source: "Images/Logo_benhvien.png"
            fillMode: Image.PreserveAspectFit
        }


        ColumnLayout {
            id: columnLayout
            x: 43
            y: 290
            width: 68
            height: 256
            spacing: 10

            Image {
                id: image1
                x: 26
                y: 328
                width: 57
                height: 49
                source: "Images/icons8-home-50.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: image2
                x: 26
                y: 491
                width: 57
                height: 44
                source: "Images/icons8-sick-50.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: image3
                x: 26
                y: 403
                width: 57
                height: 63
                source: "Images/Staff.png"
                fillMode: Image.PreserveAspectFit
            }

        }


        ColumnLayout {
            id: columnLayout1
            x: 104
            y: 304
            width: 90
            height: 250
            spacing: 10


            Text {
                id: _text
                x: 106
                y: 345
                width: 82
                height: 40
                color: "#ffffff"
                text: qsTr("Home")
                font.pixelSize: 25
                font.bold: true
                font.family: "Times New Roman"
            }
            Text {
                id: _text1
                x: 106
                y: 428
                width: 82
                height: 40
                color: "#ffffff"
                text: qsTr("Doctors")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text2
                x: 106
                y: 510
                width: 82
                height: 40
                color: "#ffffff"
                text: qsTr("Patients")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }
        }

        MouseArea {
            id: mouseArea
            x: 0
            y: 304
            width: 420
            height: 55
            onClicked:
            {
                stackLayout.currentIndex = 0
            }
        }

        MouseArea {
            id: mouseArea1
            x: 0
            y: 391
            width: 420
            height: 55
            onClicked:
            {
                stackLayout.currentIndex = 1
            }
        }

        MouseArea {
            id: mouseArea2
            x: 0
            y: 476
            width: 416
            height: 55
            onClicked:
            {
                stackLayout.currentIndex = 2
            }
        }

        StackLayout {
            id: stackLayout
            anchors.left: rectangle.right
            width: 1500
            height: 1080

            Loader {
                source: "Home_page.qml"
            }
            Loader {
                source: "Doctor_page.qml"
            }
            Loader {
                source: "Patient_page.qml"
            }
            Loader {
                source: "Addnewdoctor_page.qml"
            }
            Loader {
                source: "Addnewpatient_page.qml"
            }
        }
    }
}
