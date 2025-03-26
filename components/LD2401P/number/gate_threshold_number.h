#pragma once

#include "esphome/components/number/number.h"
#include "../LD2401P.h"

namespace esphome {
namespace LD2401P {

class GateThresholdNumber : public number::Number, public Parented<LD2401PComponent> {
 public:
  GateThresholdNumber(uint8_t gate);

 protected:
  uint8_t gate_;
  void control(float value) override;
};

}  // namespace LD2401P
}  // namespace esphome
