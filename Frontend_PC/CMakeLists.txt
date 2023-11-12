cmake_minimum_required(VERSION 3.5)

project(Frontend_PC VERSION 0.1 LANGUAGES CXX)

# Find Qt packages
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add MySQL include directories and libraries
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)
find_package(Threads REQUIRED)
find_package(MySQL REQUIRED)

include_directories(${MYSQL_INCLUDE_DIR})

set(PROJECT_SOURCES
    main.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Frontend_PC
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}

    )
else()
    if(ANDROID)
        add_library(Frontend_PC SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Frontend_PC
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Frontend_PC PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
    ${CMAKE_THREAD_LIBS_INIT}
    ${MYSQL_LIBRARY}
)

set_target_properties(Frontend_PC PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS Frontend_PC
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Frontend_PC)
endif()
