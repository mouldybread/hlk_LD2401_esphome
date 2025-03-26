#include "query_button.h"

namespace esphome {
namespace LD2401P {

void QueryButton::press_action() { this->parent_->read_all_info(); }

}  // namespace LD2401P
}  // namespace esphome
