#pragma once
#include "esphome/core/component.h"
#include "esphome/components/output/binary_output.h"
#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

namespace esphome {
namespace mp3player {

class MP3PlayerOutput : public Component, public BinaryOutput {
 public:
  void setup() override;
  void write_state(bool state) override;

 protected:
  SoftwareSerial software_serial_{D5, D2};  // RX, TX
  DFRobotDFPlayerMini dfplayer_;
};

}  // namespace mp3player
}  // namespace esphome
