import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQml 2.15
import Person 1.0
Item {
    id: root
    width: 1500
    height: 1080

    // Doctor{
    //     id: doctor
    // }

    property int check_name: 0
    property int check_doctorId: 0
    property int check_CCCD: 0
    property int check_phone: 0
    property int check_date: 0

    Person {
        id: person
    }
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 1500
        height: 1080
        color: "#f0f0f0"
        border.width: 0

        Text {
            id: _text
            x: 567
            y: 53
            width: 366
            height: 71
            text: qsTr("Add Doctor Details")
            font.pixelSize: 40
            font.bold: true
            font.family: "Times New Roman"
        }

        Rectangle {
            id: rectangle1
            x: 68
            y: 143
            width: 1365
            height: 878
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3

            Text {
                id: _text1
                x: 59
                y: 39
                width: 104
                height: 34
                text: qsTr("Name")
                font.pixelSize: 25
                font.bold: true
                font.family: "Times New Roman"
            }

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
                placeholderText: qsTr("Nguyen Van A")
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


            Text {
                id: _text2
                x: 490
                y: 39
                width: 183
                height: 49
                text: "ID Number"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: doctorIdField
                x: 491
                y: 73
                width: 313
                height: 41
                readOnly: false
                placeholderText: qsTr("D00001")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
                validator: RegularExpressionValidator {
                    regularExpression: /^[D][0-9]{0,4}$/
                }

                onEditingFinished: {

                    if (text.length !== 5) {
                        checkId_text.visible = true
                        check_doctorId = 0
                        checkId_text.text = "Doctor Id consists of 5 characters!"
                    } else if(!doctor.checkDoctorId(text)) {
                        checkId_text.visible = true
                        check_doctorId = 0
                        checkId_text.text = "Doctor Id has been duplicated!"
                    } else {
                        check_doctorId =1
                        checkId_text.visible = false
                    }
                }
            }

            // TextInput {
            //     id:  textinput
            //     x: 200
            //     y: 73
            //     width: 313
            //     height: 41
            // }

            Text{
                id: checkId_text
                x: 491
                y: 120
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
            }

            Text{
                id: checkCCCD_text
                x: 935
                y: 120
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
                text: "CNIC consists of 12 characters!"
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
                id: checkphone_text
                x: 59
                y: 241
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
                text: "Phone consists of 10 characters!"
            }

            Text{
                id: checkdate_text
                x: 935
                y: 241
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
            }

            Text {
                id: _text4
                x: 935
                y: 42
                width: 91
                height: 31
                text: qsTr("CNIC")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: personalIDField
                x: 935
                y: 73
                width: 295
                height: 41
                placeholderText: qsTr("048205XXXXXX")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
                validator: RegularExpressionValidator {
                    regularExpression: /^[0][0-9]{0,11}$/
                }
                onEditingFinished: {
                    if (text.length !== 12) {
                        checkCCCD_text.visible = true
                        check_CCCD = 0
                    } else {
                        checkCCCD_text.visible = false
                        check_CCCD = 1
                    }
                }
            }

            Text {
                id: _text5
                x: 59
                y: 157
                width: 112
                height: 31
                text: qsTr("Phone No.")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: phoneField
                x: 59
                y: 194
                width: 313
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

            Text {
                id: _text6
                x: 935
                y: 157
                width: 167
                height: 31
                text: qsTr("Date of Birth")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                x: 491
                y: 194
                id:  emailField
                width: 313
                height: 41
                placeholderText: qsTr("XXXXXXXXXX@gmail.com")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
            }

            Text {
                id: _text7
                x: 490
                y: 157
                width: 91
                height: 31
                text: qsTr("Mail")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: dateField
                x: 935
                y: 194
                width: 320
                height: 41
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
                        check_date =0
                    } else {
                        let formattedDate = validateDate(text)
                        if (!formattedDate) {
                            checkdate_text.text = "Invalid date format or value!"
                            checkdate_text.visible = true
                            check_date =0
                        } else {
                            checkdate_text.visible = false
                            text = formattedDate
                            check_date =1
                        }
                    }
                }
            }

            Text {
                id: _text8
                x: 59
                y: 277
                width: 91
                height: 31
                text: qsTr("sex")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            ComboBox {
                id: sexField
                x: 59
                y: 314
                width: 181
                height: 41
                flat: false
                editable: false
                font.pointSize: 14
                font.family: "Times New Roman"
                model: ListModel {
                    ListElement { sex: "Male" }
                    ListElement { sex: "Female" }
                    ListElement { sex: "Other" }
                }

                textRole: "sex"
                displayText :  "Select sex";
                currentIndex: -1
                delegate: ItemDelegate {
                    width: sexField.width
                    contentItem: Text {
                        text: model.sex
                        font.pointSize: 14
                        font.family: "Times New Roman"
                    }
                }

                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        displayText = model.get(currentIndex).sex;
                    }
                }
            }

            Text {
                id: _text9
                x: 490
                y: 277
                width: 91
                height: 31
                text: qsTr("Address")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: addressField
                x: 490
                y: 323
                width: 393
                height: 79
                verticalAlignment: Text.AlignTop
                placeholderText: qsTr("Xã xxxxx, huyện xxxxxx, thành phố xxxxxxxxxx")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                leftPadding: 14
                wrapMode: TextEdit.Wrap
            }


            Text {
                id: _text11
                x: 59
                y: 480
                width: 176
                height: 29
                text: qsTr("Department")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            ComboBox {
                id: departmentField
                x: 59
                y: 508
                width: 320
                height: 41
                font.pointSize: 14
                font.family: "Times New Roman"
                flat: false
                editable: false

                model: ListModel {
                    ListElement { department: "Noi khoa" }
                    ListElement { department: "Ngoai khoa" }
                    ListElement { department: "Khoa Tai-Mui-Hong"}
                    ListElement { department: "Khoa Mat"}
                    ListElement { department: "Khoa Da Lieu"}
                    ListElement { department: "Khoa Tim Mach" }
                    ListElement { department: "Khoa Than - Tiet Nieu" }
                    ListElement { department: "Khoa Gan-Mat"}
                    ListElement { department: "Khoa Than Kinh"}
                    ListElement { department: "Khoa Ho Hap"}
                    ListElement { department: "Khoa Xuong Khop"}
                    ListElement { department: "Khoa Khac"}
                }
                textRole: "department"
                displayText: "Select Department"
                currentIndex: -1


                delegate: ItemDelegate {
                    width: departmentField.width
                    contentItem: Text {
                        text: model.department
                        font.pointSize: 14
                        font.family: "Times New Roman"
                    }
                }

                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        displayText = model.get(currentIndex).department;
                    }
                }
            }

            Text {
                id: _text12
                x: 479
                y: 480
                width: 176
                height: 29
                text: qsTr("Working hours")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            RowLayout {
                id: rowLayout
                x: 479
                y: 508
                width: 416
                height: 55
                spacing: 15

                Text {
                    id: _text13
                    x: 99
                    y: 816
                    width: 64
                    height: 36
                    text: qsTr("From")
                    font.pixelSize: 25
                    font.family: "Times New Roman"
                    font.bold: false
                }



                ComboBox {
                    id: shift1Field
                    x: 188
                    y: 813
                    width: 160
                    height: 41

                    font.pointSize: 14
                    font.family: "Times New Roman"
                    flat: false
                    editable: false
                    displayText: "Select shift 1"
                    model: ListModel {
                        ListElement { hour: "07:00" }
                        ListElement { hour: "08:00" }
                        ListElement { hour: "09:00" }
                        ListElement { hour: "10:00" }
                        ListElement { hour: "11:00" }
                        ListElement { hour: "12:00" }
                        ListElement { hour: "13:00" }
                        ListElement { hour: "14:00" }
                        ListElement { hour: "15:00" }
                        ListElement { hour: "16:00" }
                        ListElement { hour: "17:00" }
                    }

                    textRole: "hour"
                    currentIndex: -1

                    delegate: ItemDelegate {
                        width: shift1Field.width
                        contentItem: Text {
                            text: model.hour
                            font.pointSize: 14
                            font.family: "Times New Roman"
                        }
                    }

                    onCurrentIndexChanged: {
                        if (currentIndex >= 0) {
                            displayText = model.get(currentIndex).hour;
                        }
                    }

                }

                Text {
                    id: _text14
                    x: 386
                    y: 836
                    width: 28
                    height: 38
                    text: qsTr("to")
                    font.pixelSize: 25
                    font.family: "Times New Roman"
                    font.bold: false


                }

                ComboBox {
                    id: shift2Field
                    x: 421
                    y: 829
                    width: 160
                    height: 41
                    font.pointSize: 14
                    font.family: "Times New Roman"
                    flat: false
                    editable: false
                    displayText: "Select shift 2"

                    model: ListModel {
                        ListElement { hour: "12:00" }
                        ListElement { hour: "13:00" }
                        ListElement { hour: "14:00" }
                        ListElement { hour: "15:00" }
                        ListElement { hour: "16:00" }
                        ListElement { hour: "17:00" }
                        ListElement { hour: "18:00" }
                        ListElement { hour: "19:00" }
                        ListElement { hour: "20:00" }
                        ListElement { hour: "21:00" }
                        ListElement { hour: "22:00" }
                        ListElement { hour: "23:00" }
                    }

                    textRole: "hour"
                    currentIndex: -1

                    delegate: ItemDelegate {
                        width: shift2Field.width
                        contentItem: Text {
                            text: model.hour
                            font.pointSize: 14
                            font.family: "Times New Roman"
                        }
                    }

                    onCurrentIndexChanged: {
                        if (currentIndex >= 0) {
                            displayText = model.get(currentIndex).hour;
                        }
                    }

                }
            }


            Text {
                id: _text15
                x: 925
                y: 480
                width: 91
                height: 35
                text: qsTr("Days")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }
            // ComboBox {
            //     id: comboBox5
            //     x: 592
            //     y: 592
            //     width: 181
            //     height: 41
            //     font.pointSize: 14
            //     font.family: "Times New Roman"
            //     flat: false
            //     editable: false

            //     model: ListModel {
            //             ListElement { day: "Monday" }
            //             ListElement { day: "Tuesday" }
            //             ListElement { day: "Wednesday"}
            //             ListElement { day: "Wednesday"}
            //             ListElement { day: "Thursday"}
            //             ListElement { day: "Friday"}
            //             ListElement { day: "Saturday"}
            //             ListElement { day: "Sunday"}
            //     }

            //     textRole: "day"
            //     displayText :  "Select Day";
            //     currentIndex: -1

            //     delegate: ItemDelegate {
            //         width: comboBox.width
            //         contentItem: Text {
            //             text: model.day
            //             font.pointSize: 14
            //             font.family: "Times New Roman"
            //         }
            //     }

            //     onCurrentIndexChanged: {
            //         if (currentIndex >= 0) {
            //             displayText = model.get(currentIndex).sex;
            //         }
            //     }
            // }

            ListView {
                id: dayOfWeek
                x: 994
                y: 487
                width: 281
                height: 274
                spacing: 40

                model: ListModel {
                    ListElement { day: "Monday"; selected: false }
                    ListElement { day: "Tuesday"; selected: false }
                    ListElement { day: "Wednesday"; selected: false }
                    ListElement { day: "Thursday"; selected: false }
                    ListElement { day: "Friday"; selected: false }
                    ListElement { day: "Saturday"; selected: false }
                    ListElement { day: "Sunday"; selected: false }
                }

                delegate: Item {
                    Row {
                        spacing: 10
                        CheckBox {
                            id: checkBox
                            checked: model.selected
                            onCheckedChanged: {
                                model.selected = checked;
                            }
                        }
                        Text {
                            text: model.day
                            font.pointSize: 14
                            font.family: "Times New Roman"
                        }
                    }
                }
            }

            Button {
                id: button
                x: 1049
                y: 809
                width: 131
                height: 49
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
                    x: (1800 - width) / 2 + 200
                    y: (1080 - height) / 2 - 80
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
                            text: "Don't save this Doctor?"
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
                            anchors.horizontalCenter: parent.horizontalCenter

                            Button {
                                text: "Yes"
                                width: 100
                                height: 40
                                onClicked: {
                                    console.log("Yes clicked")
                                    confirmationCancle.close()
                                    stackView1.pop()
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
                x: 1206
                y: 809
                width: 131
                height: 49
                text: qsTr("Update")
                icon.width: 20
                font.pointSize: 20
                font.family: "Times New Roman"
                font.bold: true
                onClicked: {
                    if (    check_name && check_doctorId && check_CCCD && check_phone && check_date
                            && departmentField.text !== "" && sexField.currentIndex !== -1 && departmentField.currentIndex !== -1
                            && shift1Field.currentIndex !== -1 && shift2Field.currentIndex !== -1) {

                        confirmationDialog.open()
                    } else {
                        messageDialog.open()
                    }
                }

                Dialog {
                    id: confirmationDialog
                    width: 400
                    height: 200
                    x: (1800 - width) / 2 + 200
                    y: (1080 - height) / 2 - 80
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
                            anchors.horizontalCenter: parent.horizontalCenter

                            Button {
                                text: "Yes"
                                width: 100
                                height: 40
                                onClicked: {
                                    console.log("Yes clicked")
                                    let selectedDays = [];
                                    for (let i = 0; i < dayOfWeek.model.count; i++) {
                                        let element = dayOfWeek.model.get(i);
                                        if (element.selected) {
                                            selectedDays.push(element.day);
                                        }
                                    }

                                    doctor.getDoctorData(
                                                doctorIdField.text,
                                                //departmentField.text,
                                                //"tim",
                                                departmentField.currentText,
                                                phoneField.text,
                                                nameField.text,
                                                addressField.text,
                                                emailField.text,
                                                dateField.text,
                                                personalIDField.text,
                                                // sexField.text
                                                //    "man"
                                                sexField.currentText,
                                                selectedDays,
                                                selectedDays.length,
                                                shift1Field.currentText,
                                                shift2Field.currentText,
                                                )
                                    // Lưu thông tin vào file
                                    doctor.addDoctorData();
                                    confirmationDialog.close()
                                    completedialog.open()
                                    stackView1.pop()
                                    doctor.showDoctorDataFromFile()
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
                id: messageDialog
                width: 300
                height: 150
                x: (1920 - width) / 2
                y: (1080 - height) / 2 -100
                anchors.centerIn: root.Center
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

            Dialog {
                id: completedialog
                width: 300
                height: 150
                x: (1920 - width) / 2
                y: (1080 - height) / 2 -100
                anchors.centerIn: root.Center
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
                Timer {
                    id: autoCloseTimer
                    interval: 3000  // 2 giây
                    running: true
                    repeat: false
                    onTriggered: {
                        completedialog.visible = false
                    }
                }
            }
        }
    }
}
