#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QQmlContext>
#include <QDebug>
#include <QDir>
#include "Doctor.h"
#include "Admin.h"
#include "Patient.h"
#include "Person.h"
#include "Medicine.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    Admin admin;
    engine.rootContext()->setContextProperty("admin", &admin);

    qmlRegisterType<Admin> ("Admin",1,0,"Admin");
    qmlRegisterType<Person> ("Person",1,0,"Person");

    qmlRegisterType<Doctor>("Doctor", 1, 0, "Doctor");
    qmlRegisterType<Available>("Available", 1, 0, "Available");
    qmlRegisterType<DoctorModel>("DoctorModel", 1, 0, "DoctorModel");

    qmlRegisterType<Medicine> ("Medicine",1,0,"Medicine");
    qmlRegisterType<MedicineModel>("MedicineModel",1,0,"MedicineModel");

    qmlRegisterType<Disease> ("Disease",1,0,"Disease");
    qmlRegisterType<Patient> ("Patient",1,0,"Patient");
    qmlRegisterType<Inpatient>("Inpatient",1,0,"Inpatient");
    qmlRegisterType<InpatientModel> ("InpatientModel",1,0,"InpatientModel");
    qmlRegisterType<Outpatient>("Outpatient",1,0,"Outpatient");
    qmlRegisterType<OutpatientModel> ("OutpatientModel",1,0,"OutpatientModel");


    engine.loadFromModule("Project_PBL", "Main");

    if (engine.rootObjects().isEmpty()) {
        qDebug() << "Không thể tải root object từ module.";
        return -1; // Hoặc xử lý lỗi khác
    } else {
        qDebug() << "Đã tải thành công root object từ module.";
    }

    return app.exec();
}
