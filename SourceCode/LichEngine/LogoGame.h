#pragma once
#include <Resources/Scripting.h>
#include <UI/Image.h>

class LogoGame : public Resources::Scripting
{
public:

	UI::Image* imageLogo;
	FIELD() float showTime;
	
	float showTimer;
	bool isShowing;

	void Start() override;
	void UpdateScript() override;

	std::string SaveScript() override;
	void LoadScript(std::string data) override;

};


