#include <Rcpp.h>
using namespace Rcpp;


// [[Rcpp::export]]
IntegerVector C_which_colMins(NumericMatrix X) {
  int n = X.ncol();
  IntegerVector V(n);
  for (int i=0; i<n; i++) {
     NumericVector W = X.column(i);
     // from the STL
     V[i] = std::distance(W.begin(),std::min_element(W.begin(), W.end())) +1;  
  }
  return(V);

}


// [[Rcpp::export]]
IntegerVector C_which_rowMins(NumericMatrix X) {
  int n = X.nrow();
	IntegerVector V(n);
	for (int i=0; i<n; i++) {
  	NumericVector W = X.row(i);
  	V[i] = std::distance(W.begin(),std::min_element(W.begin(), W.end())) +1;  // from the STL
	}
	return V;
}

//' Computes quickly the minima of each column of a matrix
//'
// [[Rcpp::export]]
NumericVector colMins(NumericMatrix X) {
  int n = X.ncol();
  NumericVector V(n);
  for (int i=0; i<n; i++) {
    NumericVector W = X.column(i);
    V[i] = *std::min_element(W.begin(), W.end());  // from the STL
  }
  return V;
}

//' Computes quickly the minima of each row of a matrix
//' 
// [[Rcpp::export]]
NumericVector rowMins(NumericMatrix X) {
  int n = X.nrow();
  NumericVector V(n);
  for (int i=0; i<n; i++) {
     NumericVector W = X.row(i);
     V[i] = *std::min_element(W.begin(), W.end());  // from the STL
  }
  return(V);  
}

// [[Rcpp::export]]
IntegerVector C_which_colMaxs(NumericMatrix X) {
  int n = X.ncol();
	IntegerVector V(n);
	for (int i=0; i<n; i++) {
  	NumericVector W = X.column(i);
  	V[i] = std::distance(W.begin(),std::max_element(W.begin(), W.end())) +1;  // from the STL
	}
	return(V);
}

// [[Rcpp::export]]
IntegerVector C_which_rowMaxs(NumericMatrix X) {
  int n = X.nrow();
	IntegerVector V(n);
	for (int i=0; i<n; i++) {
    NumericVector W = X.row(i);
  	V[i] = std::distance(W.begin(),std::max_element(W.begin(), W.end())) +1;  // from the STL
	}
	return(V);
}

//' Computes quickly the maxima of each column of a matrix
//' 
// [[Rcpp::export]]
NumericVector colMaxs(NumericMatrix X) {
  int n = X.ncol();
	NumericVector V(n);
	for (int i=0; i<n; i++) {
  	NumericVector W = X.column(i);
  	V[i] = *std::max_element(W.begin(), W.end());  // from the STL
	}
	return(V);
}

//' Computes quickly the maxima of each row of a matrix
//' 
// [[Rcpp::export]]
NumericVector rowMaxs(NumericMatrix X) {
  int n = X.nrow();
	NumericVector V(n);
	for (int i=0; i<n; i++) {
  	NumericVector W = X.row(i);
  	V[i] = *std::max_element(W.begin(), W.end());  // from the STL
	}
	return(V);
}
