#include "src/graphics/window.hpp"

int main() {
    using namespace chapi;
    using namespace graphics;

    Window window("Chapi Engine", 960, 540);

    glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

    while (!window.closed()) {
        window.clear();

        glBegin(GL_QUADS);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(-0.5f,  0.5f);
        glVertex2f( 0.5f,  0.5f);
        glVertex2f( 0.5f, -0.5f);
        glEnd();

        window.update();
    }

    return 0;
}