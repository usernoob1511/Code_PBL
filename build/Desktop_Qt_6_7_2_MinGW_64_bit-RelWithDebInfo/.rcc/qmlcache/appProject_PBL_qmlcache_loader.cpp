#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>
#include <QtCore/qhash.h>
#include <QtCore/qstring.h>

namespace QmlCacheGeneratedCode {
namespace _qt_qml_Project_PBL_Main_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Project_PBL_Addnewdoctor_page_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Project_PBL_Addnewpatient_page_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Project_PBL_Home_page_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Project_PBL_Login_page_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Project_PBL_Side_bar_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Project_PBL_Doctor_page_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}
namespace _qt_qml_Project_PBL_Patient_page_qml { 
    extern const unsigned char qmlData[];
    extern const QQmlPrivate::AOTCompiledFunction aotBuiltFunctions[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), &aotBuiltFunctions[0], nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    ~Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Project_PBL/Main.qml"), &QmlCacheGeneratedCode::_qt_qml_Project_PBL_Main_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Project_PBL/Addnewdoctor_page.qml"), &QmlCacheGeneratedCode::_qt_qml_Project_PBL_Addnewdoctor_page_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Project_PBL/Addnewpatient_page.qml"), &QmlCacheGeneratedCode::_qt_qml_Project_PBL_Addnewpatient_page_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Project_PBL/Home_page.qml"), &QmlCacheGeneratedCode::_qt_qml_Project_PBL_Home_page_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Project_PBL/Login_page.qml"), &QmlCacheGeneratedCode::_qt_qml_Project_PBL_Login_page_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Project_PBL/Side_bar.qml"), &QmlCacheGeneratedCode::_qt_qml_Project_PBL_Side_bar_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Project_PBL/Doctor_page.qml"), &QmlCacheGeneratedCode::_qt_qml_Project_PBL_Doctor_page_qml::unit);
    resourcePathToCachedUnit.insert(QStringLiteral("/qt/qml/Project_PBL/Patient_page.qml"), &QmlCacheGeneratedCode::_qt_qml_Project_PBL_Patient_page_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.structVersion = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
}

Registry::~Registry() {
    QQmlPrivate::qmlunregister(QQmlPrivate::QmlUnitCacheHookRegistration, quintptr(&lookupCachedUnit));
}

const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appProject_PBL)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qmlcache_appProject_PBL))
int QT_MANGLE_NAMESPACE(qCleanupResources_qmlcache_appProject_PBL)() {
    return 1;
}
