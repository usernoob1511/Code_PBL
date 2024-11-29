#include "Person.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>



void Person::calculateAge() {
    QStringList dateParts = date.split('/');  // Tách ngày theo định dạng dd/mm/yyyy
    if (dateParts.size() == 3) {
        int birthYear = dateParts[2].toInt();  // Lấy năm sinh
        age = QString::number(2024 - birthYear); // Tính tuổi và chuyển đổi sang QString
    } else {
        age = "0"; // Gán giá trị mặc định
    }
}

void Person::getPersonData(const QString &I_phone, const QString &I_name, const QString &I_address,
                         const QString &I_date, const QString &I_CCCD, const QString &I_sex) {
    phone = I_phone;
    name = I_name;
    address = I_address;
    date = I_date;
    CCCD = I_CCCD;
    sex = I_sex;
    calculateAge();
}

bool Person::checkPersonPhone(const QString &I_phone) {
    if (I_phone.size() != 10 || I_phone[0] != '0') {
        qDebug() << "Số điện thoại không hợp lệ. Vui lòng nhập lại!";
        return false;
    }
    for (int i = 0; i < I_phone.size(); ++i) {
        if (!I_phone[i].isDigit()) {
            qDebug() << "Số điện thoại không hợp lệ. Vui lòng nhập lại!";
            return false;
        }
    }
    return true;
}

QString Person :: formatDate(const QString &date) {
    QStringList parts = date.split('/');
    if (parts.size() != 3) return "";

    QString day = parts[0];
    QString month = parts[1];
    QString year = parts[2];
    if (day.length() == 1) day = "0" + day;
    if (month.length() == 1) month = "0" + month;

    return year + month + day;
}
// Person::Person(QObject *parent)
//     : QAbstractItemModel(parent)
// {}

// QVariant Person::headerData(int section, Qt::Orientation orientation, int role) const
// {
//     // FIXME: Implement me!
// }

// QModelIndex Person::index(int row, int column, const QModelIndex &parent) const
// {
//     // FIXME: Implement me!
// }

// QModelIndex Person::parent(const QModelIndex &index) const
// {
//     // FIXME: Implement me!
// }

// int Person::rowCount(const QModelIndex &parent) const
// {
//     if (!parent.isValid())
//         return 0;

//     // FIXME: Implement me!
// }

// int Person::columnCount(const QModelIndex &parent) const
// {
//     if (!parent.isValid())
//         return 0;

//     // FIXME: Implement me!
// }

// QVariant Person::data(const QModelIndex &index, int role) const
// {
//     if (!index.isValid())
//         return QVariant();

//     // FIXME: Implement me!
//     return QVariant();
// }
