# -*- python -*-
# This file contains rules for Bazel; see https://bazel.io/ .

load(
    "//tools:dreal.bzl",
    "dr_test",
)

dr_test(
    name = "car10dumped",
    size = "small",
)

dr_test(
    name = "logical_operator1",
    size = "small",
)

dr_test(
    name = "logical_operator2",
    size = "small",
)

dr_test(
    name = "logical_operator3",
    size = "small",
)

dr_test(
    name = "logical_operator4",
    size = "small",
)

dr_test(
    name = "pow",
    size = "small",
)

dr_test(
    name = "simple",
    size = "small",
)

dr_test(
    name = "smallctr",
    size = "small",
)

dr_test(
    name = "unary_minus",
    size = "small",
)

dr_test(
    name = "unconstrained_opt_beale",
    size = "small",
    args = [
        "--precision 0.01",
        "--local-optimization",
    ],
)

dr_test(
    name = "unconstrained_opt_eggholder",
    size = "small",
    args = [
        "--precision 2",
        "--local-optimization",
    ],
)

dr_test(
    name = "unconstrained_opt_mccormick",
    size = "small",
    args = [
        "--precision 0.2",
        "--local-optimization",
    ],
)

dr_test(
    name = "unconstrained_opt_poly1",
    size = "small",
)

dr_test(
    name = "unconstrained_opt_sincos",
    size = "small",
)

dr_test(
    name = "constrained_opt_rosenbrock_cubic",
    size = "small",
)

dr_test(
    name = "constrained_opt_rosenbrock_disk",
    size = "small",
)

dr_test(
    name = "constrained_opt_mishra_bird",
    size = "small",
    args = [
        "--precision 0.01",
        "--local-optimization",
    ],
)

# dr_test(
#     name = "constrained_opt_townsend",
#     size = "small",
#     args = [
#         "--precision 0.001",
#         "--local-optimization",
#     ],
# )

dr_test(
    name = "constrained_opt_simionescu",
    size = "small",
)
