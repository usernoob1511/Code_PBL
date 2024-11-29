import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Item {
    property int check_username: 0
    property int check_phone: 0

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 480
        height: 711
        color: "#ffffff"
        radius: 20
        border.color: "#0b98bc"
        Text {
            id: _text
            x: 99
            y: 172
            width: 283
            height: 58
            color: "#0b98bc"
            text: qsTr("Get pasword")
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
            source: "qrc:/Images/logon_nen(1).png"
            fillMode: Image.PreserveAspectFit
        }

        Text {
            id: _text1
            x: 53
            y: 271
            width: 253
            height: 32
            text: qsTr("Enter your username")
            font.pixelSize: 25
            font.bold: true
            font.family: "Times New Roman"
        }
        TextField {
            id: usernameField
            x: 53
            y: 309
            width: 377
            height: 41
            verticalAlignment: Text.AlignVCenter
            leftPadding: 14
            font.family: "Times New Roman"
            font.pointSize: 14
            placeholderText: qsTr("doanngocminh1511")
            //wrapMode: TextEdit.wrap

            validator: RegularExpressionValidator {
                regularExpression: /^[a-zA-Z0-9]+$/
            }
            onEditingFinished: {
                if (text.length === "") {
                    checkname_text.visible = true
                    check_username = 0
                } else {
                    checkname_text.visible = false
                    check_username = 1
                }
            }
        }

        Text{
            id: checkname_text
            x: 53
            y: 356
            width: 313
            height: 31
            color: "#ff0000"
            font.pointSize: 14
            font.family: "Times New Roman"
            visible: false
            text: "Name field cannot be empty!"
        }

        Text {
            id: _text2
            x: 53
            y: 399
            width: 253
            height: 32
            text: qsTr("Enter your phone")
            font.pixelSize: 25
            font.bold: true
            font.family: "Times New Roman"
        }

        TextField {
            id: phoneField
            x: 53
            y: 437
            width: 377
            height: 41
            placeholderText: qsTr("0795513XXX")
            font.pointSize: 14
            font.italic: false
            font.family: "Times New Roman"
            verticalAlignment: Text.AlignVCenter
            leftPadding: 14

            validator: RegularExpressionValidator {
                regularExpression: /^[0][0-9]{0,9}$/
            }
            onEditingFinished: {
                if (text.length !== 10) {
                    checkphone_text.visible = true
                    check_phone = 0
                } else {
                    checkphone_text.visible = false
                    check_phone = 1
                }
            }
        }

        Text{
            id: checkdate_text
            x: 53
            y: 490
            width: 313
            height: 31
            color: "#ff0000"
            font.pointSize: 14
            font.family: "Times New Roman"
            visible: false
        }


        Button {
            id: button
            x: 84
            y: 638
            width: 131
            height: 49
            text: qsTr("Cancel")
            icon.width: 20
            font.bold: true
            font.pointSize: 20
            font.family: "Times New Roman"
            onClicked: {
                stackView3.clear()
            }
        }

        Button {
            id: button1
            x: 281
            y: 638
            width: 131
            height: 49
            text: qsTr("Get pass")
            icon.width: 20
            font.pointSize: 20
            font.family: "Times New Roman"
            font.bold: true
            onClicked: {
                if (check_username && check_phone && admin.forgotPassword(usernameField.text, phoneField.text)) {
                    notificantsWrong.text = "Your password is: " + admin.password
                    notificantsWrong.color = "#00ff00"
                    notificantsWrong.visible= true
                } else {
                    notificantsWrong.text = "Your UserID is not found!"
                    notificantsWrong.color = "#c4170e"
                    notificantsWrong.visible= true
                }
            }
        }

        Text {
            id: notificantsWrong
            x: 25
            y: 555
            width: 433
            height: 38
            font.pixelSize: 30
            font.bold: true
            font.family: "Times New Roman"
            visible: false
        }
    }
}
