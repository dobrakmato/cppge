#include "thirdparty/glew/include/GL/glew.h"
#include "thirdparty/glfw/include/GLFW/glfw3.h"
#include <cstdio>

void error_callback(int error, const char *description) {
    fprintf(stderr, "Error: %s\n", description);
}

int main() {

    // Initialise GLFW
    if (!glfwInit()) {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }


    glfwSetErrorCallback(error_callback);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window;

    // Open a window and create its OpenGL context
    if (!(window = glfwCreateWindow(1024, 768, "Nadpis okna", nullptr, nullptr))) {
        fprintf(stderr,
                "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");
        glfwTerminate();
        return -1;
    }

    // Make this thread a current context.
    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (GLEW_OK != err) {
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    fprintf(stdout, "OpenGL Version: %s\n", glGetString(GL_VERSION));
    fprintf(stdout, "OpenGL Vendor: %s\n", glGetString(GL_VENDOR));
    fprintf(stdout, "OpenGL Renderer: %s\n", glGetString(GL_RENDERER));

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    do {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Swap buffers
        glfwSwapBuffers(window);

        // Poll events so user can control the window.
        glfwPollEvents();

    } // Check if the ESC key was pressed or the window was closed
    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS);

    // Close OpenGL window and terminate GLFW
    glfwTerminate();

    return 0;
}