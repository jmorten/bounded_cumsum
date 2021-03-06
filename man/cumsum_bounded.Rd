% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{cumsum_bounded}
\alias{cumsum_bounded}
\title{Bounded cumulative sum}
\arguments{
\item{x}{A numeric vector}

\item{lower}{Lower bound}

\item{upper}{Upper bound}
}
\value{
res A numeric vector of the bounded cumulative sum
}
\description{
\code{cumsum_bounded} takes a numeric vector and applies
    upper and/or lower bounds while calculating the cumulative sum. Uses rcpp for speed.
}
\details{
\code{cumsum_bounded} takes a numeric vector and applies upper and or
lower bounds.
}
\examples{
# lower bound only
a = c(1, -2, 1, 1)
cumsum_bounded(a, lower = 1)

# upper bound only
b = c(1, -2, 2, 1)
cumsum_bounded(b, upper = 1)

# upper and lower bound
c = c(1, -2, 2, 1)
cumsum_bounded(c, lower = 0, upper = 2)

}
