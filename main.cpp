#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // GLFWの初期化
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // ウィンドウ作成
    GLFWwindow* window = glfwCreateWindow(640, 480, "OpenGL Info", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    // GLEWの初期化
    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(err) << std::endl;
        return -1;
    }

    // OpenGL情報の取得と表示
    const GLubyte* vendor = glGetString(GL_VENDOR);
    const GLubyte* renderer = glGetString(GL_RENDERER);
    const GLubyte* version = glGetString(GL_VERSION);
    const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

    std::cout << "Vendor: " << vendor << std::endl;
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL Version: " << version << std::endl;
    std::cout << "GLSL Version: " << glslVersion << std::endl;

    // メインループ
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}