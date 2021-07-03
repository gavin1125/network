add_executable(graceserver grace_server.c)
target_link_libraries(graceserver network)

add_executable(graceclient grace_client.c)
target_link_libraries(graceclient network)