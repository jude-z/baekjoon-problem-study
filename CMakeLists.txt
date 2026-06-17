cmake_minimum_required(VERSION 3.16)
project(baekjoon_problem_study CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 각 chapter*/<문제번호>/main.cpp 를 개별 실행 타겟으로 등록한다.
# CONFIGURE_DEPENDS 로 새 main.cpp 가 추가되면 자동으로 다시 스캔된다.
file(GLOB MAIN_FILES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/chapter*/*/main.cpp")

foreach(MAIN_FILE ${MAIN_FILES})
    get_filename_component(PROBLEM_DIR ${MAIN_FILE} DIRECTORY)
    get_filename_component(PROBLEM_NUM ${PROBLEM_DIR} NAME)
    get_filename_component(CHAPTER_DIR ${PROBLEM_DIR} DIRECTORY)
    get_filename_component(CHAPTER_NAME ${CHAPTER_DIR} NAME)

    # 타겟 이름 예: chapter2_1992
    set(TARGET_NAME "${CHAPTER_NAME}_${PROBLEM_NUM}")

    add_executable(${TARGET_NAME} ${MAIN_FILE})
    set_target_properties(${TARGET_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/${CHAPTER_NAME}")
endforeach()
