import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import QtQuick.Window

Item {
    id: rootPatient
    width: 1500
    height: 1080

    property string inpatient_id: ""
    property int in_index:-1
    property string outpatient_id: ""
    property int out_index:-1

    states: [
        State {
            name: "Inpatient"
            PropertyChanges { target: listviewPatient; model: inpatientModel }
            PropertyChanges { target: inPatientRec; color: "white" }
        },
        State {
            name: "Outpatient"
            PropertyChanges { target: listviewPatient; model: outpatientModel }
            PropertyChanges { target: outPatientRec; color: "white" }
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

        Rectangle {
            id: inPatientRec
            x: 0
            y: 1
            width: 683
            height: 90
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3
        }

        Rectangle {
            id: outPatientRec
            x: 681
            y: 1
            width: 685
            height: 90
            color: "#f0f0f0"
            border.color: "#020202"
            border.width: 3
        }

        Text {
            id: inPatientLable
            x: 264
            y: 24
            width: 136
            height: 43
            text: qsTr("In Patient")
            font.pixelSize: 30
            font.bold: true
            font.family: "Times New Roman"
        }
        Text {
            id: outPatientLable
            x: 959
            y: 24
            width: 160
            height: 36
            text: qsTr("Out Patient")
            font.pixelSize: 30
            font.bold: true
            font.family: "Times New Roman"
        }

        MouseArea {
            id: inPatientMouse
            x: 0
            y: 1
            width: 685
            height: 90
            onClicked: {
                rootPatient.state= "Inpatient"
                inpatient.showIn_PatientDataFromFile()
            }
        }
        MouseArea {
            id: outPatientMouse
            x: 681
            y: 0
            width: 685
            height: 90

            onClicked: {
                rootPatient.state= "Outpatient"
                outpatient.showOut_PatientDataFromFile()
            }
        }

        property int selectedIndex: -1  // Chỉ mục của mục được chọn (-1 nghĩa là không có mục nào được chọn)

        ListView {
            id: listviewPatient
            anchors.fill: parent
            anchors.leftMargin: 26
            anchors.rightMargin: 281
            anchors.topMargin: 178
            anchors.bottomMargin: 88
            //model: state == "Inpatient" ? inpatientModel : outpatientModel
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
                            text: patientId
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
            anchors.bottom: listviewPatient.top
            anchors.bottomMargin: 0
            width: listviewPatient.width
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
                    text: "Patient ID"
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
            id: registerPatient
            x: 1145
            y: 615
            width: 184
            height: 40
            text: qsTr("Register Patient")
            icon.width: 24
            font.bold: true
            font.pointSize: 18
            font.family: "Times New Roman"

            background: Rectangle {
                id:registerPatientColor
                border.width: 2
                border.color: "black"
                color: "white"
            }

            MouseArea{
                anchors.fill: registerPatient
                anchors.leftMargin: -2
                anchors.rightMargin: 2
                anchors.topMargin: 2
                anchors.bottomMargin: -2
                onPressed: {
                    registerPatientColor.color = "#black"
                }
                onReleased: {
                    registerPatientColor.color = "white"
                }

                onClicked: {
                    if (rootPatient.state === "Inpatient") {
                        stackView1.push("Add_In_Out_patient_page.qml",{state: "addInpatient"})
                    } else {
                        stackView1.push("Add_In_Out_patient_page.qml",{state: "addOutpatient"})
                    }
                }
            }
        }
    }

    Button {
        id: viewPatient
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
            id:viewPatientColor
            border.width: 2
            border.color: "black"
            color: "white"
        }

        onPressed: {
            viewPatientColor.color = "#66ffcc"
        }
        onReleased: {
            viewPatientColor.color = "white"
        }
        onClicked: {
            if(rectangle1.selectedIndex !== -1) {
                if (rootPatient.state === "Inpatient") {
                    in_index = rectangle1.selectedIndex
                    inpatient_id= inpatientModel.get_patientId(rectangle1.selectedIndex)
                    stackView1.push("ViewandEdit_Inpatient_page.qml",{inpatient_id: inpatient_id, in_index: in_index, state: "viewInpatient"})
                } else {
                    out_index = rectangle1.selectedIndex
                    outpatient_id= outpatientModel.get_patientId(rectangle1.selectedIndex)
                    stackView1.push("ViewandEdit_Outpatient_page.qml",{outpatient_id: outpatient_id, out_index: out_index, state: "viewOutpatient"})
                }

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
            if(rectangle1.selectedIndex !== -1) {
                if (rootPatient.state === "Inpatient") {
                    in_index = rectangle1.selectedIndex
                    inpatient_id= inpatientModel.get_patientId(rectangle1.selectedIndex)
                    stackView1.push("ViewandEdit_Inpatient_page.qml",{inpatient_id: inpatient_id, in_index: in_index, state: "editInpatient"})
                } else {
                    out_index = rectangle1.selectedIndex
                    outpatient_id= outpatientModel.get_patientId(rectangle1.selectedIndex)
                    stackView1.push("ViewandEdit_Outpatient_page.qml",{outpatient_id: outpatient_id, out_index: out_index, state: "editOutpatient"})
                }

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

                if (rootPatient.state === "Inpatient") {
                    in_index = rectangle1.selectedIndex
                    inpatient_id = inpatientModel.get_patientId(rectangle1.selectedIndex)
                } else {
                    out_index = rectangle1.selectedIndex
                    outpatient_id = outpatientModel.get_patientId(rectangle1.selectedIndex)
                }

                confirmationDialog.open()
            } else {
                mainWindow.showDialogSelect()
            }
        }

        Dialog {
            id: confirmationDialog
            width: 400
            height: 200
            x: 414 + (rootPatient.width - width)/2
            y: (rootPatient.height - height)/2
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
                    text: "Are you sure you want to delete this patient?"
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
                            if (rootPatient.state === "Inpatient") {
                                inpatientModel.removeAt(in_index)
                                inpatient.deleteInpatientData(inpatient_id)
                            } else {
                                outpatientModel.removeAt(out_index)
                                outpatient.deleteOutpatientData(outpatient_id)
                            }
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
    //         if (rootPatient.state === "Inpatient") {
    //             inpatient.showIn_PatientDataFromFile()
    //         } else {
    //             outpatient.showOut_PatientDataFromFile()
    //         }
    //     }
    // }

    Component.onCompleted: {
        if (rootPatient.state === "Inpatient") {
            inpatient.showIn_PatientDataFromFile()
        } else {
            outpatient.showOut_PatientDataFromFile()
        }
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
        placeholderText: qsTr("Search Patient...")
        leftPadding: 15
        onTextChanged: {
            if(rootPatient.state === "Inpatient") {
                if (text !== "") {
                    inpatient.showSearchInpatient(text)
                } else {
                    inpatient.showIn_PatientDataFromFile()
                }
            } else {
                if (text !== "") {
                    outpatient.showSearchOutpatient(text)
                } else {
                    outpatient.showOut_PatientDataFromFile()
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
        id: searchpatientbefore
        x: 649
        y: 877
        width: 125
        height: 39
        text: qsTr("Select Day")
        font.pixelSize: 24
        font.family: "Times New Roman"
    }

    TextField {
        id: searchpatientField
        x: 770
        y: 868
        width: 279
        height: 48
        verticalAlignment: Text.AlignVCenter
        font.pointSize: 15
        font.family: "Times New Roman"
        placeholderText: qsTr("20/10/2024")
        leftPadding: 15
        validator: RegularExpressionValidator {
            regularExpression: /^\d{1,2}\/\d{1,2}\/\d{4}$/ // Cho phép nhập cả ngày/tháng 1 chữ số
        }

        onEditingFinished: {
            if (text === "") {

                if (rootPatient.state === "Inpatient") {
                    inpatient.showIn_PatientDataFromFile()
                } else {
                    outpatient.showOut_PatientDataFromFile()
                }

            } else {

                let formattedDate = validateDate(text)
                if (!formattedDate) {
                    checkdate_text.text = "Invalid date format or value!"
                    checkdate_text.visible = true
                    console.log("Goi dc cau lenh tren khong")
                } else {
                    console.log("Goi dc cau lenh duoi khong")
                    checkdate_text.visible = false
                    text = formattedDate
                }

                if (rootPatient.state === "Inpatient") {
                    inpatient.showIn_PatientBefore(text)
                } else {
                    outpatient.showOut_PatientBefore(text)
                }

            }
        }
    }

    Text{
        id: checkdate_text
        x: 1085
        y: 877
        width: 313
        height: 31
        color: "#ff0000"
        font.pointSize: 12
        font.family: "Times New Roman"
        visible: false
    }

    Text {
        id: _text1
        x: 683
        y: 35
        width: 135
        height: 57
        text: qsTr("Patient")
        font.pixelSize: 40
        font.family: "Times New Roman"
        font.bold: true
    }
}
