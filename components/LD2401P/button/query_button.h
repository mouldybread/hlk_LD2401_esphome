#pragma once

#include "esphome/components/button/button.h"
#include "../LD2401P.h"

namespace esphome {
namespace LD2401P {

class QueryButton : public button::Button, public Parented<LD2401PComponent> {
 public:
  QueryButton() = default;

 protected:
  void press_action() override;
};

}  // namespace LD2401P
}  // namespace esphome
