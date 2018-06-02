#' Computes quickly the index of the largest element of each row of a matrix
which.rowMaxs = function(mat) {
  C_which_rowMaxs(mat)
}

#' Computes quickly the index of the largest element of each column of a matrix
which.colMaxs = function(mat) {
  C_which_colMaxs(mat)
}

#' Computes quickly the index of the smallest element of each row of a matrix
which.rowMins = function(mat) {
  C_which_rowMins(mat)
}  


#' Computes quickly the index of the smallest element of each column of a matrix
which.colMins = function(mat) {
  C_which_colMins(mat)
}  


examples.colMins = function() {
  mat = cbind(c(1,2,NA),c(100,-12,30))
  mat
  
  colMaxs(mat)
  colMins(mat)
  rowMaxs(mat)
  rowMins(mat)
  
  which.colMaxs(mat)
  which.colMins(mat)
  which.rowMaxs(mat)
  which.rowMins(mat)
  
  
  mat = matrix(runif(3*4),3,4)
  mat
  which.colMaxs(mat)
  
  
  library(rbenchmark)
  
  colMaxs.apply = function(mat) {
    apply(mat,2,max)
  }
  
  
  library(matrixStats)
  Z <- matrix(rnorm(500*500), 500, 500)
  Z <- matrix(rnorm(900*900), 900, 900)
  benchmark(rowmins::colMaxs(Z), max.col(Z), rowmins::which.colMaxs(Z), matrixStats::colMaxs(Z), colMaxs.apply(Z),replications=100, order="relative")
  
}
