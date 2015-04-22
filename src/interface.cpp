#include <gamepad_controller/gamepad_controller.h>

extern "C" {
void* getInstance () {
    return new GamepadController();
}
}
