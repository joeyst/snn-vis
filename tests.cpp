
#include "utils.h"
#include <vector>
#include "ctest.h" 
#include <iostream>
#include "Block.h"
#include "Neuron.h"

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

void TestGetSynapseIndex() {
  Neuron recver = Neuron();
  recver.xyz = {0, 0, 0};
  Neuron sender = Neuron();
  sender.xyz = {1, 1, 0};
  int synapseindex = recver.GetSynapseIndex(sender.xyz);
  Neuron sender2 = Neuron();
  sender2.xyz = {-1, -1, 0};
  int synapseindex2 = recver.GetSynapseIndex(sender2.xyz);

  CTEST_ASSERT(synapseindex == 16, "synapse index down");
  std::cout << "Actual index: " << synapseindex << std::endl;
  std::cout << "Expected index: " << 16 << std::endl;
  CTEST_ASSERT(synapseindex2 == 9, "synapse index up");
  std::cout << "Actual index: " << synapseindex2 << std::endl;
  std::cout << "Expected index: " << 9 << std::endl;
}

int main(void)
{
    CTEST_VERBOSE(1);
    CTEST_COLOR(1);

    TestGetOjaWeightChange();
    TestGetSynapseIndex();

    CTEST_RESULTS();

    CTEST_EXIT();
}
#endif
