set(network_lib
        read.c
        log.c
        )

add_library(network ${network_lib})
install(TARGETS network DESTINATION lib)

#file(GLOB HEADERS "*.h")
#install(FILES ${HEADERS} DESTINATION include/)

