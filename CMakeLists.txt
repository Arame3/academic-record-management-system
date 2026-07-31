cmake_minimum_required(VERSION 3.20)

project(
	AcademicRecordManagementSystem
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(
	AcademicRecordManagementSystemCore
	STATIC

	AcademicRecordManagementSystem/AcademicPolicy.cpp
	AcademicRecordManagementSystem/InputValidator.cpp
	AcademicRecordManagementSystem/Logger.cpp
	AcademicRecordManagementSystem/Student.cpp
	AcademicRecordManagementSystem/StudentFileStorage.cpp
	AcademicRecordManagementSystem/StudentManager.cpp
	AcademicRecordManagementSystem/StudentPersistenceService.cpp
)

target_include_directories(
	AcademicRecordManagementSystemCore

	PUBLIC
		${CMAKE_CURRENT_SOURCE_DIR}/AcademicRecordManagementSystem
)

add_executable(
	AcademicRecordManagementSystemApp

	AcademicRecordManagementSystem/AcademicRecordManagementSystem.cpp
	AcademicRecordManagementSystem/ConsoleMenu.cpp
	AcademicRecordManagementSystem/CsvFilePathReader.cpp
	AcademicRecordManagementSystem/CsvFilePathValidator.cpp
	AcademicRecordManagementSystem/CsvPathValidationMessageProvider.cpp
	AcademicRecordManagementSystem/InputReader.cpp
	AcademicRecordManagementSystem/StudentInputReader.cpp
)

target_link_libraries(
	AcademicRecordManagementSystemApp

	PRIVATE
		AcademicRecordManagementSystemCore
)

include(FetchContent)

set(
	gtest_force_shared_crt
	ON
	CACHE BOOL ""
	FORCE
)

FetchContent_Declare(
	googletest

	GIT_REPOSITORY
		https://github.com/google/googletest.git

	GIT_TAG
		v1.15.2
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
	AcademicRecordManagementSystemTests

	tests/AcademicRecordManagementSystem.Tests/test.cpp
)

target_include_directories(
	AcademicRecordManagementSystemTests

	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/tests/AcademicRecordManagementSystem.Tests
)

target_link_libraries(
	AcademicRecordManagementSystemTests

	PRIVATE
		AcademicRecordManagementSystemCore
		GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(
	AcademicRecordManagementSystemTests
)