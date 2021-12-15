cmake_minimum_required(VERSION 3.17)

INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/cmake/include
)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_BUILD_TYPE Debug)

PROJECT(bomberman)

FILE(GLOB SRCS  src/*.cpp 
                src/Engine/Scene/*.cpp
                src/Engine/Entity/*.cpp
                src/Engine/Component/*.cpp
                src/Engine/ComponentManager/*.cpp
                src/Engine/Grind/*.cpp
                src/Raylib/*.cpp
                src/Engine/Button/*.cpp
                src/Engine/Core/*.cpp
                src/Bomberman/*.cpp
                src/Bomberman/HelpScene.cpp
                src/Engine/System/*.cpp
                )

IF (WIN32)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR})
ENDIF(WIN32)

ADD_EXECUTABLE(bomberman ${SRCS})

IF (WIN32)
    TARGET_LINK_LIBRARIES(bomberman
            "../cmake/"
    )
    target_include_directories(bomberman PUBLIC
            "${PROJECT_BINARY_DIR}"
            "${PROJECT_SOURCE_DIR}/cmake/include"
    )
    add_custom_target(CopyBinaries
            COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/cmake/raylib.dll  ${CMAKE_BINARY_DIR}
    )

ENDIF(WIN32)

IF (UNIX)
        SET(GCC_COVERAGE_COMPILE_FLAGS "-lraylib -lGL -lm -lpthread -ldl -lrt")
        LINK_DIRECTORIES(${PROJECT_SOURCE_DIR}/cmake/)
        target_link_directories(bomberman PUBLIC ${PROJECT_SOURCE_DIR}/cmake/)
        TARGET_LINK_LIBRARIES(bomberman raylib)
ENDIF(UNIX)
