#include "Patient.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

InpatientModel::InpatientModel(QObject *parent)
    : QAbstractListModel(parent) {
    // qWarning() << "InpatientModel initialized";
    // addInpatient("101230456", "Le Van An", "012345678901", "0912345678");
}

void InpatientModel::addInpatient(const QString &patientId, const QString &name, const QString &cccd, const QString &phone) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    inpatients.append({Inpatient{patientId, name, cccd, phone}});
    endInsertRows();
    if (inpatients.isEmpty()) {
        qWarning() << "Danh sách inpatients chưa khởi tạo!";
    }
}

void InpatientModel::printInpatients() {
    qDebug() << "Danh sách bệnh nhân nội trú:";
    for (const auto &inpatient : inpatients) {
        qDebug() << "Patient ID:" << inpatient.patientId
                 << ", Name:" << inpatient.name
                 << ", CCCD:" << inpatient.cccd
                 << ", Phone:" << inpatient.phone;
    }
}

int InpatientModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return inpatients.size();
}

QVariant InpatientModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= inpatients.size())
        return QVariant();

    const auto &inpatient = inpatients.at(index.row());
    if (role == PatientIdRole)
        return inpatient.patientId;
    else if (role == NameRole)
        return inpatient.name;
    else if (role == CccdRole)
        return inpatient.cccd;
    else if (role == PhoneRole)
        return inpatient.phone;
    return QVariant();
}

QHash<int, QByteArray> InpatientModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[PatientIdRole] = "patientId";
    roles[NameRole] = "name";
    roles[CccdRole] = "cccd";
    roles[PhoneRole] = "phone";
    return roles;
}

QString InpatientModel::get_patientId(int index) {
    return inpatients[index].patientId;
}

QString InpatientModel::get_name(int index) {
    return inpatients[index].name;
}

void InpatientModel::editInpatientModel(const int index, const QString &name, const QString &cccd, const QString &phone) {
    if (index < 0 || index >= inpatients.size())
        return;

    inpatients[index].name = name;
    inpatients[index].cccd = cccd;
    inpatients[index].phone = phone;

    emit dataChanged(this->index(index), this->index(index)); // Thông báo cập nhật dữ liệu
}

void InpatientModel::clear() {
    beginResetModel();
    inpatients.clear();
    endResetModel();
}

void InpatientModel::removeAt(int index) {
    if (index < 0 || index >= inpatients.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    inpatients.removeAt(index);
    endRemoveRows();
}

void Disease :: getDiseaseData(const QString& I_diseasename, const QString& I_symptoms, const QString& I_treatment, const QString& I_department){
    diseasename = I_diseasename;
    symptoms = I_symptoms;
    treatment = I_treatment;
    department = I_department;
}
void Patient :: getPatientData(const QString& I_patientId, const QString& I_BHYT, const QString& I_weight, const QString& I_height, const QString& I_appointDate){
    patientId = I_patientId;
    BHYT = I_BHYT;
    weight = I_weight;
    height = I_height;
    appointDate = I_appointDate;
}

void Inpatient :: getIn_PatientData(
    const QString &I_phone, const QString &I_name, const QString &I_address, const QString &I_date, const QString &I_CCCD, const QString &I_sex,
    const QString& I_diseaseName, const QString& I_symptoms, const QString& I_treatment, const QString& I_department,
    const QString& I_patientId, const QString& I_BHYT, const QString& I_weight, const QString& I_height, const QString& I_appointDate,
    const QString& I_dischargeDate, const QString& I_roomNumber) {

    getPersonData(I_phone, I_name, I_address, I_date, I_CCCD, I_sex);
    getDiseaseData(I_diseaseName, I_symptoms, I_treatment, I_department);
    getPatientData(I_patientId, I_BHYT, I_weight, I_height, I_appointDate);
    dischargeDate = I_dischargeDate;
    roomNumber = I_roomNumber;
}

bool Inpatient :: checkInpatientId(const QString &I_patientId) {

    QFile ifinpatient(In_patientFile_read);

    if (!ifinpatient.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return false;
    }
    QTextStream in(&ifinpatient);


    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile;
        QString diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile;
        QString dischargeDateFromFile, roomNumberFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        dischargeDateFromFile = in.readLine().trimmed();
        roomNumberFromFile = in.readLine().trimmed();

        if (patientIdFromFile == I_patientId) {
            return false;
        }
    }
    ifinpatient.close();
    qDebug() <<"kiem tra hoan tat";
    return true;
}

void Inpatient::showIn_PatientBefore(const QString& I_date) {
    QFile file(In_patientFile_read); // Sử dụng đường dẫn file của lớp Inpatient
    qDebug() << In_patientFile_read;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading.";
        qWarning() << "Error:" << file.errorString();
        return;
    }
    m_model->clear();
    QTextStream in(&file);


    QString day = formatDate(I_date);

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile;
        QString diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile;
        QString dischargeDateFromFile, roomNumberFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        dischargeDateFromFile = in.readLine().trimmed();
        roomNumberFromFile = in.readLine().trimmed();

        QString temp = formatDate(appointDateFromFile);

        if (day <= temp ) {
            m_model->addInpatient(patientIdFromFile, nameFromFile, CCCDFromFile, phoneFromFile);
        }
    }

    m_model->printInpatients(); // In danh sách bệnh nhân nếu cần
    qDebug() << "Rowcount model:" << m_model->rowCount();
    file.close();
    qDebug() << "Inpatient data read successfully.";
}


void Inpatient::addIn_PatientData() {
    QFile file(In_patientFile_write); // Sử dụng đường dẫn file của lớp Inpatient
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        stream << patientId << "\n";
        stream << BHYT << "\n";

        stream << phone << "\n";
        stream << name << "\n";
        stream << address << "\n";
        stream << date << "\n";
        stream << CCCD << "\n";
        stream << sex << "\n";

        stream << diseasename << "\n";
        stream << symptoms << "\n";
        stream << treatment << "\n";
        stream << department << "\n";
        stream << weight << "\n";
        stream << height <<"\n";
        stream << appointDate << "\n";
        stream << dischargeDate << "\n";
        stream << roomNumber << "\n";

        file.close();
        qDebug() << "Inpatient data added successfully.";
    } else {
        qDebug() << "Cannot open file for writing:" << In_patientFile_write;
        qDebug() << "Error:" << file.errorString();
    }
}

void Inpatient::showIn_PatientDataFromFile() {
    QFile file(In_patientFile_read); // Sử dụng đường dẫn file của lớp Inpatient
    qDebug() << In_patientFile_read;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading.";
        qWarning() << "Error:" << file.errorString();
        return;
    }
    m_model->clear();
    QTextStream in(&file);

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        if (line.isEmpty()) {
            continue;
        }
        patientId = line;
        BHYT = in.readLine().trimmed();
        phone = in.readLine().trimmed();
        name = in.readLine().trimmed();
        address = in.readLine().trimmed();
        date = in.readLine().trimmed();
        CCCD = in.readLine().trimmed();
        sex = in.readLine().trimmed();
        diseasename = in.readLine().trimmed();
        symptoms = in.readLine().trimmed();
        treatment = in.readLine().trimmed();
        department = in.readLine().trimmed();
        weight = in.readLine().trimmed();
        height = in.readLine().trimmed();
        appointDate = in.readLine().trimmed();
        dischargeDate = in.readLine().trimmed();
        roomNumber = in.readLine().trimmed();

        // Nếu cần thêm vào model hoặc xử lý dữ liệu, thêm logic tại đây
        m_model->addInpatient(patientId, name, CCCD, phone); // Ví dụ thêm vào model
    }

    m_model->printInpatients(); // In danh sách bệnh nhân nếu cần
    qDebug() << "Rowcount model:" << m_model->rowCount();
    file.close();
    qDebug() << "Inpatient data read successfully.";
}

void Inpatient ::setModel(InpatientModel *model) {
    m_model = model;
}

void Inpatient :: searchInpatientData(const QString &I_patientId) {
    QFile file(In_patientFile_read);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;

        while (!in.atEnd()) {
            line = in.readLine().trimmed();

            if (line == I_patientId) {
                patientId = line;
                BHYT = in.readLine().trimmed();
                phone = in.readLine().trimmed();
                name = in.readLine().trimmed();
                address = in.readLine().trimmed();
                date = in.readLine().trimmed();
                CCCD = in.readLine().trimmed();
                sex = in.readLine().trimmed();
                diseasename = in.readLine().trimmed();
                symptoms = in.readLine().trimmed();
                treatment = in.readLine().trimmed();
                department = in.readLine().trimmed();
                weight = in.readLine().trimmed();
                height = in.readLine().trimmed();
                appointDate = in.readLine().trimmed();
                dischargeDate = in.readLine().trimmed();
                roomNumber = in.readLine().trimmed();
                break;
            }
        }
        file.close();
    } else {
        qDebug() << "Cannot open file for reading:" << In_patientFile_read;
        qDebug() << "Error:" << file.errorString();
    }
}

void Inpatient::editInpatientData() {
    QFile ifinpatient(In_patientFile_read);
    QFile ofinpatient(In_patientFileTemp);

    if (!ifinpatient.open(QIODevice::ReadOnly | QIODevice::Text) || !ofinpatient.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return;
    }

    QTextStream in(&ifinpatient);
    QTextStream out(&ofinpatient);

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile;
        QString diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile;
        QString dischargeDateFromFile, roomNumberFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        dischargeDateFromFile = in.readLine().trimmed();
        roomNumberFromFile = in.readLine().trimmed();

        // Check if patient ID matches
        if (patientId == patientIdFromFile) {
            qDebug() << "Editing inpatient data with ID" << patientId;

            // Write the updated data
            out << patientId << "\n";
            out << BHYT << "\n";
            out << phone << "\n";
            out << name << "\n";
            out << address << "\n";
            out << date << "\n";
            out << CCCD << "\n";
            out << sex << "\n";
            out << diseasename << "\n";
            out << symptoms << "\n";
            out << treatment << "\n";
            out << department << "\n";
            out << weight << "\n";
            out << height << "\n";
            out << appointDate << "\n";
            out << dischargeDate << "\n";
            out << roomNumber << "\n";
            //dischargeDate, roomNumber
        } else {
            // Write original data if patient ID doesn't match
            out << patientIdFromFile << "\n";
            out << BHYTFromFile << "\n";
            out << phoneFromFile << "\n";
            out << nameFromFile << "\n";
            out << addressFromFile << "\n";
            out << dateFromFile << "\n";
            out << CCCDFromFile << "\n";
            out << sexFromFile << "\n";
            out << diseasenameFromFile << "\n";
            out << symptomsFromFile << "\n";
            out << treatmentFromFile << "\n";
            out << departmentFromFile << "\n";
            out << weightFromFile << "\n";
            out << heightFromFile << "\n";
            out << appointDateFromFile << "\n";
            out << dischargeDateFromFile << "\n";
            out << roomNumberFromFile << "\n";
        }
    }

    ifinpatient.close();
    ofinpatient.close();

    QFile::remove("../../In_patient.txt");
    QFile::rename("../../In_patient_temp.txt", "../../In_patient.txt");
    In_patientFile_read = "../../In_patient.txt";
}

void Inpatient::deleteInpatientData(const QString &I_inpatientId) {
    QFile ifinpatient(In_patientFile_read);
    QFile ofinpatient(In_patientFileTemp);

    if (!ifinpatient.open(QIODevice::ReadOnly | QIODevice::Text) || !ofinpatient.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return;
    }

    QTextStream in(&ifinpatient);
    QTextStream out(&ofinpatient);

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile;
        QString diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile;
        QString dischargeDateFromFile, roomNumberFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        dischargeDateFromFile = in.readLine().trimmed();
        roomNumberFromFile = in.readLine().trimmed();

        // Check if patient ID matches
        if (I_inpatientId == patientIdFromFile) {
            qDebug() << "Delete doctor data with ID" << I_inpatientId;
        } else {
            out << patientIdFromFile << "\n";
            out << BHYTFromFile << "\n";
            out << phoneFromFile << "\n";
            out << nameFromFile << "\n";
            out << addressFromFile << "\n";
            out << dateFromFile << "\n";
            out << CCCDFromFile << "\n";
            out << sexFromFile << "\n";
            out << diseasenameFromFile << "\n";
            out << symptomsFromFile << "\n";
            out << treatmentFromFile << "\n";
            out << departmentFromFile << "\n";
            out << weightFromFile << "\n";
            out << heightFromFile << "\n";
            out << appointDateFromFile << "\n";
            out << dischargeDateFromFile << "\n";
            out << roomNumberFromFile << "\n";
        }
    }

    ifinpatient.close();
    ofinpatient.close();

    QFile::remove("../../In_patient.txt");
    QFile::rename("../../In_patient_temp.txt", "../../In_patient.txt");
    In_patientFile_read = "../../In_patient.txt";
}

void Inpatient::showSearchInpatient(const QString &name) {
    if (!m_model) {
        qWarning() << "Model chưa được gán!";
        return;
    }

    QFile file(In_patientFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file:" << In_patientFile_read;
        return;
    }

    QTextStream in(&file);
    QString searchName = name.toLower(); // Chuyển tên tìm kiếm về chữ thường để so sánh
    m_model->clear(); // Xóa dữ liệu cũ trong model

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile,
            diseaseFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile,
            appointDateFromFile, dischargeDateFromFile, roomNumberFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseaseFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        dischargeDateFromFile = in.readLine().trimmed();
        roomNumberFromFile = in.readLine().trimmed();

        // Kiểm tra tên bệnh nhân khớp với tìm kiếm
        QString test = nameFromFile.toLower();
        if (test.indexOf(searchName.toLower()) != -1) {
            m_model->addInpatient(patientIdFromFile, nameFromFile, CCCDFromFile, phoneFromFile);
        }
    }

    file.close();
    qDebug() << "Tìm kiếm hoàn tất.";
}

QString Inpatient::get_name() const { return name; }
QString Inpatient::get_address() const { return address; }
QString Inpatient::get_phone() const { return phone; }
QString Inpatient::get_date() const { return date; }
QString Inpatient::get_CCCD() const { return CCCD; }
QString Inpatient::get_sex() const { return sex; }
QString Inpatient::get_age() const { return age; }
QString Inpatient::get_diseasename() const { return diseasename; }
QString Inpatient::get_symptoms() const { return symptoms; }
QString Inpatient::get_treatment() const { return treatment; }
QString Inpatient::get_department() const { return department; }
QString Inpatient::get_patientId() const { return patientId; }
QString Inpatient::get_BHYT() const { return BHYT; }
QString Inpatient::get_weight() const { return weight; }
QString Inpatient::get_height() const { return height; }
QString Inpatient::get_appointDate() const { return appointDate; }
QString Inpatient::get_dischargeDate() const { return dischargeDate; }
QString Inpatient::get_roomNumber() const { return roomNumber; }

// Setter methods
void Inpatient::set_name(const QString &value) { name = value; }
void Inpatient::set_address(const QString &value) { address = value; }
void Inpatient::set_phone(const QString &value) { phone = value; }
void Inpatient::set_date(const QString &value) { date = value; }
void Inpatient::set_CCCD(const QString &value) { CCCD = value; }
void Inpatient::set_sex(const QString &value) { sex = value; }
void Inpatient::set_age(const QString &value) { age = value; }
void Inpatient::set_diseasename(const QString &value) { diseasename = value; }
void Inpatient::set_symptoms(const QString &value) { symptoms = value; }
void Inpatient::set_treatment(const QString &value) { treatment = value; }
void Inpatient::set_department(const QString &value) { department = value; }
void Inpatient::set_patientId(const QString &value) { patientId = value; }
void Inpatient::set_BHYT(const QString &value) { BHYT = value; }
void Inpatient::set_weight(const QString &value) { weight = value; }
void Inpatient::set_height(const QString &value) { height = value; }
void Inpatient::set_appointDate(const QString &value) { appointDate = value; }
void Inpatient::set_dischargeDate(const QString &value) { dischargeDate = value; }
void Inpatient::set_roomNumber(const QString &value) { roomNumber = value; }




OutpatientModel::OutpatientModel(QObject *parent)
    : QAbstractListModel(parent) {}

void OutpatientModel::addOutpatient(const QString &patientId, const QString &name, const QString &cccd, const QString &phone) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    outpatients.append({patientId, name, cccd, phone});
    endInsertRows();
}

void OutpatientModel::printOutpatients() {
    qDebug() << "Danh sách bệnh nhân ngoại trú:";
    for (const auto &outpatient : outpatients) {
        qDebug() << "Patient ID:" << outpatient.patientId
                 << ", Name:" << outpatient.name
                 << ", CCCD:" << outpatient.cccd
                 << ", Phone:" << outpatient.phone;
    }
}

int OutpatientModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return outpatients.size();
}

QVariant OutpatientModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= outpatients.size())
        return QVariant();

    const auto &outpatient = outpatients.at(index.row());
    switch (role) {
    case PatientIdRole: return outpatient.patientId;
    case NameRole: return outpatient.name;
    case CccdRole: return outpatient.cccd;
    case PhoneRole: return outpatient.phone;
    default: return QVariant();
    }
}

QHash<int, QByteArray> OutpatientModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[PatientIdRole] = "patientId";
    roles[NameRole] = "name";
    roles[CccdRole] = "cccd";
    roles[PhoneRole] = "phone";
    return roles;
}

QString OutpatientModel::get_patientId(int index) {
    return outpatients[index].patientId;
}

QString OutpatientModel::get_name(int index) {
    return outpatients[index].name;
}

void OutpatientModel::editOutpatientModel(const int index, const QString &name, const QString &cccd, const QString &phone) {
    if (index < 0 || index >= outpatients.size())
        return;

    outpatients[index].name = name;
    outpatients[index].cccd = cccd;
    outpatients[index].phone = phone;

    emit dataChanged(this->index(index), this->index(index));
}

void OutpatientModel::clear() {
    beginResetModel();
    outpatients.clear();
    endResetModel();
}

void OutpatientModel::removeAt(int index) {
    if (index < 0 || index >= outpatients.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    outpatients.removeAt(index);
    endRemoveRows();
}

bool Outpatient :: checkOutpatientId(const QString &I_patientId) {

    QFile ifoutpatient(Out_patientFile_read);

    if (!ifoutpatient.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return false;
    }

    QTextStream in(&ifoutpatient);

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile,
            diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile,
            numberOfFollowUpsFromFile, daysBetweenVisitsFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        numberOfFollowUpsFromFile = in.readLine().trimmed();
        daysBetweenVisitsFromFile = in.readLine().trimmed();
        // Check if patient ID matches

        if (patientIdFromFile == I_patientId) {
            return false;
        }
    }
    ifoutpatient.close();
    return true;
}

void Outpatient::showOut_PatientBefore(const QString& I_date) {
    QFile file(Out_patientFile_read);
    qDebug() << Out_patientFile_read;

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading.";
        qWarning() << "Error:" << file.errorString();
        return;
    }
    m_model->clear();
    QTextStream in(&file);


    QString day = formatDate(I_date);

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile,
            diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile,
            numberOfFollowUpsFromFile, daysBetweenVisitsFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        numberOfFollowUpsFromFile = in.readLine().trimmed();
        daysBetweenVisitsFromFile = in.readLine().trimmed();

        QString temp = formatDate(appointDateFromFile);

        if (day <= temp ) {
            m_model->addOutpatient(patientIdFromFile, nameFromFile, CCCDFromFile, phoneFromFile);
        }
    }

    m_model->printOutpatients(); // In danh sách bệnh nhân nếu cần
    qDebug() << "Rowcount model:" << m_model->rowCount();
    file.close();
    qDebug() << "Inpatient data read successfully.";
}


void Outpatient::getOut_PatientData(
    const QString& I_phone, const QString& I_name, const QString& I_address, const QString& I_date, const QString& I_CCCD, const QString& I_sex,
    const QString& I_diseaseName, const QString& I_symptoms, const QString& I_treatment, const QString& I_department,
    const QString& I_patientId, const QString& I_BHYT, const QString& I_weight, const QString& I_height, const QString& I_appointDate,
    const QString& I_numberOfFollowUps, const QString& I_daysBetweenVisits)
{
    getPersonData(I_phone, I_name, I_address, I_date, I_CCCD, I_sex);
    getDiseaseData(I_diseaseName, I_symptoms, I_treatment, I_department);
    getPatientData(I_patientId, I_BHYT, I_weight, I_height, I_appointDate);

    numberOfFollowUps = I_numberOfFollowUps;
    daysBetweenVisits = I_daysBetweenVisits;
}

void Outpatient::addOut_PatientData() {
    QFile file(Out_patientFile_write);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);

        // Ghi dữ liệu chung
        stream << patientId << "\n";
        stream << BHYT << "\n";

        stream << phone << "\n";
        stream << name << "\n";
        stream << address << "\n";
        stream << date << "\n";
        stream << CCCD << "\n";
        stream << sex << "\n";

        stream << diseasename << "\n";
        stream << symptoms << "\n";
        stream << treatment << "\n";
        stream << department << "\n";
        stream << weight << "\n";
        stream << height << "\n";
        stream << appointDate << "\n";

        stream << numberOfFollowUps << "\n";
        stream << daysBetweenVisits << "\n";

        file.close();
        qDebug() << "Outpatient data added successfully.";
    } else {
        qDebug() << "Cannot open file for writing:" << Out_patientFile_write;
        qDebug() << "Error:" << file.errorString();
    }
}

void Outpatient::showOut_PatientDataFromFile() {
    QFile file(Out_patientFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading.";
        qWarning() << "Error:" << file.errorString();
        return;
    }
    m_model->clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        patientId = line;
        BHYT = in.readLine().trimmed();
        phone = in.readLine().trimmed();
        name = in.readLine().trimmed();
        address = in.readLine().trimmed();
        date = in.readLine().trimmed();
        CCCD = in.readLine().trimmed();
        sex = in.readLine().trimmed();
        diseasename = in.readLine().trimmed();
        symptoms = in.readLine().trimmed();
        treatment = in.readLine().trimmed();
        department = in.readLine().trimmed();
        weight = in.readLine().trimmed();
        height = in.readLine().trimmed();
        appointDate = in.readLine().trimmed();
        numberOfFollowUps = in.readLine().trimmed();
        daysBetweenVisits = in.readLine().trimmed();
        m_model->addOutpatient(patientId, name, CCCD, phone);
    }

    file.close();
    qDebug() << "Outpatient data read successfully.";
}

void Outpatient :: searchOutpatientData(const QString &I_patientId) {
    QFile file(Out_patientFile_read);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;

        while (!in.atEnd()) {
            line = in.readLine().trimmed();

            if (line == I_patientId) {
                patientId = line;
                BHYT = in.readLine().trimmed();
                phone = in.readLine().trimmed();
                name = in.readLine().trimmed();
                address = in.readLine().trimmed();
                date = in.readLine().trimmed();
                CCCD = in.readLine().trimmed();
                sex = in.readLine().trimmed();
                diseasename = in.readLine().trimmed();
                symptoms = in.readLine().trimmed();
                treatment = in.readLine().trimmed();
                department = in.readLine().trimmed();
                weight = in.readLine().trimmed();
                height = in.readLine().trimmed();
                appointDate = in.readLine().trimmed();
                numberOfFollowUps = in.readLine().trimmed();
                daysBetweenVisits = in.readLine().trimmed();
                break;
            }
        }
        file.close();
    } else {
        qDebug() << "Cannot open file for reading:" << Out_patientFile_read;
        qDebug() << "Error:" << file.errorString();
    }
}
void Outpatient::editOutpatientData() {
    QFile ifoutpatient(Out_patientFile_read);
    QFile ofoutpatient(Out_patientFileTemp);

    if (!ifoutpatient.open(QIODevice::ReadOnly | QIODevice::Text) || !ofoutpatient.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return;
    }

    QTextStream in(&ifoutpatient);
    QTextStream out(&ofoutpatient);

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile,
            diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile,
            numberOfFollowUpsFromFile, daysBetweenVisitsFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        numberOfFollowUpsFromFile = in.readLine().trimmed();
        daysBetweenVisitsFromFile = in.readLine().trimmed();
        // Check if patient ID matches
        if (patientId == patientIdFromFile) {
            qDebug() << "Editing inpatient data with ID" << patientId;

            // Write the updated data
            out << patientId << "\n";
            out << BHYT << "\n";
            out << phone << "\n";
            out << name << "\n";
            out << address << "\n";
            out << date << "\n";
            out << CCCD << "\n";
            out << sex << "\n";
            out << diseasename << "\n";
            out << symptoms << "\n";
            out << treatment << "\n";
            out << department << "\n";
            out << weight << "\n";
            out << height << "\n";
            out << appointDate << "\n";
            out << numberOfFollowUps << "\n";
            out << daysBetweenVisits << "\n";
        } else {
            // Write original data if patient ID doesn't match
            out << patientIdFromFile << "\n";
            out << BHYTFromFile << "\n";
            out << phoneFromFile << "\n";
            out << nameFromFile << "\n";
            out << addressFromFile << "\n";
            out << dateFromFile << "\n";
            out << CCCDFromFile << "\n";
            out << sexFromFile << "\n";
            out << diseasenameFromFile << "\n";
            out << symptomsFromFile << "\n";
            out << treatmentFromFile << "\n";
            out << departmentFromFile << "\n";
            out << weightFromFile << "\n";
            out << heightFromFile << "\n";
            out << appointDateFromFile << "\n";
            out << numberOfFollowUpsFromFile << "\n";
            out << daysBetweenVisitsFromFile << "\n";
        }
    }

    ifoutpatient.close();
    ofoutpatient.close();

    QFile::remove("../../Out_patient.txt");
    QFile::rename("../../Out_patient_temp.txt", "../../Out_patient.txt");
    Out_patientFile_read = "../../Out_patient.txt";
}

void Outpatient::deleteOutpatientData(const QString &I_outpatientId) {
    QFile ifoutpatient(Out_patientFile_read);
    QFile ofoutpatient(Out_patientFileTemp);

    if (!ifoutpatient.open(QIODevice::ReadOnly | QIODevice::Text) || !ofoutpatient.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return;
    }

    QTextStream in(&ifoutpatient);
    QTextStream out(&ofoutpatient);

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile,
            diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile,
            numberOfFollowUpsFromFile, daysBetweenVisitsFromFile;
        // numberOfFollowUps = in.readLine().trimmed();
        // daysBetweenVisits = in.readLine().trimmed();
        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        numberOfFollowUpsFromFile = in.readLine().trimmed();
        daysBetweenVisitsFromFile = in.readLine().trimmed();

        // Check if patient ID matches
        if (I_outpatientId == patientIdFromFile) {
            qDebug() << "Delete doctor data with ID" << I_outpatientId;
        } else {
            out << patientIdFromFile << "\n";
            out << BHYTFromFile << "\n";
            out << phoneFromFile << "\n";
            out << nameFromFile << "\n";
            out << addressFromFile << "\n";
            out << dateFromFile << "\n";
            out << CCCDFromFile << "\n";
            out << sexFromFile << "\n";
            out << diseasenameFromFile << "\n";
            out << symptomsFromFile << "\n";
            out << treatmentFromFile << "\n";
            out << departmentFromFile << "\n";
            out << weightFromFile << "\n";
            out << heightFromFile << "\n";
            out << appointDateFromFile << "\n";
            out << numberOfFollowUpsFromFile << "\n";
            out << daysBetweenVisitsFromFile << "\n";
        }
    }

    ifoutpatient.close();
    ofoutpatient.close();

    QFile::remove("../../Out_patient.txt");
    QFile::rename("../../Out_patient_temp.txt", "../../Out_patient.txt");
    Out_patientFile_read = "../../Out_patient.txt";
}
void Outpatient ::setModel(OutpatientModel *model) {
    m_model = model;
}

void Outpatient::showSearchOutpatient(const QString &name) {
    if (!m_model) {
        qWarning() << "Model chưa được gán!";
        return;
    }

    QFile file(Out_patientFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file:" << Out_patientFile_read;
        return;
    }

    QTextStream in(&file);
    QString searchName = name.toLower(); // Chuyển tên tìm kiếm về chữ thường để so sánh
    m_model->clear(); // Xóa dữ liệu cũ trong model

    while (!in.atEnd()) {
        QString patientIdFromFile, BHYTFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile,
            diseasenameFromFile, symptomsFromFile, treatmentFromFile, departmentFromFile, weightFromFile, heightFromFile, appointDateFromFile,
            numberOfFollowUpsFromFile, daysBetweenVisitsFromFile;

        patientIdFromFile = in.readLine().trimmed();
        BHYTFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        diseasenameFromFile = in.readLine().trimmed();
        symptomsFromFile = in.readLine().trimmed();
        treatmentFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        weightFromFile = in.readLine().trimmed();
        heightFromFile = in.readLine().trimmed();
        appointDateFromFile = in.readLine().trimmed();
        numberOfFollowUpsFromFile = in.readLine().trimmed();
        daysBetweenVisitsFromFile = in.readLine().trimmed();

        // Kiểm tra tên bệnh nhân khớp với tìm kiếm
        QString test = nameFromFile.toLower();
        if (test.indexOf(searchName.toLower()) != -1) {
            m_model->addOutpatient(patientIdFromFile, nameFromFile, CCCDFromFile, phoneFromFile);
        }
    }

    file.close();
    qDebug() << "Tìm kiếm hoàn tất.";
}

QString Outpatient::get_name() const { return name; }
QString Outpatient::get_address() const { return address; }
QString Outpatient::get_phone() const { return phone; }
QString Outpatient::get_date() const { return date; }
QString Outpatient::get_CCCD() const { return CCCD; }
QString Outpatient::get_sex() const { return sex; }
QString Outpatient::get_age() const { return age; }
QString Outpatient::get_diseasename() const { return diseasename; }
QString Outpatient::get_symptoms() const { return symptoms; }
QString Outpatient::get_treatment() const { return treatment; }
QString Outpatient::get_department() const { return department; }
QString Outpatient::get_patientId() const { return patientId; }
QString Outpatient::get_BHYT() const { return BHYT; }
QString Outpatient::get_weight() const { return weight; }
QString Outpatient::get_height() const { return height; }
QString Outpatient::get_appointDate() const { return appointDate; }
QString Outpatient::get_numberOfFollowUps() const { return numberOfFollowUps; }
QString Outpatient::get_daysBetweenVisits() const { return daysBetweenVisits; }

// Setter methods
void Outpatient::set_name(const QString &value) { name = value; }
void Outpatient::set_address(const QString &value) { address = value; }
void Outpatient::set_phone(const QString &value) { phone = value; }
void Outpatient::set_date(const QString &value) { date = value; }
void Outpatient::set_CCCD(const QString &value) { CCCD = value; }
void Outpatient::set_sex(const QString &value) { sex = value; }
void Outpatient::set_age(const QString &value) { age = value; }
void Outpatient::set_diseasename(const QString &value) { diseasename = value; }
void Outpatient::set_symptoms(const QString &value) { symptoms = value; }
void Outpatient::set_treatment(const QString &value) { treatment = value; }
void Outpatient::set_department(const QString &value) { department = value; }
void Outpatient::set_patientId(const QString &value) { patientId = value; }
void Outpatient::set_BHYT(const QString &value) { BHYT = value; }
void Outpatient::set_weight(const QString &value) { weight = value; }
void Outpatient::set_height(const QString &value) { height = value; }
void Outpatient::set_appointDate(const QString &value) { appointDate = value; }
void Outpatient::set_numberOfFollowUps(const QString &value) { numberOfFollowUps = value; }
void Outpatient::set_daysBetweenVisits(const QString &value) { daysBetweenVisits = value; }
// Patient::Patient(QObject *parent)
//     : QAbstractItemModel(parent)
// {}

// QVariant Patient::headerData(int section, Qt::Orientation orientation, int role) const
// {
//     // FIXME: Implement me!
// }

// QModelIndex Patient::index(int row, int column, const QModelIndex &parent) const
// {
//     // FIXME: Implement me!
// }

// QModelIndex Patient::parent(const QModelIndex &index) const
// {
//     // FIXME: Implement me!
// }

// int Patient::rowCount(const QModelIndex &parent) const
// {
//     if (!parent.isValid())
//         return 0;

//     // FIXME: Implement me!
// }

// int Patient::columnCount(const QModelIndex &parent) const
// {
//     if (!parent.isValid())
//         return 0;

//     // FIXME: Implement me!
// }

// QVariant Patient::data(const QModelIndex &index, int role) const
// {
//     if (!index.isValid())
//         return QVariant();

//     // FIXME: Implement me!
//     return QVariant();
// }
