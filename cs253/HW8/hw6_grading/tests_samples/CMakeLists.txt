# Each test must be in a file named test*.cc
file(GLOB tests test*.cc)

# Tests
foreach(test ${tests})

  get_filename_component(test_name ${test} NAME_WE)
  set(tmp_test_names ${tmp_test_names} ${test_name})
  add_executable(${test_name} ${test})
  target_link_libraries(${test_name} LINK_PUBLIC hw8)
  
endforeach(test)

set(test_samples_names ${tmp_test_names} PARENT_SCOPE)
