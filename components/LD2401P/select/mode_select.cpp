#include "mode_select.h"

namespace esphome {
namespace LD2401P {

void ModeSelect::control(const std::string &value) {
  this->publish_state(value);
  this->parent_->set_mode(state);
}

}  // namespace LD2401P
}  // namespace esphome
