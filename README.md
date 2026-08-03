# Academic Record Management System

Academic Record Management System is a C++17 console application for managing student records, academic results, and CSV-based data persistence.

The project is divided into separate application, core, and testing components. It demonstrates structured C++ development through domain modeling, input validation, file handling, logging, automated testing, and CMake-based project configuration.

## Features

- Add students using unique identifiers
- Display all registered students
- Search for students by ID
- Update student names and scores
- Remove student records
- Calculate average, highest, and lowest scores
- Calculate pass rates and student category counts
- Generate academic reports
- Save student records to CSV files
- Load student records from CSV files
- Reject malformed CSV records
- Reject duplicate student identifiers during import
- Log persistence operations and errors
- Validate menu input and file paths

## Application Menu

```text
1. Add student
2. Show all students
3. Search student by ID
4. Update student name
5. Update student score
6. Remove student
7. Show academic report
8. Save students to CSV
9. Load students from CSV
0. Exit
```

## Project Architecture

The project is divided into three main targets.

### AcademicRecordManagementSystemCore

A static library containing the main domain and business logic:

- `Student`
- `StudentManager`
- `AcademicPolicy`
- `InputValidator`
- `Logger`
- `StudentFileStorage`
- `StudentPersistenceService`

### AcademicRecordManagementSystemApp

The executable application responsible for:

- Console menu output
- Validated user input
- Student data entry
- CSV path validation
- Menu command processing
- Communication with the core library

The application layer uses the following input-related components:

- `InputReader`
- `StudentInputReader`
- `CsvFilePathReader`
- `ConsoleMenu`

### AcademicRecordManagementSystemTests

A Google Test executable containing unit and integration tests for the core functionality.

## Main Components

### Student

Represents a student record containing:

- Student ID
- Student name
- Academic score

The class also normalizes invalid constructor values.

### StudentManager

Manages the collection of students and provides:

- Add, update, search, and remove operations
- Duplicate-ID validation
- Academic statistics
- Pass and fail calculations
- Academic report generation

### AcademicPolicy

Defines the score thresholds used to classify students as:

- Failed
- Passed
- Excellent

### StudentFileStorage

Handles CSV serialization and parsing.

The expected CSV format is:

```csv
id,name,score
```

Example:

```csv
id,name,score
1,Ani,95.5
2,Aram,78
3,Mane,88.5
```

### StudentPersistenceService

Coordinates:

- CSV storage operations
- Student import operations
- Duplicate-record rejection
- Persistence logging
- Structured load results

### InputReader

Provides reusable and validated console input for numeric values and non-empty text.

### StudentInputReader

Reads and validates student-specific data:

- Positive student IDs
- Non-empty student names
- Scores between `0` and `100`

### CsvFilePathReader

Reads and validates CSV input and output paths before persistence operations are performed.

## Data Validation

The current implementation applies the following rules:

- Student IDs must be positive
- Student IDs must be unique within the manager
- Student names entered through the application must not be empty
- Empty names passed directly to the `Student` constructor are normalized to `Unknown`
- Scores entered through the application must be between `0` and `100`
- Scores outside the valid range are normalized to `0` by the `Student` class
- Malformed CSV rows are rejected
- Duplicate IDs found during import are rejected
- CSV input and output paths are validated before use

## Requirements

- CMake 3.20 or newer
- A compiler supporting C++17
- Git
- Internet access during the first CMake configuration

On Windows, Visual Studio 2022 with the **Desktop development with C++** workload can be used.

## Building the Project

Clone the repository:

```powershell
git clone https://github.com/Arame3/academic-record-management-system.git
cd academic-record-management-system
```

Configure the project:

```powershell
cmake -S . -B build
```

Build the application and tests:

```powershell
cmake --build build --config Debug
```

Google Test is downloaded automatically through CMake `FetchContent`.

## Running the Application

On Windows using the Visual Studio CMake generator:

```powershell
.\build\Debug\AcademicRecordManagementSystemApp.exe
```

The application creates the following log file in its working directory:

```text
academic_record_system.log
```

## Running the Tests

Run the complete test suite with:

```powershell
ctest --test-dir build -C Debug --output-on-failure
```

The current test suite contains five tests and covers:

- Valid student construction
- Invalid student data normalization
- Complete student management workflow
- Duplicate student rejection
- Student search and update operations
- Academic score classification
- CSV save and load operations
- Malformed CSV row rejection
- Duplicate ID rejection during import

A successful test run reports:

```text
100% tests passed, 0 tests failed out of 5
```

## Repository Structure

```text
academic-record-management-system/
├── AcademicRecordManagementSystem/
│   └── Application and production source files
├── src/
│   └── AcademicRecordManagementSystem.Core/
├── tests/
│   └── AcademicRecordManagementSystem.Tests/
├── CMakeLists.txt
├── README.md
└── .gitignore
```

The main application and production source files are stored in `AcademicRecordManagementSystem`.

The `src` directory contains the Visual Studio static library project, while `tests` contains the Google Test project and automated tests.

## Technical Topics Demonstrated

- C++17
- Object-oriented programming
- Encapsulation
- Separation of concerns
- Modular architecture
- Static libraries
- Standard Library containers
- File input and output
- CSV parsing
- Input validation
- File path validation
- Error handling
- Logging
- Structured operation results
- Dependency injection through references
- Function templates
- Compile-time type validation
- Unit testing
- Integration testing
- CMake
- Git version control

## Current Limitations

- The application uses a console-based interface
- CSV fields containing commas are not currently escaped
- Student records must be saved or loaded manually through the application menu
- The documented executable path is intended for Windows and Visual Studio multi-configuration builds

## Author

Arame Badalyan