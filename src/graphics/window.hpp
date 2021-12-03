#ifndef CHAPPY_CORE_GRAPHICS_WINDOW_HPP
#define CHAPPY_CORE_GRAPHICS_WINDOW_HPP

#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glew.h>

namespace chapi {
    namespace graphics {
        class Window {
        private:
            const char* m_Title;
            int m_Width, m_Height;
            bool m_Closed;

            GLFWwindow* m_Window;

        public:
            Window(const char* title, int width, int height);
            ~Window();

            bool closed() const;

            void update();
            void clear() const;

            inline int getWidth() const { return m_Width; }
            inline int getHeight() const { return m_Height; }

        private:
            bool init();
        };
    }
}

#endif // CHAPPY_CORE_GRAPHICS_WINDOW_HPP