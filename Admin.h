#ifndef ADMIN_H
#define ADMIN_H


#include <QObject>
#include <QString>

class Admin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged)
    Q_PROPERTY(QString phone READ phone WRITE setPhone NOTIFY phoneChanged)
public:
    explicit Admin(QObject *parent = nullptr);

    Q_INVOKABLE bool login(const QString &username, const QString &password);
    Q_INVOKABLE void registerAdmin(const QString &username, const QString &password, const QString &phone);
    Q_INVOKABLE bool forgotPassword(const QString &username, const QString &phone);
    Q_INVOKABLE void changePassword(const QString& password);
    QString username() const;
    void setUsername(const QString &username);

    QString password() const;
    void setPassword(const QString &password);

    QString phone() const;
    void setPhone(const QString &phone);

signals:
    void usernameChanged();
    void passwordChanged();
    void phoneChanged();
private:
    QString m_username;
    QString m_password;
    QString m_phone;
    QString adminFile_read = ":/Admin.txt";
    QString adminFile_write="../../Admin.txt";
    QString adminFile_writeTemp="../../Admin_temp.txt";
};

#endif

