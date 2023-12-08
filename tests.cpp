
#include "utils.h"
#include <vector>
#include "ctest.h" 
#include <iostream>

#ifdef CTEST_ENABLE 

void TestGetOjaWeightChange() {
  std::vector<float> energies { 1.f, 1.f, 1.f };
  std::vector<float> weights { 0.1f, 0.2f, 0.2f };
  std::vector<float> expected { 0.475f, 0.450f, 0.450f };
  std::vector<float> actual = GetOjaWeightChanges(energies, weights);

  CTEST_ASSERT(expected == GetOjaWeightChanges(energies, weights), "3 neurons");
  
  std::cout << "Actual: ";
  for (const auto& result : actual) {
    std::cout << result << " ";
  }
  std::cout << std::endl;
  std::cout << "Expected: ";
  for (const auto& result : expected) {
    std::cout << result << " ";
  }
  std::cout << std::endl;
}

int main(void)
{
    CTEST_VERBOSE(1);
    CTEST_COLOR(1);

    TestGetOjaWeightChange();

    CTEST_RESULTS();

    CTEST_EXIT();
}
#endif
