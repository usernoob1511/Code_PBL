import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window 2.15

Item {
    id: root
    width: 1920
    height: 1080

    property bool isLogined: true
    property bool showPassword: false


    Image {
        id: image
        x: 0
        y: 0
        width: root.width
        height: root.height
        source: "qrc:/Images/anhnenbenhvien.jpg"
        fillMode: Image.PreserveAspectFit

        Rectangle {
            id: rectangle
            x: 720
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
                source: "qrc:/Images/logon_nen(1).png"
                fillMode: Image.PreserveAspectFit
            }

            TextField {
                id: user_Field
                x: 103
                y: 309
                width: 321
                height: 49
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 14
                font.italic: true
                font.family: "Times New Roman"
                placeholderText: qsTr("Tài khoản")
                leftPadding: 12
                rightPadding: 12
            }

            TextField {
                id: password_Field
                x: 103
                y: 404
                width: 321
                height: 49
                font.letterSpacing: 0
                verticalAlignment: Text.AlignVCenter
                font.strikeout: false
                z: 0
                echoMode: showPassword ? TextInput.Normal : TextInput.Password
                font.family: "Times New Roman"
                font.italic: true
                font.pointSize: 14
                placeholderText: qsTr("Mật khẩu")
                leftPadding: 12
                rightPadding: 50
            }

            Image {
                id: image4
                x: 370
                y: 404
                width: 54
                height: 43
                opacity: 1
                source: showPassword ?  "qrc:/Images/eye_open.png" :  "qrc:/Images/eye_hide.png"
                fillMode: Image.PreserveAspectFit
                MouseArea {
                    id: mouseArea3
                    anchors.fill : parent
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    z: 1
                    onClicked: {
                        showPassword = !showPassword
                    }
                }
            }


            Rectangle {
                id: rectangle1
                x: 73
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
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    onClicked: {
                        Qt.quit()
                    }
                }
            }

            Image {
                id: image2
                x: 49
                y: 309
                width: 53
                height: 49
                source: "qrc:/Images/logo_taikhoan.png"
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: image3
                x: 46
                y: 404
                width: 60
                height: 44
                source: "qrc:/Images/logo_matkhau.png"
                fillMode: Image.PreserveAspectFit
            }

            Rectangle {
                id: rectangle_Login
                x: 280
                y: 557
                width: 144
                height: 48
                color: "#0b98bc"
                radius: 35
                border.color: "#0b98bc"
                border.width: 3

                MouseArea {
                    anchors.fill: rectangle_Login
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0

                    onPressed: {
                        rectangle_Login.color = "white"
                        text_Login.color = "#0b98bc"
                    }
                    onReleased: {
                        rectangle_Login.color = "#0b98bc"
                        text_Login.color = "#f7f7f7"
                    }
                    onClicked: {
                        if(admin.login(user_Field.text, password_Field.text)) {
                            isLogined= true
                            stackView.push("Side_bar.qml")
                        } else {
                            isLogined= false
                        }

                        showPassword= false
                        user_Field.text = ""
                        password_Field.text= ""
                    }

                    Text {
                        id: text_Login
                        x: 44
                        y: 12
                        width: 68
                        height: 36
                        color: "white"
                        text: qsTr("Login")
                        font.pixelSize: 22
                        font.family: "Times New Roman"

                    }
                }
            }

            Text {
                id: _text1
                x: 125
                y: 570
                width: 35
                height: 22
                color: "#0b89bc"
                text: qsTr("Exit")
                font.pixelSize: 22
                font.family: "Times New Roman"
            }
            ColumnLayout{
                id: inform_loginWrong
                spacing: 0
                x: 103
                y: 469
                width: 186
                height: 31
                visible: isLogined ? false : true
                Text{
                    width: 120
                    height: 25
                    color: "#c4170e"
                    text: "Please login again!"
                    font.pixelSize: 14
                }
                Text{
                    width: 120
                    height: 25
                    color: "#c4170e"
                    text: "Wrong account or password"
                    font.pixelSize: 14
                }
            }

            Text {
                id: _text5
                x: 320
                y: 458
                width: 120
                height: 25
                color: "#0b89bc"
                text: "Forgot pasword?"
                font.pixelSize: 14
                font.underline: true

                MouseArea {
                    anchors.fill: parent
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    onClicked:{
                        isLogined = true
                        user_Field.text = ""
                        password_Field.text= ""
                        showPassword: false
                        stackView3.push("Forgotpassword_page.qml")
                    }
                }
            }

            Text {
                id: register_button
                x: 320
                y: 489
                width: 120
                height: 25
                color: "#0b89bc"
                text: "Register account?"
                font.pixelSize: 14
                font.underline: true
                MouseArea {
                    anchors.fill: parent
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0

                    onClicked:{
                        isLogined = true
                        user_Field.text = ""
                        password_Field.text= ""
                        showPassword: false
                        stackView3.push("Registeraccount_page.qml")
                    }
                }
            }
        }
    }
}



