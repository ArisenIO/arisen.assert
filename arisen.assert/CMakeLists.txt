add_contract(arisen.assert arisen.assert
   ${CMAKE_CURRENT_SOURCE_DIR}/src/arisen.assert.cpp
   )

target_compile_options(arisen.assert.wasm PUBLIC -fcolor-diagnostics)

target_include_directories(arisen.assert.wasm
   PUBLIC
   ${CMAKE_CURRENT_SOURCE_DIR}/include)

set_target_properties(arisen.assert.wasm
   PROPERTIES
   RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
