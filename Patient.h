#ifndef PATIENT_H
#define PATIENT_H
#include "Person.h"
#include <QAbstractItemModel>
#include <QString>
#include <QObject>
#include <QList>
#include <QTime>
#include <QStringList>
#include <QDebug>


class InpatientModel : public QAbstractListModel {
    Q_OBJECT
public:
    // Enum định nghĩa các vai trò
    enum InpatientRoles {
        PatientIdRole = Qt::UserRole + 1,
        NameRole,
        CccdRole,
        PhoneRole
    };

    explicit InpatientModel(QObject *parent = nullptr);
    void addInpatient(const QString &patientId, const QString &name, const QString &cccd, const QString &phone);
    Q_INVOKABLE void printInpatients();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE QString get_patientId(int index);
    Q_INVOKABLE QString get_name(int index);
    Q_INVOKABLE void editInpatientModel(const int index, const QString &name, const QString &cccd, const QString &phone);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void removeAt(int index);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    struct Inpatient {
        QString patientId;
        QString name;
        QString cccd;
        QString phone;
    };

    QList<Inpatient> inpatients;
};

class Disease {
protected:
    QString diseasename, symptoms, treatment, department;

public:
    void getDiseaseData(const QString& I_diseasename, const QString& I_symptoms, const QString& I_treatment, const QString& I_department);
};


class Patient : public Person, public Disease {
protected:
    QString patientId, BHYT, weight, height, appointDate;

public:
    void getPatientData(const QString& I_patientId, const QString& I_BHYT, const QString& I_weight, const QString& I_height, const QString& I_appointDate);
};

class Inpatient : public Patient {
    Q_OBJECT
    Q_PROPERTY(InpatientModel* model WRITE setModel);
private:
    QString dischargeDate, roomNumber;
    QString In_patientFile_read = "../../In_patient.txt";
    QString In_patientFile_write = "../../In_patient.txt";
    QString In_patientFileTemp = "../../In_patient_temp.txt";

    //DoctorModel* m_model= nullptr;
public:
    InpatientModel* m_model= nullptr;

    Q_INVOKABLE bool checkInpatientId(const QString &I_patientId);
    Q_INVOKABLE void showIn_PatientBefore(const QString& I_date);
    Q_INVOKABLE void getIn_PatientData(
        const QString &I_phone, const QString &I_name, const QString &I_address, const QString &I_date, const QString &I_CCCD, const QString &I_sex,
        const QString& I_diseaseName, const QString& I_symptoms, const QString& I_treatment, const QString& I_department,
        const QString& I_patientId, const QString& I_BHYT, const QString& I_weight, const QString& I_height, const QString& I_appointDate,
        const QString& I_dischargeDate, const QString& I_roomNumber);

    Q_INVOKABLE void addIn_PatientData();
    Q_INVOKABLE void showIn_PatientDataFromFile();
    void setModel(InpatientModel *model);
    Q_INVOKABLE void searchInpatientData(const QString &I_patientId);
    Q_INVOKABLE void editInpatientData();
    Q_INVOKABLE void deleteInpatientData(const QString &I_inpatientId);
    Q_INVOKABLE void showSearchInpatient(const QString &searchName);

    // Getter methods
    Q_INVOKABLE QString get_name() const;
    Q_INVOKABLE QString get_address() const;
    Q_INVOKABLE QString get_phone() const;
    Q_INVOKABLE QString get_date() const;
    Q_INVOKABLE QString get_CCCD() const;
    Q_INVOKABLE QString get_sex() const;
    Q_INVOKABLE QString get_age() const;
    Q_INVOKABLE QString get_diseasename() const;
    Q_INVOKABLE QString get_symptoms() const;
    Q_INVOKABLE QString get_treatment() const;
    Q_INVOKABLE QString get_department() const;
    Q_INVOKABLE QString get_patientId() const;
    Q_INVOKABLE QString get_BHYT() const;
    Q_INVOKABLE QString get_weight() const;
    Q_INVOKABLE QString get_height() const;
    Q_INVOKABLE QString get_appointDate() const;
    Q_INVOKABLE QString get_dischargeDate() const;
    Q_INVOKABLE QString get_roomNumber() const;

    // Setter methods
    Q_INVOKABLE void set_name(const QString &value);
    Q_INVOKABLE void set_address(const QString &value);
    Q_INVOKABLE void set_phone(const QString &value);
    Q_INVOKABLE void set_date(const QString &value);
    Q_INVOKABLE void set_CCCD(const QString &value);
    Q_INVOKABLE void set_sex(const QString &value);
    Q_INVOKABLE void set_age(const QString &value);
    Q_INVOKABLE void set_diseasename(const QString &value);
    Q_INVOKABLE void set_symptoms(const QString &value);
    Q_INVOKABLE void set_treatment(const QString &value);
    Q_INVOKABLE void set_department(const QString &value);
    Q_INVOKABLE void set_patientId(const QString &value);
    Q_INVOKABLE void set_BHYT(const QString &value);
    Q_INVOKABLE void set_weight(const QString &value);
    Q_INVOKABLE void set_height(const QString &value);
    Q_INVOKABLE void set_appointDate(const QString &value);
    Q_INVOKABLE void set_dischargeDate(const QString &value);
    Q_INVOKABLE void set_roomNumber(const QString &value);
};

class OutpatientModel : public QAbstractListModel {
    Q_OBJECT
public:
    // Enum định nghĩa các vai trò
    enum OutpatientRoles {
        PatientIdRole = Qt::UserRole + 1,
        NameRole,
        CccdRole,
        PhoneRole
    };

    explicit OutpatientModel(QObject *parent = nullptr);
    void addOutpatient(const QString &patientId, const QString &name, const QString &cccd, const QString &phone);
    Q_INVOKABLE void printOutpatients();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE QString get_patientId(int index);
    Q_INVOKABLE QString get_name(int index);
    Q_INVOKABLE void editOutpatientModel(const int index, const QString &name, const QString &cccd, const QString &phone);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void removeAt(int index);

protected:
    QHash<int, QByteArray> roleNames() const override;

private:
    struct Outpatient {
        QString patientId;
        QString name;
        QString cccd;
        QString phone;
    };

    QList<Outpatient> outpatients;
};

class Outpatient : public Patient {
    Q_OBJECT
    Q_PROPERTY(OutpatientModel* model WRITE setModel);
private:
    QString numberOfFollowUps, daysBetweenVisits;

    QString Out_patientFile_read = "../../Out_patient.txt";
    QString Out_patientFile_write = "../../Out_patient.txt";
    QString Out_patientFileTemp = "../../Out_patient_temp.txt";

public:
    OutpatientModel* m_model= nullptr;
    Q_INVOKABLE bool checkOutpatientId(const QString &I_patientId);
    Q_INVOKABLE void showOut_PatientBefore(const QString& I_date);
    Q_INVOKABLE void getOut_PatientData(
        const QString& I_phone, const QString& I_name, const QString& I_address, const QString& I_date, const QString& I_CCCD, const QString& I_sex,
        const QString& I_diseaseName, const QString& I_symptoms, const QString& I_treatment, const QString& I_department,
        const QString& I_patientId, const QString& I_BHYT, const QString& I_weight, const QString& I_height, const QString& I_appointDate,
        const QString& I_numberOfFollowUps, const QString& I_daysBetweenVisits);
    Q_INVOKABLE void addOut_PatientData();
    Q_INVOKABLE void showOut_PatientDataFromFile();
    Q_INVOKABLE void searchOutpatientData(const QString &I_patientId);
    Q_INVOKABLE void editOutpatientData();
    Q_INVOKABLE void deleteOutpatientData(const QString &I_outpatientId);
    Q_INVOKABLE void showSearchOutpatient(const QString &searchName);
    void setModel(OutpatientModel *model);

    // Getter methods
    Q_INVOKABLE QString get_name() const;
    Q_INVOKABLE QString get_address() const;
    Q_INVOKABLE QString get_phone() const;
    Q_INVOKABLE QString get_date() const;
    Q_INVOKABLE QString get_CCCD() const;
    Q_INVOKABLE QString get_sex() const;
    Q_INVOKABLE QString get_age() const;
    Q_INVOKABLE QString get_diseasename() const;
    Q_INVOKABLE QString get_symptoms() const;
    Q_INVOKABLE QString get_treatment() const;
    Q_INVOKABLE QString get_department() const;
    Q_INVOKABLE QString get_patientId() const;
    Q_INVOKABLE QString get_BHYT() const;
    Q_INVOKABLE QString get_weight() const;
    Q_INVOKABLE QString get_height() const;
    Q_INVOKABLE QString get_appointDate() const;
    Q_INVOKABLE QString get_numberOfFollowUps() const;
    Q_INVOKABLE QString get_daysBetweenVisits() const;

    // Setter methods
    Q_INVOKABLE void set_name(const QString &value);
    Q_INVOKABLE void set_address(const QString &value);
    Q_INVOKABLE void set_phone(const QString &value);
    Q_INVOKABLE void set_date(const QString &value);
    Q_INVOKABLE void set_CCCD(const QString &value);
    Q_INVOKABLE void set_sex(const QString &value);
    Q_INVOKABLE void set_age(const QString &value);
    Q_INVOKABLE void set_diseasename(const QString &value);
    Q_INVOKABLE void set_symptoms(const QString &value);
    Q_INVOKABLE void set_treatment(const QString &value);
    Q_INVOKABLE void set_department(const QString &value);
    Q_INVOKABLE void set_patientId(const QString &value);
    Q_INVOKABLE void set_BHYT(const QString &value);
    Q_INVOKABLE void set_weight(const QString &value);
    Q_INVOKABLE void set_height(const QString &value);
    Q_INVOKABLE void set_appointDate(const QString &value);
    Q_INVOKABLE void set_numberOfFollowUps(const QString &value);
    Q_INVOKABLE void set_daysBetweenVisits(const QString &value);

};


// class Patient : public QAbstractItemModel
// {
//     Q_OBJECT

// public:
//     explicit Patient(QObject *parent = nullptr);

//     // Header:
//     QVariant headerData(int section,
//                         Qt::Orientation orientation,
//                         int role = Qt::DisplayRole) const override;

//     // Basic functionality:
//     QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
//     QModelIndex parent(const QModelIndex &index) const override;

//     int rowCount(const QModelIndex &parent = QModelIndex()) const override;
//     int columnCount(const QModelIndex &parent = QModelIndex()) const override;

//     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

// private:
// };

#endif // PATIENT_H
