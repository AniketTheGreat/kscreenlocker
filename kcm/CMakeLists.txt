# KI18N Translation Domain for this library
add_definitions(-DTRANSLATION_DOMAIN=\"screenlocker_kcm\")

set(screenlocker_kcm_SRCS kcm.cpp)
ki18n_wrap_ui(screenlocker_kcm_SRCS kcm.ui)
kconfig_add_kcfg_files(screenlocker_kcm_SRCS ../kcfg/kscreensaversettings.kcfgc)
qt5_add_dbus_interface(screenlocker_kcm_SRCS ../dbus/org.kde.screensaver.xml screenlocker_interface)

add_library(screenlocker_kcm MODULE ${screenlocker_kcm_SRCS})

target_link_libraries(screenlocker_kcm
    Qt5::DBus
    KF5::ConfigWidgets
    KF5::I18n
    KF5::Service
)

kservice_desktop_to_json(screenlocker_kcm screenlocker.desktop)

install(
    TARGETS
        screenlocker_kcm
    DESTINATION
        ${PLUGIN_INSTALL_DIR}
)

install(
    FILES
        screenlocker.desktop
    DESTINATION
        ${SERVICES_INSTALL_DIR}
)