#ifndef DOCTOR_H
#define DOCTOR_H

#include <QString>
#include <QObject>
#include <QList>
#include <QTime>
#include <QStringList>
#include <QAbstractListModel>
#include <QDebug>
#include <QDateTime>
#include "Person.h"
#include "Medicine.h"


// CLASS DOCTOR
class DoctorModel : public QAbstractListModel {
    Q_OBJECT
public:

    enum DoctorRoles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        CccdRole,
        PhoneRole
    };

    DoctorModel(QObject *parent = nullptr) : QAbstractListModel(parent) {
        qWarning() << "Call construct";
    }

    void addDoctor(const QString &id, const QString &name, const QString &cccd, const QString &phone);

    // Các phương thức QML
    Q_INVOKABLE void printDoctors();
    Q_INVOKABLE QString get_doctorId(int index);
    Q_INVOKABLE QString get_name(int index);
    Q_INVOKABLE void editDoctorModel(const int index, const QString &name, const QString &cccd, const QString &phone);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void removeAt(int index);

    // Phương thức của QAbstractListModel
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

private:
    struct Doctor {
        QString id;
        QString name;
        QString cccd;
        QString phone;
    };
    QList<Doctor> doctors;
};


class Available {
protected:
    QStringList daysOfWeek;
    QString shift1, shift2, NoD;  // Số lượng ngày làm việc

public:
    void whenAvailable(const QStringList days, const QString& I_NoD, const QString& I_shift1, const QString& I_shift2);  // Cập nhật ngày làm việc
    QString getDayOfWeek();
};



// CLASS DOCTOR
class Doctor : public Person, public Available {
    Q_OBJECT
    Q_PROPERTY(DoctorModel* model WRITE setModel);
public:
    Doctor(QObject* parent = nullptr) : Person(), Available(){
        // Khởi tạo model mới cho Doctor
    }
    Q_INVOKABLE bool checkDoctorId(const QString &I_doctorId);
    //Q_INVOKABLE int checkDoctorId(const QString &I_doctorId);

    Q_INVOKABLE void getDoctorData(const QString &I_doctorId, const QString &I_department, const QString &I_phone,
                                   const QString &I_name, const QString &I_address, const QString &I_email, const QString &I_date,
                                   const QString &I_CCCD, const QString &I_sex, const QStringList days, const QString& I_NoD,
                                   const QString& I_shift1, const QString& I_shift2);
    Q_INVOKABLE void addDoctorData();
    Q_INVOKABLE void showDoctorDataFromFile();
    Q_INVOKABLE void searchDoctorData(const QString &I_doctorId);
    Q_INVOKABLE void editDoctorData();
    Q_INVOKABLE void deleteDoctorData(const QString &I_doctorId);
    Q_INVOKABLE void showSearchDoctor(const QString& name);
    Q_INVOKABLE void showDoctorOnline();
    void setModel(DoctorModel *model);

    // Getter methods
    Q_INVOKABLE QString get_doctorId() const;
    Q_INVOKABLE QString get_department() const;
    Q_INVOKABLE QString get_CCCD() const;
    Q_INVOKABLE QString get_name() const;
    Q_INVOKABLE QString get_address() const;
    Q_INVOKABLE QString get_phone() const;
    Q_INVOKABLE QString get_mail() const;
    Q_INVOKABLE QString get_date() const;
    Q_INVOKABLE QString get_sex() const;
    Q_INVOKABLE QString get_age() const;
    Q_INVOKABLE QStringList get_days() const;
    Q_INVOKABLE QString get_shift1() const;
    Q_INVOKABLE QString get_shift2() const;
    Q_INVOKABLE QString get_NoD() const;

    // Setter methods
    Q_INVOKABLE void set_doctorId(const QString &id);
    Q_INVOKABLE void set_department(const QString &dep);
    Q_INVOKABLE void set_CCCD(const QString &cccd);
    Q_INVOKABLE void set_name(const QString &n);
    Q_INVOKABLE void set_address(const QString &addr);
    Q_INVOKABLE void set_phone(const QString &ph);
    Q_INVOKABLE void set_mail(const QString &m);
    Q_INVOKABLE void set_date(const QString &d);
    Q_INVOKABLE void set_sex(const QString &s);
    Q_INVOKABLE void set_age(const QString &a);
    Q_INVOKABLE void set_days(const QStringList &days);
    Q_INVOKABLE void set_shift1(const QString &shift);
    Q_INVOKABLE void set_shift2(const QString &shift);
    Q_INVOKABLE void set_NoD(const QString &noD);

private:
    QString doctorId, department, mail;
    //QString doctorFile_read = ":/Doctor.txt";
    QString doctorFile_read = "../../Doctor.txt";
    QString doctorFile_write="../../Doctor.txt";
    QString doctorFileTemp = "../../Doctor_temp.txt";
    DoctorModel* m_model= nullptr;

};



#endif

// #ifndef DOCTOR_PATIENT_H
// #define DOCTOR_PATIENT_H

// #include <QString>
// #include <QObject>
// #include <QList>
// #include <QTime>
// //#include <vector>

// //CLASS AVAILABLE
// class Available {
// protected:
//     QStringList daysOfWeek;  // Danh sách các ngày làm việc
//     QString shift1;
//     QString shift2;
//     int NoD;  // Số lượng ngày làm việc

// public:
//     Q_INVOKABLE void whenAvailable(QStringList days, const int Noday, const QString& shiftStart, const QString& shiftEnd);  // Cập nhật ngày làm việc
//     //QString getCurrentAvailability() const;  // Trả về trạng thái hiện tại
// };

// class Doctor_and_Patient
// {
// public:
//     Doctor_and_Patient();
// };

// //CLASS PERSON

// class Person : public QObject {
//     Q_OBJECT
//     Q_PROPERTY(int age READ age NOTIFY ageChanged)
//     Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
//     Q_PROPERTY(QString address READ address WRITE setAddress NOTIFY addressChanged)
//     Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged)
//     Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY phoneChanged)
//     Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)
//     Q_PROPERTY(QString personalID READ personalID WRITE setPersonalID NOTIFY personalIDChanged)
//     Q_PROPERTY(QString sex READ sex WRITE setSex NOTIFY sexChanged)

// public:
//     explicit Person(QObject *parent = nullptr);

//     int age() const;
//     QString name() const;
//     QString address() const;
//     QString email() const;
//     QString phone() const;
//     QString date() const;
//     QString personalID() const;
//     QString sex() const;

//     void setName(const QString &name);
//     void setAddress(const QString &address);
//     void setEmail(const QString &email);
//     void setPhone(const QString &phone);
//     void setDate(const QString &date);
//     void setPersonalID(const QString &personalID);
//     void setSex(const QString &sex);

//     Q_INVOKABLE void getPersonData(const QString &phone, const QString &name, const QString &address,
//                                    const QString &email, const QString &date, const QString &personalID, const QString &sex);

// signals:
//     void ageChanged();
//     void nameChanged();
//     void addressChanged();
//     void emailChanged();
//     void phoneChanged();
//     void dateChanged();
//     void personalIDChanged();
//     void sexChanged();

// protected:
//     void calculateAge();

//     int m_age;
//     QString m_name, m_address, m_email, m_phone, m_date, m_personalID, m_sex;
// };


// // CLASS DOCTOR
// class Doctor : public Person, public Available {
//     Q_OBJECT
//     Q_PROPERTY(long long doctorId READ doctorId WRITE setDoctorId NOTIFY doctorIdChanged)
//     Q_PROPERTY(QString department READ department WRITE setDepartment NOTIFY departmentChanged)

// public:
//     Doctor(QObject *parent = nullptr);

//     // Getters and Setters for Doctor properties
//     long long doctorId() const;
//     QString department() const;

//     void setDoctorId(long long id);
//     void setDepartment(const QString &department);

//     Q_INVOKABLE void getDoctorData(const long long &doctorId, const QString &department, const QString &phone,
//                                    const QString &name, const QString &address, const QString &email,
//                                    const QString &date, const QString &personalID, const QString &sex,
//                                    QStringList days, const int NoDay, const QString& shiftStart, const QString& shiftEnd);

//     Q_INVOKABLE void addDoctorData();

// signals:
//     void doctorIdChanged();
//     void departmentChanged();


// private:
//     long long m_doctorId;
//     QString m_department;
//     QString m_room;
// };

// #endif // DOCTOR_AND_PATIENT_H
