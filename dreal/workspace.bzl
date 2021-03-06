# -*- python -*-
load("//tools:github.bzl", "github_archive")
load("//tools:third_party/com_github_robotlocomotion_drake/tools/workspace/pkg_config.bzl", "pkg_config_repository")

def dreal_workspace():
    pkg_config_repository(
        name = "ibex", # LGPL3
        modname = "ibex",
        pkg_config_paths = [
            # macOS
            "/usr/local/opt/ibex@2.6.5/share/pkgconfig",
            "/usr/local/opt/clp/lib/pkgconfig",  # dep of ibex, EPL
            "/usr/local/opt/coinutils/lib/pkgconfig",  # dep of clp, EPL
            # Linux
            "/opt/libibex/2.6.5/share/pkgconfig",
        ],
    )
    pkg_config_repository(
        name = "nlopt",  # LGPL2 + MIT
        modname = "nlopt",
        pkg_config_paths = [
            "/usr/local/opt/nlopt/lib/pkgconfig",
        ]
    )
    github_archive(
        name = "drake_symbolic", # BSD
        repository = "dreal-deps/drake-symbolic",
        commit = "5870b74ebfc6e16d2334cace0ffb6569c2688a3b",
        sha256 = "b41ca8a6b92211a957dac46499e9ec7bd17a16a2aef183eff0d15331b78fc051",
    )
    github_archive(
        name = "spdlog", # MIT
        repository = "gabime/spdlog",
        commit = "v0.13.0",
        sha256 = "d798a6ca19165f0a18a43938859359269f5a07fd8e0eb83ab8674739c9e8f361",
        build_file = str(Label("//tools:spdlog.BUILD")),
    )
    github_archive(
        name = "fmt", # BSD2
        repository = "fmtlib/fmt",
        commit = "3.0.1",
        sha256 = "dce62ab75a161dd4353a98364feb166d35e7eea382169d59d9ce842c49c55bad",
        build_file = str(Label("//tools:fmt.BUILD")),
    )
    github_archive(
        name = "picosat", # MIT
        repository = "dreal-deps/picosat",
        commit = "b17ad98a29ac64b1e62182e40a01bd616b129418", # v965
        sha256 = "b47f084ae6ac75c7ce921a1930bfa3d2de7c89ff4911d8107ecb1e90d87abdf1",
        build_file = str(Label("//tools:picosat.BUILD")),
    )
