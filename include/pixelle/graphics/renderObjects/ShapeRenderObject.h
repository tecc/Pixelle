#ifndef PIXELLE_SHAPERENDEROBJECT_H
#define PIXELLE_SHAPERENDEROBJECT_H

#include <pixelle/graphics/RenderObject.h>

namespace pixelle::graphics {
    class TriangleRenderObject : public RenderObject {
    private:
        std::vector<math::Vector2<float>> vertices;
        bool isSetup = false;
    public:
        TriangleRenderObject() : TriangleRenderObject({{-.5f, -.5f}, {.5f, -.5f}, {0, .5f}}) {};
        explicit TriangleRenderObject(std::vector<math::Vector2<float>> vertices);
        ~TriangleRenderObject();

        void setVertices(std::vector<math::Vector2<float>> v);

        void setup() override;
        void render() override;
    };
    class SquareRenderObject : public RenderObject {
    private:
        bool isSetup = false;
        math::Vector2<float> corner1;
        math::Vector2<float> corner2;
    protected:
        float* getVertices();
        void updateVertices();
    public:
        SquareRenderObject() : SquareRenderObject(0, 0) {};
        SquareRenderObject(math::Vector2<float> c1, math::Vector2<float> c2) : corner1(c1), corner2(c2) {};

        void setCorner1(math::Vector2<float> c1);
        void setCorner2(math::Vector2<float> c2);
        void setup() override;

        void render() override;
    };
}

#endif
