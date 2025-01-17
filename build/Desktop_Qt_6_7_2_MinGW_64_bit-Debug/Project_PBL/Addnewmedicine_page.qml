import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQml 2.15
Item {
    id: rootaddMedicine
    width: 1060
    height: 625

    property int check_name: 0
    property int check_id: 0
    property int check_quantity: 0
    property int check_usage: 0
    property int check_expirydate: 0


    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 1060
        height: 625
        color: "#f0f0f0"
        border.width: 0

        Text {
            id: _text
            x: 375
            y: 16
            width: 307
            height: 60
            text: qsTr("Add Medicine Details")
            font.pixelSize: 30
            font.family: "Times New Roman"
            font.bold: true
        }

        Rectangle {
            id: rectangle1
            x: 58
            y: 88
            width: 940
            height: 479
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3



            TextField {
                id: nameField
                x: 59
                y: 73
                width: 313
                height: 41
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
                font.family: "Times New Roman"
                font.pointSize: 14
                placeholderText: qsTr("Paracetamol")
                //wrapMode: TextEdit.wrap

                validator: RegularExpressionValidator {
                    regularExpression: /^[\p{L}\s'-]+$/u
                }

                onTextChanged: {

                    let formattedText = text.split(" ").map(function(word) {
                        if (word.length > 0) {
                            return word[0].toUpperCase() + word.slice(1).toLowerCase(); // Viết hoa chữ cái đầu, các chữ sau viết thường
                        }
                        return "";
                    }).join(" ");

                    if (formattedText !== text) {
                        text = formattedText;
                    }
                }

                onEditingFinished: {
                    if (text.length === "") {
                        checkname_text.visible = true
                        check_name = 0
                    } else {
                        checkname_text.visible = false
                        check_name = 1
                    }
                }
            }

            TextField {
                id: medicineIdField
                x: 491
                y: 73
                width: 313
                height: 41
                readOnly: false
                placeholderText: qsTr("M00001")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
                validator: RegularExpressionValidator {
                    regularExpression: /^[M][0-9]{0,4}$/
                }

                onEditingFinished: {

                    if (text.length !== 5) {
                        checkId_text.visible = true
                        check_id = 0
                        checkId_text.text = "Medicine Id consists of 5 characters!"
                    } else if(!medicine.checkMedicineId(text)) {
                        checkId_text.visible = true
                        check_id = 0
                        checkId_text.text = "Medicine Id has been duplicated!"
                    } else {
                        check_id =1
                        checkId_text.visible = false
                    }
                }
            }

            TextField {
                id: quantityField
                x: 59
                y: 235
                width: 132
                height: 41
                placeholderText: qsTr("5000 (viên)")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
                validator: RegularExpressionValidator {
                    regularExpression: /^[0-9]{1,6}$/
                }

                onEditingFinished: {
                    if (text.length === "") {
                        checkquantity_text.visible = true
                        check_quantity = 0
                    } else {
                        checkquantity_text.visible = false
                        check_quantity = 1
                    }
                }
            }


            TextField {
                id: usageField
                x: 322
                y: 238
                width: 239
                height: 80
                placeholderText: qsTr("...")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                leftPadding: 14

                onEditingFinished: {
                    if (text.length === "") {
                        checkusage_text.visible = true
                        check_usage = 0
                    } else {
                        checkusage_text.visible = false
                        check_usage = 1
                    }
                }
            }

            TextField {
                id: dateField
                x: 653
                y: 238
                width: 226
                height: 40
                placeholderText: qsTr("01/01/1990")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
                validator: RegularExpressionValidator {
                    regularExpression: /^\d{1,2}\/\d{1,2}\/\d{4}$/ // Cho phép nhập cả ngày/tháng 1 chữ số
                }

                onEditingFinished: {
                    if (text === "") {
                        checkdate_text.text = "Date field cannot be empty!"
                        checkdate_text.visible = true
                        check_expirydate: 0
                    } else {
                        let formattedDate = validateDate2(text)
                        if (!formattedDate) {
                            checkdate_text.text = "Invalid date format or value!"
                            checkdate_text.visible = true
                            check_expirydate =0
                        } else {
                            checkdate_text.visible = false
                            text = formattedDate
                            check_expirydate =1
                        }
                    }
                }
            }

            Text{
                id: checkname_text
                x: 59
                y: 120
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
                text: "Name field cannot be empty!"
            }

            Text{
                id: checkId_text
                x: 490
                y: 120
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
            }

            Text{
                id: checkquantity_text
                x: 59
                y: 282
                width: 235
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
                text: "Quantity field cannot be empty!"
            }
            Text {
                id: _text1
                x: 59
                y: 39
                width: 254
                height: 30
                text: qsTr("Name medicine")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }
            Text {
                id: _text2
                x: 490
                y: 39
                width: 183
                height: 30
                text: "ID Number"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }
            Text {
                id: _text3
                x: 59
                y: 199
                width: 104
                height: 30
                text: "Quantity"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text10
                x: 322
                y: 202
                width: 208
                height: 30
                text: qsTr("Usage Instruction")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true


            }

            Text {
                id: checkusage_text
                x: 326
                y: 324
                width: 235
                height: 31
                visible: false
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
            }

            Text{
                id: checkdate_text
                x: 653
                y: 284
                width: 233
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
            }

            Text {
                id: _text6
                x: 653
                y: 199
                width: 176
                height: 30
                text: qsTr("Date expiration")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }
        }

        Button {
            id: button
            x: 697
            y: 501
            width: 114
            height: 44
            text: qsTr("Cancel")
            icon.width: 20
            font.bold: true
            font.pointSize: 20
            font.family: "Times New Roman"

            onClicked: {
                confirmationCancle.open()
            }

            Dialog {
                id: confirmationCancle
                width: 400
                height: 200
                x: 484 + (rootaddMedicine.width - width)/2 + 25
                y: 237 + (rootaddMedicine.height - height)/2
                parent: Overlay.overlay
                modal: true
                title: "Notificants"


                background: Rectangle {
                    color: "white"
                    border.color: "lightgray"
                    radius: 10
                }

                Column {
                    spacing: 40
                    anchors.fill: parent
                    anchors.margins: 20

                    Label {
                        text: "Don't save this Medicine?"
                        font.pixelSize: 20
                        color: "#333333"
                        wrapMode: Text.WordWrap
                        font.bold: true
                        font.family: "Times New Roman"
                        horizontalAlignment: Text.AlignHCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Row {
                        spacing: 30
                        x: 55

                        Button {
                            text: "Yes"
                            width: 100
                            height: 40
                            onClicked: {
                                console.log("Yes clicked")
                                confirmationCancle.close()
                                stackView2.clear()
                            }
                        }
                        Button {
                            text: "No"
                            width: 100
                            height: 40
                            onClicked: {
                                console.log("No clicked")
                                confirmationCancle.close()

                            }
                        }
                    }
                }
            }
        }

        Button {
            id: button1
            x: 847
            y: 501
            width: 114
            height: 44
            text: qsTr("Update")
            icon.width: 20
            font.pointSize: 20
            font.family: "Times New Roman"
            font.bold: true
            onClicked: {
                if (check_name && check_id && check_quantity
                    && check_usage && check_expirydate) {
                    confirmationDialog.open()
                } else {
                    messageDialog.open()
                    mainWindow.showMessageDialog2()
                }
            }

            Dialog {
                id: confirmationDialog
                width: 400
                height: 200
                x: 484 + (rootaddMedicine.width - width)/2 + 25
                y: 237 + (rootaddMedicine.height - height)/2
                parent: Overlay.overlay
                modal: true
                title: "Notificants"


                background: Rectangle {
                    color: "white"
                    border.color: "lightgray"
                    radius: 10
                }

                Column {
                    spacing: 40
                    anchors.fill: parent
                    anchors.margins: 20

                    Label {
                        text: "Are you sure you want to register this doctor?"
                        font.pixelSize: 20
                        color: "#333333"
                        wrapMode: Text.WordWrap
                        font.bold: true
                        font.family: "Times New Roman"
                        horizontalAlignment: Text.AlignHCenter
                        anchors.horizontalCenter: parent.horizontalCenter
                    }

                    Row {
                        spacing: 30
                        x: 55
                        Button {
                            text: "Yes"
                            width: 100
                            height: 40
                            onClicked: {
                                console.log("Yes clicked")
                                medicine.getMedicineData(
                                            medicineIdField.text,
                                            nameField.text,   
                                            quantityField.text,
                                            usageField.text,
                                            dateField.text
                                            )
                                // Lưu thông tin vào file
                                medicine.addMedicineData();
                                confirmationDialog.close()
                                stackView2.clear()
                                mainWindow.showCompletedDialog2()
                                medicine.showMedicineDataFromFile()
                            }
                        }

                        Button {
                            text: "No"
                            width: 100
                            height: 40
                            onClicked: {
                                console.log("No clicked")
                                confirmationDialog.close()
                            }
                        }
                    }
                }
            }
        }

        Dialog {
            id: completedialog
            width: 300
            height: 150
            x: 484 + (rootaddMedicine.width - width)/2
            y: 237 + (rootaddMedicine.height - height)/2
            parent: Overlay.overlay
            modal: true
            title: "Notification"

            background: Rectangle {
                color: "white"
                border.color: "lightgray"
                radius: 10
            }

            Image {
                id: complete
                source: "qrc:/Images/dautich.png"
                width: 80
                height: 80
                anchors.top: parent.top
                anchors.topMargin: 15
                anchors.left: parent.left
                anchors.leftMargin: 20
            }

            Label {
                id: ladbelcomplete
                anchors.verticalCenter: complete.verticalCenter
                anchors.left: complete.right
                anchors.leftMargin: 0
                text: "Sucessfull!"
                font.pixelSize: 20
                font.bold: true
                styleColor: "#616161"
                font.family: "Times New Roman"
                color: "#333333"
            }
        }


        Dialog {
            id: messageDialog
            width: 300
            height: 150
            x: 484 + (rootaddMedicine.width - width)/2
            y: 237 + (rootaddMedicine.height - height)/2
            parent: Overlay.overlay
            modal: true
            title: "Notification"

            background: Rectangle {
                color: "white"
                border.color: "lightgray"
                radius: 10
            }

            Image {
                id: chamthang
                source: "qrc:/Images/chamthang.png"
                width: 80
                height: 80
                anchors.top: parent.top
                anchors.topMargin: 15
                anchors.left: parent.left
                anchors.leftMargin: 20
            }

            Label {
                id: ladbeldelete
                anchors.verticalCenter: chamthang.verticalCenter
                anchors.left: chamthang.right
                anchors.leftMargin: 0
                text: "Please fill all data!"
                font.pixelSize: 20
                font.bold: true
                styleColor: "#616161"
                font.family: "Times New Roman"
                color: "#333333"
            }
        }
    }
}
