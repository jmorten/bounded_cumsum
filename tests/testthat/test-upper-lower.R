test_that("both bounds are respected", {
  expect_equal(cumsum_bounded(c(0, -1, -1, 2, 2), lower = -1, upper = 1), c(0, -1, -1, 1, 1))
})
