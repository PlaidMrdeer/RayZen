//
// Created by plaidmrdeer on 2024/12/21.
//

#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>

#include <lum/Opengl.h>

namespace ray
{
    class Window
    {
    public:
        Window(int width, int height, const char *title);

        void create() const;
        void show(const Opengl &oepngl);
        void cleanup() const;
        static GLFWwindow* getWindow();
    private:
        struct windowSettings
        {
            int width;
            int height;
            const char *title;
        };

        windowSettings settings{};
        static GLFWwindow *windowHandle;
    };
}

#endif //WINDOW_H