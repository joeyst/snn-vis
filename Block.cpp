
#include "Block.h"
#include "config.h"

Block::Block() {
  std::vector<std::vector<Neuron>> neurons(LAYERS_PER_BLOCK, std::vector<Neuron>(NEURONS_PER_LAYER));
}
