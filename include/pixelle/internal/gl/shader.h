#ifndef PIXELLE_SHADER_H
#define PIXELLE_SHADER_H

#define PIXELLE_GL_VERTEX_SHADER "\
#version 330 core \n\
layout (location = 0) in vec3 pos; \n\
void main() { \n\
    gl_Position = vec4(pos.x, pos.y, pos.z, 1.0 ); \n\
}"

#define PIXELLE_GL_FRAG_SHADER "\
#version 400 core \n\
out vec4 FragColor; \n\
void main() { \n\
    FragColor = vec4(gl_SamplePosition.x, gl_SamplePosition.y, 1.0f, 1.0f); \n\
}"

#endif
