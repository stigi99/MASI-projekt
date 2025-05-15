cmake_minimum_required(VERSION 3.19)
project(nienazwane3 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

qt_standard_project_setup()

qt_add_executable(nienazwane3
    WIN32 MACOSX_BUNDLE
    main.cpp


    verticalwidget.h
    verticalwidget.cpp
    horizontalwidget.h horizontalwidget.cpp

    globals.h
    globals.cpp
    combinedwidget.h combinedwidget.cpp
)

target_link_libraries(nienazwane3
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS nienazwane3
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET nienazwane3
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
