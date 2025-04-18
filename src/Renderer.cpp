//
// Created by Myles Hansen on 4/17/25.
//

#include "Renderer.h"

#include <iostream>

void GLClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* func, const char* file, int line) {
    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::string errorName;
        switch (error) {
            case GL_INVALID_ENUM: errorName = "GL_INVALID_ENUM"; break;
            case GL_INVALID_VALUE: errorName = "GL_INVALID_VALUE"; break;
            case GL_INVALID_OPERATION: errorName = "GL_INVALID_OPERATION"; break;
            case GL_STACK_OVERFLOW: errorName = "GL_STACK_OVERFLOW"; break;
            case GL_STACK_UNDERFLOW: errorName = "GL_STACK_UNDERFLOW"; break;
            case GL_OUT_OF_MEMORY: errorName = "GL_OUT_OF_MEMORY"; break;
            default: errorName = "UNKNOWN ERROR"; break;
        }
        std::cout << "[OpenGL Error] " << errorName << " (0x" << std::hex << error << std::dec << ") at "
                  << file << ":" << line << " in " << func << std::endl;

        // Clear all remaining errors without reporting them
        while (glGetError() != GL_NO_ERROR);

        return false;
    }
    return true;
}

