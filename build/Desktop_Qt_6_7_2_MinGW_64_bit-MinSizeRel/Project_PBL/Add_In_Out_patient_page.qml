import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: root
    property int check_InpatientId: 0
    property int check_OutpatientId: 0

    property int check_name: 0
    property int check_CCCD: 0
    property int check_phone: 0
    property int check_date: 0
    property int check_BHYT: 0
    property int check_address: 0

    // function validateDate(input) {
    //     let parts = input.split("/")
    //     if (parts.length !== 3) return false

    //     let day = parseInt(parts[0])
    //     let month = parseInt(parts[1])
    //     let year = parseInt(parts[2])

    //     if (month < 1 || month > 12) return false

    //     let daysInMonth = [31, (year % 4 === 0 && (year % 100 !== 0 || year % 400 === 0)) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    //     if (day < 1 || day > daysInMonth[month - 1]) return false

    //     if (year < 1900 || year > 2024) return false

    //     let formattedDay = day.toString().padStart(2, "0")
    //     let formattedMonth = month.toString().padStart(2, "0")
    //     return `${formattedDay}/${formattedMonth}/${year}`
    // }

    // function getCurrentDate() {
    //     var currentDate = new Date(); // Lấy ngày giờ hiện tại
    //     var day = currentDate.getDate(); // Lấy ngày
    //     var month = currentDate.getMonth() + 1; // Lấy tháng (bắt đầu từ 0, nên cộng thêm 1)
    //     var year = currentDate.getFullYear(); // Lấy năm

    //     // Định dạng ngày theo kiểu dd/MM/yyyy
    //     var formattedDate = (day < 10 ? "0" + day : day) + "/" +
    //             (month < 10 ? "0" + month : month) + "/" +
    //             year;
    //     return formattedDate;
    // }

    states: [
        State {
            name: "addInpatient"
            PropertyChanges { target: titleField; text: qsTr("Add In Patient Details") }

            PropertyChanges { target: dischargedayField; visible: true }
            PropertyChanges { target: roomnumberField; visible: true }
            PropertyChanges { target: dischargedayText; visible: true }
            PropertyChanges { target: roomnumberText; visible: true }

            PropertyChanges { target: nofuvField; visible: false }
            PropertyChanges { target: dbvField; visible: false }
            PropertyChanges { target: nofuvText; visible: false }
            PropertyChanges { target: dbvText; visible: false }
        },
        State {
            name: "addOutpatient"
            PropertyChanges { target: titleField; text: qsTr("Add Out Patient Details") }

            PropertyChanges { target: dischargedayField; visible: false }
            PropertyChanges { target: roomnumberField; visible: false }
            PropertyChanges { target: dischargedayText; visible: false }
            PropertyChanges { target: roomnumberText; visible: false }

            PropertyChanges { target: nofuvField; visible: true }
            PropertyChanges { target: dbvField; visible: true }
            PropertyChanges { target: nofuvText; visible: true }
            PropertyChanges { target: dbvText; visible: true }
        }
    ]
    Rectangle {
        id: rectangle
        x: 0
        y: 0
        width: 1500
        height: 1080
        color: "#f0f0f0"
        border.width: 0

        Text {
            id: titleField
            x: 538
            y: 46
            width: 426
            height: 64
            //text: qsTr("Add In Patient Details")
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
                x: 60
                y: 73
                width: 281
                height: 41
                font.italic: false
                font.family: "Times New Roman"
                font.pointSize: 14
                placeholderText: qsTr("Nguyen Van A")
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
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

            Text{
                id: checkname_text
                x: 63
                y: 120
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
                text: "Date field cannot be empty!"
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
                id: patientIdField
                x: 490
                y: 73
                width: 308
                height: 41
                placeholderText:  root.state === "addInpatient" ? qsTr("I0001") : qsTr("O1001")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14

                validator: RegularExpressionValidator {
                    regularExpression: root.state === "addInpatient" ? /^[I][0-9]{0,4}$/ : /^[O][0-9]{0,4}$/
                }

                onEditingFinished: {
                    if (root.state === "addInpatient") {

                        if (text.length !== 5) {
                            checkId_text.visible = true
                            check_InpatientId = 0
                            checkId_text.text = "Inpatient Id consists of 5 characters!"
                        } else if(!inpatient.checkInpatientId(text)) {
                            checkId_text.visible = true
                            check_InpatientId = 0
                            checkId_text.text = "Inpatient Id has been duplicated!"
                        } else {
                            check_InpatientId =1
                            checkId_text.visible = false
                        }

                    } else {

                        if (text.length !== 5) {
                            checkId_text.visible = true
                            check_OutpatientId = 0
                            checkId_text.text = "Inpatient Id consists of 5 characters!"
                        } else if(!outpatient.checkOutpatientId(text)) {
                            checkId_text.visible = true
                            check_OutpatientId = 0
                            checkId_text.text = "Inpatient Id has been duplicated!"
                        } else {
                            check_OutpatientId =1
                            checkId_text.visible = false
                        }

                    }
                }
            }

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

            Text {
                id: _text3
                x: 59
                y: 616
                width: 163
                height: 35
                text: "Appoint Date"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: cccdField
                x: 935
                y: 73
                width: 281
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
                id: cccd_text
                x: 935
                y: 41
                width: 91
                height: 31
                text: qsTr("CNIC")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
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

            TextField {
                id: bhytField
                x: 60
                y: 188
                width: 281
                height: 41
                placeholderText: qsTr("BHYT401412XXX")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
                validator: RegularExpressionValidator {
                    regularExpression: /^BHYT\d{0,9}$/
                }

                onEditingFinished: {
                    if (text.length !== 13) {
                        checkBHYT_text.visible = true
                        check_BHYT = 0
                    } else {
                        checkBHYT_text.visible = false
                        check_BHYT = 1
                    }
                }

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
                id: phoneField
                x: 491
                y: 188
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

            Text{
                id: checkphone_text
                x: 490
                y: 235
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
                text: "Phone consists of 10 characters!"
            }

            Text{
                id: checkBHYT_text
                x: 63
                y: 235
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
                text: "BHYT consists of 13 characters!"
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
            // function getCurrentDate() {
            //     let today = new Date()
            //     let day = today.getDate().toString().padStart(2, "0") // Đảm bảo ngày có 2 chữ số
            //     let month = (today.getMonth() + 1).toString().padStart(2, "0") // Tháng bắt đầu từ 0 nên +1
            //     let year = today.getFullYear().toString()
            //     return `${day}/${month}/${year}` // Định dạng dd/MM/yyyy
            // }
            TextField {
                id: dateField
                x: 935
                y: 188
                width: 281
                height: 41
                placeholderText: qsTr("01/01/1900")
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

            Text{
                id: checkdate_text
                x: 935
                y: 235
                width: 313
                height: 31
                color: "#ff0000"
                font.pointSize: 14
                font.family: "Times New Roman"
                visible: false
            }

            Text {
                id: _text7
                x: 59
                y: 157
                width: 191
                height: 36
                text: qsTr("Health insurance")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text8
                x: 59
                y: 281
                width: 91
                height: 31
                text: qsTr("Gender")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            ComboBox {
                id: sexField
                x: 59
                y: 313
                width: 181
                height: 41
                flat: false
                editable: false
                font.pointSize: 14
                font.family: "Times New Roman"
                leftPadding: 14
                model: ListModel {
                    ListElement { gender: "Male" }
                    ListElement { gender: "Female" }
                    ListElement { gender: "Other" }
                }

                textRole: "gender"
                displayText :  "Select Gender";
                currentIndex: -1
                delegate: ItemDelegate {
                    width: sexField.width
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
            TextField {
                id: weightField
                x: 591
                y: 281
                width: 98
                height: 31
                placeholderText: qsTr("60 (kg)")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
                validator: RegularExpressionValidator {
                    regularExpression: /^[1-9][0-9]{0,2}$/
                }
            }

            TextField {
                id: heightField
                x: 591
                y: 339
                width: 98
                height: 32
                placeholderText: qsTr("170 (cm)")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14

                validator: RegularExpressionValidator {
                    regularExpression: /^[1-9][0-9]{0,2}$/
                }
            }
            Text {
                id: _text9
                x: 935
                y: 281
                width: 91
                height: 31
                text: qsTr("Address")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }
            TextField {
                id: addressField
                x: 935
                y: 313
                width: 342
                height: 84
                verticalAlignment: Text.AlignTop
                placeholderText: qsTr("Xã xxxxx, huyện xxxxxx, thành phố xxxxxxxxxx")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                leftPadding: 14
                onTextChanged: {
                    check_address = 1
                }
            }

            // ListModel {
            //     id: department_and_diseasenameList
            //     ListElement {
            //         department: "Noi khoa"
            //         diseases: "Cao huyet ap, Tieu duong, Dot quy"
            //     }
            //     ListElement {
            //         department: "Ngoai khoa"
            //         diseases: "Ruot thua, Soi mat, Ung thu, Gay xuong"
            //     }
            //     ListElement {
            //         department: "Khoa Tai Mui Hong"
            //         diseases: "Viem amidan, Viem xoang, Viem mui di ung, Viem tai giua, Ngat mui, Di vat duong tho"
            //     }
            //     ListElement {
            //         department: "Khoa Mat"
            //         diseases: "Can thi, Vien thi, Loan thi, Duc thuy tinh the, Viem ket mac, Tang nhan ap"
            //     }
            //     ListElement {
            //         department: "Khoa Da Lieu"
            //         diseases: "Viem da co dia, Nam da, Ghe, Mun trung ca, Viem da tiep xuc, Benh vay nen"
            //     }
            //     ListElement {
            //         department: "Khoa Tim Mach"
            //         diseases: "Suy tim, Nhoi mau co tim, Loan nhip tim, Benh mach vanh"
            //     }
            //     ListElement {
            //         department: "Khoa Than - Tiet Nie"
            //         diseases: "Viem than, Suy than, Soi than, Soi bang quang, Hoi chung than hu"
            //     }
            //     ListElement {
            //         department: "Khoa Gan - Mat"
            //         diseases: "Viem gan B, Viem gan C, Gan nhiem mo, Xo gan, Soi mat, Ung thu gan"
            //     }
            //     ListElement {
            //         department: "Khoa Than Kinh"
            //         diseases: "Dot quy nao, Dau dau, Dau nua dau, Benh Parkinson, Dong kinh, Thai hoa than kinh"
            //     }
            //     ListElement {
            //         department: "Khoa Ho Hap"
            //         diseases: "Viem phoi, Hen suyen, Lao phoi, Viem phe quan, COPD"
            //     }
            //     ListElement {
            //         department: "Khoa Xuong Khop"
            //         diseases: "Thai hoa khop, Gay xuong, Viem khop, Loang xuong, Chan thuong day chang"
            //     }
            //     ListElement {
            //         department: "Khoa Khac"
            //         diseases: "Khac"
            //     }
            // }
            // ComboBox {
            //     id: departmentField
            //     x: 70
            //     y: 475
            //     width: 260
            //     height: 40
            //     font.pointSize: 14
            //     font.family: "Times New Roman"
            //     flat: false
            //     editable: false
            //     leftPadding: 14
            //     model: department_and_diseasenameList
            //     textRole: "department"
            //     displayText: "Select Department"
            //     currentIndex: -1

            //     delegate: ItemDelegate {
            //         width: departmentField.width
            //         contentItem: Text {
            //             text: model.department
            //             font.pointSize: 14
            //             font.family: "Times New Roman"
            //         }
            //     }

            //     onCurrentIndexChanged: {
            //         if (currentIndex >= 0) {
            //             displayText = model.get(currentIndex).department;
            //         }
            //     }
            // }
            // ComboBox {
            //     id: diseasenameField
            //     x: 495
            //     y: 475
            //     width: 232
            //     height: 40
            //     font.pointSize: 14
            //     font.family: "Times New Roman"
            //     flat: false
            //     editable: false
            //     leftPadding: 14
            //     model: department_and_diseasenameList
            //     textRole: "diseases"
            //     displayText: "Select Disease Name"
            //     currentIndex: -1

            //     delegate: ItemDelegate {
            //         width: diseasenameField.width
            //         contentItem: Text {
            //             text: model.department
            //             font.pointSize: 14
            //             font.family: "Times New Roman"
            //         }
            //     }

            //     onCurrentIndexChanged: {
            //         if (currentIndex >= 0) {
            //             displayText = model.get(currentIndex).department;
            //         }
            //     }
            // }

            ListModel {
                id: department_and_diseasenameList
                ListElement {
                    department: "Noi khoa"
                    diseases: "Cao huyet ap, Tieu duong, Dot quy"
                }
                ListElement {
                    department: "Ngoai khoa"
                    diseases: "Ruot thua, Soi mat, Ung thu, Gay xuong"
                }
                ListElement {
                    department: "Khoa Tai Mui Hong"
                    diseases: "Viem amidan, Viem xoang, Viem mui di ung, Viem tai giua, Ngat mui, Di vat duong tho"
                }
                ListElement {
                    department: "Khoa Mat"
                    diseases: "Can thi, Vien thi, Loan thi, Duc thuy tinh the, Viem ket mac, Tang nhan ap"
                }
                ListElement {
                    department: "Khoa Da Lieu"
                    diseases: "Viem da co dia, Nam da, Ghe, Mun trung ca, Viem da tiep xuc, Benh vay nen"
                }
                ListElement {
                    department: "Khoa Tim Mach"
                    diseases: "Suy tim, Nhoi mau co tim, Loan nhip tim, Benh mach vanh"
                }
                ListElement {
                    department: "Khoa Than - Tiet Nieu"
                    diseases: "Viem than, Suy than, Soi than, Soi bang quang, Hoi chung than hu"
                }
                ListElement {
                    department: "Khoa Gan - Mat"
                    diseases: "Viem gan B, Viem gan C, Gan nhiem mo, Xo gan, Soi mat, Ung thu gan"
                }
                ListElement {
                    department: "Khoa Than Kinh"
                    diseases: "Dot quy nao, Dau dau, Dau nua dau, Benh Parkinson, Dong kinh, Thai hoa than kinh"
                }
                ListElement {
                    department: "Khoa Ho Hap"
                    diseases: "Viem phoi, Hen suyen, Lao phoi, Viem phe quan, COPD"
                }
                ListElement {
                    department: "Khoa Xuong Khop"
                    diseases: "Thai hoa khop, Gay xuong, Viem khop, Loang xuong, Chan thuong day chang"
                }
                ListElement {
                    department: "Khoa Khac"
                    diseases: "Khac"
                }
            }

            ListModel {
                id: filteredDiseaseList
            }

            ComboBox {
                id: departmentField
                x: 60
                y: 475
                width: 260
                height: 40
                font.pointSize: 14
                font.family: "Times New Roman"
                flat: false
                editable: false
                leftPadding: 14
                model: department_and_diseasenameList
                textRole: "department" // Tự động hiển thị giá trị 'department' từ model
                currentIndex: -1 // Không chọn mục nào ban đầu
                displayText: "Select Department"

                delegate: ItemDelegate {
                    width: departmentField.width
                    contentItem: Text {
                        text: model.department // Hiển thị giá trị department trong danh sách
                        font.pointSize: 14
                        font.family: "Times New Roman"
                    }
                }

                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        displayText = model.get(currentIndex).department;

                        let diseases = department_and_diseasenameList.get(currentIndex).diseases;
                        let diseaseArray = diseases.split(",").map(d => d.trim()); // Tách danh sách bệnh
                        filteredDiseaseList.clear();
                        for (let disease of diseaseArray) {
                            filteredDiseaseList.append({ text: disease });
                        }
                        console.log(filteredDiseaseList);
                        console.log("hello ae");

                        diseasenameField.currentIndex = -1; // Reset lại
                        diseasenameField.displayText = "Select Disease"
                    } else {
                        filteredDiseaseList.clear();
                    }
                }
            }


            ComboBox {
                id: diseasenameField
                x: 490
                y: 475
                width: 232
                height: 40
                font.pointSize: 14
                font.family: "Times New Roman"
                flat: false
                editable: false
                leftPadding: 14
                model: filteredDiseaseList // Sử dụng danh sách bệnh cập nhật từ departmentField
                textRole: "text" // Tự động hiển thị giá trị 'text' từ model
                currentIndex: -1 // Không chọn mục nào ban đầu
                displayText: "Select Disease"

                delegate: ItemDelegate {
                    width: diseasenameField.width
                    contentItem: Text {
                        text: model.text // Hiển thị giá trị tên bệnh trong danh sách
                        font.pointSize: 14
                        font.family: "Times New Roman"
                    }
                }

                onCurrentIndexChanged: {
                    if (currentIndex >= 0) {
                        displayText = filteredDiseaseList.get(currentIndex).text;
                    }
                }
            }

            TextField {
                id: symptomsField
                x: 1070
                y: 445
                width: 239
                height: 80
                placeholderText: qsTr("...")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                leftPadding: 14

                validator: RegularExpressionValidator {
                    regularExpression: /^[A-Za-zÀ-ÿ\s-]*$/
                }
            }
            Text {
                id: _text10
                x: 938
                y: 445
                width: 143
                height: 34
                text: qsTr(" Symptoms")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: treatmentField
                x: 1070
                y: 555
                width: 239
                height: 81
                placeholderText: qsTr("...")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                leftPadding: 14

                validator: RegularExpressionValidator {
                    regularExpression: /^[A-Za-zÀ-ÿ\s-]*$/
                }
            }

            TextField {
                id: appointdayField
                x: 60
                y: 648
                width: 281
                height: 41
                verticalAlignment: Text.AlignVCenter
                placeholderText: qsTr("15/11/2024")
                leftPadding: 14
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                text: getCurrentDate()
                readOnly: true
            }
            TextField {
                id: dischargedayField
                x: 60
                y: 742
                width: 104
                height: 41
                verticalAlignment: Text.AlignVCenter
                placeholderText: qsTr("5")
                leftPadding: 14
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                validator: RegularExpressionValidator {
                    regularExpression: /^[1-9][0-9]{0,2}$/
                }
            }
            TextField {
                id: roomnumberField
                x: 490
                y: 648
                width: 133
                height: 41
                verticalAlignment: Text.AlignVCenter
                placeholderText: qsTr("A101")
                leftPadding: 14
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                validator: RegularExpressionValidator {
                    regularExpression: /^[A-Z][0-9]*$/
                }
            }
            Text {
                id: _text11
                x: 938
                y: 555
                width: 138
                height: 34
                text: qsTr("Treatment")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text12
                x: 490
                y: 445
                width: 165
                height: 34
                text: "Disease Name"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text13
                x: 59
                y: 445
                width: 163
                height: 34
                text: "Department"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text15
                x: 490
                y: 281
                width: 95
                height: 31
                text: "Weight"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            Text {
                id: _text16
                x: 490
                y: 332
                width: 79
                height: 39
                text: qsTr("Height")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }


            Text {
                id: dischargedayText
                x: 63
                y: 713
                width: 174
                height: 36
                text: "Discharge Date"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
                visible: addInpatient ? true : false
            }
            Text {
                id: roomnumberText
                x: 490
                y: 616
                width: 176
                height: 35
                text: "Room Number"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
                visible: addInpatient ? true : false
            }

            Text {
                id: nofuvText
                x: 491
                y: 616
                width: 335
                height: 35
                text: "Number of Follow-Up Visit"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
                visible: addOutpatient ? true : false
            }

            TextField {
                id: nofuvField
                x: 491
                y: 648
                width: 133
                height: 41
                verticalAlignment: Text.AlignVCenter
                placeholderText: qsTr("3")
                leftPadding: 14
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                validator: RegularExpressionValidator {
                    regularExpression: /^[1-9][0-9]{0,2}$/
                }
            }

            Text {
                id: dbvText
                x: 491
                y: 713
                width: 245
                height: 36
                text: "Days Between Visit"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
                visible: addOutpatient ? true : false
            }

            TextField {
                id: dbvField
                x: 494
                y: 742
                width: 104
                height: 41
                verticalAlignment: Text.AlignVCenter
                placeholderText: qsTr("5")
                leftPadding: 14
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                validator: RegularExpressionValidator {
                    regularExpression: /^[1-9][0-9]{0,2}$/
                }
            }
        }
    }
    Button {
        id: button
        x: 1101
        y: 944

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
                    text: "Don't save this Patient?"
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
        id: updatebutton
        x: 1257
        y: 944
        width: 131
        height: 49
        text: qsTr("Update")
        icon.width: 20
        font.pointSize: 20
        font.family: "Times New Roman"
        font.bold: true
        onClicked: {


            if (root.state === "addInpatient") {

                if ( check_InpatientId && check_name && check_CCCD && check_phone && check_date && check_BHYT &&
                        sexField.currentIndex !== -1 && departmentField.currentIndex !== -1
                        && diseasenameField.currentIndex !== -1 && check_address) {

                    confirmationDialog.open()
                } else {
                    messageDialog.open()
                }

            } else {

                if ( check_OutpatientId && check_name && check_CCCD && check_phone && check_date && check_BHYT &&
                        sexField.currentIndex !== -1 && departmentField.currentIndex !== -1
                        && diseasenameField.currentIndex !== -1 && check_address) {

                    confirmationDialog.open()
                } else {
                    messageDialog.open()
                }

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
                    text: "Are you sure you want to register this patient?"
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

                            if (root.state === "addInpatient") {
                                inpatient.getIn_PatientData(
                                            phoneField.text, nameField.text, addressField.text, dateField.text, cccdField.text, sexField.currentText,
                                            diseasenameField.currentText, symptomsField.text, treatmentField.text, departmentField.currentText,
                                            patientIdField.text, bhytField.text, weightField.text, heightField.text, appointdayField.text,
                                            dischargedayField.text, roomnumberField.text)
                                inpatient.addIn_PatientData()
                            } else {
                                outpatient.getOut_PatientData(
                                            phoneField.text, nameField.text, addressField.text, dateField.text, cccdField.text, sexField.currentText,
                                            diseasenameField.currentText, symptomsField.text, treatmentField.text, departmentField.currentText,
                                            patientIdField.text, bhytField.text, weightField.text, heightField.text, appointdayField.text,
                                            nofuvField.text, dbvField.text)
                                outpatient.addOut_PatientData()
                            }

                            confirmationDialog.close()
                            completedialog.open()
                            stackView1.pop()

                            if (root.state === "addInpatient") {
                                inpatient.showIn_PatientDataFromFile()
                            } else {
                                outpatient.showOut_PatientDataFromFile()
                            }
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
            width: 150
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
            text: "Check data required!"
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

