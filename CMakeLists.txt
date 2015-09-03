set ( SOURCES 
        "src/gamepad_controller.cpp"
	"src/interface.cpp"
)

set (HEADERS
        "include/gamepad_controller/gamepad_controller.h"
)

include_directories("include")

add_library ( gamepad_controller MODULE ${SOURCES} ${HEADERS})
target_link_libraries(gamepad_controller PRIVATE lmscore gamepad_lib)
