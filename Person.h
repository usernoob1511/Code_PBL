#ifndef PERSON_H
#define PERSON_H

#include <QAbstractItemModel>
#include <QString>
#include <QObject>
#include <QList>
#include <QTime>
#include <QStringList>
#include <QDebug>

class Person : public QObject {

public:
    void getPersonData(const QString &I_phone, const QString &I_name, const QString &I_address,
                       const QString &I_date, const QString &I_CCCD, const QString &I_sex);
    Q_INVOKABLE bool checkPersonPhone(const QString &I_phone);


    QString formatDate(const QString &date);

protected:
    void calculateAge();

    QString name, address, phone, date, CCCD, sex, age;

};








// class Person : public QAbstractItemModel
// {
//     Q_OBJECT

// public:
//     explicit Person(QObject *parent = nullptr);

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

#endif // PERSON_H
