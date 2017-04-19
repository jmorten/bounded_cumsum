test_that("floor bound is respected", {
  expect_equal(cumsum_bounded(c(1, 1, 1, 1), upper = 1), c(1, 1, 1, 1))
  expect_equal(cumsum_bounded(c(-1, 1, 1, 1), upper = 1), c(-1, 0, 1, 1))
})
