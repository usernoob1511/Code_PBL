import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 2.15

import Admin 1.0

import Doctor 1.0
import DoctorModel 1.0

import Inpatient 1.0
import InpatientModel 1.0

import Outpatient 1.0
import OutpatientModel 1.0

import Medicine 1.0
import MedicineModel 1.0

import Person 1.0

Window {
    id: mainWindow
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Hospital Management System")

    signal showCompletedDialog()
    signal showMessageDialog()
    signal showCompletedDialog2()
    signal showMessageDialog2()
    signal showDialogSelect()

    // Person {
    //     id: person
    // }

    DoctorModel {
        id: doctorModel
    }
    Doctor {
        id: doctor
        model: doctorModel
    }

    InpatientModel{
        id: inpatientModel
    }
    Inpatient{
        id: inpatient
        model: inpatientModel
    }

    OutpatientModel{
        id: outpatientModel
    }
    Outpatient{
        id: outpatient
        model: outpatientModel
    }

    MedicineModel{
        id: medicineModel
    }
    Medicine{
        id: medicine
        model: medicineModel
    }
    Component.onCompleted: {
        console.log("Kiem tra person")
        console.log(person) // Xem thử đối tượng có tồn tại không
    }

    function validateDate(input) {
        let parts = input.split("/")
        if (parts.length !== 3) return false

        let day = parseInt(parts[0])
        let month = parseInt(parts[1])
        let year = parseInt(parts[2])

        if (month < 1 || month > 12) return false

        let daysInMonth = [31, (year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if (day < 1 || day > daysInMonth[month - 1]) return false

        if (year < 1900 || year > 2024) return false

        let formattedDay = day.toString().padStart(2, "0")
        let formattedMonth = month.toString().padStart(2, "0")
        return `${formattedDay}/${formattedMonth}/${year}`
    }

    function validateDate2(input) {
        let parts = input.split("/")
        if (parts.length !== 3) return false

        let day = parseInt(parts[0])
        let month = parseInt(parts[1])
        let year = parseInt(parts[2])

        if (month < 1 || month > 12) return false

        let daysInMonth = [31, (year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if (day < 1 || day > daysInMonth[month - 1]) return false

        if (year < 1900 || year > 2100) return false

        let formattedDay = day.toString().padStart(2, "0")
        let formattedMonth = month.toString().padStart(2, "0")
        return `${formattedDay}/${formattedMonth}/${year}`
    }

    function getCurrentDate() {
        var currentDate = new Date(); // Lấy ngày giờ hiện tại
        var day = currentDate.getDate(); // Lấy ngày
        var month = currentDate.getMonth() + 1; // Lấy tháng (bắt đầu từ 0, nên cộng thêm 1)
        var year = currentDate.getFullYear(); // Lấy năm

        // Định dạng ngày theo kiểu dd/MM/yyyy
        var formattedDate = (day < 10 ? "0" + day : day) + "/" +
                (month < 10 ? "0" + month : month) + "/" +
                year;
        return formattedDate;
    }

    StackView {
        id: stackView
        x: 0
        y: 0
        width: 1920
        height: 1080

        initialItem: "Login_page.qml"
        z: 0
    }

    StackView {
        id: stackView2
        x: 484
        y: 237
        width: 1060
        height: 625
        z: 2

        pushEnter: Transition {
            NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 100 }
            NumberAnimation { property: "x"; from: width; to: 26; duration: 300 }
        }
        pushExit: Transition {
            NumberAnimation { property: "opacity"; from: 1; to: 0; duration: 300 }
            // NumberAnimation { property: "x"; from: 0; to: -width; duration: 300 }
        }

        // Hiệu ứng khi quay lại trang trước (pop)
        popEnter: Transition {
            NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 100 }
            NumberAnimation { property: "x"; from: width; to: 26; duration: 300 }
        }
        popExit: Transition {
            NumberAnimation { property: "opacity"; from: 1; to: 0; duration: 100 }
            //     NumberAnimation { property: "x"; from: 0; to: width; duration: 300 }
        }
    }

    StackView {
        id: stackView3
        x: 695
        y: 185
        width: 480
        height: 711
        z: 2

        pushEnter: Transition {
            NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 100 }
            NumberAnimation { property: "x"; from: width; to: 26; duration: 300 }
        }
        pushExit: Transition {
            NumberAnimation { property: "opacity"; from: 1; to: 0; duration: 300 }
            // NumberAnimation { property: "x"; from: 0; to: -width; duration: 300 }
        }

        // Hiệu ứng khi quay lại trang trước (pop)
        popEnter: Transition {
            NumberAnimation { property: "opacity"; from: 0; to: 1; duration: 100 }
            NumberAnimation { property: "x"; from: width; to: 26; duration: 300 }
        }
        popExit: Transition {
            NumberAnimation { property: "opacity"; from: 1; to: 0; duration: 100 }
            //     NumberAnimation { property: "x"; from: 0; to: width; duration: 300 }
        }
    }
    Dialog {
        id: messageDialogSelect
        width: 300
        height: 150
        x: 414 + (1500 - width) / 2
        y: (1080 - height) / 2
        parent: Overlay.overlay
        modal: true
        title: "Notification"

        Component.onCompleted: mainWindow.showDialogSelect.connect(open)
        background: Rectangle {
            color: "white"
            border.color: "lightgray"
            radius: 10
        }

        Image {
            id: chamthangSelect
            source: "qrc:/Images/chamthang.png"
            width: 80
            height: 80
            anchors.top: parent.top
            anchors.topMargin: 15
            anchors.left: parent.left
            anchors.leftMargin: 20
        }

        Label {
            id: ladbeldeleteSelect
            anchors.verticalCenter: chamthangSelect.verticalCenter
            anchors.left: chamthangSelect.right
            anchors.leftMargin: 0 // Tăng khoảng cách để đẩy sang phải
            text: "Please select a row!!!"
            font.pixelSize: 20
            font.bold: true
            styleColor: "#616161"
            font.family: "Times New Roman"
            color: "#333333"
        }
    }

    Rectangle {
        id: overlay
        color: "black"
        opacity: 0.5
        anchors.fill: parent
        visible: (stackView2.depth > 0 || stackView3.depth > 0)
        z: 1
        MouseArea {
            anchors.fill: parent
            enabled: true
        }
    }

    Dialog {
        id: completedialog
        width: 300
        height: 150
        x: 414 + (1500 - width)/2
        y: (1080 - height)/2
        anchors.centerIn: root.Center
        parent: Overlay.overlay
        modal: true
        title: "Notification"

        Component.onCompleted: mainWindow.showCompletedDialog.connect(open)

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
        x: 414 + (1500 - width)/2
        y: (1080 - height)/2
        anchors.centerIn: root.Center
        parent: Overlay.overlay
        modal: true
        title: "Notification"

        Component.onCompleted: mainWindow.showMessageDialog.connect(open)

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
        id: completedialog2
        width: 300
        height: 150
        x: 484 + (1060 - width)/2
        y: 237 + (625 - height)/2
        parent: Overlay.overlay
        modal: true
        title: "Notification"
        Component.onCompleted: mainWindow.showCompletedDialog2.connect(open)
        background: Rectangle {
            color: "white"
            border.color: "lightgray"
            radius: 10
        }

        Image {
            id: complete2
            source: "qrc:/Images/dautich.png"
            width: 80
            height: 80
            anchors.top: parent.top
            anchors.topMargin: 15
            anchors.left: parent.left
            anchors.leftMargin: 20
        }

        Label {
            id: ladbelcomplete2
            anchors.verticalCenter: complete2.verticalCenter
            anchors.left: complete2.right
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
        id: messageDialog2
        width: 300
        height: 150
        x: 484 + (1060 - width)/2
        y: 237 + (625 - height)/2
        parent: Overlay.overlay
        modal: true
        title: "Notification"
        Component.onCompleted: mainWindow.showMessageDialog2.connect(open)
        background: Rectangle {
            color: "white"
            border.color: "lightgray"
            radius: 10
        }

        Image {
            id: chamthang2
            source: "qrc:/Images/chamthang.png"
            width: 80
            height: 80
            anchors.top: parent.top
            anchors.topMargin: 15
            anchors.left: parent.left
            anchors.leftMargin: 20
        }

        Label {
            id: ladbeldelete2
            anchors.verticalCenter: chamthang2.verticalCenter
            anchors.left: chamthang2.right
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
