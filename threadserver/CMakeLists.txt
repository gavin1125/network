add_executable(threadhelloserver thread_hello.c)
target_link_libraries(threadhelloserver network)


add_executable(thread01server thread01.c echo.c)
target_link_libraries(thread01server network)

add_executable(thread02server thread02.c echo.c)
target_link_libraries(thread02server network)