#cmake_minimum_required(VERSION 3.22)
#project(test_ultimate_oop)
#
##C++ init
#set(CMAKE_CXX_STANDART 17)
#set(CMAKE_CXX_STANDART_REQUIRED ON)
##
#
##Qt6 init
#function(init_qt6)
#	find_package(Qt6 REQUIRED COMPONENTS Widgets Gui Core)
#    set(CMAKE_AUTOMOC ON)
#	set(CMAKE_AUTORCC ON)
#	set(CMAKE_AUTOUIC ON)
#endfunction()
#
#set(MESSAGE_GOOD_PATH "\"C:\\Qt\\6.2.2\\msvc2019_64\"")
##option(CMAKE_PREFIX_PATH "Set CMAKE_PREFIX_PATH like: ${MESSAGE_GOOD_PATH}" OFF)
##string(COMPARE EQUAL "${CMAKE_PREFIX_PATH}" "OFF" IS_QT_6_PATH_EMPTY)
##	if(IS_QT_6_PATH_EMPTY)
##                message(FATAL_ERROR "### CMAKE_PREFIX_PATH is empty! Set CMAKE_PREFIX_PATH on cmake.exe call like: 'cmake . -D CMAKE_PREFIX_PATH=${MESSAGE_GOOD_PATH}'")
##                return()
##	else()
##		message("### -D CMAKE_PREFIX_PATH is ${CMAKE_PREFIX_PATH}")
##	endif()
##
#set(CMAKE_PREFIX_PATH "S:\\Code\\Qt\\6.2.2\\msvc2019_64")
#init_qt6()
##
#
##general source-targets processing
#file(GLOB IN_PROJECT_CPP_FILES
#     ${SOURCE_DIR}*.cpp *.h)
#message(" ### IN_PROJECT_CPP_FILES = ${IN_PROJECT_CPP_FILES}")
#add_executable(${PROJECT_NAME} ${IN_PROJECT_CPP_FILES})
#target_link_libraries(${PROJECT_NAME} Qt6::Widgets Qt6::Gui Qt6::Core)
#
##post build actions #1 #2 #3
#set(FULL_PATH_TO_EXECUTABLE $<TARGET_FILE:${PROJECT_NAME}>)
#set(FULL_PATH_TO_EXECUTABLE_DIR $<TARGET_FILE_DIR:${PROJECT_NAME}>)
##1
#message(" ### Add post build event : windeployqt.exe")
#add_custom_command(
#	TARGET ${PROJECT_NAME} POST_BUILD
#	COMMAND ${CMAKE_COMMAND} -E echo "POST_BUILD: Using windeployqt to copy all depends to executable path"
#	COMMAND ${CMAKE_PREFIX_PATH}/bin/windeployqt.exe 
#			${FULL_PATH_TO_EXECUTABLE}
#			--no-quick-import 
#			--no-translations 
#)
#
##2
#message(" ### Add post build event : make archive")
#set(POST_BUILD_ARCHIVE OFF)
#if(POST_BUILD_ARCHIVE)
#	add_custom_command(
#		TARGET ${PROJECT_NAME} POST_BUILD
#		COMMAND ${CMAKE_COMMAND} -E echo "POST_BUILD:Making build folder archive."
#		COMMAND ${CMAKE_COMMAND} -E tar cJ build.xz.tar ${FULL_PATH_TO_EXECUTABLE_DIR}
#	)
#endif()#POST_BUILD_ARCHIVE
#
##3
#message(" ### Add post build event :lauch app after build")
#set(POST_BUILD_EXECUTION ON)
#if(POST_BUILD_EXECUTION)
#	message(" ### Add post build event : ./${PROJECT_NAME}.exe")
#	add_custom_command(
#		TARGET ${PROJECT_NAME} POST_BUILD
#		COMMAND ${CMAKE_COMMAND} -E echo "POST_BUILD:Launch an app after build."
#		COMMAND ${FULL_PATH_TO_EXECUTABLE} 
#		
#	)
#endif()#POST_BUILD_EXECUTION
##
