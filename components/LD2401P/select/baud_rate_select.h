#pragma once

#include "esphome/components/select/select.h"
#include "../LD2401P.h"

namespace esphome {
namespace LD2401P {

class BaudRateSelect : public select::Select, public Parented<LD2401PComponent> {
 public:
  BaudRateSelect() = default;

 protected:
  void control(const std::string &value) override;
};

}  // namespace LD2401P
}  // namespace esphome
