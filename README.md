# swift-detours
Library to use https://github.com/microsoft/Detours from Swift to intercept Win32 API calls

## Usage

In order to use this library, you can add a reference to it in your package.swift. You then create a C library which does the actual detouring, see `DetoursExample` for how to build this library.