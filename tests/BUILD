load("@rules_cc//cc:defs.bzl", "cc_test")

cc_test(
    name = "graph_shortestpath_tests",
    srcs = ["graph_shortestpath_tests.cc"],
    deps = [
        "//src/search:searchlib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "tree_tests",
    srcs = ["tree_tests.cc"],
    deps = [
        "//src:treelib",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "twosum_tests",
    srcs = ["twosum_tests.cc"],
    deps = [
        "//src:twosum",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "weirdalgo_tests",
    srcs = ["weirdalgo_tests.cc"],
    deps = [
        "//src:weirdalgo",
        "@com_google_googletest//:gtest_main",
    ],
)