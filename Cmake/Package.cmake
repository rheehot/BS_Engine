if (CMAKE_SYSTEM_NAME MATCHES "Linux")
	find_package (Threads)
endif ()

find_package (Eigen3 REQUIRED)

find_package (SDL2 REQUIRED)