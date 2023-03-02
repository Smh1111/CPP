cmake_minimum_required(VERSION 3.10)

project(acpp_ch04)

add_executable(grading1 grading1.cpp)
add_executable(grading2 grading2.cpp)
add_executable(
    grading3
    grading3.cpp grade.cpp median.cpp student_info.cpp)

set(TARGETS grading1 grading2 grading3)

set_target_properties(
    ${TARGETS}
    PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO)

foreach(T ${TARGETS})
    if (MSVC)
        target_compile_options(${T} PRIVATE /Wall /WX)
    else()
        target_compile_options(${T} PRIVATE -Wall -Wextra)
    endif()
endforeach()

set(DATA_FILES single_grade grades)

foreach(FN ${DATA_FILES})
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/${FN}
    COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_CURRENT_SOURCE_DIR}/${FN}
        ${CMAKE_CURRENT_BINARY_DIR}/${FN}
    DEPENDS ${FN})

add_custom_target(
    data-${FN} ALL DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/${FN})
endforeach()
