#include <Rcpp.h>
#include <float.h>
#include <cmath>
#include <climits>
using namespace Rcpp;

//' @title Bounded cumulative sum
//' @description \code{cumsum_bounded} takes a numeric vector and applies
//'     upper and/or lower bounds while calculating the cumulative sum. Uses rcpp for speed.
//' @name cumsum_bounded
//' @useDynLib boundedcumsum
//' @importFrom Rcpp evalCpp
//'
//' @param x A numeric vector
//' @param lower Lower bound
//' @param upper Upper bound
//' @return res A numeric vector of the bounded cumulative sum
//' @details
//' \code{cumsum_bounded} takes a numeric vector and applies upper and or
//' lower bounds.
//' @export
//' @examples
//' # lower bound only
//' a = c(1, -2, 1, 1)
//' cumsum_bounded(a, lower = 1)
//'
//' # upper bound only
//' b = c(1, -2, 2, 1)
//' cumsum_bounded(b, upper = 1)
//'
//' # upper and lower bound
//' c = c(1, -2, 2, 1)
//' cumsum_bounded(c, lower = 0, upper = 2)
//'
NumericVector cumsum_bounded_logic(NumericVector x,
                                   long long int upper = LLONG_MAX,
                                   long long int lower = LLONG_MIN) {

  NumericVector res(x.size());
  double acc = 0;
  for (int i=0; i < x.size(); ++i) {
    acc += x[i];
    if (acc < lower)  acc = lower;
    else if (acc > upper)  acc = upper;
    res[i] = acc;
  }

  return res;
}

// [[Rcpp::export]]
NumericVector cumsum_bounded(NumericVector x,
                             Rcpp::Nullable<long long int> upper = R_NilValue,
                             Rcpp::Nullable<long long int> lower = R_NilValue) {

  if(upper.isNotNull() && lower.isNotNull()){
    return cumsum_bounded_logic(x, Rcpp::as< long long int >(upper), Rcpp::as< long long int >(lower));
  } else if(upper.isNull() && lower.isNotNull()){
    return cumsum_bounded_logic(x, LLONG_MAX, Rcpp::as< long long int >(lower));
  } else if(upper.isNotNull() && lower.isNull()) {
    return cumsum_bounded_logic(x, Rcpp::as< long long int >(upper), LLONG_MIN);
  } else {
    return cumsum_bounded_logic(x, LLONG_MAX, LLONG_MIN);
  }

  // Required to quiet compiler
  return x;
}
