LD2401P support for EspHome **TESTING/EXPERIMENTAL**
=======
Introduction
--
A fork of Rihan9/LD2412 to add esphome support for the Hi-Link LD2401P module which thus far was unsupported. This is a learning experience for me, I have no idea what I am doing.

I have renamed everything accordingly and removed the option to set a 0.5m detection accuracy as this module does not support it.

Without further modification all of the functionality except the light sensor seems to work.

This model purports to be an improved version of the 2410. The default baud rate is 256000 and it consumes 74ma at 3.3V. The board measures 18 x 22mm. 

While this module claims to be 3.3V I have been able to power it with 5 volts via the VCC pin. Probably not a good idea in the long term. So far this sensor seems to be able to run from the 3.3v pin on the D1 Mini, unlike the 2410 which draws too much current in 3.3V.

Configuration example
--
```
#System Params
captive_portal:
# Disable logging
logger:
  baud_rate: 0
# Enable Home Assistant API
api:
#  encryption:
#    key: !secret api_encryption_key
# Disabled, occasionally causes issues when combined with HLK modules: https://github.com/esphome/issues/issues/5790
ota:
  platform: esphome
  password: !secret ota_password

safe_mode:
  boot_is_good_after: 90s
  num_attempts: 3

#Load external components for radar peripheral
external_components:
  - source:
      type: git
      url: https://github.com/mouldybread/LD2401P
      ref: main
    components: [LD2401P]


#Hardware Params
uart:
  id: uart_bus
  tx_pin: TX
  rx_pin: RX
  baud_rate: 256000
  parity: NONE
  stop_bits: 1

#Peripheral & Sensor Params

#Throttle the radar
LD2401P:
  id: ld2401p
  throttle: 3s

binary_sensor:
  - platform: LD2401P
    has_target:
      name: Presence
    has_moving_target:
      name: Moving Target
    has_still_target:
      name: Still Target

sensor:
  - platform: LD2401P
    moving_distance:
      name : Moving Distance
    still_distance:
      name: Still Distance
    moving_energy:
      name: Move Energy
    still_energy:
      name: Still Energy
    detection_distance:
      name: Detection Distance
    light:
      name: light
    g0:
      move_energy:
        name: g00 move energy
      still_energy:
        name: g00 still energy
    g1:
      move_energy:
        name: g01 move energy
      still_energy:
        name: g01 still energy
    g2:
      move_energy:
        name: g02 move energy
      still_energy:
        name: g02 still energy
    g3:
      move_energy:
        name: g03 move energy
      still_energy:
        name: g03 still energy
    g4:
      move_energy:
        name: g04 move energy
      still_energy:
        name: g04 still energy
    g5:
      move_energy:
        name: g05 move energy
      still_energy:
        name: g05 still energy
    g6:
      move_energy:
        name: g06 move energy
      still_energy:
        name: g06 still energy
    g7:
      move_energy:
        name: g07 move energy
      still_energy:
        name: g07 still energy
    g8:
      move_energy:
        name: g08 move energy
      still_energy:
        name: g08 still energy
    g9:
      move_energy:
        name: g09 move energy
      still_energy:
        name: g09 still energy
    g10:
      move_energy:
        name: g10 move energy
      still_energy:
        name: g10 still energy
    g11:
      move_energy:
        name: g11 move energy
      still_energy:
        name: g11 still energy
    g12:
      move_energy:
        name: g12 move energy
      still_energy:
        name: g12 still energy
    g13:
      move_energy:
        name: g13 move energy
      still_energy:
        name: g13 still energy

number:
  - platform: LD2401P
    timeout:
      name: "presence holding"
    min_distance_gate:
      name: "min distance gate"
    max_distance_gate:
      name: "max distance gate"
    g0:
      move_threshold:
        name: g00 move threshold
      still_threshold:
        name: g00 still threshold
    g1:
      move_threshold:
        name: g01 move threshold
      still_threshold:
        name: g01 still threshold
    g2:
      move_threshold:
        name: g02 move threshold
      still_threshold:
        name: g02 still threshold
    g3:
      move_threshold:
        name: g03 move threshold
      still_threshold:
        name: g03 still threshold
    g4:
      move_threshold:
        name: g04 move threshold
      still_threshold:
        name: g04 still threshold
    g5:
      move_threshold:
        name: g05 move threshold
      still_threshold:
        name: g05 still threshold
    g6:
      move_threshold:
        name: g06 move threshold
      still_threshold:
        name: g06 still threshold
    g7:
      move_threshold:
        name: g07 move threshold
      still_threshold:
        name: g07 still threshold
    g8:
      move_threshold:
        name: g08 move threshold
      still_threshold:
        name: g08 still threshold
    g9:
      move_threshold:
        name: g09 move threshold
      still_threshold:
        name: g09 still threshold
    g10:
      move_threshold:
        name: g10 move threshold
      still_threshold:
        name: g10 still threshold
    g11:
      move_threshold:
        name: g11 move threshold
      still_threshold:
        name: g11 still threshold
    g12:
      move_threshold:
        name: g12 move threshold
      still_threshold:
        name: g12 still threshold
    g13:
      move_threshold:
        name: g13 move threshold
      still_threshold:
        name: g13 still threshold
        
select:
  - platform: LD2401P
    out_pin_level:
      name: 'Hardware output pin level'
    distance_resolution:
      name: 'Distance resolution'
    baud_rate:
      name: "baud rate"
      on_value:
        - delay: 3s
        - lambda: |-
            id(uart_bus).flush();
            uint32_t new_baud_rate = stoi(x);
            ESP_LOGD("change_baud_rate", "Changing baud rate from %i to %i",id(uart_bus).get_baud_rate(), new_baud_rate);
            if (id(uart_bus).get_baud_rate() != new_baud_rate) {
            id(uart_bus).set_baud_rate(new_baud_rate);
            id(uart_bus).load_settings();
            }
    mode:
      name: "Mode"
button:
  - platform: LD2401P
    factory_reset:
      name: "factory reset"
    restart:
      name: "restart"
    query_params:
      name: query params

text_sensor:
  - platform: LD2401P
    version:
      name: "firmware version"
    mac_address:
      name: "mac address"
switch:
  - platform: LD2401P
    bluetooth:
      name: "Bluetooth"
```
