# -*- python -*-
# This file contains rules for Bazel; see https://bazel.io/ .

load("//:tools/cpplint.bzl", "cpplint")
load("//tools:dreal.bzl", "dreal_cc_googletest", "dreal_cc_library")
load("@bazel_tools//tools/build_defs/pkg:pkg.bzl", "pkg_tar")

package(default_visibility = ["//visibility:public"])

# ---------
# Libraries
# ---------
dreal_cc_library(
    name = "config",
    srcs = [
        "config.cc",
    ],
    hdrs = [
        "config.h",
    ],
    deps = ["//dreal/util:option_value"],
)

# We combine context and theory_solver in a single target because they
# have mutual dependencies.
dreal_cc_library(
    name = "solver",
    srcs = [
        "context.cc",
        "expression_evaluator.cc",
        "forall_formula_evaluator.cc",
        "forall_formula_evaluator.h",
        "formula_evaluator.cc",
        "formula_evaluator_cell.cc",
        "formula_evaluator_cell.h",
        "icp.cc",
        "relational_formula_evaluator.cc",
        "relational_formula_evaluator.h",
        "theory_solver.cc",
    ],
    hdrs = [
        "context.h",
        "expression_evaluator.h",
        "formula_evaluator.h",
        "icp.h",
        "theory_solver.h",
    ],
    deps = [
        ":config",
        ":filter_assertion",
        ":sat_solver",
        "//dreal:version_header",
        "//dreal/contractor",
        "//dreal/smt2:logic",
        "//dreal/smt2:sort",
        "//dreal/symbolic",
        "//dreal/util:assert",
        "//dreal/util:box",
        "//dreal/util:exception",
        "//dreal/util:ibex_converter",
        "//dreal/util:if_then_else_eliminator",
        "//dreal/util:logging",
        "//dreal/util:math",
        "//dreal/util:nnfizer",
        "//dreal/util:scoped_vector",
    ],
)

dreal_cc_library(
    name = "sat_solver",
    srcs = [
        "sat_solver.cc",
    ],
    hdrs = [
        "sat_solver.h",
    ],
    deps = [
        "//dreal/symbolic",
        "//dreal/util:assert",
        "//dreal/util:exception",
        "//dreal/util:logging",
        "//dreal/util:predicate_abstractor",
        "//dreal/util:tseitin_cnfizer",
        "@picosat//:picosat",
    ],
)

dreal_cc_library(
    name = "filter_assertion",
    srcs = [
        "filter_assertion.cc",
    ],
    hdrs = [
        "filter_assertion.h",
    ],
    deps = [
        "//dreal/symbolic",
        "//dreal/util:box",
        "//dreal/util:logging",
    ],
)

# -----
# Tests
# -----
dreal_cc_googletest(
    name = "expression_evaluator_test",
    tags = ["unit"],
    deps = [
        ":solver",
    ],
)

dreal_cc_googletest(
    name = "filter_assertion_test",
    tags = ["unit"],
    deps = [
        ":filter_assertion",
    ],
)

dreal_cc_googletest(
    name = "formula_evaluator_test",
    tags = ["unit"],
    deps = [
        ":solver",
    ],
)

dreal_cc_googletest(
    name = "icp_test",
    tags = ["unit"],
    deps = [
        ":solver",
    ],
)

dreal_cc_googletest(
    name = "sat_solver_test",
    tags = ["unit"],
    deps = [
        ":sat_solver",
        "//dreal/util:logging",
    ],
)

dreal_cc_googletest(
    name = "theory_solver_test",
    tags = ["unit"],
    deps = [
        ":solver",
        "//dreal/util:logging",
    ],
)

# ----------------------
# Header files to expose
# ----------------------
filegroup(
    name = "headers",
    srcs = [
        "config.h",
        "context.h",
    ],
    visibility = ["//visibility:public"],
)

pkg_tar(
    name = "package_headers",
    srcs = [
        ":headers",
    ],
    extension = "tar.gz",
    package_dir = "include/dreal/solver",
    tags = ["manual"],
)

cpplint()
