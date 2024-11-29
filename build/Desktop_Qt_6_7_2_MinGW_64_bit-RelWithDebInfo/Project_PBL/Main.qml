import QtQuick
import QtQuick.Controls
import QtQuick.Layouts 2.15

Window {
    id: mainWindow
    width: 1920
    height: 1080
    visible: true
    title: qsTr("Hospital Management System")

    StackView {
        id: stackView
        x: 0
        y: 0
        width: 1920
        height: 1080

        initialItem: "Login_page.qml"
    }


}
