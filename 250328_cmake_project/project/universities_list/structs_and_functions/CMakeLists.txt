target_sources(universities_list
	PRIVATE
		functions.cpp
		functions.hpp
		menu_fragments.cpp
		menu_fragments.hpp
		structs.hpp
)

target_include_directories(universities_list PRIVATE
	"${PROJECT_SOURCE_DIR}/structs_and_functions"
)