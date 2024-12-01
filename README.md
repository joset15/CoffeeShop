# CoffeeShop
Management of drink orders.

## Folder structure

```
/
├── cmake
│   ├── CompilerWarnings.cmake
│   ├── GenerateAndInstallConfig.cmake
│   ├── InterviewPracticeQuestionsConfig.cmake.in
│   ├── ProjectOptions.cmake
│   ├── StandardProjectSettings.cmake
│   ├── StaticAnalysers.cmake
│   ├── FindGit.cmake
│   ├── git_revision.cmake
│   └── safeguards.cmake
├── include
│   ├── Domain
│   │   ├── Entities
│   │   └── DomainEvents
│   ├── Application
│   │   ├── UseCases
│   │   ├── ApplicationServices
│   │   └── DTOs
│   ├── InterfaceAdapters
│   │   ├── Controllers
│   │   ├── Presenters
│   │   └── Gateways
│   └── Infrastructure
│       ├── UI
│       ├── DB
│       ├── Devices
│       └── Web
├── src
│   ├── Domain
│   ├── Application
│   ├── InterfaceAdapters
│   ├── Infrastructure
│   │   ├── UI
│   │   ├── DB
│   │   └── Devices
│   └── CMakeLists.txt
├── libs
│   ├── googletest
│   └── CMakeLists.txt
├── tests
│   ├── UnitTests
│   │   ├── unitest.cpp
│   │   └── CMakeLists.txt
│   ├── IntegrationTests
│   │   ├── integrationest.cpp
│   │   └── CMakeLists.txt
│   └── CMakeLists.txt
├── apps
│   ├── ConsoleApp
│   │   ├── main.cpp
│   │   └── CMakeLists.txt
│   └── CMakeLists.txt
├── deploy
│   └── .gitkeep
├── scripts
│   └── helper.py
├── docs
│   ├── doxygen
│   │   └── doxyfile.in
│   ├── CMakeLists.txt
│   ├── OtherFile.md
│   └── CMakeLists.txt
├── .gitignore
├── .gitattributes
├── .clang-format
├── .clang-tidy
├── README.md
├── LICENSE.md
├── conanfile.txt
├── CMakeLists.txt
└── CMakeUserPresets.json

```