import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Item {
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
            x: 538
            y: 46
            width: 426
            height: 64
            text: qsTr("Add In_Patient Details")
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
                placeholderText: qsTr("XXXXXXXXX")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
            }

            Text {
                id: _text3
                x: 66
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
            }

            Text {
                id: _text4
                x: 935
                y: 41
                width: 91
                height: 31
                text: qsTr("CNIC")
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }

            TextField {
                id: bhytField
                x: 60
                y: 188
                width: 281
                height: 41
                placeholderText: qsTr("SV 401412XXXXXX")
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
                verticalAlignment: Text.AlignVCenter
                leftPadding: 14
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
                id: sdtField
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
            }

            TextField {
                id: appointdayField
                x: 66
                y: 657
                width: 281
                height: 41
                verticalAlignment: Text.AlignVCenter
                placeholderText: qsTr("SV 401412XXXXXX")
                leftPadding: 14
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
            }
            TextField {
                id: dischargedayField
                x: 70
                y: 742
                width: 104
                height: 41
                verticalAlignment: Text.AlignVCenter
                placeholderText: qsTr("5")
                leftPadding: 14
                font.pointSize: 14
                font.italic: false
                font.family: "Times New Roman"
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
                id: dischargedaytext
                x: 66
                y: 713
                width: 174
                height: 36
                text: "Discharge Date"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
            }
            Text {
                id: _text18
                x: 490
                y: 616
                width: 176
                height: 35
                text: "Room Number"
                font.pixelSize: 25
                font.family: "Times New Roman"
                font.bold: true
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
            stackView1.pop()
        }
    }

    Button {
        id: button1
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
            inpatient.getIn_PatientData(
                        sdtField.text, nameField.text, addressField.text, dateField.text, cccdField.text, sexField.currentText,
                        diseasenameField.currentText, symptomsField.text, treatmentField.text, departmentField.currentText,
                        patientIdField.text, bhytField.text, weightField.text, heightField.text, appointdayField.text,
                        dischargedayField.text, roomnumberField.text)
            inpatient.addIn_PatientData()
        }
    }
}

