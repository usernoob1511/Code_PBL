import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Window
Item {
    id: rootMedicine
    width: 1500
    height: 1080

    property string code: ""
    property int medicine_index:-1

    property int check_name: 0
    property int check_Id: 0
    property int check_quantity: 0
    property int check_usage: 0
    property int check_expiredate: 0

    states: [
        State {
            name: "Allmedicine"
            PropertyChanges { target: allMedicineRec; color: "white" }
        },
        State {
            name: "MedicineNotUsed"
            PropertyChanges { target: mcbuRec; color: "white" }
        }
    ]



    Rectangle {
        id: rectangle1
        x: 68
        y: 112
        width: 1365
        height: 831
        color: "#f0f0f0"
        border.color: "#020202"
        border.width: 3

        property int selectedIndex: -1

        Rectangle {
            id: allMedicineRec
            x: 0
            y: 1
            width: 683
            height: 90
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3
        }

        Rectangle {
            id:mcbuRec
            x: 681
            y: 1
            width: 685
            height: 90
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3
        }

        Text {
            id: allMedicineLable
            x: 250
            y: 24
            width: 184
            height: 43
            text: qsTr("All Medicine")
            font.pixelSize: 30
            font.bold: true
            font.family: "Times New Roman"
        }
        Text {
            id: mcbuLable
            x: 877
            y: 24
            width: 293
            height: 43
            text: qsTr("Medicine not used")
            font.pixelSize: 30
            font.bold: true
            font.family: "Times New Roman"
        }

        MouseArea {
            id: allMedicineMouse
            x: 0
            y: 1
            width: 685
            height: 90
            onClicked: {
                rootMedicine.state = "Allmedicine"
                medicine.showMedicineDataFromFile()
            }
        }
        MouseArea {
            id: mcbuMouse
            x: 681
            y: 0
            width: 685
            height: 90
            onClicked: {
                rootMedicine.state = "MedicineNotUsed"
                medicine.showSearchMedicineNotUsed()
            }
        }
        ListView {
            id: listviewMedicine
            anchors.fill: parent
            anchors.leftMargin: 26
            anchors.rightMargin: 281
            anchors.topMargin: 185
            anchors.bottomMargin: 86
            model: medicineModel
            orientation: ListView.Vertical
            clip: true

            ScrollBar.vertical: ScrollBar {
                policy: ScrollBar.AlwaysOn
            }

            delegate: Item {
                width: parent.width
                height: 70  // Đặt chiều cao lớn hơn một chút để có khoảng cách giữa các hàng
                property bool selected: (index === rectangle1.selectedIndex)

                Rectangle {
                    id: rectangledata
                    width: parent.width
                    height: parent.height
                    color: selected ? "#0176c5" : (index % 2 === 0) ? "#f4f5f2" : "#fffffd"
                    border.color: "black"

                    Row {
                        spacing: 50  // Tăng khoảng cách giữa các cột để giãn đều
                        anchors.left: rectangledata.left
                        anchors.leftMargin: 30
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            text: code
                            width: 70
                            font.pixelSize: 22
                            horizontalAlignment: Text.AlignLeft  // Căn lề trái
                            color: selected ? "white" : "black"
                            font.family: "Times New Roman"
                        }
                        Text {
                            text: name
                            width: 200
                            font.pixelSize: 22
                            horizontalAlignment: Text.AlignLeft  // Căn lề trái
                            color: selected ? "white" : "black"
                            font.family: "Times New Roman"
                        }
                        Text {
                            text: quantity
                            width: 80
                            font.pixelSize: 22
                            horizontalAlignment: Text.AlignLeft  // Căn lề trái
                            color: selected ? "white" : "black"
                            font.family: "Times New Roman"
                        }
                        Text {
                            text: usageInstructions
                            width: 260
                            font.pixelSize: 22
                            horizontalAlignment: Text.AlignLeft  // Căn lề trái
                            color: selected ? "white" : "black"
                            font.family: "Times New Roman"
                        }

                        Text {
                            text: expiryDate
                            width: 120
                            font.pixelSize: 22
                            horizontalAlignment: Text.AlignLeft  // Căn lề trái
                            color: selected ? "white" : "black"
                            font.family: "Times New Roman"
                        }
                    }
                }
                MouseArea {
                    id: mouseArea
                    anchors.fill: parent
                    anchors.leftMargin: 0
                    anchors.rightMargin: 0
                    anchors.topMargin: 0
                    anchors.bottomMargin: 0
                    hoverEnabled: true
                    onClicked: {
                        rectangle1.selectedIndex = index
                    }
                }
            }


        }

        Rectangle {
            id:rectangleHead
            x: 26
            y: 129
            width: listviewMedicine.width
            height: 60
            color: "#d3d3d3"  // Màu nền tiêu đề
            border.color: "black"

            Row {
                width: 915
                height: 26
                spacing: 50
                anchors.left: parent.left
                anchors.leftMargin: 30
                anchors.verticalCenter: parent.verticalCenter

                Text {
                    text: "Code"
                    width: 70
                    font.pixelSize: 25
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    font.family: "Times New Roman"
                    color: "black"
                }
                Text {
                    text: "Name"
                    width: 200
                    font.pixelSize: 25
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    font.family: "Times New Roman"
                    color: "black"
                }
                Text {
                    text: "Quantity"
                    width: 80
                    font.pixelSize: 25
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    font.family: "Times New Roman"
                    color: "black"
                }
                Text {
                    text: "Usage Instruction"
                    width: 260
                    font.pixelSize: 25
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    font.family: "Times New Roman"
                    color: "black"
                }
                Text {
                    text: "Expiry Date"
                    width: 120
                    font.pixelSize: 25
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    font.family: "Times New Roman"
                    color: "black"
                }
            }
        }

        Button{
            id: registerMedicine
            x: 1127
            y: 572
            width: 184
            height: 40
            text: qsTr("Add New")
            icon.width: 24
            font.bold: true
            font.pointSize: 18
            font.family: "Times New Roman"

            background: Rectangle {
                id:registerMedicineColor
                border.width: 2
                border.color: "black"
                color: "white"
            }

            onPressed: {
                registerMedicineColor.color = "#black"
            }
            onReleased: {
                registerMedicineColor.color = "white"
            }
            onClicked: {
                stackView2.push("Addnewmedicine_page.qml")
            }
        }
    }

    Button {
        id:editMedicine
        x: 1197
        y: 475
        width: 184
        height: 40
        text: qsTr("Edit")
        icon.width: 24
        font.bold: true
        font.pointSize: 18
        font.family: "Times New Roman"
        background: Rectangle {
            id:editMedicineColor
            border.width: 2
            border.color: "black"
            color: "white"
        }
        onPressed: {
            editMedicineColor.color = "#66ffcc"
        }
        onReleased: {
            editMedicineColor.color = "white"
        }
        onClicked: {
            if (rectangle1.selectedIndex !== -1) {
                medicine_index = rectangle1.selectedIndex
                code = medicineModel.get_medicineCode(rectangle1.selectedIndex)
                stackView2.push("EditMedicine_page.qml",{index: medicine_index, id: code})
            } else {
                mainWindow.showDialogSelect()
            }
        }
    }

    Button {
        id:deleteMedicine
        x: 1197
        y: 585
        width: 184
        height: 40
        text: qsTr("Delete")
        icon.width: 24
        font.bold: true
        font.pointSize: 18
        font.family: "Times New Roman"
        background: Rectangle {
            id:deleteMedicineColor
            border.width: 2
            border.color: "black"
            color: "white"
        }
        onPressed: {
            deleteMedicineColor.color = "#66ffcc"
        }
        onReleased: {
            deleteMedicineColor.color = "white"
        }
        onClicked: {
            if (rectangle1.selectedIndex !== -1) {
                medicine_index = rectangle1.selectedIndex
                code = medicineModel.get_medicineCode(rectangle1.selectedIndex)
                confirmationDialog.open()
            } else {
                mainWindow.showDialogSelect()
            }
        }

        Dialog {
            id: confirmationDialog
            width: 400
            height: 200
            x: 414 + (rootMedicine.width - width)/2
            y: (rootMedicine.height - height)/2
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
                    text: "Are you sure delete this medicine?"
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
                            medicineModel.removeAt(medicine_index)
                            medicine.deleteMedicineData(code)
                            confirmationDialog.close()
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

    // Button {
    //     width: 201
    //     height: 135
    //     text: "Doan Ngoc Minh"
    //     anchors.verticalCenterOffset: 477
    //     anchors.horizontalCenterOffset: -649
    //     anchors.centerIn: parent
    //     onClicked: {
    //         medicine.showMedicineDataFromFile()
    //     }
    // }

    Component.onCompleted: {
        medicine.showMedicineDataFromFile()
    }

    TextField {
        id: textField
        x: 261
        y: 868
        width: 279
        height: 48
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 15
        font.family: "Times New Roman"
        placeholderText: qsTr("Search Medicine...")
        leftPadding: 15
        onTextChanged: {
            if (rootMedicine.state === "Allmedicine") {

                if (text !== "") {
                    medicine.showSearchMedicine(text)
                } else {
                    medicine.showMedicineDataFromFile()
                }

            } else {

                if (text !== "") {
                    medicine.showSearchMedicine(text)
                } else {
                    medicine.showSearchMedicineNotUsed()
                }

            }
        }
    }

    Text {
        id: _text_normal
        x: 177
        y: 877
        width: 78
        height: 39
        text: qsTr("Search")
        font.pixelSize: 24
        font.family: "Times New Roman"
    }

    Text {
        id: _text1
        x: 665
        y: 36
        width: 170
        height: 61
        text: qsTr("Medicine")
        font.pixelSize: 40
        font.family: "Times New Roman"
        font.bold: true
    }


}

