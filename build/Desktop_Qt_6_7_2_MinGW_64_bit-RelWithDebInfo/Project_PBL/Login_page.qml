import QtQuick
import QtQuick.Controls

Item {
    id: root
    width: 1920
    height: 1080

    property bool showPassword: false

    Image {
        id: image
        x: 0
        y: 0
        width: root.width
        height: root.height
        source: "Images/anhnenbenhvien.jpg"
        fillMode: Image.PreserveAspectFit

        Rectangle {
            id: rectangle
            x: 712
            y: 185
            width: 480
            height: 711
            color: "#ffffff"
            radius: 20
            border.color: "#0b98bc"

            Text {
                id: _text
                x: 170
                y: 180
                width: 151
                height: 68
                color: "#0b98bc"
                text: qsTr("Log in")
                font.pixelSize: 50
                font.family: "Times New Roman"
                font.bold: true
            }

            Image {
                id: image1
                x: 175
                y: 73
                width: 131
                height: 114
                source: "Images/logo_nen(1)_tachnen.png"
                fillMode: Image.PreserveAspectFit
            }

            TextField {
                id: textField
                x: 85
                y: 309
                width: 321
                height: 49
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 12
                font.italic: true
                font.family: "Times New Roman"
                placeholderText: qsTr("  Tài khoản")
            }

            TextField {
                id: textField1
                x: 85
                y: 403
                width: 321
                height: 49
                verticalAlignment: Text.AlignVCenter
                z: 0
                echoMode: showPassword ? TextInput.Normal : TextInput.Password
                font.family: "Times New Roman"
                font.italic: true
                font.pointSize: 12
                placeholderText: qsTr("  Mật khẩu")
            }

             Image {
                id: image4
                x: 352
                y: 406
                width: 54
                height: 43
                opacity: 1
                source: showPassword ?  "Images/eye_open.png" :  "Images/eye_hide.png"
                fillMode: Image.PreserveAspectFit
                MouseArea {
                    id: mouseArea3
                    anchors.fill : parent
                    anchors.leftMargin: -2
                    anchors.rightMargin: 2
                    anchors.topMargin: 2
                    anchors.bottomMargin: -2
                    z: 1
                    onClicked: {
                        showPassword = !showPassword
                    }
                }
             }


            Rectangle {
                id: rectangle1
                x: 81
                y: 557
                width: 144
                height: 48
                color: "#ffffff"
                radius: 35
                border.color: "#0b98bc"
                border.width: 3
                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                }
            }

            Image {
                id: image2
                x: 42
                y: 309
                width: 60
                height: 49
                source: "../../Images_PBL/logo_taikhoan.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: image3
                x: 31
                y: 403
                width: 83
                height: 49
                source: "../../Images_PBL/logo_matkhau.png"
                fillMode: Image.PreserveAspectFit
            }

            Rectangle {
                id: rectangle2
                x: 270
                y: 557
                width: 144
                height: 48
                color: "#0b98bc"
                radius: 35
                border.color: "#0b98bc"
                border.width: 3

                MouseArea:
                {

                }
            }

            Text {
                id: _text1
                x: 136
                y: 570
                width: 35
                height: 22
                color: "#0b89bc"
                text: qsTr("Exit")
                font.pixelSize: 22
                font.family: "Times New Roman"
            }

            Text {
                id: _text4
                x: 314
                y: 570
                width: 57
                height: 29
                color: "#f7f7f7"
                text: qsTr("Login")
                font.pixelSize: 22
                font.family: "Times New Roman"
            }

            Text {
                id: _text5
                x: 294
                y: 458
                width: 120
                height: 25
                color: "#0b89bc"
                text: "Register account?"
                font.pixelSize: 14
                font.underline: true
                MouseArea {
                    anchors.fill: parent
                    anchors.leftMargin: -12
                    anchors.rightMargin: 12
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                }
            }
        }
    }
}
