/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Texts.cpp
*/

#include "Arcade/NCursesRenderer.hpp"

void Arcade::NCursesRenderer::moveText(const std::string &textName, int pos_x, int pos_y)
{
    _texts[textName].pos_x = pos_x;
    _texts[textName].pos_y = pos_y;
    mvaddstr(_texts[textName].pos_x, _texts[textName].pos_y, _texts[textName].text.c_str());
}

void Arcade::NCursesRenderer::displayText(const std::string &textName)
{
    mvaddstr(_texts[textName].pos_x, _texts[textName].pos_y,  _texts[textName].text.c_str());
}

std::string Arcade::NCursesRenderer::updateTextBox()
{
    _texts[" "].text = _userName;
    return _userName;
}

void Arcade::NCursesRenderer::createText(const std::string &fontName, const std::string &text, int size, float pos_x, float pos_y)
{
    (void) fontName; (void) size;
    Text textTmp;
    textTmp.text = text;
    textTmp.pos_x = static_cast<int>(pos_x);
    textTmp.pos_y = static_cast<int>(pos_y);
    _texts[textTmp.text] = textTmp;
}
