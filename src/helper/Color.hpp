#if !defined(COLOR_HPP)
#define COLOR_HPP

#include <iostream>

class Color
{
  private:
    //   0xAARRGGBB (alpha, red, green, blue)
    int _value;

  public:
    Color(int rgb) : _value(0xFF000000 | rgb) {}
    Color(int r, int g, int b) : Color(r, g, b, 255) {}
    Color(int r, int g, int b, int a) : _value(((a & 0xFF) << 24) | ((r & 0xFF) << 16) | ((g & 0xFF) << 8) | ((b & 0xFF) << 0)) {}
    Color(const Color &c) : _value(c.getRGB()) {}

    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    int getAlpha() const;
    int getRGB() const;

    bool operator==(const Color &) const;
    Color operator+(const Color &) const;
    Color operator-(const Color &) const;

// Static Colors Declaration
#pragma region
    /**
     * The color white.  In the default sRGB space.
     */
    static Color white;
    static Color WHITE;

    /**
     * The color light gray.  In the default sRGB space.
     */
    static Color lightGray;
    static Color LIGHT_GRAY;

    /**
     * The color gray.  In the default sRGB space.
     */
    static Color gray;
    static Color GRAY;

    /**
     * The color dark gray.  In the default sRGB space.
     */
    static Color darkGray;
    static Color DARK_GRAY;

    /**
     * The color black.  In the default sRGB space.
     */
    static Color black;
    static Color BLACK;

    /**
     * The color red.  In the default sRGB space.
     */
    static Color red;
    static Color RED;

    /**
     * The color pink.  In the default sRGB space.
     */
    static Color pink;
    static Color PINK;

    /**
     * The color orange.  In the default sRGB space.
     */
    static Color orange;
    static Color ORANGE;

    /**
     * The color yellow.  In the default sRGB space.
     */
    static Color yellow;
    static Color YELLOW;

    /**
     * The color green.  In the default sRGB space.
     */
    static Color green;
    static Color GREEN;

    /**
     * The color magenta.  In the default sRGB space.
     */
    static Color magenta;
    static Color MAGENTA;

    /**
     * The color cyan.  In the default sRGB space.
     */
    static Color cyan;
    static Color CYAN;

    /**
     * The color blue.  In the default sRGB space.
     */
    static Color blue;
    static Color BLUE;
#pragma endregion
};
// Static Colors Initialization
#pragma region
Color Color::white = Color(255, 255, 255);
Color Color::WHITE = white;

Color Color::lightGray = Color(192, 192, 192);
Color Color::LIGHT_GRAY = lightGray;

Color Color::gray = Color(128, 128, 128);
Color Color::GRAY = gray;

Color Color::darkGray = Color(64, 64, 64);
Color Color::DARK_GRAY = darkGray;

Color Color::black = Color(0, 0, 0);
Color Color::BLACK = black;

Color Color::red = Color(255, 0, 0);
Color Color::RED = red;

Color Color::pink = Color(255, 175, 175);
Color Color::PINK = pink;

Color Color::orange = Color(255, 200, 0);
Color Color::ORANGE = orange;

Color Color::yellow = Color(255, 255, 0);
Color Color::YELLOW = yellow;

Color Color::green = Color(0, 255, 0);
Color Color::GREEN = green;

Color Color::magenta = Color(255, 0, 255);
Color Color::MAGENTA = magenta;

Color Color::cyan = Color(0, 255, 255);
Color Color::CYAN = cyan;

Color Color::blue = Color(0, 0, 255);
Color Color::BLUE = blue;
#pragma endregion

// Returns the red component in the range 0-255 in the default sRGB space.
int Color::getRed() const
{
    return (this->_value >> 16) & 0xFF;
}

// Returns the green component in the range 0-255 in the default sRGB space.
int Color::getGreen() const
{

    return (this->_value >> 8) & 0xFF;
}

// Returns the blue component in the range 0-255 in the default sRGB space.
int Color::getBlue() const
{

    return (this->_value >> 0) & 0xFF;
}

// Returns the alpha component in the range 0-255.
int Color::getAlpha() const
{
    return (this->_value >> 24) & 0xFF;
}

// Returns the RGB _value representing the color in the default sRGB
// (Bits 24-31 are alpha, 16-23 are red, 8-15 are green, 0-7 are blue).
int Color::getRGB() const
{
    return this->_value;
}

bool Color::operator==(const Color &c) const
{
    return this->_value == c.getRGB();
}

Color Color::operator+(const Color &c) const
{
    //! Need implementation
    return 0;
}

Color Color::operator-(const Color &c) const
{
    //! Need implementation
    return 0;
}

std::ostream &operator<<(std::ostream &os, const Color &c)
{
    return os << "Color[ R = " << c.getRed() << ", G = " << c.getGreen() << ", B = " << c.getBlue() << "]";
}

#endif // COLOR_HPP
