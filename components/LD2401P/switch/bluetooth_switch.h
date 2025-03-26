#pragma once

#include "esphome/components/switch/switch.h"
#include "../LD2401P.h"

namespace esphome {
namespace LD2401P {

class BluetoothSwitch : public switch_::Switch, public Parented<LD2401PComponent> {
 public:
  BluetoothSwitch() = default;

 protected:
  void write_state(bool state) override;
};

}  // namespace LD2401P
}  // namespace esphome
