#include <cstddef>
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <immintrin.h>

constexpr int n = 4096;

alignas(32) float A[n][n];
alignas(32) float B[n][n];
alignas(32) float C[n][n];

int main() {
  std::random_device dev;
  std::default_random_engine e1(dev());
  std::uniform_real_distribution<float> uniform_dist(1.0, 6.0);


  // init matrix
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = uniform_dist(e1);
      B[i][j] = uniform_dist(e1);
      C[i][j] = 0;
    }
  }

  float gflops = 2 * float(n) * float(n) * float(n);

  const auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      __m256 ra = _mm256_set1_ps(A[i][k]);
      for (int j = 0; j < n; j += 8) {
        *(__m256 *)&C[i][j] = _mm256_add_ps(*(__m256 *)&C[i][j],
                                _mm256_mul_ps(ra, *(__m256 *)&B[k][j]));
      }
    }
  }
  const auto end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> elapsed_seconds{end - start};

  std::cout << "avx " << elapsed_seconds.count() << "s elapsed\t" << gflops / elapsed_seconds.count() * 1e-9 << " Gflops\n";

  return 0;
}
