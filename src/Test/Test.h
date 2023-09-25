#pragma once
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_glfw.h"
#include "ImGui/imgui_impl_opengl3.h"
class Test
{
public:
	Test(){}
	virtual ~Test(){}
	virtual void OnRender(){}
	virtual void OnImGuiRender(){}

};