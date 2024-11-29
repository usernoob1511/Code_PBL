import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Window

Item {
    id: rootDoctor
    width: 1500
    height: 1080

    property string doc_id: ""
    property int index:-1

    states: [
        State {
            name: "Alldoctor"
            PropertyChanges { target: allDoctorRec; color: "white" }
        },
        State {
            name: "Availdoctor"
            PropertyChanges { target: availDoctorRec; color: "white" }
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
            id: allDoctorRec
            x: 0
            y: 1
            width: 683
            height: 90
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3
        }

        Rectangle {
            id: availDoctorRec
            x: 681
            y: 1
            width: 685
            height: 90
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3
        }

        Text {
            id: allDoctorLable
            x: 275
            y: 24
            width: 136
            height: 43
            text: qsTr("All Doctor")
            font.pixelSize: 30
            font.bold: true
            font.family: "Times New Roman"
        }
        Text {
            id: availDoctorLable
            x: 900
            y: 24
            width: 248
            height: 36
            text: qsTr("Doctor available")
            font.pixelSize: 30
            font.bold: true
            font.family: "Times New Roman"
        }

        MouseArea {
            id: allDoctorMouse
            x: 0
            y: 1
            width: 685
            height: 90
            onClicked: {
                rootDoctor.state = "Alldoctor"
                doctor.showDoctorDataFromFile()

            }
        }
        MouseArea {
            id: availDoctorMouse
            x: 681
            y: 0
            width: 685
            height: 90
            onClicked: {
                rootDoctor.state = "Availdoctor"
                doctor.showDoctorOnline()
            }
        }
        ListView {
            id: listviewDoctor
            anchors.fill: parent
            anchors.leftMargin: 26
            anchors.rightMargin: 281
            anchors.topMargin: 185
            anchors.bottomMargin: 90
            model: doctorModel
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
                        anchors.left: parent.left
                        anchors.leftMargin: 30
                        anchors.verticalCenter: parent.verticalCenter

                        Text {
                            text: id
                            width: 150
                            font.pixelSize: 22
                            horizontalAlignment: Text.AlignLeft  // Căn lề trái
                            color: selected ? "white" : "black"
                            font.family: "Times New Roman"
                        }
                        Text {
                            text: name
                            width: 280
                            font.pixelSize: 22
                            horizontalAlignment: Text.AlignLeft  // Căn lề trái
                            color: selected ? "white" : "black"
                            font.family: "Times New Roman"
                        }
                        Text {
                            text: cccd
                            width: 200
                            font.pixelSize: 22
                            horizontalAlignment: Text.AlignLeft  // Căn lề trái
                            color: selected ? "white" : "black"
                            font.family: "Times New Roman"
                        }
                        Text {
                            text: phone
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
            // anchors.bottom: listviewDoctor.top
            // anchors.bottomMargin: 0
            width: listviewDoctor.width
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
                    text: "Doctor ID"
                    width: 150
                    font.pixelSize: 25
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    font.family: "Times New Roman"
                    color: "black"
                }
                Text {
                    text: "Name"
                    width: 280
                    font.pixelSize: 25
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    font.family: "Times New Roman"
                    color: "black"
                }
                Text {
                    text: "CCCD"
                    width: 200
                    font.pixelSize: 25
                    font.bold: true
                    horizontalAlignment: Text.AlignLeft
                    font.family: "Times New Roman"
                    color: "black"
                }
                Text {
                    text: "Phone"
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
            id: registerDoctor
            x: 1144
            y: 606
            width: 184
            height: 40
            text: qsTr("Register Doctor")
            icon.width: 24
            font.bold: true
            font.pointSize: 18
            font.family: "Times New Roman"

            background: Rectangle {
                id:registerDoctorColor
                border.width: 2
                border.color: "black"
                color: "white"
            }

            MouseArea{
                anchors.fill: registerDoctor
                anchors.leftMargin: -3
                anchors.rightMargin: 3
                anchors.topMargin: 3
                anchors.bottomMargin: -3
                onPressed: {
                    registerDoctorColor.color = "#black"
                }
                onReleased: {
                    registerDoctorColor.color = "white"
                }

                onClicked: {
                    stackView1.push("Addnewdoctor_page.qml")
                }
            }
        }
    }

    Button {
        id: viewDoctor
        x: 1214
        y: 409
        width: 184
        height: 40
        text: qsTr("View")
        icon.width: 24
        font.bold: true
        font.pointSize: 18
        font.family: "Times New Roman"
        background: Rectangle {
            id:viewDoctorColor
            border.width: 2
            border.color: "black"
            color: "white"
        }

        onPressed: {
            viewDoctorColor.color = "#66ffcc"
        }
        onReleased: {
            viewDoctorColor.color = "white"
        }
        onClicked: {

            if (rectangle1.selectedIndex !== -1) {
                index = rectangle1.selectedIndex
                doc_id= doctorModel.get_doctorId(rectangle1.selectedIndex)
                stackView1.push("ViewandEdit_page.qml",{doc_id: doc_id, index: index, state: "viewDoctor" })
            } else {
                mainWindow.showDialogSelect()
            }
        }
    }

    Button{
        id:editDoctor
        x: 1214
        y: 520
        width: 184
        height: 40
        text: qsTr("Edit")
        icon.width: 24
        font.bold: true
        font.pointSize: 18
        font.family: "Times New Roman"

        background: Rectangle {
            id:editDoctorColor
            border.width: 2
            border.color: "black"
            color: "white"
        }

        onPressed: {
            editDoctorColor.color = "#66ffcc"
        }
        onReleased: {
            editDoctorColor.color = "white"
        }

        onClicked: {
            if (rectangle1.selectedIndex !== -1) {
                index = rectangle1.selectedIndex
                doc_id= doctorModel.get_doctorId(rectangle1.selectedIndex)
                stackView1.push("ViewandEdit_page.qml",{doc_id: doc_id, index: index, state: "editDoctor" })
            } else {
                mainWindow.showDialogSelect()
            }
        }
    }

    Button {
        id:deleteDoctor
        x: 1214
        y: 625
        width: 184
        height: 40
        text: qsTr("Delete")
        icon.width: 24
        font.bold: true
        font.pointSize: 18
        font.family: "Times New Roman"
        background: Rectangle {
            id:deleteDoctorColor
            border.width: 2
            border.color: "black"
            color: "white"
        }
        onPressed: {
            deleteDoctorColor.color = "#66ffcc"
        }
        onReleased: {
            deleteDoctorColor.color = "white"
        }
        onClicked: {
            if (rectangle1.selectedIndex !== -1) {
                index = rectangle1.selectedIndex
                doc_id= doctorModel.get_doctorId(rectangle1.selectedIndex)
                confirmationDialog.open()
            } else {
                mainWindow.showDialogSelect()
            }
        }

        Dialog {
            id: confirmationDialog
            width: 400
            height: 200
            x: 414 + (rootDoctor.width - width)/2
            y: (rootDoctor.height - height)/2
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
                    text: "Are you sure you want to delete this doctor?"
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
                            doctorModel.removeAt(index)
                            doctor.deleteDoctorData(doc_id)
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
    //         if (rootDoctor.state === "Alldoctor") {
    //             doctor.showDoctorDataFromFile()
    //         } else {
    //             doctor.showDoctorOnline()
    //         }
    //     }
    // }
    Component.onCompleted: {
        if (state === "Alldoctor") {
            doctor.showDoctorDataFromFile()
        } else {
            doctor.showDoctorOnline()
        }
    }

    TextField {
        id: searchField
        x: 261
        y: 868
        width: 279
        height: 48
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 15
        font.family: "Times New Roman"
        placeholderText: qsTr("Search Doctor...")
        leftPadding: 15
        onTextChanged: {
            if(rootDoctor.state === "Alldoctor") {
                if (text !== "") {
                    doctor.showSearchDoctor(text)
                } else {
                    doctor.showDoctorDataFromFile()
                }
            } else {
                if (text !== "") {
                    doctor.showSearchDoctor(text)
                } else {
                    doctor.showDoctorOnline()
                }
            }
        }
    }

    Text {
        id: _text
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
        x: 691
        y: 50
        width: 119
        height: 57
        text: qsTr("Doctor")
        font.pixelSize: 40
        font.family: "Times New Roman"
        font.bold: true
    }
}
