#include "admin.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Admin::Admin(QObject *parent) : QObject(parent) {}

bool Admin::login(const QString &username, const QString &password) {
    qDebug() <<"da goi duoc ham login";
    QFile file(adminFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    QTextStream in(&file);
    QString u, p, ph;
    while (!in.atEnd()) {
        in >> u >> p >> ph;
        if (u!="") {
            qDebug() << u << p << ph << "\n";
            if (u == username && p == password) {
                setUsername(u);
                setPassword(p);
                setPhone(ph);
                file.close();
                return true;
            }
        }
        else {
            break;
        }
    }
    file.close();
    return false;
}

void Admin::registerAdmin(const QString &username, const QString &password, const QString &phone) {
    QFile file(adminFile_write);
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << username << " " << password << " " << phone << "\n";
        file.close();
        qDebug() << "Registration successful!";
    }
    adminFile_read = "../../Admin.txt";
}


QString Admin::username() const {
    qDebug()  << "có goi dc ham nay khong";
    qDebug() << m_username;
    return m_username;
}

void Admin::setUsername(const QString &username) {
    if (m_username != username) {
        m_username = username;
        emit usernameChanged();
    }
}

QString Admin::password() const {
    return m_password;
}

void Admin::setPassword(const QString &password) {
    if (m_password != password) {
        m_password = password;
        emit passwordChanged();
    }
}

QString Admin::phone() const {
    return m_phone;
}

void Admin::setPhone(const QString &phone) {
    if (m_phone != phone) {
        m_phone = phone;
        emit phoneChanged();
    }
}

bool Admin::forgotPassword(const QString &username, const QString &phone) {
    QFile file(adminFile_read);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return false;
    qDebug() <<"vao dc khong";
    QTextStream in(&file);
    QString u, p, ph;
    while (!in.atEnd()) {
        in >> u >> p >> ph;
        if (u == username && ph == phone) {
            qDebug() << "Password found: " << p;
            setPassword(p);
            file.close();
            return true;
        }
    }
    file.close();
    qDebug() << "User not found.";
    return false;
}

void Admin :: changePassword(const QString& password) {
    setPassword(password);
    QFile file(adminFile_read);
    QFile tempFile(adminFile_writeTemp);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the original file.";
        return;
    }
    if (!tempFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the temporary file.";
        file.close();
        return;
    }
    QTextStream in(&file);
    QTextStream out(&tempFile);
    QString u, p, ph;

    bool userFound = false;

    while (!in.atEnd()) {
        in >> u >> p >> ph;
        if (u == m_username) {
            out << u << " " << m_password << " " << ph << "\n";
        } else {
            out << u << " " << p << " " << ph << "\n";
        }
    }
    file.close();
    tempFile.close();
    QFile::remove("../../Admin.txt");
    QFile::rename("../../Admin_temp.txt","../../Admin.txt");
    adminFile_read = "../../Admin.txt";
}
