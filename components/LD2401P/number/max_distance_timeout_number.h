#pragma once

#include "esphome/components/number/number.h"
#include "../LD2401P.h"

namespace esphome {
namespace LD2401P {

class MaxDistanceTimeoutNumber : public number::Number, public Parented<LD2401PComponent> {
 public:
  MaxDistanceTimeoutNumber() = default;

 protected:
  void control(float value) override;
};

}  // namespace LD2401P
}  // namespace esphome
