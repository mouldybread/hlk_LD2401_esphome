#include "distance_resolution_select.h"

namespace esphome {
namespace LD2401P {

void DistanceResolutionSelect::control(const std::string &value) {
  this->publish_state(value);
  this->parent_->set_distance_resolution(state);
}

}  // namespace LD2401P
}  // namespace esphome
