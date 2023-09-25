#include "TestMenu.h"

void TestMenu::OnImGuiRender()
{
	ImGui::Begin("Test Menu");
	bool isClicked;
	for (auto iter = m_Tests.begin();iter != m_Tests.end();iter++)
	{
		isClicked=ImGui::Button(iter->first.c_str());
		if (isClicked)
		{
			m_CurTest = iter->second();
		}
	}
	isClicked=ImGui::Button("Reset");
	if (isClicked)
	{
		m_CurTest.reset();
	}
	ImGui::End();
	if (!m_CurTest)
		return;
	m_CurTest->OnImGuiRender();
}

void TestMenu::OnRender()
{
	if (!m_CurTest)
		return;
	m_CurTest->OnRender();
}

void TestMenu::RegisterTest(const std::string& name, std::function<std::unique_ptr<Test>()> creator)
{
	m_Tests[name] = creator;
}
