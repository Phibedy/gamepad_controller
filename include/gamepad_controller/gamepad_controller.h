#ifndef GAMEPAD_CONTROLLER_H
#define GAMEPAD_CONTROLLER_H
#include <lms/module.h>
#include <gamepad_controller/gamepad_controller.h>

class GamepadController: public lms::Module{

public:
    GamepadController();

    bool initialize()override;
    bool deinitialize()override;

    bool cycle()override;
private:

};

#endif /*GAMEPAD_CONTROLLER_H*/
