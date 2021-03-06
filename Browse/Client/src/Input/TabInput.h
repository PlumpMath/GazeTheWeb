//============================================================================
// Distributed under the Apache License, Version 2.0.
// Author: Raphael Menges (raphaelmenges@uni-koblenz.de)
//============================================================================
// Input structure for tab which holds coordinates in web view space.
// Origin in upper left corner.

#ifndef TABINPUT_H_
#define TABINPUT_H_

#include "src/Input/Input.h"

class TabInput : public Input
{
public:
    TabInput(
        const Input& rInput,
        int webViewPixelGazeX,
        int webViewPixelGazeY,
        float webViewRelativeGazeX,
        float webViewRelativeGazeY) : Input(rInput.gazeX, rInput.gazeY, rInput.gazeUsed, rInput.instantInteraction, rInput.saccade)
    {
        this->webViewPixelGazeX = webViewPixelGazeX;
        this->webViewPixelGazeY = webViewPixelGazeY;
        this->webViewGazeRelativeX = webViewRelativeGazeX;
        this->webViewGazeRelativeY = webViewRelativeGazeY;
        this->gazeUsed = gazeUsed;
        insideWebView =
            this->webViewGazeRelativeX < 1.f
            && this->webViewGazeRelativeX >=0
            && this->webViewGazeRelativeY < 1.f
            && this->webViewGazeRelativeY >= 0;
    }

    int webViewPixelGazeX;
    int webViewPixelGazeY;
    float webViewGazeRelativeX;
    float webViewGazeRelativeY;
    bool insideWebView;
};

#endif // TABINPUT_H_
