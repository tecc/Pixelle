#include <pixelle/graphics/renderObjects/ShapeRenderObject.h>

graphics::TriangleRenderObject::TriangleRenderObject(std::vector<math::Vector2<float>> vertices) {
    this->meta = new RenderObjectMeta();
    this->setVertices(vertices);
}

void graphics::TriangleRenderObject::setup() {
    glGenVertexArrays(1, &this->meta->vao);
    glGenBuffers(1, &this->meta->vbo);

    glBindVertexArray(this->meta->vao);
    glBindBuffer(GL_ARRAY_BUFFER, this->meta->vbo);
    glEnableVertexAttribArray(0);
    isSetup = true;
    setVertices(this->vertices);
}

void graphics::TriangleRenderObject::render() {
    //return;
    glBindVertexArray(this->meta->vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void graphics::TriangleRenderObject::setVertices(std::vector<math::Vector2<float>> v) {
    this->vertices = v;
    if (isSetup) {
        float data[] = {
                this->vertices[0].x, this->vertices[0].y, 0.f,
                this->vertices[1].x, this->vertices[1].y, 0.f,
                this->vertices[2].x, this->vertices[2].y, 0.f
        };
        glBindBuffer(GL_ARRAY_BUFFER, this->meta->vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*) 0);
    }
}

graphics::TriangleRenderObject::~TriangleRenderObject() {
    glDeleteVertexArrays(1, &this->meta->vao);
    glDeleteBuffers(1, &this->meta->vbo);
}

float* graphics::SquareRenderObject::getVertices() {
    float vertices[] = {
            this->corner1.x, this->corner1.y, 0, // bottom left
            this->corner1.x, this->corner2.y, 0, // top left
            this->corner2.x, this->corner2.y, 0, // top right
            this->corner2.x, this->corner1.y, 0, // bottom right
    };
    return vertices;
}

void graphics::SquareRenderObject::setup() {
    glGenVertexArrays(1, &this->meta->vao);
    glGenBuffers(1, &this->meta->vbo);
    glGenBuffers(1, &this->meta->ebo);

    glBindVertexArray(this->meta->vao);

    // glBindBuffer(GL_ARRAY_BUFFER, this->meta->vbo); //< not sure it's necessary here

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->meta->ebo);
    const int indices[] = { 0, 1, 2, 1, 2, 3 };
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


    glEnableVertexAttribArray(0);
    isSetup = true;
    this->setCorner1(corner1);
    this->setCorner2(corner2);
}

void graphics::SquareRenderObject::render() {

}

void graphics::SquareRenderObject::updateVertices() {
    glBindBuffer(1, this->meta->vbo);
    float* vertices = getVertices();
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void graphics::SquareRenderObject::setCorner1(math::Vector2<float> c1) {
    this->corner1 = c1;
    if (isSetup) {
        updateVertices();
    }
}
void graphics::SquareRenderObject::setCorner2(math::Vector2<float> c2) {
    this->corner2 = c2;
    if (isSetup) {
        updateVertices();
    }
}
