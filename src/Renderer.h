//
// Created by Myles Hansen on 4/17/25.
//

#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>

#ifndef ASSERT_H
#define ASSERT_H

#if defined(__APPLE__)
    // macOS - use a less intrusive approach
    #include <csignal>
    #define DEBUG_BREAK do { \
    std::cerr << "ASSERTION FAILED at " << __FILE__ << ":" << __LINE__ << std::endl; \
    std::raise(SIGINT); /* Use SIGINT instead of SIGTRAP */ \
    } while(0)
#elif defined(_MSC_VER)
    // Visual Studio
    #define DEBUG_BREAK __debugbreak()
#elif defined(__clang__)
    // Clang
    #define DEBUG_BREAK __builtin_debugtrap()
#elif defined(__GNUC__)
    // GCC
    #define DEBUG_BREAK __builtin_trap()
#else
    #include <signal.h>
    #define DEBUG_BREAK raise(SIGTRAP)
#endif

#define ASSERT(x) if(!(x)) DEBUG_BREAK

#endif // ASSERT_H

#define GLCall(x) GLClearError();\
x;\
ASSERT(GLLogCall(#x, __FILE__, __LINE__))

void GLClearError();

bool GLLogCall(const char* func, const char* file, int line);

#endif //RENDERER_H
