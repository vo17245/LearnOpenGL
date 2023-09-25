#pragma once
#include "Test.h"
#include <string>
#include <functional>
#pragma once
#include <memory>
#include <unordered_map>
class TestMenu :public Test
{
public:
	TestMenu(){};
	~TestMenu(){};
	void OnImGuiRender()override;
	void OnRender()override;
	void RegisterTest(const std::string& name, std::function<std::unique_ptr<Test>()> creator);
private:
	std::unordered_map<std::string, std::function<std::unique_ptr<Test>()>> m_Tests;
	std::unique_ptr<Test> m_CurTest;
};