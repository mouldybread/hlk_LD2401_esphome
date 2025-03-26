#include "bluetooth_switch.h"

namespace esphome {
namespace LD2401P {

void BluetoothSwitch::write_state(bool state) {
  this->publish_state(state);
  this->parent_->set_bluetooth(state);
}

}  // namespace LD2401P
}  // namespace esphome
