# Arcade - Graphics
This directory contains graphics Library for the Arcade project.

## Implement your own graphics library


### Entrypoint
First you need to create your entry point for your graphics library. This entry point must be a function that returns a pointer to an instance of your graphics library class.
This function must be declared as `extern "C"` to avoid name mangling. Here is an example of an entry point function:

```cpp
extern "C"
{
    std::unique_ptr<Arcade::IRenderer> entryPoint()
    {
        return std::make_unique<Arcade::MyGraphicLib>();
    }
}
```

### Implement the `arcade::IRenderer` class
To implement your own graphics library, you need to create a class that inherits from the `Arcade::IRenderer`.
This class must implement the following methods:

```cpp
class MyGraphicLib : public Arcade::IRenderer {
public:
    ~MyGraphicLib() override;

    IWindow *getWindow() override;
    KeyboardEvent getEvent() override;
    bool isASCII() override;
    bool loadTexture(const std::string &filepath, const std::string &name) override;
    bool loadFont(const std::string &filepath, const std::string &name) override;
    void createSprite(const std::string &textureName, float pos_x, float pos_y, float scale_x, float scale_y) override;
    void displaySprite(const std::string &spriteName) override;void createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y) override;
    void displayText(const std::string &textName) override;
    void moveText(const std::string &textName, int pos_x, int pos_y) override;
    void loadSound(const std::string &filePath) override;
    void stopSound() override;
    void moveSprite(const std::string &spriteName, float pos_x, float pos_y) override;void rotateSprite(const std::string &spriteName, float angle) override;
    std::string updateTextBox() override;
    void setSize(float x, float y) override;
    void deleteRessources() override;
};
```

### Implement the `arcade::IWindow` class

To implement your own window class, you need to create a class that inherits from the `Arcade::IWindow`.
This class must implement the following methods:

```cpp

class MyWindow : public Arcade::IWindow {

    ~MyWindow() override;
    
    void openWindow() override;
    void displayWindow() override;
    void clearWindow() override;
    void closeWindow() override;
    void setTitle(const std::string &title) override;

};
```

### Compile your library

To compile your library, you need to create a `CMakeLists.txt` file that will compile your library as a shared library,
in a new directory named `libcaca` for exemple. Here is an example of a `CMakeLists.txt` file:

```cmake
project(arcade_libCaca
        LANGUAGES CXX
)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib/)

set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)

add_library(${PROJECT_NAME} SHARED ${SOURCE})

target_sources(${PROJECT_NAME} PRIVATE
        ${SRC_DIR}/libCaca.cpp
)
```

Add this line at the Graphics/CMakeLists.txt file:

```cmake
add_subdirectory(libcaca)
```

And then you have it.
