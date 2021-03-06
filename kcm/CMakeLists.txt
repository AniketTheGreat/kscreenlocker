# KI18N Translation Domain for this library
add_definitions(-DTRANSLATION_DOMAIN=\"screenlocker_kcm\")

set(screenlocker_kcm_SRCS
    kcm.cpp
    selectimagebutton.cpp
    ../greeter/wallpaper_integration.cpp
)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../)

ki18n_wrap_ui(screenlocker_kcm_SRCS kcm.ui)
kconfig_add_kcfg_files(screenlocker_kcm_SRCS ../kcfg/kscreensaversettings.kcfgc)
qt5_add_dbus_interface(screenlocker_kcm_SRCS ../dbus/org.kde.screensaver.xml screenlocker_interface)
qt5_add_resources( screenlocker_kcm_SRCS resources.qrc )

add_library(screenlocker_kcm MODULE ${screenlocker_kcm_SRCS})

target_link_libraries(screenlocker_kcm
    Qt5::DBus
    Qt5::QuickWidgets
    KF5::ConfigWidgets
    KF5::I18n
    KF5::TextWidgets
    KF5::GlobalAccel
    KF5::Package
    KF5::XmlGui
    KF5::Declarative
)

kcoreaddons_desktop_to_json(screenlocker_kcm screenlocker.desktop SERVICE_TYPES kcmodule.desktop)

install(
    TARGETS
        screenlocker_kcm
    DESTINATION
        ${KDE_INSTALL_PLUGINDIR}
)

install(
    FILES
        screenlocker.desktop
    DESTINATION
        ${KDE_INSTALL_KSERVICES5DIR}
)
