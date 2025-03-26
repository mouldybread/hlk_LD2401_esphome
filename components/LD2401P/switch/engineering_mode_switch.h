#pragma once

#include "esphome/components/switch/switch.h"
#include "../LD2401P.h"

namespace esphome {
namespace LD2401P {

class EngineeringModeSwitch : public switch_::Switch, public Parented<LD2401PComponent> {
 public:
  EngineeringModeSwitch() = default;

 protected:
  void write_state(bool state) override;
};

}  // namespace LD2401P
}  // namespace esphome
