import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15

Item {
    property int check_oldpassword: 0
    property int check_newpassword: 0
    property int check_confirmpass: 0

    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 480
        height: 720
        color: "#ffffff"
        radius: 20
        border.color: "#0b98bc"
        Text {
            id: _text
            x: 45
            y: 47
            width: 380
            height: 60
            color: "#0b98bc"
            text: qsTr("Change password")
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
            text: qsTr("Enter old password")
            font.pixelSize: 25
            font.bold: true
            font.family: "Times New Roman"
        }
        TextField {
            id: oldpasswordField
            x: 53
            y: 173
            width: 377
            height: 41
            verticalAlignment: Text.AlignVCenter
            echoMode: TextInput.Password
            leftPadding: 14
            font.family: "Times New Roman"
            font.pointSize: 14
            placeholderText: qsTr("123456XXX")
            //wrapMode: TextEdit.wrap


            RegularExpressionValidator {
                regularExpression: /^[^\s]+$/
            }

            onEditingFinished: {
                if (text.length === "") {
                    checkoldpassword_text.visible = true
                    check_oldpassword = 0
                } else {
                    checkoldpassword_text.visible = false
                    check_oldpassword = 1
                }
            }
        }

        Text{
            id: checkoldpassword_text
            x: 53
            y: 220
            width: 313
            height: 31
            color: "#ff0000"
            font.pointSize: 14
            font.family: "Times New Roman"
            visible: false
            text: "Password field cannot be empty!"
        }

        Text {
            id: _text2
            x: 53
            y: 264
            width: 253
            height: 32
            text: qsTr("Enter new password")
            font.pixelSize: 25
            font.bold: true
            font.family: "Times New Roman"
        }

        TextField {
            id: newpasswordField
            x: 53
            y: 302
            width: 377
            height: 41
            verticalAlignment: Text.AlignVCenter
            echoMode: TextInput.Password
            leftPadding: 14
            font.family: "Times New Roman"
            font.pointSize: 14
            placeholderText: qsTr("987XXXXXX")
            //wrapMode: TextEdit.wrap

            RegularExpressionValidator {
                regularExpression: /^[^\s]+$/  // Chấp nhận tất cả ký tự ngoại trừ dấu cách
            }
            onEditingFinished: {
                if (text.length === "") {
                    checknewpassword_text.visible = true
                    check_newpassword = 0
                } else {
                    checknewpassword_text.visible = false
                    check_newpassword = 1
                }
            }
        }

        Text{
            id: checknewpassword_text
            x: 53
            y: 349
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
            text: qsTr("Confirm new password")
            font.pixelSize: 25
            font.bold: true
            font.family: "Times New Roman"
        }

        TextField {
            id: confirmpasswordField
            x: 53
            y: 435
            width: 377
            height: 41
            placeholderText: qsTr("987XXXXXX")
            font.pointSize: 14
            font.italic: false
            font.family: "Times New Roman"
            verticalAlignment: Text.AlignVCenter
            echoMode: TextInput.Password
            leftPadding: 14

            RegularExpressionValidator {
                regularExpression: /^[^\s]+$/  // Chấp nhận tất cả ký tự ngoại trừ dấu cách
            }
            onEditingFinished: {
                if (text.length === "") {
                    checkconfirmpass_text.visible = true
                    check_confirmpass = 0
                } else {
                    checkconfirmpass_text.visible = false
                    check_confirmpass = 1
                }
            }
        }

        Text{
            id: checkconfirmpass_text
            x: 53
            y: 482
            width: 313
            height: 31
            color: "#ff0000"
            font.pointSize: 14
            font.family: "Times New Roman"
            visible: false
            text: "Password field cannot be empty!"
        }

        Button {
            id: button
            x: 72
            y: 654
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
            x: 294
            y: 654
            width: 131
            height: 49
            text: qsTr("Change")
            icon.width: 20
            font.pointSize: 20
            font.family: "Times New Roman"
            font.bold: true
            onClicked: {
                if (newpasswordField.text !== oldpasswordField.text
                       && check_oldpassword && check_newpassword && check_confirmpass
                        && newpasswordField.text === confirmpasswordField.text) {

                    notificantsWrong.text = "Change password successfully!"
                    notificantsWrong.color = "#00ff00"
                    notificantsWrong.visible= true
                    admin.changePassword(newpasswordField.text)

                    oldpasswordField.text =""
                    newpasswordField.text = ""
                    confirmpasswordField.text=""
                } else {
                    notificantsWrong.text = "Please check data required!"
                    notificantsWrong.color = "#c4170e"
                    notificantsWrong.visible= true
                }
            }
        }

        Text {
            id: notificantsWrong
            x: 24
            y: 563
            width: 433
            height: 38
            font.pixelSize: 30
            font.bold: true
            font.family: "Times New Roman"
            visible: false
            wrapMode: TextEdit.Wrap
            horizontalAlignment: Text.AlignHCenter // Căn giữa văn bản trong Text
            verticalAlignment: Text.AlignVCenter // Căn giữa theo chiều dọc (tuỳ chọn)

        }
    }
}
