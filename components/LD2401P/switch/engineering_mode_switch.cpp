#include "engineering_mode_switch.h"

namespace esphome {
namespace LD2401P {

void EngineeringModeSwitch::write_state(bool state) {
  this->publish_state(state);
  this->parent_->set_engineering_mode(state);
}

}  // namespace LD2401P
}  // namespace esphome
