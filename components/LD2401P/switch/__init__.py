import esphome.codegen as cg
from esphome.components import switch
import esphome.config_validation as cv
from esphome.const import (
    DEVICE_CLASS_SWITCH,
    ICON_BLUETOOTH,
    ENTITY_CATEGORY_CONFIG,
    ICON_PULSE,
)
from .. import CONF_LD2401P_ID, LD2401PComponent, LD2401P_ns

BluetoothSwitch = LD2401P_ns.class_("BluetoothSwitch", switch.Switch)
# EngineeringModeSwitch = LD2401P_ns.class_("EngineeringModeSwitch", switch.Switch)

CONF_ENGINEERING_MODE = "engineering_mode"
CONF_BLUETOOTH = "bluetooth"

CONFIG_SCHEMA = {
    cv.GenerateID(CONF_LD2401P_ID): cv.use_id(LD2401PComponent),
    # cv.Optional(CONF_ENGINEERING_MODE): switch.switch_schema(
    #     EngineeringModeSwitch,
    #     device_class=DEVICE_CLASS_SWITCH,
    #     entity_category=ENTITY_CATEGORY_CONFIG,
    #     icon=ICON_PULSE,
    # ),
    cv.Optional(CONF_BLUETOOTH): switch.switch_schema(
        BluetoothSwitch,
        device_class=DEVICE_CLASS_SWITCH,
        entity_category=ENTITY_CATEGORY_CONFIG,
        icon=ICON_BLUETOOTH,
    ),
}


async def to_code(config):
    LD2401P_component = await cg.get_variable(config[CONF_LD2401P_ID])
    # if engineering_mode_config := config.get(CONF_ENGINEERING_MODE):
    #     s = await switch.new_switch(engineering_mode_config)
    #     await cg.register_parented(s, config[CONF_LD2401P_ID])
    #     cg.add(LD2401P_component.set_engineering_mode_switch(s))
    if bluetooth_config := config.get(CONF_BLUETOOTH):
        s = await switch.new_switch(bluetooth_config)
        await cg.register_parented(s, config[CONF_LD2401P_ID])
        cg.add(LD2401P_component.set_bluetooth_switch(s))
