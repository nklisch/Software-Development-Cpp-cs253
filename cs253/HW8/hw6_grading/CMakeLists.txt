cmake_minimum_required(VERSION 3.14)
project(hw3_grading)

SET(HOMEWORK_DIR "" CACHE PATH "[Required] Path to the library and to the header files")

IF (NOT HOMEWORK_DIR)
      MESSAGE(FATAL_ERROR "'HOMEWORK_DIR' variable is required but was not set.
To set this variable, add to the CMake command
-DHOMEWORK_DIR=/path/to/homework6/library/and/header/files")
ENDIF ()


# Using -Wall is required:
add_compile_options(-Wall)

# These compile flags are highly recommended, but not required:
add_compile_options(-Wextra -Wpedantic)

# Optional super-strict mode:
add_compile_options(-fmessage-length=80 -fno-diagnostics-show-option)
add_compile_options(-fstack-protector-all -g -O3 -std=c++14)
add_compile_options(-Wctor-dtor-privacy)
add_compile_options(-Werror -Wfatal-errors -Winit-self)
add_compile_options(-Wlogical-op -Wold-style-cast -Wshadow)
add_compile_options(-Wzero-as-null-pointer-constant)

#

include_directories(${HOMEWORK_DIR})
link_directories(${HOMEWORK_DIR})


add_subdirectory(tests_hw5)

foreach(test_name ${test_hw5_names})
  add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests_hw5/data)
  if (${test_name} STREQUAL "test20")
    set_tests_properties(${test_name} PROPERTIES WILL_FAIL true LABELS "Tests HW5")
  else ()
    set_tests_properties(${test_name} PROPERTIES LABELS "Tests HW5")
  endif ()
endforeach(test_name)


add_subdirectory(tests_samples)

foreach(test_name ${test_samples_names})
  add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests_samples/data)
  set_tests_properties(${test_name} PROPERTIES LABELS "Tests samples")
endforeach(test_name)


add_subdirectory(tests_array_subscript_op)

foreach(test_name ${test_array_subscript_op_names})
  add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data)
  set_tests_properties(${test_name} PROPERTIES LABELS "Tests array subscript operator")
endforeach(test_name)


add_subdirectory(tests_boolean_conversion_op)

foreach(test_name ${test_boolean_conversion_op_names})
  add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data)
  set_tests_properties(${test_name} PROPERTIES LABELS "Tests boolean conversion operator")
endforeach(test_name)


add_subdirectory(tests_eq_ne_op)

foreach(test_name ${test_eq_ne_op_names})
  add_test(NAME ${test_name} COMMAND ${test_name} WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/data)
  set_tests_properties(${test_name} PROPERTIES LABELS "Tests equality and non equality ")
endforeach(test_name)


enable_testing()
