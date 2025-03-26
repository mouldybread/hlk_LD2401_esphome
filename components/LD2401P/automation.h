#pragma once

#include "esphome/core/automation.h"
#include "esphome/core/component.h"
#include "LD2401P.h"

namespace esphome {
namespace LD2401P {

template<typename... Ts> class BluetoothPasswordSetAction : public Action<Ts...> {
 public:
  explicit BluetoothPasswordSetAction(LD2401PComponent *LD2401P_comp) : LD2401P_comp_(LD2401P_comp) {}
  TEMPLATABLE_VALUE(std::string, password)

  void play(Ts... x) override { this->LD2401P_comp_->set_bluetooth_password(this->password_.value(x...)); }

 protected:
  LD2401PComponent *LD2401P_comp_;
};

}  // namespace LD2401P
}  // namespace esphome
