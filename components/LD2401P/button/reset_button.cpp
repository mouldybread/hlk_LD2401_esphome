#include "reset_button.h"

namespace esphome {
namespace LD2401P {

void ResetButton::press_action() { this->parent_->factory_reset(); }

}  // namespace LD2401P
}  // namespace esphome
