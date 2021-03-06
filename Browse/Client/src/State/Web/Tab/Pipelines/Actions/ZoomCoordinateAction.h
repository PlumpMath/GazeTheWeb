//============================================================================
// Distributed under the Apache License, Version 2.0.
// Author: Raphael Menges (raphaelmenges@uni-koblenz.de)
//============================================================================
// Action to zoom to a coordinate with gaze.
// - Input: none
// - Output: vec2 coordinate in CEFPixel space

#ifndef ZOOMCOORDINATEACTION_H_
#define ZOOMCOORDINATEACTION_H_

#include "src/State/Web/Tab/Pipelines/Actions/Action.h"
#include "src/Utils/LerpValue.h"
#include <deque>

class ZoomCoordinateAction : public Action
{
public:

    // Constructor
    ZoomCoordinateAction(TabInteractionInterface* pTab, bool doDimming = true);

    // Update retuns whether finished with execution
    virtual bool Update(float tpf, TabInput tabInput);

    // Draw
    virtual void Draw() const;

    // Activate
    virtual void Activate();

    // Deactivate
    virtual void Deactivate();

    // Abort
    virtual void Abort();

protected:

	// Dimming duration
	const float DIMMING_DURATION = 0.5f; // seconds until it is dimmed

	// Dimming value
	const float DIMMING_VALUE = 0.3f;

	// Deviation fading duration (how many seconds until full deviation is back to zero)
	const float DEVIATION_FADING_DURATION = 1.0f;

	// Deviation weight on zoom speed
	const float DEVIATION_WEIGHT = 3.0f;

	// Multiplier of movement towards center (one means, that on maximum zoom the outermost corner is moved into center)
	const float CENTER_OFFSET_MULTIPLIER = 0.25f;

	// Maximum log zoom level
	const float MAX_LOG_ZOOM = 0.1f;

	// Duration to replace current coordinate with input
	const float MOVE_DURATION = 0.75f;

	// Speed of zoom
	const float ZOOM_SPEED = 0.4f;

    // Coordinate which is updated and later output. In relative page space
    glm::vec2 _relativeZoomCoordinate;

    // Log zooming amount (used for rendering)
	// Calculated as 1.f - log(_linZoom), so becoming smaller at higher zoom levels
    float _logZoom = 1.f;

    // Linear zooming amout (used for calculations)
	// Increasing while zooming
    float _linZoom = 1.f;

    // Offset to center of webview
    glm::vec2 _relativeCenterOffset = glm::vec2(0, 0);

    // Bool to indicate first update
    bool _firstUpdate = true;

	// Deviation of coordinate (not of gaze!; relative coordiantes, no pixels!)
	// Not really in relative coordinates, since aspect ratio corrected...
	float _deviation = 0.f; // [0..1]

	// Dimming
	float _dimming = 0.f;

	// Do dimming
	bool _doDimming = true;
};

#endif // ZOOMCOORDINATEACTION_H_
