#file(GLOB SRCS
#    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
#)
# set(SRCS
#     "commit.c"
#     "version.c"
#     "sw_queue.c"
#     "us_recovery.c"
#     )
# 
# 
# set(FLAGS
#   # Warning
#     "-Wall"
# 	"-Wextra"
# 	"-Wconversion"
#     "-Wshadow"
#     "-Wcast-qual"
#     "-Wstrict-prototypes"
#     "-Winit-self"
#     "-Wmissing-include-dirs"
#     "-Wc++-compat"
# 	"-Winline"
#    # Define
#     "-D_BSD_SOURCE"
# 	"-D_POSIX_C_SOURCE=199309L"
# 	"-U_FORTIFY_SOURCE"
#    # Other 
#     "-std=c99 -g -O3 -pedantic -fPIC"
#     )
# 
# string(REPLACE ";" " " FLAGS_STR "${FLAGS}")
# 
# set_source_files_properties(${SRCS} PROPERTIES COMPILE_FLAGS ${FLAGS_STR})
# set(PassName "smtx")
# 
# include_directories(./)
# 
# add_library(${PassName} STATIC ${SRCS})
# add_library(${PassName}_shared SHARED ${SRCS})
# set_target_properties(${PassName}_shared PROPERTIES OUTPUT_NAME ${PassName}) 
# install(TARGETS ${PassName} ${PassName}_shared
#         DESTINATION lib)
# 
# # sw_queue.noinline.co
# add_library("sw_queue.noinline" OBJECT sw_queue.c)
# string(CONCAT FLAGS_NOINLINE_STR ${FLAGS_STR} " -DNO_INLINE")
# set_target_properties("sw_queue.noinline" 
#                       PROPERTIES
#                       COMPILE_FLAGS ${FLAGS_NOINLINE_STR}
#                       OUTPUT_NAME "sw_queue.noinline")
# install(TARGETS "sw_queue.noinline"
#         DESTINATION lib)

# FIXME!
add_custom_target(smtx ALL COMMAND make -f Makefile.original WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
#add_custom_target(smtx ALL COMMAND make -f "${CMAKE_CURRENT_SOURCE_DIR}/Makefile.original" SOURCES ${SRCS})
#add_custom_command(TARGET smtx POST_BUILD COMMAND cat bitcast.h DEPENDS bitcast.h)
#add_custom_command(TARGET smtx POST_BUILD COMMAND make -f Makefile.original all)
install(DIRECTORY .
        DESTINATION support/smtx/)
