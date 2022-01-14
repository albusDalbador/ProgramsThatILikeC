#include <iostream>
#include <vector>

//returns matrix without n-th row and first column
std::vector<std::vector<long long>> getSubmatrix(std::vector<std::vector<long long >> matrix,int n) {
    std::vector<std::vector<long long>> result;

    for (int i = 0; i < matrix.size(); i++) {
        if (i != n) {
            result.push_back({matrix[i].begin() +1, matrix[i].end()});
        }
    }

    return result;
}

long long determinant(std::vector< std::vector<long long> > matrix) {
  // TODO: Return the determinant of the square matrix passed in

  if (matrix[0].size() == 1) return matrix[0][0];

  int sign = 1, sum = 0;

  for (int i = 0 ; i < matrix.size(); i++) {
        if (sign >0 ) sum += matrix[i][0] * determinant(getSubmatrix(matrix,i));
        else sum -= matrix[i][0] * determinant(getSubmatrix(matrix,i));

        sign = -sign;
  }

  return sum;
}


int main() {

    //-20
    std::cout << determinant(std::vector< std::vector<long long> > {
      std::vector<long long> {2, 5, 3},
      std::vector<long long> {1, -2, -1},
      std::vector<long long> {1, 3, 4}
    }) << std::endl;

    //-1
    std::cout << determinant(std::vector< std::vector<long long> > {
      std::vector<long long> {1, 3},
      std::vector<long long> {2, 5}
    }) << std::endl;

}