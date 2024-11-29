import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Item {
    property int check_username: 0
    property int check_phone: 0
    property int check_password: 0
    property int check_passcode: 0

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 480
        height: 780
        color: "#ffffff"
        radius: 20
        border.color: "#0b98bc"
        Text {
            id: _text
            x: 61
            y: 49
            width: 358
            height: 64
            color: "#0b98bc"
            text: qsTr("Register account")
            font.pixelSize: 50
            font.family: "Times New Roman"
            font.bold: true
        }

        Text {
            id: _text1
            x: 53
            y: 135
            width: 253
            height: 32
            text: qsTr("Enter username")
            font.pixelSize: 25
            font.bold: true
            font.family: "Times New Roman"
        }
        TextField {
            id: usernameField
            x: 53
            y: 173
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
            y: 220
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
            y: 265
            width: 253
            height: 32
            text: qsTr("Enter password")
            font.pixelSize: 25
            font.bold: true
            font.family: "Times New Roman"
        }

        TextField {
            id: passwordField
            x: 53
            y: 303
            width: 377
            height: 41
            verticalAlignment: Text.AlignVCenter
            leftPadding: 14
            font.family: "Times New Roman"
            font.pointSize: 14
            placeholderText: qsTr("123456789")
            echoMode: TextInput.Password
            //wrapMode: TextEdit.wrap

            RegularExpressionValidator {
                regularExpression: /^[^\s]+$/  // Chấp nhận tất cả ký tự ngoại trừ dấu cách
            }
            onEditingFinished: {
                if (text.length === "") {
                    checkpass_text.visible = true
                    check_password = 0
                } else {
                    checkpass_text.visible = false
                    check_password = 1
                }
            }
        }

        Text{
            id: checkpass_text
            x: 53
            y: 350
            width: 313
            height: 31
            color: "#ff0000"
            font.pointSize: 14
            font.family: "Times New Roman"
            visible: false
            text: "Password field cannot be empty!"
        }

        Text {
            id: _text3
            x: 53
            y: 397
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
            y: 435
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
            id: checkphone_text
            x: 53
            y: 482
            width: 313
            height: 31
            color: "#ff0000"
            font.pointSize: 14
            font.family: "Times New Roman"
            visible: false
            text: "Phone consists of 10 characters!"
        }

        Text {
            id: _text4
            x: 53
            y: 525
            width: 253
            height: 32
            text: qsTr("Enter Passcode")
            font.pixelSize: 25
            font.bold: true
            font.family: "Times New Roman"
        }

        TextField {
            id: passcodeField
            x: 53
            y: 563
            width: 377
            height: 41
            placeholderText: qsTr("XXXXXX")
            font.pointSize: 14
            font.italic: false
            font.family: "Times New Roman"
            verticalAlignment: Text.AlignVCenter
            leftPadding: 14
            echoMode: TextInput.Password
            validator: RegularExpressionValidator {
                regularExpression: /^[0-9]{0,6}$/
            }

            onEditingFinished: {
                if (text !== "153759"){
                    checkpasscode_text.visible = true
                    check_passcode = 0
                } else {
                    check_passcode = 1
                    checkpasscode_text.visible = false
                }
            }
        }

        Text{
            id: checkpasscode_text
            x: 53
            y: 610
            width: 313
            height: 31
            color: "#ff0000"
            font.pointSize: 14
            font.family: "Times New Roman"
            visible: false
            text: "Wrong passcode!"
        }

        Button {
            id: button
            x: 74
            y: 716
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
            x: 288
            y: 716
            width: 131
            height: 49
            text: qsTr("Register")
            icon.width: 20
            font.pointSize: 20
            font.family: "Times New Roman"
            font.bold: true
            onClicked: {
                if (check_username && check_phone && check_password && check_passcode) {
                    notificantsWrong.text = "Register account successfully!"
                    notificantsWrong.color = "#00ff00"
                    notificantsWrong.visible= true

                    admin.registerAdmin(usernameField.text, passwordField.text, phoneField.text)

                    usernameField.text =""
                    passwordField.text = ""
                    phoneField.text=""
                    passcodeField.text=""
                } else {
                    notificantsWrong.text = "Please fill all data!"
                    notificantsWrong.color = "#c4170e"
                    notificantsWrong.visible= true
                }
            }
        }

        Text {
            id: notificantsWrong
            x: 21
            y: 662
            width: 442
            height: 36
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.family: "Times New Roman"
            visible: false

        }
    }
}

