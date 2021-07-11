set(network_lib
        read.c
        log.c
        tcp_client.c
        tcp_server.c
        )

add_library(network ${network_lib})
target_link_libraries(network pthread)
install(TARGETS network DESTINATION lib)

#file(GLOB HEADERS "*.h")
#install(FILES ${HEADERS} DESTINATION include/)

