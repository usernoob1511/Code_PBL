import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root
    width: 1920
    height: 1080

    Rectangle {
        id: rectangle
        x: 420
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
            text: qsTr("Add Patient Details")
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
                id: textField
                x: 59
                y: 73
                width: 281
                height: 41
                font.italic: false
                font.family: "Times New Roman"
                font.pointSize: 14
                placeholderText: qsTr("Nguyen Van A")
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
                id: textField1
                x: 491
                y: 73
                width: 313
                height: 41
                placeholderText: qsTr("XXXXXXXXX")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            Text {
                id: _text3
                x: 935
                y: 39
                width: 258
                height: 34
                text: "Registration Date"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: textField2
                x: 935
                y: 73
                width: 313
                height: 41
                placeholderText: qsTr("01/01/1900")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            Text {
                id: _text4
                x: 59
                y: 157
                width: 91
                height: 31
                text: qsTr("CNIC")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: textField3
                x: 59
                y: 188
                width: 281
                height: 41
                placeholderText: qsTr("048205XXXXXX")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            Text {
                id: _text5
                x: 490
                y: 157
                width: 112
                height: 31
                text: qsTr("Phone No.")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: textField4
                x: 491
                y: 188
                width: 313
                height: 41
                placeholderText: qsTr("0795513XXX")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
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
                id: textField5
                x: 935
                y: 194
                width: 313
                height: 41
                placeholderText: qsTr("01/01/1900")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            Text {
                id: _text7
                x: 59
                y: 277
                width: 91
                height: 31
                text: qsTr("Mail")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: textField6
                x: 59
                y: 314
                width: 320
                height: 41
                placeholderText: qsTr("XXXXXXXXXX@gmail.com")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            Text {
                id: _text8
                x: 490
                y: 277
                width: 91
                height: 31
                text: qsTr("Gender")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            ComboBox {
                id: comboBox
                x: 491
                y: 314
                width: 181
                height: 41
                flat: false
                editable: false
                font.pointSize: 14
                font.family: "Times New Roman"
                model: ListModel {
                        ListElement { gender: "Male" }
                        ListElement { gender: "Female" }
                        ListElement { gender: "Other" }
                }

                textRole: "gender"
                displayText :  "Select Gender";
                currentIndex: -1
                delegate: ItemDelegate {
                    width: comboBox.width
                    contentItem: Text {
                        text: model.gender
                        font.pointSize: 14
                        font.family: "Times New Roman"
                    }
                }

                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        displayText = model.get(currentIndex).gender;
                    }
                }
            }

            Text {
                id: _text9
                x: 935
                y: 277
                width: 91
                height: 31
                text: qsTr("Address")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: textField7
                x: 935
                y: 319
                width: 391
                height: 123
                verticalAlignment: Text.AlignTop
                placeholderText: qsTr("Xã xxxxx, huyện xxxxxx, thành phố xxxxxxxxxx")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            Text {
                id: _text10
                x: 59
                y: 425
                width: 104
                height: 29
                text: qsTr("Gurdian")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
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
            }

            TextField {
                id: textField8
                x: 59
                y: 460
                width: 281
                height: 41
                placeholderText: qsTr("Huynh Thi B")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            Text {
                id: _text11
                x: 490
                y: 425
                width: 176
                height: 29
                text: qsTr("Relation")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: textField9
                x: 490
                y: 460
                width: 281
                height: 41
                placeholderText: qsTr("Parents")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            Text {
                id: _text12
                x: 59
                y: 551
                width: 162
                height: 30
                text: "Disease Name"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text13
                x: 490
                y: 551
                width: 162
                height: 30
                text: "Patient Status"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text14
                x: 940
                y: 551
                width: 162
                height: 30
                text: "Type Patient"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: textField10
                x: 59
                y: 587
                width: 281
                height: 41
                placeholderText: qsTr("Diabetes")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            TextField {
                id: textField11
                x: 490
                y: 587
                width: 335
                height: 157
                verticalAlignment: Text.AlignTop
                placeholderText: qsTr("...")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }

            ComboBox {
                id: _comboBox
                x: 940
                y: 587
                width: 247
                height: 41
                flat: false
                editable: false
                font.pointSize: 14
                font.family: "Times New Roman"
                model: ListModel {
                        ListElement { patient: "Inpatient" }
                        ListElement { patient: "Outpatient" }
                        ListElement { patient: "Transferred patient" }
                }

                textRole: "patient"
                displayText :  "Select Type Patient";
                currentIndex: -1
                delegate: ItemDelegate {
                    width: comboBox.width
                    contentItem: Text {
                        text: model.patient
                        font.pointSize: 14
                        font.family: "Times New Roman"
                    }
                }

                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        displayText = model.get(currentIndex).gender;
                    }
                }
            }
        }


    }
}

