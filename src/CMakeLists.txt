add_library(improvenginelib
    improvenginelib/Displayer.cpp
    improvenginelib/TextDisplayer.cpp
    improvenginelib/TextualResourcesFileParser.cpp
    improvenginelib/ImpulsionGenerator.cpp
    improvenginelib/UIController.cpp
    improvenginelib/RandomVectorSampler.inl

    improvenginelib/Engines/AnimalGenerator.cpp
    improvenginelib/Engines/BodyPartGenerator.cpp
    improvenginelib/Engines/WordImpactGenerator.cpp
)

target_include_directories(improvenginelib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
    ${JSONCPP_INCLUDE_DIR}
)
target_link_libraries(improvenginelib PRIVATE
    ${JSONCPP_LIB_DIR}/libjsoncpp.a
    Qt6::Widgets
)

add_executable(improvCPP
    main.cpp
)

target_include_directories(improvCPP PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include
)

target_link_libraries(improvCPP PRIVATE
    improvenginelib
    Qt6::Widgets
)
