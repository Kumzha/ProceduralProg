#include <stdio.h>

int main() {
  int total_scenarios = 0;
  int max_iterations = 5555555; // Limit iterations for demonstration

  // Simulate choosing 5 objects from 36 (without actual permutations)
  for (int i = 1; i <= 36; i++) {
    for (int j = i + 1; j <= 36; j++) {
      for (int k = j + 1; k <= 36; k++) {
        for (int l = k + 1; l <= 36; l++) {
          for (int m = l + 1; m <= 36; m++) {
            total_scenarios++;
            if (total_scenarios >= max_iterations) {
              printf("Reached demonstration limit of %d scenarios (actual number much larger).\n", max_iterations);
              return 0;
            }
          }
        }
      }
    }
  }

  printf("Total scenarios (should never reach here): %d\n", total_scenarios);
  return 0;
}
