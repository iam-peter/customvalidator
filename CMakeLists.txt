cmake_minimum_required(VERSION 3.16)

project(customvalidator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appcustomvalidator
    main.cpp
    specialvalidator.h specialvalidator.cpp
)

qt_add_qml_module(appcustomvalidator
    URI customvalidator
    VERSION 1.0
    QML_FILES main.qml
)

set_target_properties(appcustomvalidator PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(appcustomvalidator
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_link_libraries(appcustomvalidator
    PRIVATE Qt6::Quick)
