test_that("ceiling bound is respected", {
  expect_equal(cumsum_bounded(c(-1, -1, -1, -1), lower =  -2), c(-1, -2, -2, -2))
  expect_equal(cumsum_bounded(c(1, -1, -1, -1), lower = 0), c(1, 0, 0, 0))
})
