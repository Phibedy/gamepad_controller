#include <gamepad_controller/gamepad_controller.h>
#include <gamepad/gamepad_handler.h>
#include <gamepad/gamepad_types.h>
#include <gamepad/gamepad.h>
GamepadController::GamepadController(){
}
Gamepad *gp;
bool GamepadController::initialize(){
    gp = nullptr;
    GamepadHandler::init(this,datamanager());
    //TODO just for testing

    std::vector<std::string> names = config().getArray<std::string>("controller");
    std::string dataChannelName = config().get<std::string>("dataChannelName", "CONTROLLER_1");
    for(std::string &name:names){
        gp = GamepadHandler::getGamepad(this,name,dataChannelName,false);
        if(gp != nullptr)
            break;
    }
    if(gp == nullptr) {
        logger.error("init") << "gamepad is not found!";
        return false;
    }

    std::string controllerType = config().get<std::string>("type");

    if(controllerType == "xpad") {
        setAsXBoxControllerXpad(*gp);
    } else if(controllerType == "xboxdrv") {
        setAsXBoxControllerXboxdrv(*gp);
    } else {
        logger.error("init")<< "Type invalid: " << controllerType;
        return false;
    }

    return true;
}

bool GamepadController::deinitialize(){
    return true;
}

bool GamepadController::cycle(){
    GamepadHandler::processEvents();
    return true;
}
