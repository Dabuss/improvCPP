add_library(improvenginelib
    improvenginelib/Displayer.cpp
    improvenginelib/TextDisplayer.cpp

    improvenginelib/AnimalGenerator.cpp

)

target_include_directories(improvenginelib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)
target_link_libraries(improvenginelib PRIVATE
    Qt6::Widgets
)

qt_add_executable(improvCPP
    main.cpp
)

target_include_directories(improvCPP PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${JSONCPP_INCLUDE_DIR}
)

target_link_libraries(improvCPP PRIVATE
    improvenginelib 
    Qt6::Widgets
    ${JSONCPP_LIB_DIR}/libjsoncpp.a
)
