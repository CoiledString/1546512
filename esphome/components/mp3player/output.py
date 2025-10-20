from esphome.components import output
import esphome.codegen as cg
import esphome.config_validation as cv  # ✅ This is required

mp3player_ns = cg.esphome_ns.namespace("mp3player")
MP3PlayerOutput = mp3player_ns.class_("MP3PlayerOutput", cg.Component, output.BinaryOutput)

CONFIG_SCHEMA = output.BINARY_OUTPUT_SCHEMA.extend({}).extend(cv.COMPONENT_SCHEMA)  # ✅ Use cv, not cg

async def to_code(config):
    var = cg.new_Pvariable(config[output.CONF_ID])
    await output.register_output(var, config)
    await cg.register_component(var, config)
