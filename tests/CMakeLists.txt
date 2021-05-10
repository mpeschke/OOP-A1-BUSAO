set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if(USE_LCOV)
    if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
        SET(CMAKE_CXX_FLAGS "-g -O0 ${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_FLAGS} -fprofile-arcs -ftest-coverage")
        SET(CMAKE_EXE_LINKER_FLAGS "--coverage")
        SET(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${GCC_COVERAGE_FLAGS} --coverage")
        message("CLang detected - using -g -O0 -fprofile-arcs -ftest-coverage --coverage")
    else()
        SET(GCC_COVERAGE_FLAGS "-fprofile-arcs -ftest-coverage")
        SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_FLAGS}")
        SET(CMAKE_EXE_LINKER_FLAGS "-fprofile-arcs -ftest-coverage")
        SET(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} ${GCC_COVERAGE_FLAGS}")
        message("GCC detected - using -fprofile-arcs -ftest-coverage")
    endif()    
endif(USE_LCOV)

include_directories(../src/BusaoBLL)

file(GLOB_RECURSE UNITTESTSOURCES
    BusaoBLL-Unit-Tests/*.h
    BusaoBLL-Unit-Tests/*.hpp
    BusaoBLL-Unit-Tests/*.cpp
)

add_executable(
    BusaoBLL-Unit-Tests
    ${UNITTESTSOURCES}
    )
target_link_libraries (BusaoBLL-Unit-Tests LINK_PUBLIC BusaoBLL ${Boost_LIBRARIES})
add_definitions( -DBOOST_ALL_DYN_LINK )

# Template para testes
function(do_test testname target arg1)
  add_test(NAME ${testname} COMMAND ${target} ${arg1})
endfunction(do_test)

do_test("unittests" BusaoBLL-Unit-Tests "--log_level=message")