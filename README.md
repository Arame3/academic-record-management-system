# Academic Record Management System

Academic Record Management System is a C++17 console application for managing student records, academic results, and CSV-based data persistence.

The project is organized into separate application, core, and testing components. Its main purpose is to demonstrate structured C++ development through domain modeling, validation, file handling, logging, automated testing, and CMake-based project configuration.

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

The application currently loads a small demonstration dataset at startup.

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
- User input
- Menu command processing
- Communication with the core library

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

## Data Validation

The current implementation applies the following rules:

- Student IDs must be positive
- Student IDs must be unique within the manager
- Empty names are normalized to `Unknown`
- Scores must be between `0` and `100`
- Scores outside the valid range are normalized to `0`
- Malformed CSV rows are rejected
- Duplicate IDs found during import are rejected

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

```powershell
ctest --test-dir build -C Debug --output-on-failure
```

The test suite currently covers:

- Valid student construction
- Invalid student data normalization
- Student management workflow
- Duplicate student rejection
- Student search and update operations
- Academic score classification
- CSV save and load operations
- Malformed CSV row rejection
- Duplicate ID rejection during import

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

The main application source files are stored in `AcademicRecordManagementSystem`.  
The `src` directory contains the Visual Studio static library project, while `tests` contains the Google Test project and automated tests.
## Technical Topics Demonstrated

- C++17
- Object-oriented programming
- Encapsulation
- Separation of concerns
- Static libraries
- Standard Library containers
- File input and output
- CSV parsing
- Input validation
- Error handling
- Logging
- Structured operation results
- Dependency injection through references
- Unit testing
- Integration testing
- CMake
- Git version control

## Current Limitations

- The application uses a console-based interface
- CSV fields containing commas are not currently escaped
- Demonstration data is loaded automatically at startup
- The project currently focuses on Windows and Visual Studio workflows

## Author

Arame Badalyan