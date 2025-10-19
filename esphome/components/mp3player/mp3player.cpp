#include "mp3player.h"
#include "esphome/core/log.h"

namespace esphome {
namespace mp3player {

static const char *TAG = "mp3player";

void MP3PlayerOutput::setup() {
  software_serial_.begin(9600);
  if (!dfplayer_.begin(software_serial_)) {
    ESP_LOGE(TAG, "DFPlayer initialization failed");
    this->mark_failed();
    return;
  }
  dfplayer_.volume(30);
  ESP_LOGI(TAG, "DFPlayer initialized successfully");
}

void MP3PlayerOutput::write_state(bool state) {
  if (state) {
    ESP_LOGD(TAG, "Playing MP3 track #1 in loop");
    dfplayer_.loop(1);
  } else {
    ESP_LOGD(TAG, "Stopping playback");
    dfplayer_.stop();
  }
}

}  // namespace mp3player
}  
