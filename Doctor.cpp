#include "Doctor.h"
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QDebug>

void DoctorModel::addDoctor(const QString &id, const QString &name, const QString &cccd, const QString &phone) {
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    doctors.append({Doctor{id, name, cccd, phone}});
    endInsertRows();
    qWarning() << "Call here";
    if (doctors.isEmpty()) {
        qWarning() << "Danh sách doctors chưa khởi tạo!";
        return;
    }
}

void DoctorModel::printDoctors() {
    qDebug() << "Danh sách bác sĩ:";
    for (const auto &doctor : doctors) {
        qDebug() << "ID:" << doctor.id
                 << ", Name:" << doctor.name
                 << ", CCCD:" << doctor.cccd
                 << ", Phone:" << doctor.phone;
    }
}

int DoctorModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    qWarning() << "Call here get parent " << doctors.size() << " " << this;
    return doctors.size();
}

QVariant DoctorModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= doctors.size())
        return QVariant();

    const auto &doctor = doctors.at(index.row());
    if (role == IdRole)
        return doctor.id;
    else if (role == NameRole)
        return doctor.name;
    else if (role == CccdRole)
        return doctor.cccd;
    else if (role == PhoneRole)
        return doctor.phone;
    return QVariant();
}

QHash<int, QByteArray> DoctorModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[IdRole] = "id";
    roles[NameRole] = "name";
    roles[CccdRole] = "cccd";
    roles[PhoneRole] = "phone";
    return roles;
}

QString DoctorModel::get_doctorId(int index) {
    return doctors[index].id;
}

QString DoctorModel::get_name(int index) {
    qDebug() << "co goi dc ham get_name model khong";
    return doctors[index].name;
}

void DoctorModel::editDoctorModel(const int index, const QString &name, const QString &cccd, const QString &phone) {
    qDebug() << "index: " << index << "size:" << doctors.size();
    doctors[index].name = name;
    doctors[index].cccd = cccd;
    doctors[index].phone = phone;
}

void DoctorModel::clear() {
    beginResetModel();
    doctors.clear();
    endResetModel();
}

void DoctorModel::removeAt(int index) {
    if (index < 0 || index >= doctors.size())
        return;

    beginRemoveRows(QModelIndex(), index, index);
    doctors.removeAt(index);
    endRemoveRows();
}
// CLASS AVAILABLE
void Available::whenAvailable(const QStringList days, const QString& I_NoD, const QString& I_shift1, const QString& I_shift2) {
    NoD = I_NoD;
    shift1 = I_shift1;
    shift2 = I_shift2;
    daysOfWeek = days;
}

QString getDayofWeek() {
    QDate currentDate = QDate::currentDate();  // Lấy ngày hiện tại
    int dayOfWeek = currentDate.dayOfWeek();   // Lấy thứ trong tuần (1 = Thứ Hai, ..., 7 = Chủ Nhật)

    // Chuyển đổi số thành tên ngày trong tuần
    switch(dayOfWeek) {
    case 1: return "Monday";
    case 2: return "Tuesday";
    case 3: return "Wednesday";
    case 4: return "Thursday";
    case 5: return "Friday";
    case 6: return "Saturday";
    case 7: return "Sunday";
    default: return "";
    }
}

// CLASS DOCTOR

bool Doctor :: checkDoctorId(const QString &I_doctorId) {
    QFile ifdoctor(doctorFile_read);

    if (!ifdoctor.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return false;
    }
    QTextStream in(&ifdoctor);

    while (!in.atEnd()) {
        QString doctorIdFromFile, departmentFromFile, ageFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile, emailFromFile, NoDFromFile, shift1FromFile, shift2FromFile;
        QStringList DayofWeek;
        doctorIdFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        ageFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        emailFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        NoDFromFile = in.readLine().trimmed();

        int noD = NoDFromFile.toInt();
        for (int i = 0; i < noD; ++i) {
            DayofWeek.append(in.readLine().trimmed());
        }

        shift1FromFile = in.readLine().trimmed();
        shift2FromFile = in.readLine().trimmed();

        if (doctorIdFromFile == I_doctorId) {
            qDebug() <<"kiem tra doctor id";
            return false;
        }
    }
    ifdoctor.close();
    qDebug() <<"kiem tra hoan tat";
    return true;
}

void Doctor::getDoctorData(const QString &I_doctorId, const QString &I_department, const QString &I_phone,
                           const QString &I_name, const QString &I_address, const QString &I_email, const QString &I_date,
                           const QString &I_CCCD, const QString &I_sex, const QStringList days, const QString& I_NoD,
                           const QString& I_shift1, const QString& I_shift2) {
    doctorId = I_doctorId;
    department = I_department;
    mail = I_email;
    getPersonData(I_phone, I_name, I_address, I_date, I_CCCD, I_sex);
    whenAvailable(days, I_NoD, I_shift1, I_shift2);
}

void Doctor::addDoctorData() {
    QFile file(doctorFile_write);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream stream(&file);
        stream << doctorId << "\n";
        stream << department << "\n";
        stream << age << "\n"; // age là QString
        stream << phone << "\n";
        stream << name << "\n";
        stream << address << "\n";
        stream << mail << "\n";
        stream << date << "\n";
        stream << CCCD << "\n";
        stream << sex << "\n";
        stream << NoD << "\n";

        for (int i = 0; i < NoD.toInt() ; i++) {
            stream << daysOfWeek[i] << "\n";
        }

        stream << shift1 << "\n";
        stream << shift2 << "\n";

        file.close();
        qDebug() << "Doctor data added successfully.";
    } else {
        qDebug() << "Cannot open file for writing:" << doctorFile_write;
        qDebug() << "Error:" << file.errorString();
    }
}

void Doctor::showDoctorDataFromFile() {
    QFile file(doctorFile_read);
    qDebug() << doctorFile_read;
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Could not open file for reading.";
        return;
    }
    QTextStream in(&file);
    m_model->clear();
    while (!in.atEnd()) {
        doctorId = in.readLine().trimmed();
        department = in.readLine().trimmed();
        age = in.readLine().trimmed();
        phone = in.readLine().trimmed();
        name = in.readLine().trimmed();
        address = in.readLine().trimmed();
        mail = in.readLine().trimmed();
        date = in.readLine().trimmed();
        CCCD = in.readLine().trimmed();
        sex = in.readLine().trimmed();
        NoD = in.readLine().trimmed();
        for (int i = 0; i < NoD.toInt(); ++i) {
            daysOfWeek.append(in.readLine().trimmed());
        }

        shift1 = in.readLine().trimmed();
        shift2 = in.readLine().trimmed();
        m_model->addDoctor(doctorId, name, CCCD, phone);
    }
    m_model->printDoctors();
    qDebug() << "Rowcount model" <<m_model->rowCount();
    file.close();
    qDebug() << "Doctor data added successfully.";
}

void Doctor::setModel(DoctorModel *model) {
    m_model = model;
}

QString Doctor::get_doctorId() const { return doctorId; }
QString Doctor::get_department() const { return department; }
QString Doctor::get_CCCD() const { return CCCD; }
QString Doctor::get_name() const { return name; }
QString Doctor::get_address() const { return address; }
QString Doctor::get_phone() const { return phone; }
QString Doctor::get_mail() const { return mail; }
QString Doctor::get_date() const { return date; }
QString Doctor::get_sex() const { return sex; }
QString Doctor::get_age() const { return age; }
QStringList Doctor::get_days() const { return daysOfWeek; }
QString Doctor::get_shift1() const { return shift1; }
QString Doctor::get_shift2() const { return shift2; }
QString Doctor::get_NoD() const { return NoD; }

// Setter methods
void Doctor::set_doctorId(const QString &id) { doctorId = id; }
void Doctor::set_department(const QString &dep) { department = dep; }
void Doctor::set_CCCD(const QString &cccd) { CCCD = cccd; }
void Doctor::set_name(const QString &n) { name = n; }
void Doctor::set_address(const QString &addr) { address = addr; }
void Doctor::set_phone(const QString &ph) { phone = ph; }
void Doctor::set_mail(const QString &m) { mail = m; }
void Doctor::set_date(const QString &d) { date = d; }
void Doctor::set_sex(const QString &s) { sex = s; }
void Doctor::set_age(const QString &a) { age = a; }
void Doctor::set_days(const QStringList &days) { daysOfWeek = days; }
void Doctor::set_shift1(const QString &shift) { shift1 = shift; }
void Doctor::set_shift2(const QString &shift) { shift2 = shift; }
void Doctor::set_NoD(const QString &noD) { NoD = noD; }



void Doctor::searchDoctorData(const QString &I_doctorId) {
    QFile file(doctorFile_read);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line;

        while (!in.atEnd()) {
            line = in.readLine().trimmed();

            if (line == I_doctorId) {
                doctorId = line;
                department = in.readLine().trimmed();
                age = in.readLine().trimmed();  // age là QString
                phone = in.readLine().trimmed();
                name = in.readLine().trimmed();
                address = in.readLine().trimmed();
                mail = in.readLine().trimmed();
                date = in.readLine().trimmed();
                CCCD = in.readLine().trimmed();
                sex = in.readLine().trimmed();
                NoD = in.readLine().trimmed();

                daysOfWeek.clear();  // Xóa danh sách cũ nếu có
                for (int i = 0; i < NoD.toInt(); ++i) {
                    daysOfWeek.append(in.readLine().trimmed());
                }

                shift1 = in.readLine().trimmed();
                shift2 = in.readLine().trimmed();
                qDebug() << shift1;
                break;
            }
        }
        file.close();
    } else {
        qDebug() << "Cannot open file for reading:" << doctorFile_read;
        qDebug() << "Error:" << file.errorString();
    }
    qDebug() << department << " " << age << " " << sex;
}

void Doctor :: editDoctorData() {

    QFile ifdoctor(doctorFile_read);
    QFile ofdoctor(doctorFileTemp);

    if (!ifdoctor.open(QIODevice::ReadOnly | QIODevice::Text) || !ofdoctor.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return;
    }

    QTextStream in(&ifdoctor);
    QTextStream out(&ofdoctor);

    while (!in.atEnd()) {
        QString doctorIdFromFile, departmentFromFile, ageFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile, emailFromFile, NoDFromFile, shift1FromFile, shift2FromFile;
        QStringList DayofWeek;
        doctorIdFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        ageFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        emailFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        NoDFromFile = in.readLine().trimmed();

        int noD = NoDFromFile.toInt();
        for (int i = 0; i < noD; ++i) {
            DayofWeek.append(in.readLine().trimmed());
        }

        shift1FromFile = in.readLine().trimmed();
        shift2FromFile = in.readLine().trimmed();

        // Check if doctor ID matches
        if (doctorId == doctorIdFromFile) {
            qDebug() << "Editing doctor data with ID" << doctorId;

            // Write the updated data
            out << doctorId << "\n";
            out << department << "\n";
            out << age << "\n";
            out << phone << "\n";
            out << name << "\n";
            out << address << "\n";
            out << mail << "\n";
            out << date << "\n";
            out << CCCD << "\n";
            out << sex << "\n";
            out << NoD << "\n";
            qDebug()<<"Dung:" << mail;
            qDebug() <<CCCD;
            for (const QString &day : daysOfWeek) {
                out << day << "\n";
            }
            qDebug() << daysOfWeek.length();

            out << shift1 << "\n";
            out << shift2 << "\n";
        } else {
            // Write original data if doctor ID doesn't match
            out << doctorIdFromFile << "\n";
            out << departmentFromFile << "\n";
            out << ageFromFile << "\n";
            out << phoneFromFile << "\n";
            out << nameFromFile << "\n";
            out << addressFromFile << "\n";
            out << emailFromFile << "\n";
            out << dateFromFile << "\n";
            out << CCCDFromFile << "\n";
            out << sexFromFile << "\n";
            out << NoDFromFile << "\n";

            for (const QString &day : DayofWeek) {
                out << day << "\n";
            }
            out << shift1FromFile << "\n";
            out << shift2FromFile << "\n";
        }
    }

    ifdoctor.close();
    ofdoctor.close();

    QFile::remove("../../Doctor.txt");
    QFile::rename("../../Doctor_temp.txt", "../../Doctor.txt");
    doctorFile_read = "../../Doctor.txt";
}

void Doctor :: deleteDoctorData(const QString &I_doctorId) {
    qDebug() << "co goi duoc ham ni khong";
    QFile ifdoctor(doctorFile_read);
    QFile ofdoctor(doctorFileTemp);

    if (!ifdoctor.open(QIODevice::ReadOnly | QIODevice::Text) || !ofdoctor.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Error opening files!";
        return;
    }

    QTextStream in(&ifdoctor);
    QTextStream out(&ofdoctor);

    while (!in.atEnd()) {
        QString doctorIdFromFile, departmentFromFile, ageFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile, emailFromFile, NoDFromFile, shift1FromFile, shift2FromFile;
        QStringList DayofWeek;
        doctorIdFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        ageFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        emailFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        NoDFromFile = in.readLine().trimmed();

        int noD = NoDFromFile.toInt();
        for (int i = 0; i < noD; ++i) {
            DayofWeek.append(in.readLine().trimmed());
        }

        shift1FromFile = in.readLine().trimmed();
        shift2FromFile = in.readLine().trimmed();

        // Check if doctor ID matches
        if (doctorIdFromFile == I_doctorId) {
            qDebug() << "Delete doctor data with ID" << doctorIdFromFile;
        } else {
            out << doctorIdFromFile << "\n";
            out << departmentFromFile << "\n";
            out << ageFromFile << "\n";
            out << phoneFromFile << "\n";
            out << nameFromFile << "\n";
            out << addressFromFile << "\n";
            out << emailFromFile << "\n";
            out << dateFromFile << "\n";
            out << CCCDFromFile << "\n";
            out << sexFromFile << "\n";
            out << NoDFromFile << "\n";

            for (const QString &day : DayofWeek) {
                out << day << "\n";
            }

            out << shift1FromFile << "\n";
            out << shift2FromFile << "\n";
        }
    }

    ifdoctor.close();
    ofdoctor.close();

    QFile::remove("../../Doctor.txt");
    QFile::rename("../../Doctor_temp.txt", "../../Doctor.txt");
    doctorFile_read = "../../Doctor.txt";
}

void Doctor::showSearchDoctor(const QString& name) {
    if (!m_model) {
        qWarning() << "Model chưa được gán!";
        return;
    }

    QFile file(doctorFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file" << doctorFile_read;
        return;
    }

    QTextStream in(&file);
    QString searchName = name.toLower();
    m_model->clear(); // Xóa dữ liệu cũ trong model

    while (!in.atEnd()) {
        QString doctorIdFromFile, departmentFromFile, ageFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile, emailFromFile, NoDFromFile, shift1FromFile, shift2FromFile;
        QStringList DayofWeek;
        doctorIdFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        ageFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        emailFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        NoDFromFile = in.readLine().trimmed();

        int noD = NoDFromFile.toInt();
        for (int i = 0; i < noD; ++i) {
            DayofWeek.append(in.readLine().trimmed());
        }

        shift1FromFile = in.readLine().trimmed();
        shift2FromFile = in.readLine().trimmed();
        QString test = nameFromFile.toLower();
        // if (test == searchName) {
        //     m_model->addDoctor(doctorIdFromFile, nameFromFile, CCCDFromFile, phoneFromFile);
        // }
        if (test.indexOf(searchName.toLower()) != -1) {
            m_model->addDoctor(doctorIdFromFile, nameFromFile, CCCDFromFile, phoneFromFile);
        }
    }
    file.close();
    qDebug() << "Tìm kiếm hoàn tất.";
}

void Doctor::showDoctorOnline() {
    if (!m_model) {
        qWarning() << "Model chưa được gán!";
        return;
    }
    qDebug() << "goi duoc ham show doctor online khong";

    QFile file(doctorFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Không thể mở file" << doctorFile_read;
        return;
    }

    QTextStream in(&file);
    m_model->clear(); // Xóa dữ liệu cũ trong model

    while (!in.atEnd()) {
        QString doctorIdFromFile, departmentFromFile, ageFromFile, phoneFromFile, nameFromFile, addressFromFile, dateFromFile, CCCDFromFile, sexFromFile, emailFromFile, NoDFromFile, shift1FromFile, shift2FromFile;
        QStringList DayofWeek;

        doctorIdFromFile = in.readLine().trimmed();
        departmentFromFile = in.readLine().trimmed();
        ageFromFile = in.readLine().trimmed();
        phoneFromFile = in.readLine().trimmed();
        nameFromFile = in.readLine().trimmed();
        addressFromFile = in.readLine().trimmed();
        emailFromFile = in.readLine().trimmed();
        dateFromFile = in.readLine().trimmed();
        CCCDFromFile = in.readLine().trimmed();
        sexFromFile = in.readLine().trimmed();
        NoDFromFile = in.readLine().trimmed();

        int noD_temp = NoDFromFile.toInt();
        for (int i = 0; i < noD_temp; ++i) {
            DayofWeek.append(in.readLine().trimmed());
        }

        shift1FromFile = in.readLine().trimmed();
        shift2FromFile = in.readLine().trimmed();

        QString currentDay = getDayofWeek();  // Lấy ngày hiện tại trong tuần
        if (DayofWeek.contains(currentDay)) {
            // Kiểm tra giờ làm việc của bác sĩ
            QTime currentTime = QTime::currentTime();
            QTime shift1Time = QTime::fromString(shift1FromFile, "hh:mm");
            QTime shift2Time = QTime::fromString(shift2FromFile, "hh:mm");
            if (currentTime >= shift1Time && currentTime <= shift2Time) {
                m_model->addDoctor(doctorIdFromFile, nameFromFile, CCCDFromFile, phoneFromFile);
            }
        }
    }

    file.close();
    qDebug() << "da goi duoc ham show doctor online";
}

