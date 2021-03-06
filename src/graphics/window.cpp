#include "window.hpp"

namespace chapi {
    namespace graphics {
        void windowResize(GLFWwindow* window, int width, int height);

        Window::Window(const char* title, int width, int height) {
            m_Title = title;
            m_Width = width;
            m_Height = height;

            if (!init()) {
                glfwTerminate();
            }
        }

        Window::~Window() {
            glfwTerminate();
        }

        bool Window::init() {
            if (!glfwInit()) {
                std::cout << "[ERROR][CHAPI] Failed to initialize GLFW." << std::endl;

                return false;
            }

            m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

            if(!m_Window) {
                std::cout << "[ERROR][CHAPI] Failed to create window." << std::endl;

                return false;
            }

            glfwMakeContextCurrent(m_Window);
            glfwSetWindowSizeCallback(m_Window, windowResize);

            return true;
        }

        bool Window::closed() const {
            return glfwWindowShouldClose(m_Window) == 1;
        }

        void Window::update() {
            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }

        void Window::clear() const {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void windowResize(GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        }
    }
}