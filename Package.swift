// swift-tools-version: 5.7
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "swift-detours",
    products: [
        .library(
            name: "Detours",
            targets: ["Detours"]
        ),
        .library(
            name: "DetoursExample",
            targets: ["DetoursExample"]
        ),
        .executable(
            name: "ExampleApp",
            targets: ["ExampleApp"]
        ),
    ],
    targets: [
        .target(name: "Detours",
          exclude: ["uimports.cpp"],
          publicHeadersPath: "include"
        ),
        // The actual detour functions need to be defined in a C library
        .target(name: "DetoursExample",
          dependencies: ["Detours"],
          publicHeadersPath: "include"
        ),
        // Targets are the basic building blocks of a package, defining a module or a test suite.
        // Targets can depend on other targets in this package and products from dependencies.
        .executableTarget(
            name: "ExampleApp",
            dependencies: [
                "DetoursExample",
            ]),
    ]
)
