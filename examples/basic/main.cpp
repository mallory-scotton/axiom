#include <axiom.hpp>

float angleX = 0.0f; // Angle for rotation around the X-axis
float angleY = 0.0f; // Angle for rotation around the Y-axis
bool isDragging = false; // Flag to check if the mouse is being dragged
int lastMouseX, lastMouseY; // Last mouse position
bool wireframeMode = false;
float zoom = 1.0f;

void drawCube() {
    glBegin(GL_QUADS);

    // Front face (z = 1.0)
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glVertex3f( 0.5f, -0.5f,  0.5f);
    glVertex3f( 0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f,  0.5f);

    // Back face (z = -1.0)
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);
    glVertex3f( 0.5f,  0.5f, -0.5f);
    glVertex3f( 0.5f, -0.5f, -0.5f);

    // Left face (x = -1.0)
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(-0.5f, -0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f,  0.5f);
    glVertex3f(-0.5f,  0.5f, -0.5f);

    // Right face (x = 1.0)
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f,  0.5f, -0.5f);
    glVertex3f(0.5f,  0.5f,  0.5f);
    glVertex3f(0.5f, -0.5f,  0.5f);

    // Top face (y = 1.0)
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glVertex3f(-0.5f, 0.5f,  0.5f);
    glVertex3f(0.5f, 0.5f,  0.5f);
    glVertex3f(0.5f, 0.5f, -0.5f);

    // Bottom face (y = -1.0)
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glVertex3f(0.5f, -0.5f,  0.5f);
    glVertex3f(-0.5f, -0.5f,  0.5f);

    glEnd();
}

void updateProjection(axg::Window& win) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = (float)win.getSize().x / (float)win.getSize().y;
    glFrustum(-aspectRatio * zoom, aspectRatio * zoom, -zoom, zoom, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, win.getSize().x, win.getSize().y);
}

int main(void)
{
    axg::ContextSettings settings;

    settings.depthBits = 24;
    settings.antialiasingLevel = 4;
    settings.stencilBits = 8;
    settings.majorVersion = 4;
    settings.minorVersion = 2;
    settings.sRgbCapable = true;

    axg::Window win(axg::VideoMode(800, 800), "OpenGL", axg::Style::Default, settings);
    axg::Event evt;

    glViewport(0, 0, 800, 800);
    glEnable(GL_DEPTH_TEST);

    updateProjection(win);
    glLoadIdentity();

    while (win.isOpen())
    {
        while (win.pollEvent(evt))
        {
            if (evt.type == axg::Event::Closed)
            {
                win.close();
            }
            else if (evt.type == axg::Event::MouseButtonPressed)
            {
                if (evt.mouseButton.button == axg::Mouse::Left)
                {
                    isDragging = true;
                    lastMouseX = evt.mouseButton.x;
                    lastMouseY = evt.mouseButton.y;
                }
            }
            else if (evt.type == axg::Event::MouseButtonReleased)
            {
                if (evt.mouseButton.button == axg::Mouse::Left)
                {
                    isDragging = false;
                }
            }
            else if (evt.type == axg::Event::MouseMoved)
            {
                if (isDragging)
                {
                    int deltaX = evt.mouseMove.x - lastMouseX;
                    int deltaY = evt.mouseMove.y - lastMouseY;

                    angleX += deltaY * .1f;
                    angleY += deltaX * .1f;

                    lastMouseX = evt.mouseMove.x;
                    lastMouseY = evt.mouseMove.y;
                }
            }
            else if (evt.type == axg::Event::MouseWheelScrolled)
            {
                zoom += evt.mouseWheelScroll.delta * 0.1f;
                if (zoom < 0.1f) zoom = 0.1f; // Prevent zooming too close
                updateProjection(win);
            }
            else if (evt.type == axg::Event::Resized)
            {
                updateProjection(win);
            }
            else if (evt.type == axg::Event::KeyPressed)
            {
                if (evt.key.code == axg::Keyboard::W)
                {
                    wireframeMode = !wireframeMode; // Toggle wireframe mode
                    if (wireframeMode)
                    {
                        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // Set to wireframe mode
                    }
                    else
                    {
                        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); // Set to fill mode
                    }
                }
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();

        glTranslatef(0.0f, 0.0f, -5.0f); // Move back to see the cube
        glRotatef(angleX, 1.0f, 0.0f, 0.0f); // Rotate around X-axis
        glRotatef(angleY, 0.0f, 1.0f, 0.0f); // Rotate around Y-axis

        drawCube();

        win.display();
    }

    return (EXIT_SUCCESS);
}
