import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window 2.15
//import Admin 1.0
Item {
    id: root
    width: 1920
    height: 1080

    signal sidebarItemSelected(string item)
    property bool check_password: true
    property bool state_menu: false
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
            source: "qrc:/Images/Logo_benhvien.png"
            fillMode: Image.PreserveAspectFit
        }

        ColumnLayout {
            id: columnLayout
            x: 43
            y: 290
            width: 64
            height: 260
            spacing: 10

            Image {
                id: image1
                x: 26
                y: 328
                width: 57
                height: 49
                source: "qrc:/Images/icons8-home-50.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: image2
                x: 26
                y: 491
                width: 57
                height: 44
                source: "qrc:/Images/icons8-sick-50.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: image3
                x: 26
                y: 403
                width: 57
                height: 63
                source: "qrc:/Images/Staff.png"
                fillMode: Image.PreserveAspectFit
            }
        }

        ColumnLayout {
            id: columnLayout1
            x: 104
            y: 304
            width: 120
            height: 331
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
            Text {
                id: _text3
                x: 106
                y: 510
                width: 82
                height: 40
                color: "#ffffff"
                text: qsTr("Medicines")
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
                // stackLayout.currentIndex = 0
                stackView1.clear()
                stackView1.push("Home_page.qml")
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
                // stackLayout.currentIndex = 1
                stackView1.clear()
                stackView1.push("Doctor_page.qml",{state: "Alldoctor"})

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
                // stackLayout.currentIndex = 2
                stackView1.clear()
                stackView1.push("Patient_page.qml",{state: "Inpatient"})
            }
        }
        MouseArea {
            id: mouseArea5
            x: 2
            y: 570
            width: 416
            height: 55
            onClicked:
            {
                // stackLayout.currentIndex = 2
                stackView1.clear()
                stackView1.push("Medicine_page.qml",{state: "Allmedicine"})
            }

            StackView {
                id: stackView1
                x: 414
                y: -570
                width: 1505
                height: 1080
                anchors.left: rectangle.right
                anchors.leftMargin: 0
                z: 1

                initialItem: "Home_page.qml"

                pushEnter: Transition {
                    NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 100 }
                    NumberAnimation { property: "x"; from: width; to: 0; duration: 300 }
                }
                pushExit: Transition {
                    NumberAnimation { property: "opacity"; from: 1; to: 0; duration: 300 }
                    // NumberAnimation { property: "x"; from: 0; to: -width; duration: 300 }
                }

                // Hiệu ứng khi quay lại trang trước (pop)
                popEnter: Transition {
                    NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 100 }
                    NumberAnimation { property: "x"; from: width; to: 0; duration: 300 }
                }
                popExit: Transition {
                    NumberAnimation { property: "opacity"; from: 1; to: 0; duration: 100 }
                    //     NumberAnimation { property: "x"; from: 0; to: width; duration: 300 }
                }
            }

            // StackLayout {
            //     id: stackLayout
            //     anchors.left: rectangle.right
            //     width: 1500
            //     height: 1080

            //     Loader {
            //         source: "Home_page.qml"
            //     }
            //     Loader {
            //         source: "Doctor_page.qml"
            //     }
            //     Loader {
            //         source: "Patient_page.qml"
            //     }
            // }

            Rectangle{
                x: -11
                y: 372
                width: 427
                height: 151
                border.color: "white"
                color: "#0b98bc"
                anchors.right: rectangle.right
                anchors.rightMargin: 0

                Text {
                    id: text_username
                    x: 19
                    y: 25
                    width: 325
                    height: 45
                    color: "#ffffff"
                    text: "Hello user: " + admin.username
                    font.pixelSize: 25
                    font.bold: true
                    font.family: "Times New Roman"

                    Image {
                        id:setting_Image
                        x: 342
                        y: 0
                        width: 49
                        height: 36
                        source: "qrc:/Images/setting.png"
                    }
                }

                MouseArea {
                    anchors.fill: parent
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    onClicked:{
                        state_menu = !state_menu
                    }
                }
            }

            Dialog {
                id: logOutDialog
                width: 400
                height: 200
                modal: true
                parent: root
                x: (root.width - width) /2
                y: (root.height - height) / 2 - 100
                //anchors.centerIn: root  // Đặt dialog ở giữa màn hình

                // Layout của Dialog
                ColumnLayout {
                    anchors.fill: parent
                    spacing: 15

                    // Tiêu đề của dialog
                    Label {
                        text: "Log out of your account?"
                        font.pixelSize: 20
                        font.bold: true
                        color: "#333333"
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    // Dòng chứa 2 nút Cancel và Logout
                    Row {
                        Layout.alignment: Qt.AlignHCenter
                        spacing: 20
                        anchors.horizontalCenter: parent.horizontalCenter

                        // Nút Cancel
                        Button {
                            text: "Cancel"
                            width: 120
                            height: 40
                            font.pixelSize: 18
                            onClicked: logOutDialog.close()  // Đóng dialog khi Cancel
                        }

                        // Nút Logout
                        Button {
                            text: "Logout"
                            width: 120
                            height: 40
                            font.pixelSize: 18
                            onClicked: {
                                stackView1.clear()
                                stackView.pop()
                                console.log("Logged out!")
                                logOutDialog.close()
                            }
                        }
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
            Rectangle {
                id: rectangle1
                x: -4
                y: 258
                width: 420
                height: 116
                color: "#0b98bc"
                visible: state_menu ? true : false

                Rectangle {
                    id: rectangle2
                    x: 0
                    y: 56
                    width: 420
                    height: 2
                    color: "white"
                }

                Rectangle {
                    id: rectangle3
                    x: 0
                    y: 0
                    width: 420
                    height: 2
                    color: "#ffffff"
                }

                Text {
                    id: text5
                    x: 126
                    y: 20
                    width: 168
                    height: 30
                    color: "white"
                    text: qsTr("Change password")
                    font.pixelSize: 22
                    font.family: "Times New Roman"
                    font.bold: true
                }

                Text {
                    id: text6
                    x: 172
                    y: 74
                    width: 79
                    height: 37
                    color: "#ffffff"
                    text: qsTr("Log out")
                    font.pixelSize: 22
                    font.family: "Times New Roman"
                    font.bold: true
                }

                Rectangle {
                    id: rectangle5
                    x: 0
                    y: 117
                    width: 420
                    height: 2
                    color: "#ffffff"
                }

                MouseArea {
                    x: 2
                    y: 3
                    width: 420
                    height: 55
                    onClicked:{
                        //changePasswordDialog.open()
                        stackView3.push("Changepassword_page.qml")
                    }
                }

                MouseArea {
                    x: 0
                    y: 56
                    width: 420
                    height: 55
                    onClicked: {
                        logOutDialog.open()
                    }
                }
            }
        }

        Image {
            id: image4
            x: 43
            y: 570
            width: 52
            height: 55
            source: "qrc:/Images/medicine.png"
            fillMode: Image.PreserveAspectFit
        }
    }
}
