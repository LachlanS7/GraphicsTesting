project(test)

add_executable(${PROJECT_NAME} main.cpp ShaderProgram.cpp Utilities.cpp Display.cpp Mesh.cpp MeshManager.cpp Vertex.cpp)

target_link_libraries(${PROJECT_NAME} glfw glad glm)