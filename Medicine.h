#ifndef MEDICINE_H
#define MEDICINE_H

#include <QAbstractItemModel>
#include <QString>
#include <QObject>
#include <QList>
#include <QTime>
#include <QStringList>
#include <QAbstractListModel>
#include <QDebug>
#include <QDateTime>

class MedicineModel : public QAbstractListModel {
    Q_OBJECT
public:
    enum MedicineRoles {
        CodeRole = Qt::UserRole + 1,
        NameRole,
        QuantityRole,
        UsageInstructionsRole,
        ExpiryDateRole
    };

    explicit MedicineModel(QObject *parent = nullptr);

    void addMedicine(const QString &code, const QString &name, const QString &quantity, const QString &usageInstructions, const QString &expiryDate);
    Q_INVOKABLE void printMedicines();
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE QString get_medicineCode(int index);
    Q_INVOKABLE QString get_medicineName(int index);
    Q_INVOKABLE void editMedicineModel(int index, const QString &name, const QString &quantity, const QString &usageInstructions, const QString &expiryDate);
    Q_INVOKABLE void clear();
    Q_INVOKABLE void removeAt(int index);

private:
    struct Medicine {
        QString code, name, quantity, usageInstructions, expiryDate;
    };
    QList<Medicine> medicines;
};

class Medicine : public QObject {
    Q_OBJECT
    Q_PROPERTY(MedicineModel* model WRITE setModel);
public:
    Medicine(QObject* parent = nullptr) : QObject(parent) {
    }
    Q_INVOKABLE bool checkMedicineId(const QString &I_meidicineId);
    Q_INVOKABLE void getMedicineData(const QString &I_medicineCode, const QString &I_medicineName,
                                     const QString &I_quantity, const QString &I_usageInstructions,
                                     const QString &I_expiryDate);
    Q_INVOKABLE void addMedicineData();
    Q_INVOKABLE void showMedicineDataFromFile();
    Q_INVOKABLE void searchMedicineData(const QString &I_medicineCode);
    Q_INVOKABLE void editMedicineData();
    Q_INVOKABLE void deleteMedicineData(const QString &I_medicineCode);
    Q_INVOKABLE void showSearchMedicine(const QString& name);
    Q_INVOKABLE void showSearchMedicineNotUsed();
    Q_INVOKABLE void showExpiredMedicines();
    void setModel(MedicineModel *model);


    Q_INVOKABLE QString get_medicineCode() const;
    Q_INVOKABLE QString get_medicineName() const;
    Q_INVOKABLE QString get_quantity() const;
    Q_INVOKABLE QString get_usageInstructions() const;
    Q_INVOKABLE QString get_expiryDate() const;

    Q_INVOKABLE void set_medicineCode(const QString &code);
    Q_INVOKABLE void set_medicineName(const QString &name);
    Q_INVOKABLE void set_quantity(const QString &qty);
    Q_INVOKABLE void set_usageInstructions(const QString &instructions);
    Q_INVOKABLE void set_expiryDate(const QString &date);

private:
    QString medicineCode, medicineName, quantity, usageInstructions, expiryDate;
    QString medicineFile_read = "../../Medicine.txt";
    QString medicineFile_write = "../../Medicine.txt";
    QString medicineFileTemp = "../../Medicine_temp.txt";
    MedicineModel* m_model = nullptr;
};
// class Medicine : public QAbstractItemModel
// {
//     Q_OBJECT

// public:
//     explicit Medicine(QObject *parent = nullptr);

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

#endif // MEDICINE_H
