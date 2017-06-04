//============================================================================
// Distributed under the Apache License, Version 2.0.
// Author: Raphael Menges (raphaelmenges@uni-koblenz.de)
//============================================================================

#include "SelectFieldAction.h"
#include "src/State/Web/Tab/Interface/TabInteractionInterface.h"
#include "submodules/eyeGUI/include/eyeGUI.h"

SelectFieldAction::SelectFieldAction(TabInteractionInterface *pTab) : Action(pTab)
{
    // TODO
}

SelectFieldAction::~SelectFieldAction()
{
    // Nothing to do
}

bool SelectFieldAction::Update(float tpf, TabInput tabInput)
{
    // TODO

	// Action is done
	return true;
}

void SelectFieldAction::Draw() const
{
    // Nothing to do
}

void SelectFieldAction::Activate()
{
    // Nothing to do
}

void SelectFieldAction::Deactivate()
{
    // Nothing to do
}

void SelectFieldAction::Abort()
{
    // Nothing to do
}
