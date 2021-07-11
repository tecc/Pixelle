#include <pixelle/graphics/GraphicsAPI.h>
#include <pixelle/internal/gl_meta.h>
#include <pixelle/internal/gl/shader.h>
#include <pixelle/util/Exception.h>
#include <pixelle/util/Util.h>
#include <pixelle/Engine.h>
#include <vector>

using namespace pixelle;

unsigned int vertexShader;
unsigned int fragShader;
unsigned int shaderProgram;

inline void loadShader(unsigned int shader, const char* source) {
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    int success;
    char info[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shader, 512, nullptr, info);
        pixelle::log::error(_str("An error occurred whilst compiling shader ") + std::to_string(shader) + ": \n" + info);
        exit(1);
    }
}

inline void loadShaders() {
    // load the vertex shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    loadShader(vertexShader, PIXELLE_GL_VERTEX_SHADER);
    // load the frag shader
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    loadShader(fragShader, PIXELLE_GL_FRAG_SHADER);

    // create shader program
    shaderProgram = glCreateProgram();
    // attach vertex & frag shaders
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragShader);
    glLinkProgram(shaderProgram);
    int success;
    char info[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(shaderProgram, 512, nullptr, info);
        pixelle::log::error(_str("An error occurred whilst compiling shader ") + std::to_string(shaderProgram) + ": \n" + info);
        exit(1);
    }
    pixelle::log::info("Loaded vertex/frag shader program");
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
}

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


void graphics::Window::onClose() {
    log::info("Close event");
    exit(0);
}
void ev_onClose(GLFWwindow*) {
    graphics::getWindow()->onClose();
}

void graphics::Window::onFramebufferSize(int width, int height) {
    log::debug(_str("Framebuffer resized to ") + (std::string) math::Vector2{width, height});
    glViewport(0, 0, width, height);
}
void ev_onFramebufSize(GLFWwindow*, int w, int h) {
    graphics::getWindow()->onFramebufferSize(w, h);
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
            settings.dimensions.x, settings.dimensions.y,
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

    // event handlers
    log::debug("Setting event handlers");
    glfwSetWindowCloseCallback(glfwWindow, ev_onClose);

    // load opengl w/ GLAD2
    log::debug("Loading GL using GLAD2");
    int glVersion = gladLoadGL(glfwGetProcAddress);
    if (glVersion == 0) {
        throw pixelle::Exception("GLAD2 couldn't load GL!");
    }
    int major = GLAD_VERSION_MAJOR(glVersion), minor = GLAD_VERSION_MINOR(glVersion);
    log::debug(std::string("Using OpenGL version ") + std::to_string(major) + "." + std::to_string(minor));

    glViewport(0, 0, settings.dimensions.x, settings.dimensions.y);
    loadShaders();

    // set meta
    this->meta = new WindowMeta();
    meta->glfw = glfwWindow;

    log::debug(std::string("Default colour: ") + (std::string) settings.defaultColour);
}

void graphics::Window::update() {
    auto settings = getSettings();
    auto defColour = settings.defaultColour;
    glClearColor(defColour.getRed(), defColour.getGreen(), defColour.getBlue(), defColour.getAlpha());
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    glfwSwapBuffers(meta->glfw);
}

graphics::Window* graphics::getWindow() {
    return window;
}

void graphics::updateGraphics() {
    glfwPollEvents();
    window->update();
}
