#include <pixelle/graphics/GraphicsAPI.h>
#include <pixelle/internal/gl_meta.h>
#include <pixelle/util/Exception.h>
#include <pixelle/util/Util.h>
#include <pixelle/Engine.h>

#define DEFAULT_WINDOW_HEIGHT 480
#define DEFAULT_WINDOW_WIDTH 640

using namespace pixelle;

inline std::string getGlfwErr() {
    const char* dat;
    if (glfwGetError(&dat)) {
        return std::string(dat);
    } else return "";
}

graphics::Window* window = nullptr;

void graphics::initGraphics() {
    log::debug("Initialising GLFW");
    if (!glfwInit()) {
        throw pixelle::Exception("An error occurred whilst initialising GLFW! " + getGlfwErr());
    }

    log::debug("Creating window instance");
    window = new Window();
}

graphics::Window::Window() {
    if (pixelle::graphics::getWindow() != nullptr) {
        throw pixelle::Exception("A Window instance already exists!");
    }
    auto settings = pixelle::getSettings();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    if (settings.vsync) {
        glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);
    } else {
        glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_FALSE);
    }

    log::debug("Creating GLFW window");
    // create window
    auto glfwWindow = glfwCreateWindow(
            DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HEIGHT,
            settings.name.c_str(),
            nullptr, nullptr
    );
    // check that it was created successfully
    if (glfwWindow == nullptr) {
        throw pixelle::Exception("An error occurred whilst instantiating GLFW window " + getGlfwErr());
    }
    log::debug("Making window context current");
    // make the window context the current context
    glfwMakeContextCurrent(glfwWindow);

    // load opengl w/ GLAD2
    log::debug("Loading GL using GLAD2");
    int glVersion = gladLoadGL(glfwGetProcAddress);
    if (glVersion == 0) {
        throw pixelle::Exception("GLAD2 couldn't load GL!");
    }
    int major = GLAD_VERSION_MAJOR(glVersion), minor = GLAD_VERSION_MINOR(glVersion);
    log::debug(std::string("Using OpenGL version ") + std::to_string(major) + "." + std::to_string(minor));

    // set meta
    this->meta = new WindowMeta();
    meta->glfw = glfwWindow;
}

void graphics::Window::update() {
    glClear(GL_COLOR_BUFFER_BIT);
}

graphics::Window* graphics::getWindow() {
    return window;
}

void graphics::updateGraphics() {
    glfwPollEvents();
}
