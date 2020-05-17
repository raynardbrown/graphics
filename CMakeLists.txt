cmake_minimum_required(VERSION 3.15.5)

# Set the name of the project and store it in a variable PROJECT_NAME
project(graphics)

# Require at least this version of boost
find_package(Boost 1.71.0)
if(NOT Boost_FOUND)
  message(FATAL_ERROR "boost not found")
endif()

set(Headers "")
list(APPEND Headers ${CMAKE_CURRENT_SOURCE_DIR}/inc)
list(APPEND Headers ${CMAKE_CURRENT_SOURCE_DIR}/src)
list(APPEND Headers ${Boost_INCLUDE_DIRS})

set(Sources src/graphics/Color.cpp
            src/graphics/Font.cpp
            src/graphics/Point2D.cpp
            src/graphics/Rectangle2D.cpp
            src/graphics/Size2D.cpp)

if (MSVC)
    add_compile_options(-Zi
                        -W4
                        -EHsc
                        -D_CRT_SECURE_NO_WARNINGS
                        -DSTRICT
                        -DUNICODE
                        -D_UNICODE)

    set(Sources_Windows src/graphics/windows/FontFactory.cpp
                        src/graphics/windows/GraphicsFactory.cpp
                        src/graphics/windows/ScreenGraphics.cpp
                        src/graphics/windows/SystemGraphics.cpp
                        src/graphics/windows/TextDimension.cpp
                        src/graphics/windows/Win32Graphics.cpp
                        src/graphics/windows/Win32GraphicsImpl.cpp
                        src/graphics/windows/WindowsFont.cpp)
    
    list(APPEND Sources ${Sources_Windows})
else()
    add_compile_options(-Wall -Wextra -pedantic -std=c++11)
endif()

if (MSVC)
  find_path(STRING_EXTRAS_INCLUDE NAMES string/extras/CharacterEncoder.h PATH_SUFFIXES string_extras/inc)

  if(NOT STRING_EXTRAS_INCLUDE)
    message(FATAL_ERROR "string extras headers not found")
  endif()

  list(APPEND Headers ${STRING_EXTRAS_INCLUDE})
endif()

add_library(${PROJECT_NAME} ${Sources})

target_include_directories(${PROJECT_NAME} PRIVATE ${Headers})