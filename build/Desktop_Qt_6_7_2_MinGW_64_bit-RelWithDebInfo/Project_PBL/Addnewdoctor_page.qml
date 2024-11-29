import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root
    width: 1500
    height: 1080

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
                id: textField
                x: 59
                y: 73
                width: 281
                height: 41
                verticalAlignment: Text.AlignTop
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
                width: 176
                height: 29
                text: qsTr("Specialization")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            ComboBox {
                id: comboBox1
                x: 59
                y: 460
                width: 301
                height: 40
                textRole: "Gender"
                model: ["Select Gender", "Male", "Female", "Other"]
                font.pointSize: 14
                font.family: "Times New Roman"
                flat: false
                editable: false
                displayText: "Select Specialization"
            }


            Text {
                id: _text11
                x: 490
                y: 425
                width: 176
                height: 29
                text: qsTr("Department")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            ComboBox {
                id: comboBox2
                x: 490
                y: 460
                width: 320
                height: 41
                font.pointSize: 14
                font.family: "Times New Roman"
                flat: false
                editable: false

                model: ListModel {
                        ListElement { department: "Internal Medicine" }
                        ListElement { department: "Surgery" }
                        ListElement { department: "Obstetrics and Gynecology"}
                        ListElement { department: "Pediatrics"}
                        ListElement { department: "Emergency Department"}
                }

                textRole: "department"
                displayText :  "Select Department";
                currentIndex: -1
                delegate: ItemDelegate {
                    width: comboBox.width
                    contentItem: Text {
                        text: model.department
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
                id: _text12
                x: 59
                y: 549
                width: 176
                height: 29
                text: qsTr("Working hours")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            RowLayout {
                id: rowLayout
                x: 59
                y: 584
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
                    id: comboBox3
                    x: 188
                    y: 813
                    width: 160
                    height: 41
                    textRole: "Gender"
                    model: ["Select Gender", "Male", "Female", "Other"]
                    font.pointSize: 14
                    font.family: "Times New Roman"
                    flat: false
                    editable: false
                    displayText: "8:00:00 AM"
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
                    id: comboBox4
                    x: 421
                    y: 829
                    width: 160
                    height: 41
                    textRole: "Gender"
                    model: ["Select Gender", "Male", "Female", "Other"]
                    font.pointSize: 14
                    font.family: "Times New Roman"
                    flat: false
                    editable: false
                    displayText: "8:00:00 PM"
                }
            }


            Text {
                id: _text15
                x: 591
                y: 549
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
            //             displayText = model.get(currentIndex).gender;
            //         }
            //     }
            // }

            ListView {
                id: listView
                x: 660
                y: 557
                width: 271
                height: 281
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
                            anchors.top: checkBox.top
                            anchors.topMargin: -3
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

        }
    }
}

