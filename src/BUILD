load("@rules_cc//cc:defs.bzl", "cc_library")

cc_library(
    name = "treelib",
    srcs = ["tree.cc"],
    hdrs = ["tree.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "twosum",
    srcs = ["twosum.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "graph_distance_matrix_lib",
    srcs = ["graph/distance_matrix.cc"],
    hdrs = ["graph/distance_matrix.h"],
    visibility = ["//visibility:public"],
    deps = ["utility"],
)

cc_library(
    name = "utility",
    hdrs = ["utility.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "recursion_lib",
    srcs = ["recursion/reverselinkedlist.cc"],
    hdrs = ["recursion/reverselinkedlist.h"],
    visibility = ["//visibility:public"],
    deps = ["utility"],
)

cc_library(
    name = "weirdalgo",
    hdrs = ["weird_algo.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "missingnum",
    hdrs = ["missingnumber.h"],
    visibility = ["//visibility:public"],
)

cc_library(
    name = "introductoryproblems_cses",
    hdrs = ["repetitions_cses.h"],
    visibility = ["//visibility:public"],
)