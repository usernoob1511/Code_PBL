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
                    check_username = 1
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
                    check_username = 0
                } else {
                    checknewpassword_text = false
                    check_username = 1
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
            leftPadding: 14

            RegularExpressionValidator {
                regularExpression: /^[^\s]+$/  // Chấp nhận tất cả ký tự ngoại trừ dấu cách
            }
            onEditingFinished: {
                if (text.length !== 10) {
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
            text: qsTr("Register")
            icon.width: 20
            font.pointSize: 20
            font.family: "Times New Roman"
            font.bold: true
            onClicked: {
                if (newpasswordField.text === oldpasswordField.text
                        && admin.changePassword(newpasswordField.text) && check_oldpassword && check_newpassword && check_confirmpass) {

                    notificantsWrong.text = "Change password successfully!"
                    notificantsWrong.color = "#00ff00"
                    notificantsWrong.visible= true
                    //oldPassword_Field.text === admin.password && newPassword_Field.text !== "" &&
                    //                             confirmPassword_Field.text === newPassword_Field.text && admin.changePassword(newPassword_Field.text)
                    admin.registerAdmin(usernameField.text, passwordField.text, phoneField.text)

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
        }
    }
}

// Dialog {
//     id: changePasswordDialog
//     width: 400
//     height: 350
//     modal: true
//     parent: root
//     x: (root.width - width) /2
//     y: (root.height - height) / 2 - 100

//     ColumnLayout {
//         anchors.fill: parent
//         spacing: 20

//         // Tiêu đề của dialog
//         Label {
//             text: "Change Your Password"
//             font.pixelSize: 22
//             font.bold: true
//             color: "#333333"
//             anchors.horizontalCenter: parent.horizontalCenter
//         }

//         // Trường nhập mật khẩu cũ
//         TextField {
//             id: oldPassword_Field
//             font.pixelSize: 18
//             font.family: "Times New Roman"
//             placeholderText: "Enter Old Password"
//             echoMode: TextInput.Password
//             Layout.fillWidth: true
//             height: 100
//         }

//         // Trường nhập mật khẩu mới
//         TextField {
//             id: newPassword_Field
//             font.pixelSize: 18
//             font.family: "Times New Roman"
//             placeholderText: "Enter New Password"
//             echoMode: TextInput.Password
//             Layout.fillWidth: true
//             height: 100
//         }

//         // Trường nhập lại mật khẩu mới
//         TextField {
//             id: confirmPassword_Field
//             font.pixelSize: 18
//             font.family: "Times New Roman"
//             placeholderText: "Confirm New Password"
//             echoMode: TextInput.Password
//             Layout.fillWidth: true
//             height: 100
//         }

//         // Thông báo lỗi nếu có
//         Text {
//             id: text_error
//             color: check_password ? "#00ff00" : "#c4170e"
//             font.pixelSize: 16
//             visible: false
//             text: check_password ? "Password changed successfully!" : "Passwords do not match or incorrect old password!"
//             anchors.horizontalCenter: parent.horizontalCenter
//         }

//         // Dòng chứa các nút Cancel và Change Password
//         Row {
//             Layout.alignment: Qt.AlignHCenter
//             spacing: 20
//             anchors.horizontalCenter: parent.horizontalCenter

//             // Nút Cancel
//             Button {
//                 text: "Cancel"
//                 width: 120
//                 height: 40
//                 font.pixelSize: 18
//                 onClicked: {
//                     changePasswordDialog.close()
//                     text_error.visible = false
//                     oldPassword_Field.text = ""
//                     newPassword_Field.text=""
//                     confirmPassword_Field.text=""
//                 }
//             }

//             // Nút Change Password
//             Button {
//                 text: "Change Password"
//                 width: 120
//                 height: 40
//                 font.pixelSize: 18
//                 onClicked: {

//                     if (oldPassword_Field.text === admin.password && newPassword_Field.text !== "" &&
//                             confirmPassword_Field.text === newPassword_Field.text && admin.changePassword(newPassword_Field.text)) {

//                         check_password= true
//                         text_error.visible = true
//                     } else {
//                         check_password = false
//                         text_error.visible = true
//                     }
//                 }
//             }
//         }
//     }
// }
