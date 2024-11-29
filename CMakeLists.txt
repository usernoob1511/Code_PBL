cmake_minimum_required(VERSION 3.16)

project(Project_PBL VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appProject_PBL
    main.cpp
    Images.qrc
)

qt_add_qml_module(appProject_PBL
    URI Project_PBL
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES Addnewdoctor_page.qml
        QML_FILES
        QML_FILES Home_page.qml
        QML_FILES Login_page.qml
        QML_FILES Side_bar.qml
        QML_FILES
        QML_FILES
        QML_FILES
        RESOURCES Images.qrc
        QML_FILES Doctor_page.qml
        QML_FILES Patient_page.qml
        SOURCES
        SOURCES Doctor.h Doctor.cpp
        SOURCES Admin.h Admin.cpp
        SOURCES Patient.h Patient.cpp
        QML_FILES Medicine_page.qml
        QML_FILES Add_In_Out_patient_page.qml
        QML_FILES
        QML_FILES ViewandEdit_page.qml
        SOURCES Person.h Person.cpp
        QML_FILES ViewandEdit_Inpatient_page.qml
        QML_FILES ViewandEdit_Outpatient_page.qml
        SOURCES
        SOURCES
        QML_FILES Addnewmedicine_page.qml
        QML_FILES EditMedicine_page.qml
        QML_FILES Forgotpassword_page.qml
        QML_FILES Registeraccount_page.qml
        QML_FILES Changepassword_page.qml
        SOURCES Medicine.h Medicine.cpp
)

# qt_add_executable(appProject_PBL
#     main.cpp
#     Images.qrc
#     Doctor.h Doctor.cpp
#     Admin.h Admin.cpp
#     Patient.h Patient.cpp
#     Person.h Person.cpp
#     Medicine.h Medicine.cpp
# )

# qt_add_qml_module(appProject_PBL
#     URI Project_PBL
#     VERSION 1.0
#     QML_FILES
#         Main.qml
#         Addnewdoctor_page.qml
#         Home_page.qml
#         Login_page.qml
#         Side_bar.qml
#         Doctor_page.qml
#         Patient_page.qml
#         Medicine_page.qml
#         Add_In_Out_patient_page.qml
#         ViewandEdit_page.qml
#         ViewandEdit_Inpatient_page.qml
#         ViewandEdit_Outpatient_page.qml
#         Addnewmedicine_page.qml
#         EditMedicine_page.qml
#         Forgotpassword_page.qml
#         Registeraccount_page.qml
#         Changepassword_page.qml
#     RESOURCES
#         Images.qrc
# )

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appProject_PBL PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appProject_PBL
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appProject_PBL
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appProject_PBL
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
