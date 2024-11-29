#include "Medicine.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MedicineModel::MedicineModel(QObject *parent) : QAbstractListModel(parent) {
    qWarning() << "MedicineModel constructed";
}

void MedicineModel::addMedicine(const QString &code, const QString &name, const QString &quantity, const QString &usageInstructions, const QString &expiryDate) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    medicines.append({Medicine{code, name, quantity, usageInstructions, expiryDate}});
    endInsertRows();
    qWarning() << "Added medicine:" << name;
}

void MedicineModel::printMedicines() {
    qDebug() << "Danh sách thuốc:";
    for (const auto &medicine : medicines) {
        qDebug() << "Code:" << medicine.code
                 << ", Name:" << medicine.name
                 << ", Quantity:" << medicine.quantity
                 << ", Usage Instructions:" << medicine.usageInstructions
                 << ", Expiry Date:" << medicine.expiryDate;
    }
}

int MedicineModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return medicines.size();
}

QVariant MedicineModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= medicines.size())
        return QVariant();

    const auto &medicine = medicines.at(index.row());
    if (role == CodeRole)
        return medicine.code;
    else if (role == NameRole)
        return medicine.name;
    else if (role == QuantityRole)
        return medicine.quantity;
    else if (role == UsageInstructionsRole)
        return medicine.usageInstructions;
    else if (role == ExpiryDateRole)
        return medicine.expiryDate;
    return QVariant();
}

QHash<int, QByteArray> MedicineModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[CodeRole] = "code";
    roles[NameRole] = "name";
    roles[QuantityRole] = "quantity";
    roles[UsageInstructionsRole] = "usageInstructions";
    roles[ExpiryDateRole] = "expiryDate";
    return roles;
}

QString MedicineModel::get_medicineCode(int index) {
    return medicines[index].code;
}

QString MedicineModel::get_medicineName(int index) {
    return medicines[index].name;
}

void MedicineModel::editMedicineModel(int index, const QString &name, const QString &quantity, const QString &usageInstructions, const QString &expiryDate) {
    if (index < 0 || index >= medicines.size())
        return;

    medicines[index].name = name;
    medicines[index].quantity = quantity;
    medicines[index].usageInstructions = usageInstructions;
    medicines[index].expiryDate = expiryDate;
}

void MedicineModel::clear() {
    beginResetModel();
    medicines.clear();
    endResetModel();
}
void MedicineModel::removeAt(int index) {
    if (index < 0 || index >= medicines.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);  // Thông báo bắt đầu xóa hàng
    medicines.removeAt(index);  // Xóa mục tại vị trí index
    endRemoveRows();  // Thông báo hoàn tất việc xóa hàng
}

void Medicine::setModel(MedicineModel *model) {
    m_model = model;
}

bool Medicine :: checkMedicineId(const QString &I_meidicineId) {
    QFile file(medicineFile_read);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file.";
        return false;
    }
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString medicineCodeFromFile, medicineNameFromFile, quantityFromFile, usageInstructionsFromFile, expiryDateFromFile;

        medicineCodeFromFile = in.readLine().trimmed();
        medicineNameFromFile = in.readLine().trimmed();
        quantityFromFile = in.readLine().trimmed();
        usageInstructionsFromFile = in.readLine().trimmed();
        expiryDateFromFile = in.readLine().trimmed();
        if ( medicineCodeFromFile == I_meidicineId) {
            qDebug() <<"kiem tra medicine id";
            return false;
        }
    }
    file.close();
    qDebug() <<"kiem tra hoan tat";
    return true;
}

// Nhập dữ liệu cho thuốc
void Medicine::getMedicineData(const QString &I_medicineCode, const QString &I_medicineName,
                               const QString &I_quantity, const QString &I_usageInstructions,
                               const QString &I_expiryDate) {
    medicineCode = I_medicineCode;
    medicineName = I_medicineName;
    quantity = I_quantity;
    usageInstructions = I_usageInstructions;
    expiryDate = I_usageInstructions;
}

// Thêm dữ liệu thuốc vào file
void Medicine::addMedicineData() {
    QFile file(medicineFile_write);
    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qWarning() << "Không thể mở file để ghi.";
        return;
    }
    QTextStream out(&file);
    out << medicineCode << "\n";
    out << medicineName << "\n";
    out << quantity << "\n";
    out << usageInstructions << "\n";
    out << expiryDate << "\n";
    file.close();
}

// Hiển thị toàn bộ dữ liệu thuốc từ file
void Medicine::showMedicineDataFromFile() {
    qDebug() <<"goi dc ham medicineData không";
    QFile file(medicineFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file để đọc.";
        return;
    }
    m_model->clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString medicineCode = in.readLine();
        QString medicineName = in.readLine();
        QString quantity = in.readLine();
        QString usageInstructions = in.readLine();
        QString expiryDate = in.readLine();
        m_model->addMedicine(medicineCode, medicineName, quantity, usageInstructions, expiryDate);
    }
    file.close();
    qDebug() <<"Cap nhât du lieu medicine Data thành công";
}

// Tìm kiếm thuốc theo mã
void Medicine::searchMedicineData(const QString &I_medicineCode) {
    QFile file(medicineFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file để đọc.";
        return;
    }
    QString line;
    QTextStream in(&file);
    while (!in.atEnd()) {
        line = in.readLine().trimmed();
        if (line == I_medicineCode) {
            medicineCode = line;
            medicineName = in.readLine().trimmed();
            quantity = in.readLine().trimmed();
            usageInstructions = in.readLine().trimmed();
            expiryDate = in.readLine().trimmed();
            break;
        }
    }
    file.close();
}

void Medicine::editMedicineData() {
    QFile file(medicineFile_read);
    QFile tempFile(medicineFileTemp);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) || !tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file.";
        return;
    }

    QTextStream in(&file);
    QTextStream out(&tempFile);

    while (!in.atEnd()) {
        QString medicineCodeFromFile, medicineNameFromFile, quantityFromFile, usageInstructionsFromFile, expiryDateFromFile;

        medicineCodeFromFile = in.readLine().trimmed();
        medicineNameFromFile = in.readLine().trimmed();
        quantityFromFile = in.readLine().trimmed();
        usageInstructionsFromFile = in.readLine().trimmed();
        expiryDateFromFile = in.readLine().trimmed();

        if (medicineCode == medicineCodeFromFile) {
            out << medicineCode << "\n";
            out << medicineName << "\n";
            out << quantity << "\n";
            out << usageInstructions << "\n";
            out << expiryDate << "\n";
        } else {
            out << medicineCodeFromFile << "\n";
            out << medicineNameFromFile << "\n";
            out << quantityFromFile << "\n";
            out << usageInstructionsFromFile << "\n";
            out << expiryDateFromFile << "\n";
        }
    }

    file.close();
    tempFile.close();

    QFile::remove("../../Medicine.txt");
    QFile::rename("../../Medicine_temp.txt", "../../Medicine.txt");
    medicineFile_read = "../../Medicine.txt";
}

void Medicine::deleteMedicineData(const QString &I_medicineCode) {
    QFile file(medicineFile_read);
    QFile tempFile(medicineFileTemp);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text) || !tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file.";
        return;
    }

    QTextStream in(&file);
    QTextStream out(&tempFile);

    while (!in.atEnd()) {
        QString medicineCodeFromFile, medicineNameFromFile, quantityFromFile, usageInstructionsFromFile, expiryDateFromFile;

        medicineCodeFromFile = in.readLine().trimmed();
        medicineNameFromFile = in.readLine().trimmed();
        quantityFromFile = in.readLine().trimmed();
        usageInstructionsFromFile = in.readLine().trimmed();
        expiryDateFromFile = in.readLine().trimmed();

        if (I_medicineCode == medicineCodeFromFile) {
            qDebug() << "Xóa dữ liệu thuốc có mã" << I_medicineCode;
        } else {
            out << medicineCodeFromFile << "\n";
            out << medicineNameFromFile << "\n";
            out << quantityFromFile << "\n";
            out << usageInstructionsFromFile << "\n";
            out << expiryDateFromFile << "\n";
        }
    }

    file.close();
    tempFile.close();

    QFile::remove("../../Medicine.txt");
    QFile::rename("../../Medicine_temp.txt", "../../Medicine.txt");
    medicineFile_read = "../../Medicine.txt";
}

void Medicine::showSearchMedicine(const QString& name) {
    if (!m_model) {
        qWarning() << "Model chưa được gán!";
        return;
    }

    QFile file(medicineFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file" << medicineFile_read;
        return;
    }

    QTextStream in(&file);
    QString searchName = name.toLower();
    m_model->clear(); // Xóa dữ liệu cũ trong model

    while (!in.atEnd()) {
        QString medicineCodeFromFile, medicineNameFromFile, quantityFromFile, usageInstructionsFromFile, expiryDateFromFile;

        medicineCodeFromFile = in.readLine().trimmed();
        medicineNameFromFile = in.readLine().trimmed();
        quantityFromFile = in.readLine().trimmed();
        usageInstructionsFromFile = in.readLine().trimmed();
        expiryDateFromFile = in.readLine().trimmed();

        QString test = medicineNameFromFile.toLower();
        if (test.indexOf(searchName) != -1) {
            m_model->addMedicine(medicineCodeFromFile, medicineNameFromFile, quantityFromFile,usageInstructionsFromFile, expiryDateFromFile);
        }
    }
    file.close();
    qDebug() << "Tìm kiếm hoàn tất.";
}

void Medicine::showSearchMedicineNotUsed() {
    if (!m_model) {
        qWarning() << "Model chưa được gán!";
        return;
    }

    // Lấy ngày hiện tại
    QDate currentDate = QDate::currentDate();

    QFile file(medicineFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file thuốc!";
        return;
    }

    QTextStream in(&file);
    m_model->clear();

    while (!in.atEnd()) {
        QString medicineCode = in.readLine().trimmed();
        QString medicineName = in.readLine().trimmed();
        QString quantity = in.readLine().trimmed();
        QString usageInstructions = in.readLine().trimmed();
        QString expiryDateString = in.readLine().trimmed();

        // Tách chuỗi ngày hết hạn thành ngày, tháng, năm
        QStringList dateParts = expiryDateString.split("/");  // Tách ngày, tháng, năm
        if (dateParts.size() != 3) {
            qWarning() << "Ngày hết hạn không hợp lệ!";
            continue;  // Bỏ qua dòng này nếu ngày hết hạn không hợp lệ
        }

        int day = dateParts[0].toInt();
        int month = dateParts[1].toInt();
        int year = dateParts[2].toInt();

        QDate expiryDate(year, month, day);
        if (!expiryDate.isValid()) {
            qWarning() << "Ngày hết hạn không hợp lệ!";
            continue;
        }

        if (currentDate > expiryDate) {
            // Nếu thuốc còn hạn, thêm vào model
            m_model->addMedicine(medicineCode, medicineName, quantity, usageInstructions, expiryDateString);
        }
    }
    file.close();
    qDebug() << "Đọc file thuốc và cập nhật model thành công!";
}

void Medicine::showExpiredMedicines() {
    QFile file(medicineFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file để đọc.";
        return;
    }
    QTextStream in(&file);
    QDate currentDate = QDate::currentDate();
    while (!in.atEnd()) {
        QString medicineCode = in.readLine();
        QString medicineName = in.readLine();
        QString quantity = in.readLine();
        QString usageInstructions = in.readLine();
        QString expiryDate = in.readLine();

        QDate expiry = QDate::fromString(expiryDate, "yyyy-MM-dd");
        if (expiry.isValid() && expiry < currentDate) {
            qDebug() << "Thuốc hết hạn:";
            qDebug() << "Mã thuốc:" << medicineCode;
            qDebug() << "Tên thuốc:" << medicineName;
            qDebug() << "Hạn sử dụng:" << expiryDate;
        }
    }
    file.close();
}
//Getter methods
QString Medicine::get_medicineCode() const { return medicineCode; }
QString Medicine::get_medicineName() const { return medicineName; }
QString Medicine::get_quantity() const { return quantity; }
QString Medicine::get_usageInstructions() const { return usageInstructions; }
QString Medicine::get_expiryDate() const { return expiryDate; }

// Setter methods
void Medicine::set_medicineCode(const QString &code) { medicineCode = code; }
void Medicine::set_medicineName(const QString &name) { medicineName = name; }
void Medicine::set_quantity(const QString &quantity) { this->quantity = quantity; }
void Medicine::set_usageInstructions(const QString &instructions) { usageInstructions = instructions; }
void Medicine::set_expiryDate(const QString &date) { expiryDate = date; }


// Medicine::Medicine(QObject *parent)
//     : QAbstractItemModel(parent)
// {}

// QVariant Medicine::headerData(int section, Qt::Orientation orientation, int role) const
// {
//     // FIXME: Implement me!
// }

// QModelIndex Medicine::index(int row, int column, const QModelIndex &parent) const
// {
//     // FIXME: Implement me!
// }

// QModelIndex Medicine::parent(const QModelIndex &index) const
// {
//     // FIXME: Implement me!
// }

// int Medicine::rowCount(const QModelIndex &parent) const
// {
//     if (!parent.isValid())
//         return 0;

//     // FIXME: Implement me!
// }

// int Medicine::columnCount(const QModelIndex &parent) const
// {
//     if (!parent.isValid())
//         return 0;

//     // FIXME: Implement me!
// }

// QVariant Medicine::data(const QModelIndex &index, int role) const
// {
//     if (!index.isValid())
//         return QVariant();

//     // FIXME: Implement me!
//     return QVariant();
// }
