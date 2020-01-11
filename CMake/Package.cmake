if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	find_package (Threads REQUIRED)
endif ()

find_package (Eigen3 CONFIG REQUIRED)
find_package (SDL2 CONFIG REQUIRED)