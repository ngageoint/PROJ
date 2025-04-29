// swift-tools-version: 5.10

import PackageDescription

let package = Package(
    name: "proj",
    platforms: [
        .iOS(.v13), .macOS(.v13)
    ],
    products: [
        .library(
            name: "proj",
//             type: .static,
            type: .dynamic,
            targets: ["proj"]
        ),
    ],
    targets: [
        .target(
            name: "proj",
            path: "src",
            exclude: [
                "apps",
                "tests",
                "CMakeLists.txt",
                "lib_proj.cmake",
                "check_md5sum.cmake",
                "generate_wkt_parser.cmake",
                "general_doc.dox",
                "wkt1_grammar.y",
                "wkt2_grammar.y",
            ],
            resources: [
//                .copy("../proj.db") // What is this?
            ],
            publicHeadersPath: ".", // The C header files are mixed with src files, we use a modulemap.module to load "proj.h"
            cSettings: [
//                .headerSearchPath("../include/proj"),
//                .headerSearchPath("../include/proj/internal"),
//                .headerSearchPath("../include/proj/internal/vendor/nlohmann"),
            ],
            cxxSettings: [
                .headerSearchPath("../include"),
                .headerSearchPath("../include/proj"),
                .headerSearchPath("../include/proj/internal"),
                .headerSearchPath("../include/proj/internal/vendor/nlohmann"),
            ],
            linkerSettings: [
                .linkedLibrary("c++"),
                .linkedLibrary("sqlite3"),
            ]
        )
    ],
    cxxLanguageStandard: .cxx17
)
