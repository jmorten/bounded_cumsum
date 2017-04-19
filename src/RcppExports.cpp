// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// cumsum_bounded
NumericVector cumsum_bounded(NumericVector x, Rcpp::Nullable<long long int> upper, Rcpp::Nullable<long long int> lower);
RcppExport SEXP boundedcumsum_cumsum_bounded(SEXP xSEXP, SEXP upperSEXP, SEXP lowerSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< NumericVector >::type x(xSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<long long int> >::type upper(upperSEXP);
    Rcpp::traits::input_parameter< Rcpp::Nullable<long long int> >::type lower(lowerSEXP);
    rcpp_result_gen = Rcpp::wrap(cumsum_bounded(x, upper, lower));
    return rcpp_result_gen;
END_RCPP
}